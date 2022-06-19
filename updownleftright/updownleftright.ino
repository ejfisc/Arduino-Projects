#include <U8g2lib.h>
#include <U8x8lib.h>
#include <U8x8lib.h>
#include <Arduino_SensorKit_BMP280.h>
#include <Arduino_SensorKit_LIS3DHTR.h>
#include "Arduino_SensorKit.h"

int up = 8;
int down = 9;
int left = 10;
int right = 11;
int x = 0;
int y = 0;
uint8_t tile[16] = {0x0f, 0x0f, 0x0f, 0x0f, 0x0, 0x0, 0x0, 0x0, 100, 100, 100, 100, 100, 100, 100, 100};
uint8_t empty[16] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 100, 100, 100, 100, 100, 100, 100, 100};

void setup() {
  // put your setup code here, to run once:
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);

  Oled.begin();
  Oled.setFlipMode(true);
  Oled.setFont(u8x8_font_courB18_2x3_f);
  Oled.drawTile(x, y, 1, tile);
}

void loop() {
  // put your main code here, to run repeatedly:
  

  int upState = digitalRead(up);
  int downState = digitalRead(down);
  int leftState = digitalRead(left);
  int rightState = digitalRead(right);

  
  if(upState == HIGH and y > 0) {
    y--;
    Oled.drawTile(x, y+1, 1, empty);
    Oled.drawTile(x, y, 1, tile);
  }
  if(downState == HIGH and y < 7) {
    y++;
    Oled.drawTile(x, y-1, 1, empty);
    Oled.drawTile(x, y, 1, tile);
  }
  if(leftState == HIGH and x > 0) {
    x--;
    Oled.drawTile(x+1, y, 1, empty);
    Oled.drawTile(x, y, 1, tile);
  }
  if(rightState == HIGH and x < 15) {
    x++;
    Oled.drawTile(x-1, y, 1, empty);
    Oled.drawTile(x, y, 1, tile);
  }
  
}
