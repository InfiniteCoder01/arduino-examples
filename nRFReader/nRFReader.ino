#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 9);

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(0x5f);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe (1, 0x7878787878LL);
  radio.startListening();
}

void loop() {
  if(radio.available()){
    char value[30];
    radio.read(&value, sizeof(value));
    Serial.println(value);
  }
}
