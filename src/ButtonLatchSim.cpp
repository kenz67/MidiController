#include "ButtonLatchSim.h"
#include "Debug.h"

ButtonLatchSim::ButtonLatchSim(byte pin, byte channel, byte ccNumber)
    : ButtonBase(pin), _channel(channel), _ccNumber(ccNumber) {
      _value = 0;
    }

void ButtonLatchSim::onPress() {
    Debug::printNameValuePair("LatchSim Button Pressed", _pin);
    if (_value == 127)
        _value = 0;
    else
        _value = 127;
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, _value};
    sendMidiMsg(msg);
}

void ButtonLatchSim::onRelease() {
    Debug::printNameValuePair("LatchSim Button Released", _pin);
}
