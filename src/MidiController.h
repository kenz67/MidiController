#ifndef MIDI_CONTROLLER_H
#define MIDI_CONTROLLER_H

/*
 * MidiController Library
 * 
 * A comprehensive library for creating MIDI controllers on Arduino.
 * Supports various button types and potentiometers to send MIDI messages over USB.
 * 
 * Developed for Arduino Leonardo with potential compatibility for other boards.
 */

// MIDI Notes and note definitions
#include "MidiNotes.h"

// Base classes
#include "MidiBase.h"
#include "ButtonBase.h"
#include "PotentiometerBase.h"

// Button implementations
#include "ButtonNote.h"
#include "ButtonControl.h"
#include "ButtonLatch.h"
#include "ButtonLatchSim.h"

// Potentiometer implementations
#include "Potentiometer.h"

// Debug utilities
#include "Debug.h"

/**
 * Main MidiController class
 * Provides static methods for initializing and updating MIDI controllers
 */
class MidiController {
public:
    /**
     * Initialize all buttons and potentiometers
     * @param buttons Array of ButtonBase pointers
     * @param numButtons Number of buttons in the array
     * @param pots Array of PotentiometerBase pointers
     * @param numPots Number of potentiometers in the array
     */
    static void setup(ButtonBase* buttons[], int numButtons, PotentiometerBase* pots[], int numPots);
    
    /**
     * Update all buttons and potentiometers
     * Call this in your loop() function regularly
     * @param buttons Array of ButtonBase pointers
     * @param numButtons Number of buttons in the array
     * @param pots Array of PotentiometerBase pointers
     * @param numPots Number of potentiometers in the array
     */
    static void update(ButtonBase* buttons[], int numButtons, PotentiometerBase* pots[], int numPots);
};

#endif // MIDI_CONTROLLER_H
