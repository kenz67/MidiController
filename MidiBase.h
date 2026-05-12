#ifndef MIDI_CONTROL_BASE_H
#define MIDI_CONTROL_BASE_H

#include <Arduino.h>
#include "MIDIUSB.h"

class MidiBase {
public:
    MidiBase(byte pin, byte debounce = 5);

    virtual ~MidiBase() {}

    virtual void begin() {};
    virtual void update() {};

    void sendMidiMsg(midiEventPacket_t msg);

protected:
    byte _pin;
    byte _debounce;
};

#endif
