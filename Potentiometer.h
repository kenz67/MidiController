#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>
#include "PotentiometerBase.h"

class Potentiometer : public PotentiometerBase {
public:
    // Constructor declaration (definition is inline in the .cpp or .h)
    Potentiometer(byte pin, byte channel, byte ccNumber, byte value);

protected:
    void onTurn() override;

private:
    byte _channel;
    byte _ccNumber;
    byte _value;
};

#endif
