#include <SPI.h>

#define CS 5

void send(uint8_t val) {
  digitalWrite(CS, LOW);
  SPI.beginTransaction(SPISettings(1000, MSBFIRST, SPI_MODE0));
  SPI.transfer(val);
  SPI.endTransaction();
  digitalWrite(CS, HIGH);
}

void setup() {
  SPI.begin();
  pinMode(CS, OUTPUT);
  pinMode(17, OUTPUT);
  digitalWrite(CS, HIGH);
  digitalWrite(17, LOW);
}

void loop() {
  send(1);
  delay(500);
  send(2);
  delay(500);
  send(3);
  delay(500);
  send(4);
  delay(500);
  send(5);
  delay(500);
}
