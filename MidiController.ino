#include "MIDIUSB.h"

#include "UserControls.h"
#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);
const int potPin = A0;
int lastValue = -1;

void setup() {
  ButtonBase::beginAll(buttons, NUM_BUTTONS);
  Serial.begin(115200);
}

void loop() {
  ButtonBase::updateAll(buttons, NUM_BUTTONS);
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

