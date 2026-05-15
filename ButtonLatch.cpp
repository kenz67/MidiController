#include "ButtonLatch.h"
#include "Debug.h"

ButtonLatch::ButtonLatch(byte pin, byte channel, byte ccNumber)
    : ButtonBase(pin), _channel(channel), _ccNumber(ccNumber) {
    }

void ButtonLatch::onPress() {
    Debug::printNameValuePair("Latch Button Pressed", _pin);
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, 127};
    sendMidiMsg(msg);
}

void ButtonLatch::onRelease() {
    Debug::printNameValuePair("Latch Button Released", _pin);
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, 0};
    sendMidiMsg(msg);
}
