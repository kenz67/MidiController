#include "MIDIUSB.h"

#include "UserControls.h"
#include <USB-MIDI.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// If 0x27 doesn't work, try 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); 

#include "Debug.h"

USBMIDI_CREATE_DEFAULT_INSTANCE();

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);
const int NUM_POTS = sizeof(pots) / sizeof(pots[0]);

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

void setup() {
    lcd.init();       // Initializes the LCD
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");

    Serial.begin(115200);
    Debug::init(1000);
    Debug::printString("Starting...");
    lcd.setCursor(0,1);
    lcd.print("Setting up Buttons...");
    ButtonBase::beginAll(buttons, NUM_BUTTONS);
    lcd.setCursor(0,1);
    lcd.print("Setting up Pots...");
    //PotentiometerBase::beginAll(pots, NUM_POTS);

    // Wait for USB-MIDI to be ready before sending startup state
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Init Midi values...");
    ButtonBase::initAll(buttons, NUM_BUTTONS);
    Debug::printString("Setup Complete");
    lcd.clear();
    delay(100); // Give LCD time to process clear
    lcd.createChar(0, midiIcon);
    delay(50);  // Give LCD time to create character
    lcd.setCursor(0, 0);  // Ensure cursor is at start
    lcd.write(0); // Prints the custom MIDI icon
    lcd.print(" MIDI CONTROL");
    
}

void loop() {
  ButtonBase::updateAll(buttons, NUM_BUTTONS);
  PotentiometerBase::updateAll(pots, NUM_POTS);

  delay(1);
  yield();
}

