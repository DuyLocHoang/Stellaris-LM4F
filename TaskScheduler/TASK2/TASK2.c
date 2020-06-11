/*
 * TASK2.c
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */
#include "../include.h"
#include "TASK2.h"
extern uint32_t Counter;


void Task2(void *myobject)
{
	if(switchState(1) == PRESSED)
	{
		Counter = 0;
	}

}


