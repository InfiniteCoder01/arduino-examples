#include <Audio.h>
#include <SPI.h>

#define SD_CS 4
Audio audio(true);

void setup() {
  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);
  SPI.begin();
  SPI.setFrequency(1000000);
  Serial.begin(115200);
  SD.begin(SD_CS);
  audio.setVolume(21);
  audio.connecttoFS(SD, "/Music/Revolution.mp3");
}

void loop() {
  audio.loop();
}
