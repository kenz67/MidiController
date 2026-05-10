#ifndef MIDI_CONTROL_BASE_H
#define MIDI_CONTROL_BASE_H

#include <Arduino.h>
#include "MIDIUSB.h"

class MidiControlBase {
public:
    MidiControlBase(byte pin, byte debounce = 5);

    virtual ~MidiControlBase() {}

    virtual void begin() {};
    virtual void update() {};

    void sendMidiMsg(midiEventPacket_t msg);

protected:
    byte _pin;
    byte _debounce;
};

#endif
