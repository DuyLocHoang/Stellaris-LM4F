/*
 * TASK1.c
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */


#include "Task1.h"
uint32_t    Counter = 0 ;



static RGB_t RGBState;

void RGBControl(enum ledState GREEN,enum ledState BLUE,enum ledState RED){
	ledControl(LEDGREEN,GREEN);
	ledControl(LEDBLUE,BLUE);
	ledControl(LEDRED,RED);
}
void initRGBState(void){
	RGBState=S_GREEN;
	RGBControl(OFF,OFF,OFF);
}
void Task1(void *myobject){
	switch (RGBState){
		case S_GREEN:
			Counter=15000;
			RGBState=S_GREEN_WAIT;
			break;
		case S_GREEN_WAIT:
			if(Counter==0) RGBState=S_BLUE;
			break;
		case S_BLUE:
			Counter=3000;
			RGBState=S_BLUE_WAIT;
			break;
		case S_BLUE_WAIT:
			if(Counter==0) RGBState=S_RED;
			break;
		case S_RED:
			Counter=15000;
			RGBState=S_RED_WAIT;
			break;
		case S_RED_WAIT:
			if(Counter==0) RGBState=S_GREEN;
			break;
	}
	switch(RGBState){
		case S_GREEN:
		case S_GREEN_WAIT:
			 RGBControl(ON,OFF,OFF);
			 break;
		case S_BLUE:
		case S_BLUE_WAIT:
			 RGBControl(OFF,ON,OFF);
			 break;
		case S_RED:
		case S_RED_WAIT:
			 RGBControl(OFF,OFF,ON);
			 break;

	}
}

