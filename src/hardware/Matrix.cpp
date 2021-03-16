#include "Matrix.h"
#include "Config.h"

Matrix::Matrix(uint16_t ledsCount)
{
    const unsigned char pin = LED_PIN;

    _ledsCount = ledsCount;
    _leds = new CRGB[ledsCount];

    FastLED.addLeds<WS2812B, pin, GRB>(_leds, _ledsCount);
    _colorR = 0;
    _colorG = 0;
    _colorB = 0;
    setAllLedsRGB(_colorR, _colorG, _colorB);
}

void Matrix::setAllLedsRGB(uint8_t colorR, uint8_t colorG, uint8_t colorB)
{
    if ((colorR != _colorR) || (colorG != _colorG) || (colorB != _colorB)) {
        _colorR = colorR;
        _colorG = colorG;
        _colorB = colorB;
        FastLED.showColor(CRGB(_colorR, _colorG, _colorB));
    }
}

void Matrix::setBrightness(uint8_t scale)
{
    if (scale != _scale) {
        _scale = scale;
        FastLED.setBrightness(_scale);
        FastLED.showColor(CRGB(_colorR, _colorG, _colorB));
    }
}
