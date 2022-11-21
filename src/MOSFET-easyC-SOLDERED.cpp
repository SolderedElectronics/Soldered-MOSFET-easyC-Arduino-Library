/**
 **************************************************
 *
 * @file        MOSFET-easyC-SOLDERED.cpp
 * @brief       Functions to controll MOSFET with easyC
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/


#include "MOSFET-easyC-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
MOSFETeasyC::MOSFETeasyC(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                  Constructor for MOSFET with easyC 
*/
MOSFETeasyC::MOSFETeasyC()
{
    native = 0;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void MOSFETeasyC::initializeNative()
{
    pinMode(pin, OUTPUT);
}

/**
 * @brief                   Function for turning on and off the MOSFET
 * 
 * @param state             State of switch you want to set to the MOSFET
 * 
 * @return                  None
*/
void MOSFETeasyC::setSwitch(bool state)
{
    byte stateToSend = (byte)state;
    sendData(&stateToSend, 1);
}

/**
 * @brief                   Function for setting PWM value to the MOSFET
 * 
 * @param pwmValue          PWM value you want to set to the mosfet
 * 
 * @return                  None
*/
void MOSFETeasyC::setPWM(byte pwmValue)
{
    // Send two times just because the breakout expects 2 bytes for set PWM to MOSFET
    byte pwm[2];
    pwm[0] = pwm[1] = pwmValue;
    sendData(pwm, 2);
}

