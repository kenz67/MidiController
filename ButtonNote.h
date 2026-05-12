#ifndef BUTTON_NOTE_H
#define BUTTON_NOTE_H

#include <Arduino.h>
#include "ButtonBase.h"

class ButtonNote : public ButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    ButtonNote(byte pin, byte channel, byte note, byte velocity = 127);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _note;
    byte _velocity;
};

#endif
