#include <Arduino.h>
//header

int switchState = 0;

//setup

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}

//loop

void loop(){
  switchState = digitalRead(2);
  //if the button is not pressed
  if(switchState == LOW) {
    digitalWrite(3, HIGH); //green LED on
    digitalWrite(4, LOW); //red LED off
    digitalWrite(5, LOW); //red LED off
  }
  //if the button is pressed
  else {
    digitalWrite(3, LOW); //green LED off
    //blink red LEDs
    digitalWrite(4, LOW); 
    digitalWrite(5, HIGH); 
    //pause for .25s
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(250);
  }
}