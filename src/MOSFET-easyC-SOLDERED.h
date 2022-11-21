/**
 **************************************************
 *
 * @file        MOSFET-easyC-SOLDERED.h
 * @brief       Header file for the MOSFET breakout with easyC.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#ifndef __MOSFET_EASYC__
#define __MOSFET_EASYC__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

class MOSFETeasyC : public EasyC
{
  public:
    MOSFETeasyC(int _pin);
    MOSFETeasyC(void);
    void setSwitch(bool state);
    void setPWM(byte pwmValue);

  protected:
    void initializeNative();

  private:
    int pin;
};

#endif
