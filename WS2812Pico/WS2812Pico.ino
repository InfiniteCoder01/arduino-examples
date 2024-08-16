#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(3, 28, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(90);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) strip.setPixelColor(i, strip.Color(255, 255, 255));
  strip.show();
}
