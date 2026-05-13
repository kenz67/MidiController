#include <Arduino.h>
#include "PotentiometerBase.h"

PotentiometerBase::PotentiometerBase(byte pin, byte debounce)
  : MidiBase(pin, debounce) {}

void PotentiometerBase::begin() {
  _lastValue = -1; // Force an update on the first read
}

void PotentiometerBase::update() {
    
  //Debouncing as pots can be noisy, but we don't want to debounce too much or we'll miss changes
  int potValue =
      (analogRead(_pin) +
       analogRead(_pin) +
       analogRead(_pin) +
       analogRead(_pin)) / 4;

    if (abs(potValue - _lastValue) > 2) {      
      _lastValue = potValue;
      onTurn();
    }
}

void PotentiometerBase::beginAll(PotentiometerBase* pots[], int count) {
    for (int i = 0; i < count; i++) {
        pots[i]->begin();
    }
}

void PotentiometerBase::updateAll(PotentiometerBase* pots[], int count) {
    for (int i = 0; i < count; i++) {
        pots[i]->update();
    }
}