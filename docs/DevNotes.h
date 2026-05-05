/*


https://henrybalme.substack.com/p/all-8-midi-messages-explained?r=3qbno3&utm_campaign=post&utm_medium=web&triedRedirect=true


Note On (0x9n): Initiates a note, including key number and velocity.
Note Off (0x8n): Ends a note, including key number and velocity.
Channel Pressure (Aftertouch) (0xDn): Represents the pressure applied to a key after it is pressed, affecting the entire channel.
Polyphonic Key Pressure (Polyphonic Aftertouch) (0xAn): Represents pressure applied to individual keys. 
Pitch Bend Change (0xEn): Controls pitch shifting using a high-resolution 14-bit value.
Program Change (0xCn): Switches presets, patches, or instrument sounds.
Control Change (CC) (0xBn): Adjusts parameters like volume, modulation, or panning (e.g., CC 7 for Volume, CC 1 for Modulation).
System Messages


A subset of CC messages (often CC 120-127) that control how a device handles channels, such as: 
All Notes Off (123): Stops all sound.
Omni On/Off (124/125): Determines if the device listens to all channels or just one.
Mono/Poly On (126/127): Sets how many notes can be played at once. 

*/