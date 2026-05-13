#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin, byte channel, byte ccNumber, byte value)
    : PotentiometerBase(pin), _channel(channel), _ccNumber(ccNumber), _value(value) {}

void Potentiometer::onTurn() {
    // Map the potentiometer value to a MIDI CC range (0-127)
    byte ccValue = map(_lastValue, 0, 1023, 0, 127);
    midiEventPacket_t event = {0x0B, 0xB0 | (1 - 1), 1, ccValue}; // Channel 1, CC #1
    sendMidiMsg(event);

    //debug stuff
    // Serial.print("Potentiometer Value: ");
    // Serial.print(_lastValue);
    // Serial.print(" -> MIDI CC Value: ");
    // Serial.println(ccValue);
}
