
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <Arduino_SensorKit_BMP280.h>
#include <Arduino_SensorKit_LIS3DHTR.h>
#include "Arduino_SensorKit.h"

int minutes = 0;
int seconds = 0;

void setup() {
  // put your setup code here, to run once:
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Oled.setFont(u8x8_font_inr33_3x6_n); 
  Oled.setCursor(0, 0);    // Set the Coordinates 

  if(minutes < 10) {
    Oled.print(0);
    Oled.print(minutes);
  }
  else {
    Oled.print(minutes);
  }
  Oled.print(":");
  if(seconds < 10) {
    Oled.print(0);
    Oled.print(seconds);
  }
  else {
    Oled.print(seconds);
  }
  Oled.refreshDisplay();    // Update the Display 
  seconds++;
  if(seconds == 60) {
    minutes++;
    seconds = 0;
  }
  delay(1000);
}
