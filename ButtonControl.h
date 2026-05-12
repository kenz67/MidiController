#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

#include <Arduino.h>
#include "ButtonBase.h"

class ButtonControl : public ButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    ButtonControl(byte pin, byte channel, byte ccNumber, byte value);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
    byte _value;
};

#endif
