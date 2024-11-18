/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */

#include "input_reading.h"

//static uint16_t GPIO_STATE

static uint16_t buttonPins[BUTTON_NUMS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin, BUTTON4_Pin};

static GPIO_PinState buttonState[BUTTON_NUMS];
static GPIO_PinState buttonDebounce0[BUTTON_NUMS];
static GPIO_PinState buttonDebounce1[BUTTON_NUMS];
static GPIO_PinState buttonDebounce2[BUTTON_NUMS];


static uint8_t 	buttonFlags[BUTTON_NUMS];
static uint16_t	buttonCounters[BUTTON_NUMS];

void buttonReading(void) {
	for (int index = 0; index < BUTTON_NUMS; index++) {
		buttonDebounce2[index] = buttonDebounce1[index];
		buttonDebounce1[index] = buttonDebounce0[index];
		buttonDebounce0[index] = HAL_GPIO_ReadPin(GPIOB, buttonPins[index]);

		if ((buttonDebounce0[index] == buttonDebounce1[index]) && (buttonDebounce1[index] == buttonDebounce2[index])) {

			if (buttonState[index] != buttonDebounce0[index]) {
				buttonState[index] = buttonDebounce0[index];

				if (buttonState[index] == PRESSED_STATE) {
					buttonFlags[index] = 1;
					buttonCounters[index] = BUTTON_PRESSED_DUR / TICK;
				}

			} else {

				if (buttonState[index] == PRESSED_STATE) {
					buttonCounters[index]--;

					if (buttonCounters[index] <= 0) {
						buttonFlags[index] = 1;
						buttonCounters[index] = BUTTON_HOLD_DUR / TICK;
					}
				}
			}
		}
	}
}

int buttonPress(int idx) {
	if (idx < 0 || idx >= BUTTON_NUMS) return 0;

	if (buttonFlags[idx] == 1) {
		buttonFlags[idx] = 0;
		return 1;
	}
	return 0;
}
