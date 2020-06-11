/*
 * Statemachine.c
 *
 *  Created on: May 30, 2020
 *      Author: DELL
 */
#include "Statemachine.h"
#include "../include.h"
static uint8_t tg;
static uint8_t trangthai_chuyendong = 0;
static uint32_t timer_chuyendong;
static uint8_t trangthai_cua;
static uint32_t timer_door;
static uint32_t timer_led;
static uint8_t trangthai_led;
void SystickIntHandler(void);
void kiemtrachuyendong(void);
void DOOR(void);
void LED(void);

void kiemtrachuyendong(void)
{
	switch(trangthai_chuyendong)
	{
		case khongchuyendong :
			if(ReadButton() == 1)
			{
				trangthai_chuyendong = khongchuyendong_wait;
				timer_chuyendong = 50;
			}
			break;
		case khongchuyendong_wait :
			if(ReadButton() == 0)
			{
				trangthai_chuyendong = khongchuyendong;
			}
			else if (timer_chuyendong == 0)
			{
				trangthai_chuyendong = chuyendong;
				tg = 1;
			}
			break;
		case chuyendong :
			if(ReadButton() == 0)
			{
				trangthai_chuyendong = chuyendong_wait;
				timer_chuyendong = 50;
			}
			break;
		case chuyendong_wait :
			if(ReadButton() == 1)
			{
				trangthai_chuyendong = chuyendong;
			}
			else if (timer_chuyendong == 0)
			{
				trangthai_chuyendong = khongchuyendong;
				tg = 0;
			}
			break;
	}
}
void DOOR(void)
{
	switch(trangthai_cua)
	{
		case 0 :
			if(tg == 1)
			{
				trangthai_cua = 1;
				CtlDoor(2);
			}
			break;
		case 1 :
			if(tg == 0)
			{
				trangthai_cua = 2;
				timer_door = 10000;
			}
			break;
		case 2 :
			if(tg == 1)
			{
				trangthai_cua = 1;
			}
			else if (timer_door == 0)
			{
				trangthai_cua = 0;
				CtlDoor(0);
			}
			break;
	}
}
void LED(void)
{
	switch(trangthai_led)
	{
		case 0 :
			if((tg == 1) && (timer_led == 0))
			{
				trangthai_led = 1;
				CtlLed(4);
				timer_led = 500;
			}
			break;
		case 1 :
			if(timer_led == 0)
			{
				trangthai_led = 0;
				CtlLed(0);
				timer_led = 500;
			}
			break;

	}
}
void SystickIntHandler(void)
{
	if (timer_chuyendong != 0)
		timer_chuyendong--;
	if (timer_door != 0)
		timer_door--;
	if(timer_led != 0)
		timer_led--;
}

