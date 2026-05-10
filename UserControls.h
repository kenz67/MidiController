
#include "MidiNotes.h"
#include "MidiButtonBase.h"
#include "NoteButton.h"
#include "ControlButton.h"
#include "LatchButton.h"
#include "SimLatchButton.h"

MidiButtonBase* buttons[] = {
    // new NoteButton(2, 0, midiNote[C][4]), 
    // new NoteButton(13, 0, midiNote[E][4]),
    //new ControlButton(2, 1, 30, 0),
    //new ControlButton(13, 1, 30, 127),
    new LatchButton(2, 1, 30),
    new SimLatchButton(13, 1, 27),
};