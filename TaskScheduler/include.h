/*
 * include.h
 *
 *  Created on: May 29, 2020
 *      Author: DELL
 */

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include "stdbool.h"
#include "stdint.h"
#include "string.h"
#include "math.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/adc.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"
#include "driverlib/fpu.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "utils/scheduler.h"


#include "SCHEDULER/scheduler.h"
#include "SWITCH/SWITCH.h"
#include "TASK1/TASK1.h"
#include "TASK2/TASK2.h"
#include "TASK3/TASK3.h"
#include"LED/LED.h"
#define PORTF GPIO_PORTF_BASE
#define SW1 GPIO_PIN_4
#define SW2 GPIO_PIN_0


#endif /* INCLUDE_H_ */
