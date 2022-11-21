/**
 **************************************************
 *
 * @file        attiny_firmware.ino
 * @brief       Fill in sensor specific code.
 *

 *
 * @authors     @ soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;
bool mode; // Mode for the transistor -> 1 - transistor as switch, 0 - PWM

byte pwmValue, swState;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    pinMode(PA4, OUTPUT); // MOSFET is connected to this pin
    pinMode(PA5, OUTPUT); // Status LED is connected to this pin
}

void loop()
{
    if (mode == 1) // Transistor as switch
    {
        digitalWrite(PA4, swState);
        digitalWrite(PA5, swState);
    }
    else // PWM mode
    {
        analogWrite(PA4, pwmValue);
    }
}


void receiveEvent(int howMany)
{
    if (Wire.available() == 1) // For switch
    {
        mode = 1;
        swState = Wire.read();
    }

    if (Wire.available() == 2) // Fot PWM
    {
        mode = 0;
        pwmValue = Wire.read();
        pwmValue = Wire.read();
    }
}

void requestEvent()
{
    int n = 5;

    char a[n];
    Wire.write(a, n);
}
