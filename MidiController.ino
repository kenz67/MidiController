#include <USB-MIDI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MIDIUSB.h>

//#include "UserControls.h"
#include "SetupControls.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// If 0x27 doesn't work, try 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2); 

USBMIDI_CREATE_DEFAULT_INSTANCE();

ButtonBase* buttons[] = {
    // Add buttons here

    // new NoteButton(2, 0, midiNote[C][4]), 
    // new ButtonNote(13, 0, midiNote[E][4]),
    //new ButtonControl(2, 1, 30, 0),
    //new ButtonControl(13, 1, 30, 127),
    new ButtonNote(13, 0, midiNote[D][4]),
    new ButtonLatch(4, 1, 30),
    //new ButtonLatchSim(13, 1, 27),
};

PotentiometerBase* pots[] = {
    // Add potentiometers here
   // new Potentiometer(A0, 1, 31, 0)
};

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

