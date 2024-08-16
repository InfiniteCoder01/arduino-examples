#include <SD.h>
#include "i2s.hpp"

void setup() {
  Serial.begin(115200);
  audio::begin();
  SD.begin(4);
  audio::play("/Music/Unity.wav");
}

void loop() {
  audio::loop();
  delay(50); // DMA will do everything for us!
}
