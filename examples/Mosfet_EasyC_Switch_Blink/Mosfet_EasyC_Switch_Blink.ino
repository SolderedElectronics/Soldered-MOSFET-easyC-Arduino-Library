/**
 **************************************************
 *
 * @file        Mosfet_EasyC_Switch_Blink.ino
 * @brief       Example for MOSFET board with easyC.
 *              This example will show you how to control MOSFET which works as a switch.
 *              For this example you will need any Dasduino board, a USB-C cable, an easyC cable, a 330 Ohm resistor, and
 *              MosfetWithEasyC breakout.
 *
 *              Don't have Dasduino? Get it here:https://soldered.com/categories/dasduino-arduino/dasduino-boards/
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              Connect LED or something similar to the MOSFET and you will see turning on and off every 1 second.
 *
 * NOTE: MOSFET works as a switch, you have to connect LED to the +VCC and the MOSFET between the other side of the LED
 *       and the ground! Also, add a 330 Ohm resistor for the LED in series.
 *
 *       Wiring diagram:
 *       VCC------[330 Ohm]------[+LED-]------[+MOSFET_WITH_EASYC-]------GND
 *
 * @link        solde.red/333194
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library for MOSFET with easyC
#include "MOSFET-easyC-SOLDERED.h"

// Create an object for the MOSFET
MOSFETeasyC mosfet;

void setup()
{
    // Begin I2C communication at the default address (0x30)
    // You can change this address by changing the address switch on the breakout
    // Possible address are from 0x30 (default) to 0x37
    // If you change the I2C address, you have to specify the new one in the bracket
    mosfet.begin();
    // mosfet.begin(0x31);
}

void loop()
{
    // Turn the MOSFET on - the LED will light up
    mosfet.setSwitch(MOSFET_SW_CLOSED);

    // Wait 1 second
    delay(1000);

    // Turn the MOSFET off - the LED will turn off
    mosfet.setSwitch(MOSFET_SW_OPEN);

    // Wait 1 second
    delay(1000);
}
