#include "ButtonNote.h"

ButtonNote::ButtonNote(byte pin, byte channel, byte note, byte velocity)
    : ButtonBase(pin), _channel(channel), _note(note), _velocity(velocity) {}

void ButtonNote::onPress() {
    midiEventPacket_t msg = {0x09, uint8_t(0x90 | _channel), _note, _velocity};
    sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}

void ButtonNote::onRelease() {
    midiEventPacket_t msg = {0x08, uint8_t(0x80 | _channel), _note, 0};
    sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}
