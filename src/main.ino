#include <Arduino.h>
#include "hardware/Display.h"
#include "hardware/GyverEncoder.h"
#include "hardware/Matrix.h"
#include "Config.h"


// =========================================
// ================= SETUP =================
// =========================================

Display *display;
Matrix *matrix;
Encoder enc(ENCODER_S2_PIN, ENCODER_S1_PIN, ENCODER_KEY_PIN, TYPE2);

enum StateType {
    setBright, setKelvin, setColorR, setColorG, setColorB
};

struct RGBColorType {
    uint8_t colorR;
    uint8_t colorG;
    uint8_t colorB;
};

RGBColorType kelvinToRGB(uint16_t kelvin)
{
    if (kelvin == 1000) {
        return {255, 56, 0};
    }
    if (kelvin == 1100) {
        return {255, 71, 0};
    }
    if (kelvin == 1200) {
        return {255, 83, 0};
    }
    if (kelvin == 1300) {
        return {255, 93, 0};
    }
    if (kelvin == 1400) {
        return {255, 101, 0};
    }
    if (kelvin == 1500) {
        return {255, 109, 0};
    }
    if (kelvin == 1600) {
        return {255, 115, 0};
    }
    if (kelvin == 1700) {
        return {255, 121, 0};
    }
    if (kelvin == 1800) {
        return {255, 126, 0};
    }
    if (kelvin == 1900) {
        return {255, 131, 0};
    }
    if (kelvin == 2000) {
        return {255, 138, 18};
    }
    if (kelvin == 2100) {
        return {255, 142, 33};
    }
    if (kelvin == 2200) {
        return {255, 147, 44};
    }
    if (kelvin == 2300) {
        return {255, 152, 54};
    }
    if (kelvin == 2400) {
        return {255, 157, 63};
    }
    if (kelvin == 2500) {
        return {255, 161, 72};
    }
    if (kelvin == 2600) {
        return {255, 165, 79};
    }
    if (kelvin == 2700) {
        return {255, 169, 87};
    }
    if (kelvin == 2800) {
        return {255, 173, 94};
    }
    if (kelvin == 2900) {
        return {255, 177, 101};
    }
    if (kelvin == 3000) {
        return {255, 180, 107};
    }
    if (kelvin == 3100) {
        return {255, 184, 114};
    }
    if (kelvin == 3200) {
        return {255, 187, 120};
    }
    if (kelvin == 3300) {
        return {255, 190, 126};
    }
    if (kelvin == 3400) {
        return {255, 193, 132};
    }
    if (kelvin == 3500) {
        return {255, 196, 137};
    }
    if (kelvin == 3600) {
        return {255, 199, 143};
    }
    if (kelvin == 3700) {
        return {255, 201, 148};
    }
    if (kelvin == 3800) {
        return {255, 204, 153};
    }
    if (kelvin == 3900) {
        return {255, 206, 159};
    }
    if (kelvin == 4000) {
        return {255, 209, 163};
    }
    if (kelvin == 4100) {
        return {255, 211, 168};
    }
    if (kelvin == 4200) {
        return {255, 213, 173};
    }
    if (kelvin == 4300) {
        return {255, 215, 177};
    }
    if (kelvin == 4400) {
        return {255, 217, 182};
    }
    if (kelvin == 4500) {
        return {255, 219, 186};
    }
    if (kelvin == 4600) {
        return {255, 221, 190};
    }
    if (kelvin == 4700) {
        return {255, 223, 194};
    }
    if (kelvin == 4800) {
        return {255, 225, 198};
    }
    if (kelvin == 4900) {
        return {255, 227, 202};
    }
    if (kelvin == 5000) {
        return {255, 228, 206};
    }
    if (kelvin == 5100) {
        return {255, 230, 210};
    }
    if (kelvin == 5200) {
        return {255, 232, 213};
    }
    if (kelvin == 5300) {
        return {255, 233, 217};
    }
    if (kelvin == 5400) {
        return {255, 235, 220};
    }
    if (kelvin == 5500) {
        return {255, 236, 224};
    }
    if (kelvin == 5600) {
        return {255, 238, 227};
    }
    if (kelvin == 5700) {
        return {255, 239, 230};
    }
    if (kelvin == 5800) {
        return {255, 240, 233};
    }
    if (kelvin == 5900) {
        return {255, 242, 236};
    }
    if (kelvin == 6000) {
        return {255, 243, 239};
    }
    if (kelvin == 6100) {
        return {255, 244, 242};
    }
    if (kelvin == 6200) {
        return {255, 245, 245};
    }
    if (kelvin == 6300) {
        return {255, 246, 247};
    }
    if (kelvin == 6400) {
        return {255, 248, 251};
    }
    if (kelvin == 6500) {
        return {255, 249, 253};
    }
    if (kelvin == 6600) {
        return {254, 249, 255};
    }
    if (kelvin == 6700) {
        return {252, 247, 255};
    }
    if (kelvin == 6800) {
        return {249, 246, 255};
    }
    if (kelvin == 6900) {
        return {247, 245, 255};
    }
    if (kelvin == 7000) {
        return {245, 243, 255};
    }
    if (kelvin == 7100) {
        return {243, 242, 255};
    }
    if (kelvin == 7200) {
        return {240, 241, 255};
    }
    if (kelvin == 7300) {
        return {239, 240, 255};
    }
    if (kelvin == 7400) {
        return {237, 239, 255};
    }
    if (kelvin == 7500) {
        return {235, 238, 255};
    }
    if (kelvin == 7600) {
        return {233, 237, 255};
    }
    if (kelvin == 7700) {
        return {231, 236, 255};
    }
    if (kelvin == 7800) {
        return {230, 235, 255};
    }
    if (kelvin == 7900) {
        return {228, 234, 255};
    }
    if (kelvin == 8000) {
        return {227, 233, 255};
    }
    if (kelvin == 8100) {
        return {225, 232, 255};
    }
    if (kelvin == 8200) {
        return {224, 231, 255};
    }
    if (kelvin == 8300) {
        return {222, 230, 255};
    }
    if (kelvin == 8400) {
        return {221, 230, 255};
    }
    if (kelvin == 8500) {
        return {220, 229, 255};
    }
    if (kelvin == 8600) {
        return {218, 229, 255};
    }
    if (kelvin == 8700) {
        return {217, 227, 255};
    }
    if (kelvin == 8800) {
        return {216, 227, 255};
    }
    if (kelvin == 8900) {
        return {215, 226, 255};
    }
    if (kelvin == 9000) {
        return {214, 225, 255};
    }
    if (kelvin == 9100) {
        return {212, 225, 255};
    }
    if (kelvin == 9200) {
        return {211, 224, 255};
    }
    if (kelvin == 9300) {
        return {210, 223, 255};
    }
    if (kelvin == 9400) {
        return {209, 223, 255};
    }
    if (kelvin == 9500) {
        return {208, 222, 255};
    }
    if (kelvin == 9600) {
        return {207, 221, 255};
    }
    if (kelvin == 9700) {
        return {207, 221, 255};
    }
    if (kelvin == 9800) {
        return {206, 220, 255};
    }
    if (kelvin == 9900) {
        return {205, 220, 255};
    }
    if (kelvin == 10000) {
        return {207, 218, 255};
    }
    if (kelvin == 10100) {
        return {207, 218, 255};
    }
    if (kelvin == 10200) {
        return {206, 217, 255};
    }
    if (kelvin == 10300) {
        return {205, 217, 255};
    }
    if (kelvin == 10400) {
        return {204, 216, 255};
    }
    if (kelvin == 10500) {
        return {204, 216, 255};
    }
    if (kelvin == 10600) {
        return {203, 215, 255};
    }
    if (kelvin == 10700) {
        return {202, 215, 255};
    }
    if (kelvin == 10800) {
        return {202, 214, 255};
    }
    if (kelvin == 10900) {
        return {201, 214, 255};
    }
    if (kelvin == 11000) {
        return {200, 213, 255};
    }
    if (kelvin == 11100) {
        return {200, 213, 255};
    }
    if (kelvin == 11200) {
        return {199, 212, 255};
    }
    if (kelvin == 11300) {
        return {198, 212, 255};
    }
    if (kelvin == 11400) {
        return {198, 212, 255};
    }
    if (kelvin == 11500) {
        return {197, 211, 255};
    }
    if (kelvin == 11600) {
        return {197, 211, 255};
    }
    if (kelvin == 11700) {
        return {197, 210, 255};
    }
    if (kelvin == 11800) {
        return {196, 210, 255};
    }
    if (kelvin == 11900) {
        return {195, 210, 255};
    }
    if (kelvin == 12000) {
        return {195, 209, 255};
    }
    return {0, 0, 0};
}

String intToStringWithZeros(uint8_t value)
{
    if (value < 10) {
        return String("00") + String(value);
    } else if (value < 100) {
        return String("0") + String(value);
    }
    return String(value);
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);

    display = new Display(LCD_ADDR, LCD_COLS, LCD_ROWS);
    matrix = new Matrix(LED_COUNT);

    // 230 = 7,6A
    // 240 - не выдерживает БП
}

// ==========================================
// ================== MAIN ==================
// ==========================================

void loop()
{
    static uint8_t brightProc = INIT_BRIGHT_PROC;
    static uint16_t kelvin = INIT_KELVIN;

    static uint8_t colorR;
    static uint8_t colorG;
    static uint8_t colorB;

    static bool isFirst = true;

    if (isFirst) {
        RGBColorType rgb = kelvinToRGB(kelvin);
        colorR = rgb.colorR;
        colorG = rgb.colorG;
        colorB = rgb.colorB;
        matrix->setBrightness(map(brightProc, 0, 100, 0, 255));
        matrix->setAllLedsRGB(colorR, colorG, colorB);
        isFirst = false;

        display->shortTimeBacklight();
    }


    static StateType state = setBright;

    display->tick();
    enc.tick();

    display->showLeftText(String(brightProc) + String("%"), 0);
    display->showRightText((kelvin == 0) ? String("") : (String(kelvin) + String("K")), 0);

    display->showText(
        intToStringWithZeros(colorR) + String(" ") +
        intToStringWithZeros(colorG) + String(" ") +
        intToStringWithZeros(colorB),
        1
    );

    if (enc.isRight()) {
        if (state == setBright) {
            if (brightProc <= 95) {
                brightProc = brightProc + 5;
                matrix->setBrightness(map(brightProc, 0, 100, 0, 255));
            }
        } else if (state == setKelvin) {
            if (kelvin < 12000) {
                kelvin = kelvin + 100;
                if (kelvin < 1000) {
                    kelvin = 1000;
                }
                RGBColorType rgb = kelvinToRGB(kelvin);
                colorR = rgb.colorR;
                colorG = rgb.colorG;
                colorB = rgb.colorB;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorR) {
            if (colorR < 255) {
                kelvin = 0;
                colorR++;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorG) {
            if (colorG < 255) {
                kelvin = 0;
                colorG++;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorB) {
            if (colorB < 255) {
                kelvin = 0;
                colorB++;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        }
        display->shortTimeBacklight();
    }

    if (enc.isLeft()) {
        if (state == setBright) {
            if (brightProc >= 5) {
                brightProc = brightProc - 5;
                matrix->setBrightness(map(brightProc, 0, 100, 0, 255));
            }
        } else if (state == setKelvin) {
            if (kelvin > 1000) {
                kelvin = kelvin - 100;
                RGBColorType rgb = kelvinToRGB(kelvin);
                colorR = rgb.colorR;
                colorG = rgb.colorG;
                colorB = rgb.colorB;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorR) {
            if (colorR > 0) {
                kelvin = 0;
                colorR--;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorG) {
            if (colorG > 0) {
                kelvin = 0;
                colorG--;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        } else if (state == setColorB) {
            if (colorB > 0) {
                kelvin = 0;
                colorB--;
                matrix->setAllLedsRGB(colorR, colorG, colorB);
            }
        }
        display->shortTimeBacklight();
    }

    if (enc.isPress()) {
        if (state == setBright) {
            state = setKelvin;
        } else if (state == setKelvin) {
            state = setBright;
        } else if (state == setColorR) {
            state = setColorG;
        } else if (state == setColorG) {
            state = setColorB;
        } else if (state == setColorB) {
            state = setColorR;
        }
        display->shortTimeBacklight();
    }

    if (enc.isDouble()) {
        if ((state == setBright) || (state == setKelvin)) {
            state = setColorR;
            kelvin = 0;
        } else if ((state == setColorR) || (state == setColorG) || (state == setColorB)) {
            state = setBright;
            kelvin = INIT_KELVIN;
            RGBColorType rgb = kelvinToRGB(kelvin);
            colorR = rgb.colorR;
            colorG = rgb.colorG;
            colorB = rgb.colorB;
            matrix->setAllLedsRGB(colorR, colorG, colorB);
        }
        display->shortTimeBacklight();
    }
}
