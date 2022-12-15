/**
 **************************************************
 *
 * @file        attiny_firmware.ino
 * @brief       Attiny firmware for MOSFET with easyC
 *

 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;
bool mode; // Mode for the transistor -> 1 - transistor as switch, 0 - PWM

byte pwmValue, swState;
bool setValues = 0; // Flag to know when set value to the mosfet

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
    if (setValues)
    {
        if (mode == 1) // Transistor as switch
        {
            digitalWrite(PA4, swState);
            digitalWrite(PA5, swState);
        }
        else // PWM mode
        {
            analogWrite(PA4, pwmValue);
            digitalWrite(PA5, LOW);
        }

        setValues = 0;
    }  
      
    delay(10);
}


void receiveEvent(int howMany)
{
    setValues = 1;
    
    if (Wire.available() == 1) // For switch
    {
        mode = 1;        
        swState = Wire.read(); 
    }

    if (Wire.available() == 2) // For PWM
    {
        mode = 0;        
        pwmValue = Wire.read();
        pwmValue = Wire.read();                
    } 
}

void requestEvent()
{
}
