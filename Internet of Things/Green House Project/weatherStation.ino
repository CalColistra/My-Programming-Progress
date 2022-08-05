#include "DHTesp.h"
#include <WiFi.h>

#define hostDomain "grevera.ddns.net"  //internet domain to request from
#define hostDoc "/~george/iot.php"  //cannot be empty; use "/" if necessary (doc root)
#define hostPort 80

#ifndef ESP32
  #pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
  #error Select ESP32 board.
#endif

#define dhtPin 33 //pin number for DHT11 data pin
static DHTesp dht;  //define dht object

#define LDR 34  //define the light sensor

#define ssid "magic-kingdom"  //wifi network name
#define pwd "Irish383"  //wifi password

double f = 0;
double h = 0;
int light = 0;
#define stringSize 100
//----------------------------------------------------------------------
void setup() {
  Serial.begin( 115200 );
  dht.setup( dhtPin, DHTesp::DHT11 ); //init sensor
  connectToWiFi();  //call function to connect to wifi
}
//----------------------------------------------------------------------
static void connectToWiFi ( void ) {
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
/*
* https://www.w3schools.com/tags/ref_httpmethods.asp
* The GET Method
* Note that the query string (name/value pairs) is sent in the URL of a GET request:
* /test/demo_form.php?name1=value1&name2=value2
*/
static void requestURL ( char* host, char* doc, uint8_t port ) {
  Serial.println( "----------" );
  Serial.println( "Connecting to domain: " + String(host) );
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println( "connection failed" );
    return;
  }
  Serial.println( "Connected!" );
  Serial.println( "----------" );
  // This will send the request to the server
  client.print( (String) "GET " + doc + " HTTP/1.1\r\n" +
  "Host: " + String(host) + "\r\n" +
  "Connection: close\r\n\r\n" );
  unsigned long timeout = millis();
  while (client.available() == 0) { //wait for response(but not forever)
    if (millis()-timeout > 5000) {
      Serial.println( ">>> Client Timeout !" );
      client.stop();
    return;
    }
  }
  
  //read all lines of the reply from server and print them
  while (client.available()) {
    String line = client.readStringUntil( '\r' );
    Serial.print( line );
  }
  Serial.println();
  Serial.println( "closing connection" );
  client.stop();
}
//----------------------------------------------------------------------
//based on: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiScan/WiFiScan.ino
static void scanNetworks ( void ) {
  Serial.println( "scanning..." );
  int n = WiFi.scanNetworks();
  Serial.println( "done" );
  Serial.print( n );
  Serial.println( " network(s) found" );
  for (int i = 0; i < n; i++) {
    Serial.print( i+1 );
    Serial.print( ": " );
    Serial.print( WiFi.SSID(i) );
    Serial.print( " (" );
    Serial.print( WiFi.RSSI(i) ); //RSSI or received signal strength indication from 0 to -100 (best to worst)
    Serial.print( ") " );
    switch (WiFi.encryptionType(i)) {
      case WIFI_AUTH_OPEN : Serial.print( "open" ); break;
      case WIFI_AUTH_WEP : Serial.print( "wep" ); break;
      case WIFI_AUTH_WPA_PSK : Serial.print( "wpa psk" ); break;
      case WIFI_AUTH_WPA2_PSK : Serial.print( "wpa2 psk" ); break;
      case WIFI_AUTH_WPA_WPA2_PSK : Serial.print( "wpa wpa2 psk" ); break;
      case WIFI_AUTH_WPA2_ENTERPRISE : Serial.print( "wpa2 enterprise" ); break;
      case WIFI_AUTH_MAX : Serial.print( "max" ); break;
      default : Serial.print( "?" ); break;
    }
    Serial.println();
  }
}
//----------------------------------------------------------------------
void loop() {

  Serial.print("Light sensor: ");
  light = analogRead(LDR);  //read light sensor
  Serial.println(light);  //print light sensor
  TempAndHumidity values = dht.getTempAndHumidity();
  if (dht.getStatus() == 0) { //success?
    f = dht.toFahrenheit( values.temperature );
    h = values.humidity;
    Serial.println( "Temp:" + String(f) + "F Humidity:" + String(h) + "%" );
  } 
  else {
    Serial.println( "DHT11 error status: " + String(dht.getStatusString()) );
  }
  int humid = int(h);  //change humidity to int for logging
  //use this st to log data:
  String st = hostDoc + String("?user=Cal&light=") + String(light) + String("&temp=") + String(f) + String("&humid=") + String(humid);
  //use this st to see data log without logging data:
  //String st = hostDoc;
  char Buf[stringSize];  //initialize a buffer char array to place st in
  st.toCharArray(Buf, stringSize);  //convert url string to a char
  Serial.println(Buf);  //print url request with data to be logged
  //call function to send request to server with my data:
  requestURL( (char*)hostDomain, (char*)Buf, hostPort );
  delay(6000);  //pause for a few seconds
}
//----------------------------------------------------------------------
