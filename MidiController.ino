#include "MIDIUSB.h"

#include "MidiNotes.h"
#include "MidiButtonBase.h"
#include "NoteButton.h"
#include "ControlButton.h"
#include "SimLatchButton.h"

#include <USB-MIDI.h>

USBMIDI_CREATE_DEFAULT_INSTANCE();


MidiButtonBase* buttons[] = {
    // new NoteButton(2, 0, midiNote[C][4]), 
    // new NoteButton(13, 0, midiNote[E][4]),
    //new ControlButton(2, 1, 30, 0),
    //new ControlButton(13, 1, 30, 127),
    new SimLatchButton(2, 1, 30),
    new SimLatchButton(13, 1, 27),
};

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);

void setup() {
  MidiButtonBase::beginAll(buttons, NUM_BUTTONS);
}

void loop() {
  MidiButtonBase::updateAll(buttons, NUM_BUTTONS);
  delay(1);
  yield();
}