#ifndef MIDI_BUTTON_BASE_H
#define MIDI_BUTTON_BASE_H

#include <Arduino.h>
#include "MIDIUSB.h"
#include "MidiBase.h"

class MidiButtonBase : public MidiBase {
public:
    MidiButtonBase(byte pin, byte debounce = 5);

    virtual ~MidiButtonBase() {}

    void begin();
    void update();

    // Static helpers
    static void beginAll(MidiButtonBase* buttons[], int count);
    static void updateAll(MidiButtonBase* buttons[], int count);

protected:
    virtual void onPress() = 0;
    virtual void onRelease() = 0;

    bool _lastState = HIGH;
    unsigned long _lastChange = 0;
};

#endif
