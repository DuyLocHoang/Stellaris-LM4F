/*
 * Control.c
 *
 *  Created on: May 30, 2020
 *      Author: DELL
 */

#include "Statemachine.h"
#include "../include.h"

//motionSensor_t  motionSenSor(void)
//{
//	if(GPIOPinRead(PORTF,SENSOR) == 0)
//		return MOTION;
//	else
//		return NOMOTION;
//}
int ReadButton(void){
	if(GPIOPinRead(PORTF,SENSOR) == 0)
	{
		return 1;
	}
	else
		return 0;
}
void CtlDoor(int DATA){
	GPIOPinWrite(PORTF, LED_RED,DATA);
}

void CtlLed(int DATA){
	GPIOPinWrite(PORTF,LED_BLUE,DATA);
}
