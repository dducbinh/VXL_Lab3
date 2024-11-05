/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "software_timer.h"

#define BUTTON_NUMS 		4
#define BUTTON_PRESSED_DUR 	1000
#define BUTTON_HOLD_DUR 	500
#define PRESSED_STATE		GPIO_PIN_RESET
#define RELEASED_STATE		GPIO_PIN_SET

void buttonReading(void);
int buttonPress(int idx);

#endif /* INC_INPUT_READING_H_ */
