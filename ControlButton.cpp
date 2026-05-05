#include "ControlButton.h"

ControlButton::ControlButton(byte pin, byte channel, byte ccNumber, byte value)
    : MidiButtonBase(pin), _channel(channel), _ccNumber(ccNumber), _value(value) {}

void ControlButton::onPress() {
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, _value};
    sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}

void ControlButton::onRelease() {
    //midiEventPacket_t msg = {0x08, uint8_t(0x80 | _channel), _note, 0};
    //sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}
