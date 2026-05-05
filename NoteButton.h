#ifndef NOTE_BUTTON_H
#define NOTE_BUTTON_H

#include <Arduino.h>
#include "MidiButtonBase.h"

class NoteButton : public MidiButtonBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    NoteButton(byte pin, byte channel, byte note, byte velocity = 127);

protected:
    void onPress() override;
    void onRelease() override;

private:
    byte _channel;
    byte _note;
    byte _velocity;
};

#endif
