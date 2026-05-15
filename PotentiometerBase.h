#ifndef POTENTIOMETER_BASE_H
#define POTENTIOMETER_BASE_H

#include <Arduino.h>
#include "MIDIUSB.h"
#include "MidiBase.h"

class PotentiometerBase : public MidiBase {
public:
    PotentiometerBase(byte pin, byte debounce = 5);

    virtual ~PotentiometerBase() {}

    void begin();
    void update();

    // Static helpers
    static void beginAll(PotentiometerBase* buttons[], int count);
    static void updateAll(PotentiometerBase* buttons[], int count);

protected:
    virtual void onTurn() = 0;

    long _lastValue = -1;
};

#endif
