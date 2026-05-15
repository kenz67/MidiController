#include "ButtonControl.h"
#include "Debug.h"

ButtonControl::ButtonControl(byte pin, byte channel, byte ccNumber, byte value)
    : ButtonBase(pin), _channel(channel), _ccNumber(ccNumber), _value(value) {}

void ButtonControl::onPress() {
    Debug::printNameValuePair("Control Button Pressed", _pin);
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, _value};
    sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}

void ButtonControl::onRelease() {
    Debug::printNameValuePair("Control Button Released", _pin);
    //midiEventPacket_t msg = {0x08, uint8_t(0x80 | _channel), _note, 0};
    //sendMidiMsg(msg);
    //MidiUSB.sendMIDI(msg);
    //MidiUSB.flush();
}