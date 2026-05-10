#ifndef LATCH_BUTTON_H
#define LATCH_BUTTON_H

#include <Arduino.h>
#include "MidiButtonBase.h"

class LatchButton : public MidiButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    LatchButton(byte pin, byte channel, byte ccNumber);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
};

#endif