/*
 * Statemachine.h
 *
 *  Created on: May 30, 2020
 *      Author: DELL
 */

#ifndef STATEMACHINE_STATEMACHINE_H_
#define STATEMACHINE_STATEMACHINE_H_

//typedef emun{
//	MOTION,NOMOTION
//}motionSensor_t;
//typedef enum

#define PORTF GPIO_PORTF_BASE
#define SENSOR GPIO_PIN_4
#define LED_RED GPIO_PIN_1
#define LED_BLUE GPIO_PIN_2
#define khongchuyendong 0
#define chuyendong 1
#define khongchuyendong_wait 2
#define chuyendong_wait 3


void Config_button();
void Config_LED();
int ReadButton();
void CtlDoor();
void CtlLed();
void kiemtrachuyendong();
void DOOR();
void LED();
int ReadButton();
#endif /* STATEMACHINE_STATEMACHINE_H_ */
