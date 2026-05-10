#include <Arduino.h>
#include "MidiControlBase.h"

MidiControlBase::MidiControlBase(byte pin, byte debounce)
  : _pin(pin), _debounce(debounce) {}


void MidiControlBase::sendMidiMsg(midiEventPacket_t msg) {
    MidiUSB.sendMIDI(msg);
    MidiUSB.flush();
}