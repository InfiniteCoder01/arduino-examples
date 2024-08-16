#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 9);

void send(char* data) {
  radio.setPayloadSize(1);
  Serial.println(radio.write(data, 1));
}

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(0x5f);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openWritingPipe(0x7878787878LL);
}

void loop() {
  if(!Serial.available()) return;
  char data[1];
  data[0] = Serial.read();
  send(data);
}
