#ifndef SETUPCONTROLS_H
#define SETUPCONTROLS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class SetupControls {
public:
    static void setup(ButtonBase* buttons[], short NUM_BUTTONS, PotentiometerBase* pots[], short NUM_POTS, LiquidCrystal_I2C *lcd = nullptr);

private:
    static bool hasLcd;
    static void lcdClear(LiquidCrystal_I2C *lcd);
    static void lcdPrint(LiquidCrystal_I2C *lcd, const char* message);
    static void lcdPrint(LiquidCrystal_I2C *lcd, uint8_t x, uint8_t y, const char* message);
    static void midiLogo(LiquidCrystal_I2C *lcd);
};

#endif