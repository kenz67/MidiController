#include "MIDIUSB.h"

#include "UserControls.h"
#include <USB-MIDI.h>

#include "Debug.h"

USBMIDI_CREATE_DEFAULT_INSTANCE();

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);
const int NUM_POTS = sizeof(pots) / sizeof(pots[0]);

//const int potPin = A0;
//int lastValue = -1;

void setup() {
    Serial.begin(115200);
    Debug::init(1000);
    Debug::printString("Starting...");

    ButtonBase::beginAll(buttons, NUM_BUTTONS);
    PotentiometerBase::beginAll(pots, NUM_POTS);

    // Wait for USB-MIDI to be ready before sending startup state
    delay(1000);
    ButtonBase::initAll(buttons, NUM_BUTTONS);
    Debug::printString("Setup Complete");
}

void loop() {
  ButtonBase::updateAll(buttons, NUM_BUTTONS);
  PotentiometerBase::updateAll(pots, NUM_POTS);

  delay(1);
  yield();
}

