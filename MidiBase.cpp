#include <Arduino.h>
#include "MidiBase.h"

MidiBase::MidiBase(byte pin, byte debounce)
  : _pin(pin), _debounce(debounce) {}


void MidiBase::sendMidiMsg(midiEventPacket_t msg) {
    MidiUSB.sendMIDI(msg);
    MidiUSB.flush();
}