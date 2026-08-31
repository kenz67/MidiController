#include "ButtonControl.h"
#include "Debug.h"

ButtonControl::ButtonControl(byte pin, byte channel, byte ccNumber, byte value,
                            byte longPressccNumber, byte longPressValue, unsigned long longPressDurationMs)
    : ButtonBase(pin),
      _channel(channel),
      _ccNumber(ccNumber),            
      _value(value),
      _longPressccNumber(longPressccNumber),
      _longPressValue(longPressValue),
      _longPressDurationMs(longPressDurationMs),
      _pressed(false),
      _longPressTriggered(false),
      _pressStartTime(0) {}

void ButtonControl::update() {
    bool reading = digitalRead(_pin);

    if (reading != _lastState && (millis() - _lastChange) > _debounce) {
        _lastChange = millis();
        _lastState = reading;

        if (reading == LOW) {
            onPress();
        } else {
            onRelease();
        }
    }

    if (_pressed && !_longPressTriggered && _longPressDurationMs > 0 &&
        (millis() - _pressStartTime) >= _longPressDurationMs) {
        _longPressTriggered = true;
        Debug::printNameValuePair("Control Button Long Pressed", _pin);
        sendLongControlMessage(_longPressValue);
    }
}

void ButtonControl::onPress() {
    Debug::printNameValuePair("Control Button Pressed", _pin);

    if (_longPressDurationMs > 0) {
        _pressed = true;
        _longPressTriggered = false;
        _pressStartTime = millis();
    } else {
        sendControlMessage(_value);
    }
}

void ButtonControl::onRelease() {
    Debug::printNameValuePair("Control Button Released", _pin);

    if (_longPressDurationMs > 0 && !_longPressTriggered) {
        sendControlMessage(_value);
    }

    _pressed = false;
}

void ButtonControl::sendControlMessage(byte value) {
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _ccNumber, value};
    sendMidiMsg(msg);
}

void ButtonControl::sendLongControlMessage(byte value) {
    midiEventPacket_t msg = {0x0B, uint8_t(0xB0 | _channel), _longPressccNumber, value};
    sendMidiMsg(msg);
}
