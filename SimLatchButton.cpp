#include "SimLatchButton.h"

SimLatchButton::SimLatchButton(byte pin, byte channel, byte ccNumber)
    : MidiButtonBase(pin), _channel(channel), _ccNumber(ccNumber) {
      _value = 0;
    }

void SimLatchButton::onPress() {
    if (_value == 127)
        _value = 0;
    else
        _value = 127;
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, _value};
    sendMidiMsg(msg);
}

void SimLatchButton::onRelease() {
}
