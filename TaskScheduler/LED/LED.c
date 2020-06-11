/*
 * LED.c
 *
 *  Created on: Jun 3, 2020
 *      Author: DELL
 */
#include "LED.h"
#include "../include.h"

const uint32_t      ledSetVal[3] = {1<<1,1<<2,1<<3};
const   uint32_t    ledPin[3]   =   {GPIO_INT_PIN_1,GPIO_INT_PIN_2,GPIO_INT_PIN_3};
void ledInit(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

}
void    ledControl(enum ledNumber led, enum ledState State)
{
    if (State)  GPIOPinWrite(GPIO_PORTF_BASE,ledPin[led], ledPin[led]);
    else GPIOPinWrite(GPIO_PORTF_BASE,ledPin[led], 0);
}




