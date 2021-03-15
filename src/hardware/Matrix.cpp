#include "Matrix.h"
#include "Config.h"

Matrix::Matrix(uint16_t ledsCount)
{
    const unsigned char pin = LED_PIN;

    _ledsCount = ledsCount;
    _leds = new CRGB[ledsCount];

    FastLED.addLeds<WS2812B, pin, GRB>(_leds, _ledsCount);
    setAllLedsColor(CRGB::Black);
}

void Matrix::setAllLedsColor(uint32_t color)
{
    for (uint16_t i = 0; i < _ledsCount; i++) {
        _leds[i] = color;
    }
    FastLED.show();
}

void Matrix::setAllLedsRGB(uint8_t colorR, uint8_t colorG, uint8_t colorB)
{
    for (uint16_t i = 0; i < _ledsCount; i++) {
        _leds[i].setRGB(colorR, colorG, colorB);
    }
    FastLED.show();
}

void Matrix::setAllLedsTemperature(uint16_t kelvins)
{
    // todo: Convert kelvins to rgb
    // todo: call setAllLedsRGB()
}

void Matrix::setBrightness(uint8_t scale)
{
    FastLED.setBrightness(scale);
    FastLED.show();
}