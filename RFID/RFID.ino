#include <SPI.h>
#include <MFRC522.h>

MFRC522 rider(9, 10);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  rider.PCD_Init();
}

void loop() {
  if (!rider.PICC_IsNewCardPresent())
    return;

  if (!rider.PICC_ReadCardSerial())
    return;

  Serial.print("UID=");
  view_data(rider.uid.uidByte, rider.uid.size);
  Serial.println();
  Serial.print("type=");
  byte piccType = rider.PICC_GetType(rider.uid.sak);
  Serial.print(rider.PICC_GetTypeName(piccType));
  Serial.println();
  delay(1000);
}

void view_data (byte *buf, byte size) {
  for (byte j = 0; j < size; j++) {
    Serial.print(buf [j]);
    Serial.print(buf [j], HEX);
  }
}
