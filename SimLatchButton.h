#ifndef SIMLATCH_BUTTON_H
#define SIMLATCH_BUTTON_H

#include <Arduino.h>
#include "MidiButtonBase.h"

class SimLatchButton : public MidiButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    SimLatchButton(byte pin, byte channel, byte ccNumber);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
    byte _value;
};

#endif