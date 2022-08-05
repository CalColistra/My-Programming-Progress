#define ledR 27
#define ledG 26
#define ledB 25

#define rCh 0
#define gCh 1
#define bCh 2

#define d 50 //delay
#define dLong 200 //longer delay
int K = 15;  //amount of steps to take when fading to next color

  int reds[] = {248, 238, 255, 255, 255, 255, 
                254, 204, 208, 170, 105, 34, 18,
                17, 68, 51, 59, 68};  //red values
  int greens[] = {12, 17, 51, 68, 102, 153, 174,
                  187, 195, 204, 208, 204, 189,
                  170, 68, 17, 12, 34};  //green values
  int blues[] = {18, 0, 17, 34, 68, 51, 45, 51, 16,
                 34, 37, 170, 185, 187, 221, 187,
                 189, 153};  //blue values

  int i = 0;  //index to be incremented throuhg all colors in arrays
  int lastRed = 0;  //saves the previous red value
  int currentRed = 0;  //saves the value to switch to for red
  int lastGreen = 0;  //saves the previous green value
  int currentGreen = 0;  //saves the value to switch to for green
  int lastBlue = 0;  //saves the previous blue value
  int currentBlue = 0;  //saves the value to switch to for blue

  //these hold the difference between last color value and current:
  int redDif = 0;
  int greenDif = 0;
  int blueDif = 0;
  //these hold the increment to use when fading between values:
  int redInc = 0;
  int greenInc = 0;
  int blueInc = 0;
  //these hold the values that are written during the fade
  int redFade = 0;
  int greenFade = 0;
  int blueFade = 0;
  
void setup() {
  Serial.begin ( 115200 );
  Serial.println("in setup");

  ledcAttachPin( ledR, rCh );  //assign RGB led pins to channels
  ledcAttachPin( ledG, gCh );
  ledcAttachPin( ledB, bCh );

  ledcSetup(rCh, 1000, 8);  //1kHz PWM, 8-bit
  ledcSetup(gCh, 1000, 8);
  ledcSetup(bCh, 1000, 8);
  //set all values to 0 to begin
  ledcWrite(rCh, i);
  ledcWrite(gCh, i);
  ledcWrite(bCh, i);
}

void loop() {
  i = random(19);  //get a random number between 0 and 18 inclusive
  currentRed = reds[i];
  currentGreen = greens[i];
  currentBlue = blues[i];
  
  //calculate values for red:
  if (lastRed < currentRed){  //check which value is larger
    redDif = currentRed - lastRed;  //subtract accordingly
    }
  else redDif = lastRed - currentRed;  //subtract accordingly
  redInc = redDif/K; //calculate the value to increment by
  redFade = lastRed;
  //calculate values for green:
  if (lastGreen < currentGreen){  //check which value is larger
    greenDif = currentGreen - lastGreen;  //subtract accordingly
    }
  else greenDif = lastGreen - currentGreen;  //subtract accordingly
  greenInc = greenDif/K; //calculate the value to increment by
  greenFade = lastGreen;
  //calculate values for blue:
  if (lastBlue < currentBlue){  //check which value is larger
    blueDif = currentBlue - lastBlue;  //subtract accordingly
    }
  else blueDif = lastBlue - currentBlue;  //subtract accordingly
  blueInc = blueDif/K; //calculate the value to increment by
  blueFade = lastBlue;
  
  //for loop to fade between colors:
  for (int j = 0; j < K; j++){  //iterates from 0 to K
    if (lastRed < currentRed){  //check which value is larger
      redFade = redFade + redInc;  //increment red value
      ledcWrite(rCh, redFade);  //write the red value
    }
    else{
      redFade = redFade - redInc;  //decrement red value
      ledcWrite(rCh, redFade);  //write the red value
    }

    if (lastGreen < currentGreen){  //check which value is larger
      greenFade = greenFade + greenInc;  //increment green value
      ledcWrite(gCh, greenFade);  //write the green value
    }
    else {
      greenFade = greenFade - greenInc;  //decrement green value
      ledcWrite(gCh, greenFade);  //write the green value
    }
    if (lastBlue < currentBlue){  //check which value is larger
      blueFade = blueFade + blueInc;  //increment blue value
      ledcWrite(bCh, blueFade);  //write the blue value
    }
    else {
      blueFade = blueFade - blueInc;  //decrement blue value
      ledcWrite(bCh, blueFade);  //write the blue value
    }
    
    delay(d); //delay between fades
  }

  //write the current values:
  ledcWrite(rCh, currentRed);
  ledcWrite(gCh, currentGreen);
  ledcWrite(bCh, currentBlue);
  //save the values of previous color:
  lastRed = currentRed;
  lastGreen = currentGreen;
  lastBlue = currentBlue;
  delay(dLong); //delay between fades
}
