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

int addr = DEFAULT_ADDRESS; // 0x30
bool mode;                  // Mode for the transistor -> 1 - transistor as switch, 0 - PWM

byte pwmValue, swState;      // Variables for PWM value to set and the switch state
volatile bool setValues = 0; // Flag to know when set value to the mosfet

#define MOSFET_PIN PA4 // The pin of the MOSFET
#define LED_PIN    PA5 // The pin of the LED

void setup()
{
    // Set the select address switches as inputs and get the I2C address
    initDefault();
    addr = getI2CAddress();

    // Init I2C communication
    Wire.begin(addr);
    Wire.onReceive(receiveEvent);

    pinMode(MOSFET_PIN, OUTPUT); // MOSFET is connected to this pin
    pinMode(LED_PIN, OUTPUT);    // Status LED is connected to this pin
}

void loop()
{
    // If there is a value to set, set it
    if (setValues)
    {
        if (mode == 1) // Transistor as switch
        {
            digitalWrite(MOSFET_PIN, swState);
            digitalWrite(LED_PIN, swState);
        }
        else // PWM mode
        {
            analogWrite(MOSFET_PIN, pwmValue);
            analogWrite(LED_PIN, pwmValue);
        }

        // Reset the flag
        setValues = 0;
    }
}


void receiveEvent(int howMany)
{
    // Set the flag to 1 for writing the state on MOSFET
    setValues = 1;

    if (Wire.available() == 1) // For switch
    {
        // Mode for the transistor -> 1 - transistor as switch, 0 - PWM
        mode = 1;

        // Read wanted switch state
        swState = Wire.read();
    }

    if (Wire.available() == 2) // For PWM
    {
        mode = 0;

        // Same values. 2 bytes just for indicating the PWM mode
        pwmValue = Wire.read();
        pwmValue = Wire.read();
    }
}
