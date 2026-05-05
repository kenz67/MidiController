#ifndef CONTROL_BUTTON_H
#define CONTROL_BUTTON_H

#include <Arduino.h>
#include "MidiButtonBase.h"

class ControlButton : public MidiButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    ControlButton(byte pin, byte channel, byte ccNumber, byte value);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
    byte _value;
};

#endif
