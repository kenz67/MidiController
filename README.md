# Project Description
This project is a standard library for Midi Controllers.  It is being developed as a learning project and will have different control types added over time.

It is being developed on an Arduino Leonardo.   Compatability with other boards is unkown.

# Control Types
## Buttons

Buttons are added by creating a list of buttons in code.  Note that channels in code starts at 0, but in Midi starts at 1.  See below for details on each button type.

    MidiButtonBase* buttons[] = {
        new NoteButton(2, 0, midiNote[C][4]),      
        new ControlButton(4, 1, 30, 0),            
        new SimLatchButton(5, 1, 27),               
    }

#### Control Button
A control button sends the same control message on each press of the button.

    ControlButton(byte pin, byte channel, byte ccNumber, byte value);
    
For example:

    new ControlButton(4, 1, 30, 0),            

Will send a message for Controller 30 with a value of 0 on Channel 1 each time the button connected to pin number 4 is pressed.

#### Note Button
A Note button will send a Note Message each time the button is pressed.

    NoteButton(byte pin, byte channel, byte note, byte velocity = 127);

For example

    new NoteButton(2, 0, midiNote[C][4]), 
    new NoteButton(13, 0, midiNote[Eb][5]),

\* The first Will send a middle C notes on channel 1 each time pin number 4 is pressed.

\* The second will send an Eb notes, one octave up from middle C, on channel 1, each time pin number 13 is pressed.

Note that only flats are available, not sharps.  This list of notes is:  **C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B**


#### SimLatchButton
This button type will simulate a latching button with a non-latching button.  The first time pressed it will send 127, the second it will send 0, then 127 again, etc.

    SimLatchButton(byte pin, byte channel, byte ccNumber);

For example

    new SimLatchButton(2, 1, 30),

This will send a Control 30 message on channel 1 each time pin number 2 is pressed.   It will alternate between 127 and 0 on each press.