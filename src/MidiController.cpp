#include "MidiController.h"

void MidiController::setup(ButtonBase* buttons[], int numButtons, PotentiometerBase* pots[], int numPots) {
    // Initialize all buttons
    if (buttons != nullptr && numButtons > 0) {
        ButtonBase::beginAll(buttons, numButtons);
        ButtonBase::initAll(buttons, numButtons);
    }
    
    // Initialize all potentiometers
    if (pots != nullptr && numPots > 0) {
        PotentiometerBase::beginAll(pots, numPots);
    }
}

void MidiController::update(ButtonBase* buttons[], int numButtons, PotentiometerBase* pots[], int numPots) {
    // Update all buttons
    if (buttons != nullptr && numButtons > 0) {
        ButtonBase::updateAll(buttons, numButtons);
    }
    
    // Update all potentiometers
    if (pots != nullptr && numPots > 0) {
        PotentiometerBase::updateAll(pots, numPots);
    }
}
