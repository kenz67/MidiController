#include "MIDIUSB.h"

// #include "MidiNotes.h"
// #include "MidiButtonBase.h"
// #include "NoteButton.h"
// #include "ControlButton.h"
// #include "LatchButton.h"
// #include "SimLatchButton.h"

#include "UserControls.h"
#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);

void setup() {
  MidiButtonBase::beginAll(buttons, NUM_BUTTONS);
}

void sendMIDI(byte value) {
  // Sends CC #10 on Channel 1
  midiEventPacket_t event = {0x0B, 0xB0, 10, value};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void loop() {
  MidiButtonBase::updateAll(buttons, NUM_BUTTONS);
  delay(1);
  yield();
}

