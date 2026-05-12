#ifndef BUTTONLATCHSIM_H
#define BUTTONLATCHSIM_H

#include <Arduino.h>
#include "ButtonBase.h"

class ButtonLatchSim : public ButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    ButtonLatchSim(byte pin, byte channel, byte ccNumber);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
    byte _value;
};

#endif