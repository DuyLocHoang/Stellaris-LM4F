/*
 * TASK3.c
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */
#include "../include.h"
#include "TASK3.h"
extern uint32_t Counter;


void Task3(void *myobject)
{
	if(switchState(2) == PRESSED)
	{
		Counter += 5000;
	}

}




