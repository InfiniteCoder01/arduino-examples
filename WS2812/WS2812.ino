#include "FastLED.h"
#define NUM_LEDS 8
#define PIN 4

CRGB leds[NUM_LEDS];
uint8_t counter;

void setup() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(50);
  pinMode(13, OUTPUT);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {            // от 0 до первой трети
    leds[i] = CHSV((counter + i) * 2, 255, 255);  // HSV. Увеличивать HUE (цвет)
  }
  counter++;  // counter меняется от 0 до 255 (тип данных byte)
  FastLED.show();
  delay(50);  // скорость движения радуги
}
