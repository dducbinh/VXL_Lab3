/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */

#include "input_reading.h"

//static uint16_t GPIO_STATE

static uint16_t buttonPins[BUTTON_NUMS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

static GPIO_PinState buttonState[BUTTON_NUMS];
static GPIO_PinState buttonDebounce0[BUTTON_NUMS];
static GPIO_PinState buttonDebounce1[BUTTON_NUMS];
static GPIO_PinState buttonDebounce2[BUTTON_NUMS];


static uint8_t 	buttonFlags[BUTTON_NUMS];
static uint16_t	buttonCounters[BUTTON_NUMS];

void buttonReading(void) {
	for (int i = 0; i < BUTTON_NUMS; i++) {
		buttonDebounce2[i] = buttonDebounce1[i];
		buttonDebounce1[i] = buttonDebounce0[i];
		buttonDebounce0[i] = HAL_GPIO_ReadPin(GPIOB, buttonPins[i]);
		if ((buttonDebounce0[i] == buttonDebounce1[i]) && (buttonDebounce1[i] == buttonDebounce2[i])) {
			if (buttonState[i] != buttonDebounce0[i]) {
				buttonState[i] = buttonDebounce0[i];
				if (buttonState[i] == PRESSED_STATE) {
					buttonFlags[i] = 1;
					buttonCounters[i] = BUTTON_PRESSED_DUR / TICK;
				}
			} else {
				if (buttonState[i] == PRESSED_STATE) {
					buttonCounters[i]--;
					if (buttonCounters[i] <= 0) {
						buttonFlags[i] = 1;
						buttonCounters[i] = BUTTON_HOLD_DUR / TICK;
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
