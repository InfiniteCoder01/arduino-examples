#pragma once
#include <FastLED.h>
#include "charmap.hpp"

class Matrix {
public:
  Matrix(int pin, uint16_t width, uint16_t height)
    : width(width), height(height) {
    leds = new CRGB[width * height];
    FastLED.addLeds<WS2811, D0, GRB>(leds, width * height).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(50);
  }

  ~Matrix() {
    delete[] leds;
  }

  void setBrightness(uint8_t brightness) {
    FastLED.setBrightness(brightness);
  }

  void show() {
    FastLED.show();
  }

  void clear() {
    for (int i = 0; i < width * height; i++) leds[i] = CRGB(0, 0, 0);
  }

  void _dot(int x, int y, CRGB color) {
    leds[((height - y - 1) % 2 == 0 ? x : width - x - 1) + (height - y - 1) * width] = color;
  }

  void dot(int x, int y, CRGB color) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    _dot(x, y, color);
  }

  void fillRect(int x, int y, int w, int h, CRGB color) {
    for (int x1 = max(x, 0); x1 < min(x + w, (int)width); x1++) {
      for (int y1 = max(y, 0); y1 < min(y + h, (int)height); y1++) {
        _dot(x1, y1, color);
      }
    }
  }

  void drawBitmap(int x, int y, int w, int h, const uint8_t* bitmap, CRGB color = CRGB(255, 255, 255), CRGB background = CRGB(255, 255, 255)) {
    if (x >= width || y >= height || x < -w || y < -h) return;
    uint8_t _byte;
    int position = -1;
    for (int x1 = max(-x, 0); x1 < min((int)width - x, w); x1++) {
      for (int y1 = max(-y, 0); y1 < min((int)height - y, h); y1++) {
        int index = min(x1, w - 1) + min(y1, h - 1) * ((w + 7) / 8 * 8);
        if (index / 8 != position) _byte = pgm_read_byte(&bitmap[index / 8]);
        if (bitRead(_byte, 7 - index % 8)) {
          _dot(x + x1, y + y1, color);
        } else if (background != color) {
          _dot(x + x1, y + y1, background);
        }
      }
    }
  }

  void drawImage(int x, int y, int w, int h, const uint8_t* image) {
    if (x >= width || y >= height || x < -w || y < -h) return;
    for (int x1 = max(-x, 0); x1 < min((int)width - x, w); x1++) {
      for (int y1 = max(-y, 0); y1 < min((int)height - y, h); y1++) {
        int index = x1 + y1 * w;
        _dot(x + x1, y + y1, CRGB(pgm_read_byte(&image[index * 3]), pgm_read_byte(&image[index * 3 + 1]), pgm_read_byte(&image[index * 3 + 2])));
      }
    }
  }

  uint8_t getFont(uint8_t font, uint8_t row) {
    if (row > 4) return 0;
    font = font - '0' + 16;
    if (font <= 95) return pgm_read_byte(&(charMap[font][row]));
    else if (font >= 96 && font <= 111) return pgm_read_byte(&(charMap[font + 47][row]));
    else if (font <= 159) return pgm_read_byte(&(charMap[font - 17][row]));
    else return pgm_read_byte(&(charMap[font - 1][row]));
  }

  void print(int x, int y, String str) {
    int cursorX = x;
    for (int i = 0; i < str.length(); i++) {
      uint8_t data = str[i];
      if (data > 127) {
        if (data > 191) data = 0;
        else if (i > 0 && str[i - 1] == 209 && data == 145) data = 192;
        else if (i > 0 && str[i - 1] == 208 && data == 129) data = 149;
        else if (i > 0 && str[i - 1] == 226 && data == 128) data = 0;
        else if (i > 0 && str[i - 1] == 128 && data == 148) data = 45;
      }
      if (data == 0) continue;
      for (uint8_t col = 0; col < 6; col++) {
        if (cursorX + col < 0 || cursorX + col >= width) continue;
        uint8_t bits = getFont(data, col);
        for (int _y = 0; _y < 8; _y++) {
          if (bitRead(bits, _y)) dot(cursorX + col, y + _y, CRGB(255, 255, 255));
        }
      }
      cursorX += 6;
    }
  }

public:
  uint16_t width, height;

protected:
  CRGB* leds;
};