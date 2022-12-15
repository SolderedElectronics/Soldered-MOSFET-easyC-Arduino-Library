/**
 **************************************************
 *
 * @file        mosfetEasyCPWM.ino
 * @brief       Example for MOSFET board with easyC.
 *              Connect LED or something simmilar to the mosfet to see effect.
 *
 *
 * NOTE: MOSFET works as a switch, you have to connect LED to the +VCC and the MOSFET between the other side of the LED
 *       and the ground! Also, add a 330 Ohm resistor for the LED in series.
 *
 *       Wiring diagram:
 *       VCC------[330 Ohm]------[+LED-]------[MOSFET]------GND
 * 
 *       When the MOSFET works in PWM mode, the LED which represents the state on the breakout is turned off.
 *
 * @link        solde.red/333194
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "MOSFET-easyC-SOLDERED.h"

MOSFETeasyC mosfet;

void setup()
{
    mosfet.begin(); // Begin I2C comunication
}

void loop()
{
    // Set PWM from 0 to 255 - increasing the brightness of the LED
    for (int i = 0; i < 255; ++i)
    {
        mosfet.setPWM(i); // Set each value to the MOSFET
        delay(10);        // Delay a little to slow changes
    }

    // Set PMW from 255 to 0 - decreasing the brightness of the LED
    for (int i = 255; i >= 0; --i)
    {
        mosfet.setPWM(i); // Set each value to the MOSFET
        delay(10);        // Delay a little to slow changes
    }
}
