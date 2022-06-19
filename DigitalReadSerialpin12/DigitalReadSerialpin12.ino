#include <U8g2lib.h>
#include <U8x8lib.h>
#include <U8x8lib.h>
#include <Arduino_SensorKit_BMP280.h>
#include <Arduino_SensorKit_LIS3DHTR.h>
#include "Arduino_SensorKit.h"

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 12;
int pressCounter = 0;
bool pressed = false;

// the setup routine runs once when you press reset:
void setup() {
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  Oled.begin();
  Oled.setFlipMode(true);
  
}

// the loop routine runs over and over again forever:
void loop() {
  Oled.setFont(u8x8_font_inr33_3x6_n); 
  Oled.setCursor(0, 0);    // Set the Coordinates 
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  if(buttonState == HIGH && pressed == false) {
    pressCounter++;
    pressed = true;
  }
  if(buttonState == LOW) {
    pressed = false;
  }
  Oled.print(pressCounter);
  Oled.refreshDisplay();
}
