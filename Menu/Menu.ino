#include <ESP8266TimerInterrupt.h>
#include <GyverEncoder.h>
#include <GyverOLED.h>

Encoder enc1(D4, D3, D0, TYPE2);
GyverOLED<SSD1306_128x32> oled;
ESP8266Timer ITimer;

String items[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
const int count = sizeof(items) / sizeof(items[0]);
int pos, offset;

void IRAM_ATTR update() {
  enc1.tick();
  pos += enc1.isRight() - enc1.isLeft();
  if (pos < 0) pos += count;
  pos %= count;
  if (pos < offset) offset = pos;
  else if (pos > offset + 3) offset = pos - 3;
}

void draw() {
  oled.clear();
  oled.home();
  for (int i = offset; i < min(count, offset + 4); i++) {
    //  for (int i = offset; i < count; i++) {
    oled.print(i == pos ? '>' : ' ');
    oled.println(items[i]);
  }
  oled.update();
}

void setup() {
  Serial.begin(9600);
  oled.init();
  ITimer.attachInterruptInterval(100, update);
}

void loop() {
  draw();
}
