/*
 * Config.c
 *
 *  Created on: May 30, 2020
 *      Author: DELL
 */

#include "Statemachine.h"
#include "../include.h"



void Config_LED(void){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(PORTF,LED_RED | LED_BLUE);
	GPIOPinWrite(PORTF,LED_RED | LED_BLUE,0);
}
void Config_button(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOInput(PORTF,SENSOR);
	GPIOPadConfigSet(PORTF,SENSOR,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD_WPU);
}

