#define led1 13
#define led2 15
#define led3 2
#define led4 0
#define led5 4
#define led6 5
#define led7 18
#define led8 19
#define led9 21
#define led10 22

#define d 150

void setup() {
  Serial.begin( 115200 );
  Serial.println( "begin setup" );

  pinMode( led1, OUTPUT );  //initialize led1 output
  digitalWrite( led1, LOW );  //set it to low
  pinMode( led2, OUTPUT );  //initialize led2 output
  digitalWrite( led2, LOW );  //set it to low
  pinMode( led3, OUTPUT );  //initialize led3 output
  digitalWrite( led3, LOW );  //set it to low
  pinMode( led4, OUTPUT );  //initialize led4 output
  digitalWrite( led4, LOW );  //set it to low
  pinMode( led5, OUTPUT );  //initialize led5 output
  digitalWrite( led5, LOW );  //set it to low
  pinMode( led6, OUTPUT );  //initialize led6 output
  digitalWrite( led6, LOW );  //set it to low
  pinMode( led7, OUTPUT );  //initialize led7 output
  digitalWrite( led7, LOW );  //set it to low
  pinMode( led8, OUTPUT );  //initialize led8 output
  digitalWrite( led8, LOW );  //set it to low
  pinMode( led9, OUTPUT );  //initialize led9 output
  digitalWrite( led9, LOW );  //set it to low
  pinMode( led10, OUTPUT );  //initialize led10 output
  digitalWrite( led10, LOW );  //set it to low

  
  Serial.println( "end setup" );
}

void loop() {
  Serial.println( "being loop" );
  
  digitalWrite( led1, HIGH );
  delay(d);
  digitalWrite( led1, LOW );
  
  digitalWrite( led2, HIGH );
  delay(d);
  digitalWrite( led2, LOW );
   
  digitalWrite( led3, HIGH );
  delay(d);
  digitalWrite( led3, LOW );
    
  digitalWrite( led4, HIGH );
  delay(d);
  digitalWrite( led4, LOW );
    
  digitalWrite( led5, HIGH );
  delay(d);
  digitalWrite( led5, LOW );
    
  digitalWrite( led6, HIGH );
  delay(d);
  digitalWrite( led6, LOW );
    
  digitalWrite( led7, HIGH );
  delay(d);
  digitalWrite( led7, LOW );
    
  digitalWrite( led8, HIGH );
  delay(d);
  digitalWrite( led8, LOW );
    
  digitalWrite( led9, HIGH );
  delay(d);
  digitalWrite( led9, LOW );
    
  digitalWrite( led10, HIGH );
  delay(d);
  digitalWrite( led10, LOW );
  

  
  Serial.println( "end loop");
}
