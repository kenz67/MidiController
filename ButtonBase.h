#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H

#include <Arduino.h>
#include "MIDIUSB.h"
#include "MidiBase.h"

class ButtonBase : public MidiBase {
public:
    ButtonBase(byte pin, byte debounce = 5);

    virtual ~ButtonBase() {}

    void begin();
    void update();

    // Static helpers
    static void beginAll(ButtonBase* buttons[], int count);
    static void updateAll(ButtonBase* buttons[], int count);

protected:
    virtual void onPress() = 0;
    virtual void onRelease() = 0;

    bool _lastState = HIGH;
    unsigned long _lastChange = 0;
};

#endif
