#ifndef Matrix_h_
#define Matrix_h_

#include <Arduino.h>
#include <FastLED.h>

class Matrix
{
    public:
        Matrix(uint16_t ledsCount);
        void setAllLedsColor(uint32_t color);
        void setAllLedsRGB(uint8_t colorR, uint8_t colorG, uint8_t colorB);
        void setBrightness(uint8_t scale);

    private:
        uint16_t _ledsCount;
        CRGB *_leds;
        uint8_t _colorR;
        uint8_t _colorG;
        uint8_t _colorB;
        uint8_t _scale;
};

#endif