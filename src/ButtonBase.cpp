#include <Arduino.h>
#include "ButtonBase.h"

ButtonBase::ButtonBase(byte pin, byte debounce)
  : MidiBase(pin, debounce) {}

void ButtonBase::begin() {
  pinMode(_pin, INPUT_PULLUP);
  _lastState = digitalRead(_pin);
  _lastChange = millis();
}

void ButtonBase::update() {
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

void ButtonBase::beginAll(ButtonBase* buttons[], int count) {
    for (int i = 0; i < count; i++) {
        buttons[i]->begin();
    }
}

void ButtonBase::updateAll(ButtonBase* buttons[], int count) {
    for (int i = 0; i < count; i++) {
        buttons[i]->update();
    }
}

void ButtonBase::initAll(ButtonBase* buttons[], int count) {
    for (int i = 0; i < count; i++) {
        buttons[i]->init();
    }
}