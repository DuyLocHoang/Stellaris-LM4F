/*
 * SWITCH.h
 *
 *  Created on: Jun 2, 2020
 *      Author: DELL
 */

#ifndef SWITCH_SWITCH_H_
#define SWITCH_SWITCH_H_



#include "driverlib/rom.h"
#include "driverlib/sysctl.h"

#define SW_GPIO_PERIPH     SYSCTL_PERIPH_GPIOF
#define SW_GPIO_BASE       GPIO_PORTF_BASE
#define SW1            GPIO_PIN_4
#define SW2            GPIO_PIN_0
typedef     enum {PRESSED,RELEASED}  sw_t;
void        switchInit(void);

sw_t        switchState(int SWnumber);



#endif /* SWITCH_SWITCH_H_ */
