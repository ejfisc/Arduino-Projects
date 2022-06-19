#include <U8g2lib.h>
#include <U8x8lib.h>
#include <Arduino_SensorKit_BMP280.h>
#include <Arduino_SensorKit_LIS3DHTR.h>
#include "Arduino_SensorKit.h"

int hours = 5;
int minutes = 22;

void setup() {
  // put your setup code here, to run once:
  Oled.begin();
  Oled.setFlipMode(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Oled.setFont(u8x8_font_inr33_3x6_n); 
  Oled.setCursor(0, 0);    // Set the Coordinates 

  if(hours < 10) {
    Oled.print(0);
    Oled.print(hours);
  }
  else {
    Oled.print(hours);
  }
  Oled.print(":");
  if(minutes < 10) {
    Oled.print(0);
    Oled.print(minutes);
  }
  else {
    Oled.print(minutes);
  }
  Oled.refreshDisplay();    // Update the Display 
  minutes++;
  if(minutes == 60) {
    hours++;
    minutes = 0;
  }
  delay(60000);
}
