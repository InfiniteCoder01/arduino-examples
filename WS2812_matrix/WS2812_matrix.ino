#include "matrix.hpp"

const CRGB eyeColor = CRGB(0, 100, 150);//CRGB(17, 140, 144);
const uint8_t PROGMEM raya[] = {
  0x30, 0x40, 0x54, 0x44, 0x54, 0x68, 0x60, 0x68, 0x74, 0x80, 0x84, 0x90, 0x80, 0x84, 0x90, 0x80, 0x84, 0x90, 0x80, 0x84, 0x90, 0x80, 0x84, 0x90, 0x80, 0x84, 0x90, 0x60, 0x68, 0x74, 0x44, 0x54, 0x68, 0x30, 0x40, 0x54, 0x30, 0x40, 0x54, 0x28, 0x44, 0x4c, 0x18, 0x24, 0x24, 0x18, 0x00, 0x34, 0x18, 0x08, 0x38, 0x18, 0x08, 0x38, 0x18, 0x0c, 0x38, 0x18, 0x0c, 0x38, 0x18, 0x08, 0x3c, 0x18, 0x24, 0x20, 0x28, 0x44, 0x4c, 0x30, 0x40, 0x54, 0x30, 0x40, 0x54, 0x18, 0x24, 0x24, 0x20, 0x30, 0x4c, 0x00, 0x68, 0xa4, 0x18, 0x3c, 0x58, 0x14, 0x44, 0x64, 0x0c, 0x34, 0x60, 0x0c, 0x34, 0x60, 0x0c, 0x34, 0x60, 0x0c, 0x30, 0x68, 0x18, 0x24, 0x20, 0x30, 0x40, 0x54, 0x40, 0x54, 0x6c, 0x18, 0x00, 0x34, 0x00, 0x68, 0xa4, 0x00, 0x68, 0x9c, 0x28, 0x24, 0x5c, 0x14, 0x04, 0x34, 0x18, 0x0c, 0x38, 0x18, 0x0c, 0x38, 0x18, 0x0c, 0x38, 0x18, 0x0c, 0x38, 0x14, 0x0c, 0x40, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x18, 0x08, 0x38, 0x18, 0x40, 0x60, 0x18, 0x00, 0x30, 0x14, 0x0c, 0x38, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x18, 0x0c, 0x3c, 0x14, 0x28, 0x50, 0x18, 0x0c, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x18, 0x10, 0x3c, 0x18, 0x0c, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x10, 0x3c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x14, 0x0c, 0x40, 0x18, 0x10, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x04, 0x38, 0x18, 0x38, 0x58, 0x18, 0x38, 0x58, 0x14, 0x08, 0x3c, 0x40, 0x54, 0x6c, 0x30, 0x40, 0x54, 0x18, 0x28, 0x24, 0x14, 0x04, 0x40, 0x18, 0x3c, 0x58, 0x18, 0x38, 0x58, 0x18, 0x38, 0x58, 0x18, 0x38, 0x58, 0x18, 0x38, 0x58, 0x18, 0x34, 0x54, 0x14, 0x30, 0x5c, 0x18, 0x24, 0x24, 0x30, 0x40, 0x54, 0x40, 0x54, 0x6c, 0x2c, 0x4c, 0x4c, 0x18, 0x2c, 0x24, 0x14, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x18, 0x08, 0x3c, 0x14, 0x08, 0x3c, 0x18, 0x28, 0x20, 0x2c, 0x4c, 0x4c, 0x40, 0x54, 0x6c, 0x20, 0x28, 0x34, 0x14, 0x08, 0x3c, 0x14, 0x0c, 0x40, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x18, 0x10, 0x3c, 0x14, 0x0c, 0x40, 0x14, 0x08, 0x3c, 0x20, 0x28, 0x34, 0x20, 0x28, 0x34, 0x20, 0x28, 0x34, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x40, 0x54, 0x6c, 0x20, 0x28, 0x34, 0x20, 0x28, 0x34, 0x20, 0x28, 0x34
};

Matrix matrix(D0, 12, 12);

void setup() {
  matrix.setBrightness(50);
}

void loop() {
  matrix.clear();
  matrix.drawImage(0, 0, 12, 12, raya);
  matrix.fillRect(3, 4, 2, 2, eyeColor);
  matrix.fillRect(7, 4, 2, 2, eyeColor);
  matrix.show();
}
