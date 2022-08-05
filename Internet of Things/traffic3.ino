//define variables for the pins of led's:
#define red1 13
#define yellow1 12
#define green1 27
#define red2 25
#define yellow2 26
#define green2 32

//define delays:
#define d 10000
#define yellowLight 3000
//define interrupt pin:
#define interrupt 15 //button


static hw_timer_t* timer = NULL;
static unsigned long count = 0;

void IRAM_ATTR timerISR ( void ) {
  //when count == 1 that means 2 seconds have passed after isr was triggered:
  if (count == 1) {
    //change lights------------------------------------------
    digitalWrite( green1, LOW );  //turn off green1
    digitalWrite( yellow1, HIGH);  //turn on yellow1

    //pause for yellow -----------------------------  
  }
  //when count == 2 that means 4 seconds have passed after isr was triggered:
  else if (count == 2) {
    //change lights------------------------------------------
    digitalWrite( yellow1, LOW );  //turn off yellow1
    digitalWrite( red1, HIGH );  //turn on red1
    digitalWrite( red2, LOW );  //turn off red2
    digitalWrite( green2, HIGH );  //turn on green2

    //pause to let cars pass for a bit-----------------------
  }
  //when count == 4 that means 8 seconds have passed after isr was triggered:
  else if (count == 4) {
    //change lights------------------------------------------
    digitalWrite( green2, LOW );  //turn off green2
    digitalWrite( yellow2, HIGH );  //turn on yellow2

    //pause for yellow -----------------------------    
  }
  //when count == 5 that means 10 seconds have passed after isr was triggered:
  else if (count == 5) {
    //change lights------------------------------------------ 
    digitalWrite( yellow2, LOW );  //turn off yellow2
    digitalWrite( red2, HIGH );  //turn on red2
    digitalWrite( red1, LOW);  //turn off red1
    digitalWrite( green1, HIGH);  //turn on green1

    //pause to let cars pass for a bit-----------------------
  }
  ++count;  //increment count every 2 seconds
  //when count == 8 that means 16 seconds have passed after isr was triggered:
  if (count == 8) {
    count = 0;  //reset count
    timerStop(timer);  //stop timer after full sequence
  }
}

void setup() {
  Serial.begin( 115200 );
  
  pinMode (red1, OUTPUT );  //set up 1st red light
  pinMode (yellow1, OUTPUT );  //set up 1st yellow light
  pinMode (green1, OUTPUT );  //set up 1st green light
  pinMode (red2, OUTPUT );  //set up 2nd red light
  pinMode (yellow2, OUTPUT );  //set up 2nd yellow light
  pinMode (green2, OUTPUT );  //set up 2nd green light
  //initialize cross light1 to green and cross light 2 to red
  //cross light1:
  digitalWrite( red1, LOW);
  digitalWrite( yellow1, LOW);
  digitalWrite( green1, HIGH);
  //cross light2:
  digitalWrite( red2, HIGH);
  digitalWrite( yellow2, LOW);
  digitalWrite( green2, LOW);
  
  //setup interrupt:
  pinMode( interrupt, INPUT_PULLUP );
  attachInterrupt( digitalPinToInterrupt(interrupt), isr, HIGH );

  //setup timer interrupt:
  timer = timerBegin( 0, 80, true );
  timerAttachInterrupt( timer, &timerISR, true );
  timerAlarmWrite( timer, 2000000, true );
  
}

void loop() {
}

void isr () {
  //when the button is pressed:
  timerAlarmEnable( timer );  //start timer
  timerRestart(timer);  //restart timer

}
