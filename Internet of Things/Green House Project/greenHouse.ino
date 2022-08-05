//----------------------------------------------------------------------
#include "DHTesp.h"  //include needed for temp & humity sensor
#include <WiFi.h>  //include needed for wifi connection

//definitions:
#define dhtPin 33 //pin number for DHT11 data
static DHTesp dht;  //define dht object
#define LDR 34  //define the light sensor pin
double f = 0;  //variable for sensing temp
double h = 0;  //variable for sensing humidity
int light = 0;  //variable for sensing light
const int T = 5;  //monitor temperautre, light & humidity ever T seconds
const int K = 25;  //keep a record of the K most recent values
int Time = 0;  //variable that will be updated with current time
//Size of array of data (K is each line of data, 65 is max amount of chars in each line):
const int ARRAYSIZE = K * 65;  //initialize size of array
String datas[ARRAYSIZE] = {};  //initialize array for storing data logs
int arrayCount = 0;  //variable used when initializing datas[] array
const int THIGH = 95;  //variable used for high temp
const int TLOW = 25;  //variable used for low temp
#define PIN_BUZZER 13  //buzzer for alarm
#define CHN 0  //define the pwm channel
#define LED_PIN_blue 12  //LED pin for low temp
#define LED_PIN_red 14  //LED pin for high temp
int alarmTime = 0;  //holds the time of when the alarm sounds
int alarmTemp = 0;  //holds the temp when alarm is sounded
String alarmNote;  //note to be posted on website to indicate alarm has sounded
#define ssid "network-name"
#define pwd "network-password"
static WiFiServer server( 80 );  //using port 80

//----------------------------------------------------------------------
void setup ( void ) {
  Serial.begin( 115200 );
  pinMode( LED_PIN_blue, OUTPUT ); //set the LED pin mode
  pinMode( LED_PIN_red, OUTPUT ); //set the LED pin mode
  dht.setup( dhtPin, DHTesp::DHT11 ); //init sensor
  pinMode(PIN_BUZZER, OUTPUT);  //setup buzzer as output
  ledcSetup(CHN, 0, 10);  //setup the pwm channel
  ledcAttachPin(PIN_BUZZER, CHN); //attach the led pin to pwm channel
  ledcWriteTone(CHN, 0);  //set the alarm to output no sound
  connectToWiFi();  //call function to connect to wifi
  server.begin();  //begin server
  //initialize array of data with blank data message:
  for (int i = 0; i < K; i++) { //loop through all 25 logs
    datas[i] = String("logging data ... please wait");  //give this String value
  }
}
//----------------------------------------------------------------------
static void connectToWiFi ( void ) {  //function to connect to wifi
  Serial.println( "Connecting to WiFi network: " + String(ssid) );
  WiFi.begin( ssid, pwd );
  while (WiFi.status() != WL_CONNECTED) { //wait until connected
    delay( 1000 );
    Serial.print( "." );
  }
  Serial.println();
  Serial.println( "WiFi connected!" );
  Serial.print( "IP address: " );
  Serial.println( WiFi.localIP() );
}

//----------------------------------------------------------------------
static void outputHTML ( WiFiClient& client, String datas[] ) {
  //HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK),
  // a content-type so the client knows what's coming, and then a blank line
  client.println( "HTTP/1.1 200 OK" );
  client.println( "Content-type:text/html" );
  client.println();
  //output the content of the HTTP response
  client.println( "<html lang='en'>" );
  client.println( " <head> ");
  client.println("<meta charset='utf-8'> ");
  client.println( "<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'> ");
  client.println( "<meta name='description' content='Greenhouse data log'> ");
  client.println( "<meta name='Cal Colistra' content='Greenhouse'> ");
  client.println( "<link rel='icon' type='image' href='https://www.my-indiana-home.com/wp-content/uploads/2014/02/greenhouse_ks-511x404.jpg'> ");
  client.println( "<title>GreenHouse</title> ");
  client.println( "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>");
  client.println(" </head> " );
  client.println("<header>");
  client.println("<div class='navbar navbar-dark bg-dark box-shadow'>");
  client.println("<div class='container d-flex justify-content-between'>");
  client.println("<a href='#' class='navbar-brand d-flex align-items-center'><strong class='shadow'>GreenHouse</strong></a>");
  client.println("</div></div></header>");
  client.println( " <body>" );
  client.println("<main role='main'><section class='jumbotron text-center'>");
  client.println("<p class='lead text-muted'><button onClick='window.location.reload();'>Refresh Data</button></p>");
  client.println("<ul class='text-center'>");
  if (alarmTime != 0) {  //if alarm has been sounded
    client.println( "<strong>" + alarmNote + "</strong>" );  //print note to user
  }
  for (int i = 0; i < K; i++) { //loop through all 25 logs
    client.println( "<li>" + datas[i] + "</li>");  //print logs
  }
  client.println("</ul>");
  client.println("</section></main>");
  client.println( " </body>" );
  client.println( "</html>" );
  client.println(); //the HTTP response ends with another blank line
}
//----------------------------------------------------------------------
//function to sound the alarm....it gets called when the temp goes above THIGH
//also it turns on the red LED light to indicate high temp for the hearing impaired 
void soundAlarmHigh() {
  alarmTime = millis() / 1000;  //record time of alarm in seconds
  alarmTemp = f;  //record the temp
  //create alarm note:
  alarmNote = String("Alarm Sounded at time: ") + String(alarmTime) + String(". Temperature is too High: ") + String(alarmTemp);
  digitalWrite(LED_PIN_red, HIGH);  //turn on LED
  float sinVal;  //variable to save sine value
  int toneVal;
  for (int x = 0; x < 180; x += 90) {
    sinVal = sin(x * (PI / 180)); //calculate the sine of x
    toneVal = 2000 + sinVal * 500;  //calculate the sound frequency according to the sine of x
    ledcWriteTone(CHN, toneVal);  //make sound
    delay(100);  //pause
    ledcWriteTone(CHN, 0);  //no sound
  }
}
//----------------------------------------------------------------------
//function to sound the alarm....it gets called when the temp goes below TLOW
//also it turns on the blue LED light to indicate low temp for the hearing impaired 
void soundAlarmLow() {
  alarmTime = millis() / 1000;  //record time of alarm in seconds
  alarmTemp = f;  //record the temp
  //create alarm note:
  alarmNote = String("Alarm Sounded at time: ") + String(alarmTime) + String(". Temperature is too Low: ") + String(alarmTemp);
  digitalWrite(LED_PIN_blue, HIGH);  //turn on LED
  float sinVal;  //variable to save sine value
  int toneVal;
  for (int x = 0; x < 360; x += 180) {
    sinVal = sin(x * (PI / 180)); //calculate the sine of x
    toneVal = 2000 + sinVal * 250;  //calculate the sound frequency according to the sine of x
    ledcWriteTone(CHN, toneVal);  //make sound
    delay(100);  //pause
    ledcWriteTone(CHN, 0);  //no sound
  }
}
//----------------------------------------------------------------------
//function to record data from sensors and place in the array of datas[]:
void logDatas() {
  //record data:
  light = analogRead(LDR);  //read light sensor
  TempAndHumidity values = dht.getTempAndHumidity();
  if (dht.getStatus() == 0) { //success?
    f = dht.toFahrenheit( values.temperature );  //read temperature
    h = values.humidity;  //read humidity
  }
  else {
    Serial.println( "DHT11 error status: " + String(dht.getStatusString()) );
  }
  Serial.println("just logged data!");  //print to serial monitor that data has been logged
  int humid = int(h);  //change humidity to int for logging
  int times = millis() / 1000; //record time of log in seconds
  //make the long String of data:
  String st = String("Time: ") + String(times) + String(", Light= ") + String(light) + String(", Temp= ") + String(f) + String(", Humidity= ") + String(humid) + String("%");
  if (arrayCount == 0) {  //check if it is first log
    datas[arrayCount] = st;  //make the first log
    arrayCount = arrayCount + 1;  //increment
  }
  if (arrayCount > 0) {  //at this point we have made the first log
    String temp1 = datas[0];  //save values for shifting logs
    String temp2 = datas[1];  //save values for shifting logs
    for (int i = 1; i < K; i++) { //loop through 24 of the 25 logs
      datas[i] = temp1;  //shift old logs one spot down
      temp1 = temp2;  //save values for shift
      temp2 = datas[i + 1];  //shift
    }
    datas[K] = temp2;  //shift
    datas[0] = st;  //enter new data at top
  }
}
//----------------------------------------------------------------------
void loop ( void ) {
  //listen for incoming clients/requests
  WiFiClient client = server.available();
  if (!client) {
    logDatas();  //call function to log data every T seconds
    delay(T * 1000);  //wait T seconds before recording more data
    //check if temp is too high:
    if (f > THIGH) soundAlarmHigh();  //if so, sound the high alarm
    //check if temp is too low:
    if (f < TLOW)  soundAlarmLow();  //if so, sound the low alarm
    return;  //restart loop()
  }
  //got a request!
  Serial.print( "new client: " );
  Serial.println( client.remoteIP().toString() );
  logDatas();  //call function to log data every T seconds
  outputHTML( client, datas );  //output HTML every T seconds
  delay(T * 1000);  //wait T seconds before sending more data
  //check if temp is too high:
  if (f > THIGH) soundAlarmHigh();  //if so, sound the high alarm
  //check if temp is too low:
  if (f < TLOW)  soundAlarmLow();  //if so, sound the low alarm
  //close the connection
  client.stop();
  Serial.println( "client disconnected." );
}
//----------------------------------------------------------------------
