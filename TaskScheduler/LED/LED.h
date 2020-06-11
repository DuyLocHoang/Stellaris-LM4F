/*
 * LED.H
 *
 *  Created on: Jun 3, 2020
 *      Author: DELL
 */

#ifndef LED_LED_H_
#define LED_LED_H_

enum ledNumber {LEDRED , LEDBLUE, LEDGREEN};
enum ledState  {OFF=0,ON=1};
void ledInit(void);
void ledControl(enum ledNumber led, enum ledState State);



#endif /* LED_LED_H_ */
