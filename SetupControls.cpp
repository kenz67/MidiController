#include <LiquidCrystal_I2C.h>

#include "Arduino.h"
#include "ButtonBase.h"
#include "PotentiometerBase.h"
#include "MIDIUSB.h"
#include "SetupControls.h"

#include "Debug.h"

byte midiIcon[8] = {
  B01010, //  *   *
  B10101, // * * * *
  B10001, // *     *
  B11111, // *******
  B11111, // *******
  B01110, //  *****
  B01110, //  *****
  B00100  //    *
};

void SetupControls::lcdClear(LiquidCrystal_I2C *lcd) {
    if (lcd != nullptr) {
        lcd->clear();
    }
}

void SetupControls::lcdPrint(LiquidCrystal_I2C *lcd, const char* message) {
    if (lcd != nullptr) {
        lcd->print(message);
    }
}

void SetupControls::lcdPrint(LiquidCrystal_I2C *lcd, uint8_t x, uint8_t y, const char* message) {
    if (lcd != nullptr) {
        lcd->setCursor(x, y);
        lcd->print(message);
    }
}

void SetupControls::midiLogo(LiquidCrystal_I2C *lcd) {
    if (lcd != nullptr) {
        SetupControls::lcdClear(lcd);
        delay(100); // Give LCD time to process clear
        lcd->createChar(0, midiIcon);
        delay(50);  // Give LCD time to create character
        lcd->setCursor(0, 0);  // Ensure cursor is at start
        lcd->write(0); // Prints the custom MIDI icon
        lcd->print(" MIDI CONTROL");
    }
}

void SetupControls::setup(ButtonBase* buttons[], short NUM_BUTTONS, PotentiometerBase* pots[], short NUM_POTS, LiquidCrystal_I2C *lcd) {
    if (lcd != nullptr) {
        lcd->init();       // Initializes the LCD
        lcd->backlight();
        SetupControls::lcdPrint(lcd, 0, 0, "Initializing...");
    }
    
    Serial.begin(115200);
    Debug::init(1000);
    Debug::printString("Starting...");
    SetupControls::lcdPrint(lcd, 0, 1, "Setting up Buttons...");
    Debug::printNameValuePair("Num Buttons", NUM_BUTTONS);
    ButtonBase::beginAll(buttons, NUM_BUTTONS);
    SetupControls::lcdPrint(lcd, 0, 1, "Setting up Pots...");
    PotentiometerBase::beginAll(pots, NUM_POTS);
    Debug::printNameValuePair("Num Pots", NUM_POTS);

    // Wait for USB-MIDI to be ready before sending startup state
    SetupControls::lcdPrint(lcd, 0, 1, "Init Midi values...");
    delay(1000);
    ButtonBase::initAll(buttons, NUM_BUTTONS);    

    SetupControls::midiLogo(lcd);
    Debug::printString("Setup Complete");
}

