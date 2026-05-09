#include <Arduino.h>
#include "MidiButtonBase.h"

MidiButtonBase::MidiButtonBase(byte pin, byte debounce)
  : MidiControlBase(pin, debounce) {}

void MidiButtonBase::begin() {
  pinMode(_pin, INPUT_PULLUP);
  _lastState = digitalRead(_pin);
  _lastChange = millis();
}

void MidiButtonBase::update() {
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
}

void MidiButtonBase::beginAll(MidiButtonBase* buttons[], int count) {
    for (int i = 0; i < count; i++) {
        buttons[i]->begin();
    }
}

void MidiButtonBase::updateAll(MidiButtonBase* buttons[], int count) {
    for (int i = 0; i < count; i++) {
        buttons[i]->update();
    }
}