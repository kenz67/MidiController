#ifndef BUTTON_LATCH_H
#define BUTTON_LATCH_H

#include <Arduino.h>
#include "ButtonBase.h"

class ButtonLatch : public ButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    ButtonLatch(byte pin, byte channel, byte ccNumber);

protected:
    void init() override;
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _ccNumber;
};

#endif