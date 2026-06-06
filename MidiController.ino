#include <USB-MIDI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "MIDIUSB.h"
#include "UserControls.h"
#include "SetupControls.h"
#include "Debug.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// If 0x27 doesn't work, try 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); 

USBMIDI_CREATE_DEFAULT_INSTANCE();

const short NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);
const short NUM_POTS = sizeof(pots) / sizeof(pots[0]);

void setup() {    
    SetupControls::setup(buttons, NUM_BUTTONS, pots, NUM_POTS, &lcd);
    lcd.setCursor(9, 1);
    lcd.print("by KenZ");
}

void loop() {
  ButtonBase::updateAll(buttons, NUM_BUTTONS);
  PotentiometerBase::updateAll(pots, NUM_POTS);

  delay(1);
  yield();
}

