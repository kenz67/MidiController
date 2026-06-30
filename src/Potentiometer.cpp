#include "Potentiometer.h"
#include "Debug.h"

Potentiometer::Potentiometer(byte pin, byte channel, byte ccNumber, byte value)
    : PotentiometerBase(pin), _channel(channel), _ccNumber(ccNumber), _value(value) {}

void Potentiometer::onTurn() {
    // Map the potentiometer value to a MIDI CC range (0-127)
    byte ccValue = map(_lastValue, 0, 1023, 0, 127);
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | (uint8_t)(_channel)), _ccNumber, ccValue};
    //midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | (uint8_t)(_channel - 1)), _ccNumber, ccValue};
    sendMidiMsg(msg);

    Debug::printNameValuePair("Potentiometer Value", _ccNumber);
    Debug::printNameValuePair("Potentiometer Value", _lastValue);
    Debug::printNameValuePair("Mapped CC Value", map(_lastValue, 0, 1023, 0, 127)); 
}
