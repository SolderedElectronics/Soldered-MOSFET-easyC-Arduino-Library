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
 * @link        solde.red/333194       
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "MOSFET-easyC-SOLDERED.h"

MOSFETeasyC mosfet;

void setup()
{
    mosfet.begin();
}

void loop()
{
    for(int i = 0; i < 255; ++i)
    {
        mosfet.setPWM(i);
        delay(10);
    }

    for(int i = 255; i >= 0; --i)
    {
        mosfet.setPWM(i);
        delay(10);
    }
}
