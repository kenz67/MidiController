#include "MIDIUSB.h"

#include "UserControls.h"
#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);
const int NUM_POTS = sizeof(pots) / sizeof(pots[0]);

//const int potPin = A0;
//int lastValue = -1;

void setup() {
    Serial.begin(115200);
    
    // Wait for Serial with timeout (for IDE debugging), but don't block forever on reset
    unsigned long startTime = millis();
    while (!Serial && (millis() - startTime) < 2000) {
        ; // wait for USB serial connection (max 1 second)
    }

    ButtonBase::beginAll(buttons, NUM_BUTTONS);
    PotentiometerBase::beginAll(pots, NUM_POTS);

    // Wait for USB-MIDI to be ready before reading potentiometers
    delay(1000);
}

void loop() {
  ButtonBase::updateAll(buttons, NUM_BUTTONS);
  PotentiometerBase::updateAll(pots, NUM_POTS);
  // int potValue =
  //   (analogRead(A0) +
  //    analogRead(A0) +
  //    analogRead(A0) +
  //    analogRead(A0)) / 4;
  //   if (abs(potValue - lastValue) > 2) {
  //   //if (potValue != lastValue) {
  //   lastValue = potValue;
  //   // Map the potentiometer value to a MIDI CC range (0-127)
  //   byte ccValue = map(potValue, 0, 1023, 0, 127);
  //   // Send a MIDI Control Change message on channel 1, controller number 1
  //   midiEventPacket_t event = {0x0B, 0xB0 | (1 - 1), 1, ccValue}; // Channel 1, CC #1
  //   //MidiUSB.sendMIDI(event);
  //    Serial.print("Potentiometer Value: ");
  //   Serial.print(potValue);
  //   Serial.print(" -> MIDI CC Value: ");
  //   Serial.println(ccValue);
  //}
  delay(1);
  yield();
}

