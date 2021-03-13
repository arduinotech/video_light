#include <Arduino.h>
#include "hardware/Display.h"
#include "hardware/GyverEncoder.h"
#include "hardware/Matrix.h"
#include "Config.h"


// =========================================
// ================= SETUP =================
// =========================================

CRGB leds[LED_COUNT];
Display *display;
Matrix *matrix;
Encoder enc(ENCODER_S2_PIN, ENCODER_S1_PIN, ENCODER_KEY_PIN, TYPE2);

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    display = new Display(LCD_ADDR, LCD_COLS, LCD_ROWS);
    display->showText("Setup...", 0);
    display->shortTimeBacklight();

    matrix = new Matrix(LED_COUNT);

    delay(1500);
    // 230 = 7,6A
    // 240 - не выдерживает БП
    matrix->setAllLedsRGB(230, 230, 230);
}


// ==========================================
// ================== MAIN ==================
// ==========================================

void loop()
{
    uint64_t now = millis();
    static uint32_t counterRight = 0;
    static uint32_t counterLeft = 0;
    static uint32_t counterPress = 0;

    static uint64_t lastClickTime = 0;

    display->tick();
    enc.tick();

    if (enc.isRight()) {
        counterLeft = 0;
        counterPress = 0;
        display->showText("ENC RIGHT: " + String(counterRight++), 0);
        display->shortTimeBacklight();
    }

    if (enc.isLeft()) {
        counterRight = 0;
        counterPress = 0;
        display->showText("ENC LEFT: " + String(counterLeft++), 0);
        display->shortTimeBacklight();
    }

    if (enc.isPress()) {
        counterLeft = 0;
        counterRight = 0;
        display->showText("ENC PRESS: " + String(counterPress++), 0);
        display->shortTimeBacklight();
    }

    int sensorVal = digitalRead(BUTTON_PIN);
    if ((sensorVal == LOW) && ((now - lastClickTime) > DOUBLE_CLICK_DELAY)) {
        display->showText("BUTTON CLICK", 0);
        display->shortTimeBacklight();
        lastClickTime = now;
    }
}
