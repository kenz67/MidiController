#include "MidiNotes.h"

#include "ButtonControl.h"
#include "ButtonBase.h"
#include "ButtonLatch.h"
#include "ButtonLatchSim.h"
#include "ButtonNote.h"

#include "Potentiometer.h"

ButtonBase* buttons[] = {
    // Add buttons here

    // new NoteButton(2, 0, midiNote[C][4]), 
    // new ButtonNote(13, 0, midiNote[E][4]),
    //new ButtonControl(2, 1, 30, 0),
    new ButtonControl(13, 1, 30, 127),
    new ButtonLatch(2, 1, 30),
    //new ButtonLatchSim(13, 1, 27),
};

PotentiometerBase* pots[] = {
    // Add potentiometers here
    new Potentiometer(A0, 1, 1, 0)
};