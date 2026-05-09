#include "MIDIUSB.h"

#include "MidiNotes.h"
#include "MidiButtonBase.h"
#include "NoteButton.h"
#include "ControlButton.h"
#include "LatchButton.h"
#include "SimLatchButton.h"

#include <USB-MIDI.h>

const int switchPin = 2;
bool isLatchingOn = false;   // Virtual latch state
bool lastRead = HIGH;        // Previous physical state
unsigned long lastDebounce = 0;
const int debounceDelay = 50;

USBMIDI_CREATE_DEFAULT_INSTANCE();


MidiButtonBase* buttons[] = {
    // new NoteButton(2, 0, midiNote[C][4]), 
    // new NoteButton(13, 0, midiNote[E][4]),
    //new ControlButton(2, 1, 30, 0),
    //new ControlButton(13, 1, 30, 127),
    new LatchButton(2, 1, 30),

    new SimLatchButton(13, 1, 27),
};

const int NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);

void setup() {
  MidiButtonBase::beginAll(buttons, NUM_BUTTONS);
    pinMode(switchPin, INPUT_PULLUP);
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
  //   bool currentRead = digitalRead(switchPin);

  // // Check if physical state changed (and debounce)
  // if (currentRead != lastRead && (millis() - lastDebounce > debounceDelay)) {
  //   if (currentRead == LOW) { // Button was just pressed
  //     isLatchingOn = !isLatchingOn; // Flip the state
      
  //     // Handle LED and MIDI based on virtual latch
  //     //digitalWrite(ledPin, isLatchingOn ? HIGH : LOW);
  //     sendMIDI(isLatchingOn ? 127 : 0);
  //   }
  //   lastDebounce = millis();
  //   lastRead = currentRead;
  // }
}

