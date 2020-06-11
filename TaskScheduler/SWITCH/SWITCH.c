#include "../include.h"
#include "SWITCH.h"
void        switchInit(void)
{
    //
    // Enable the GPIO port to which the sensors are connected.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Unlock PF0 so we can change it to a GPIO input
    // Once we have enabled (unlocked) the commit register then re-lock it
    // to prevent further changes.  PF0 is muxed with NMI thus a special case.
    //
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    //
    // Set each of the button GPIO pins as an input with a pull-up.
    //
    GPIODirModeSet(SW_GPIO_BASE, SW1 | SW2, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(SW_GPIO_BASE, SW1 | SW2,
                         GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);

}
sw_t switchState(int SWnumber)
{
    switch    (SWnumber)
        {
            case 1:
                if (GPIOPinRead(PORTF, SW1) == 0)
                {
                	SysCtlDelay(1000);
                	while(GPIOPinRead(PORTF,SW1) ==0);
                	return PRESSED;
                }

                else return RELEASED;
                break;

            case 2:
                if (GPIOPinRead(PORTF, SW2) == 0)
                {
                	SysCtlDelay(1000);
                	while(GPIOPinRead(PORTF,SW2) ==0);
                	return PRESSED;
                }
                else return RELEASED;
                break;

        }
}


/*
 * SWITCH.c
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */




