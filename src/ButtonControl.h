#ifndef BUTTON_CONTROL_H
#define BUTTON_CONTROL_H

#include "ButtonBase.h"

class ButtonControl : public ButtonBase {
public:
    ButtonControl(byte pin, byte channel, byte ccNumber, byte value,
                  byte longPressccNumber = 0, byte longPressValue = 0,
                  unsigned long longPressDurationMs = 0);

protected:
    void onPress() override;
    void onRelease() override;
    void update() override;

private:
    void sendControlMessage(byte value);
    void sendLongControlMessage(byte value);

    byte _channel;
    byte _ccNumber;
    byte _longPressccNumber;    
    byte _value;
    byte _longPressValue;    
    unsigned long _longPressDurationMs;
    bool _pressed;
    bool _longPressTriggered;
    unsigned long _pressStartTime;
};

#endif
