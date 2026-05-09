#include "LatchButton.h"

LatchButton::LatchButton(byte pin, byte channel, byte ccNumber)
    : MidiButtonBase(pin), _channel(channel), _ccNumber(ccNumber) {
    }

void LatchButton::onPress() {
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, 127};
    sendMidiMsg(msg);
}

void LatchButton::onRelease() {
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, 0};
    sendMidiMsg(msg);
}
