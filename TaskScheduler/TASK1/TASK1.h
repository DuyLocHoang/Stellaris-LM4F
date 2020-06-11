/*
 * TASK1.h
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */

#ifndef TASK1_TASK1_H_
#define TASK1_TASK1_H_



#include "../include.h"
typedef enum
{
	S_GREEN,
	S_GREEN_WAIT,
	S_BLUE,
	S_BLUE_WAIT,
	S_RED,
	S_RED_WAIT
} RGB_t;
void RGBControl(enum ledState GREEN,enum ledState BLUE,enum ledState RED);
void Task1(void *myobject);
void initRGBState(void);
extern uint32_t Counter;


#endif /* TASK1_TASK1_H_ */
