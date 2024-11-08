/*
 * fsm_auto.c
 *
 *  Created on: Nov 6, 2024
 *      Author: doand
 */


#include "fsm_auto.h"

enum FSM_STATE fsmState = FSM_NORMAL;

void fsmInitState(void) {
	trafficInitState();
	fsmReState(FSM_NORMAL);
	HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, RESET);
}

void fsmReState(enum FSM_STATE state) {
	switch (state) {
	case FSM_NORMAL:
		setTimer(1, TRAFFIC_SEC_DUR);			// CountDown
		firstSEG = trafficRedDuration;
		secondSEG = trafficGreenDuration;
		mode = 1;
		trafficReState(0, Traffic_Red);
		trafficReState(1, Traffic_Green);
		fsmState = FSM_NORMAL;
		break;
	case FSM_MODE_RED:
		setTimer(1, TRAFFIC_BLINK_DUR);
		firstSEG = trafficRedDuration;
		secondSEG = trafficRedDuration;
		mode = 2;
		trafficReState(0, Traffic_Off);
		trafficReState(1, Traffic_Off);
		fsmState = FSM_MODE_RED;
		break;
	case FSM_MODE_YELLOW:
		setTimer(1, TRAFFIC_BLINK_DUR);
		firstSEG = trafficYellowDuration;
		secondSEG = trafficYellowDuration;
		mode = 3;
		trafficReState(0, Traffic_Off);
		trafficReState(1, Traffic_Off);
		fsmState = FSM_MODE_YELLOW;
		break;
	case FSM_MODE_GREEN:
		setTimer(1, TRAFFIC_BLINK_DUR);
		firstSEG = trafficGreenDuration;
		secondSEG = trafficGreenDuration;
		mode = 4;
		trafficReState(0, Traffic_Off);
		trafficReState(1, Traffic_Off);
		fsmState = FSM_MODE_GREEN;
		break;
	default:
		break;
	}
}

void fsmProcess(void) {
	switch (fsmState) {
	case FSM_NORMAL:
		if (getTimerFlag(1) == 1) {
			setTimer(1, TRAFFIC_SEC_DUR);

			switch (trafficState[0]) {
			case Traffic_Red:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficGreenDuration;
					trafficReState(0, Traffic_Green);
				}

				break;
			case Traffic_Yellow:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficRedDuration;
					trafficReState(0, Traffic_Red);
				}

				break;
			case Traffic_Green:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficYellowDuration;
					trafficReState(0, Traffic_Yellow);
				}

				break;
			default:
				break;
			}

			switch (trafficState[1]) {
			case Traffic_Red:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficGreenDuration;
					trafficReState(1, Traffic_Green);
				}

				break;
			case Traffic_Yellow:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficRedDuration;
					trafficReState(1, Traffic_Red);
				}

				break;
			case Traffic_Green:
				firstSEG--;
				if (firstSEG == 0) {
					firstSEG = trafficYellowDuration;
					trafficReState(1, Traffic_Yellow);
				}

				break;
			default:
				break;
			}
		}

		if (buttonPress(0)) {
			fsmReState(FSM_MODE_RED);
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
		}
		break;
	case FSM_MODE_RED:
		if (getTimerFlag(1) == 1) {
			switch (trafficState[0]) {
			case Traffic_Off:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Red);
				trafficReState(1, Traffic_Red);
				break;
			case Traffic_Red:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Off);
				trafficReState(1, Traffic_Off);
				break;
			default:
				break;
			}
		}
		if (buttonPress(0)) {
			fsmReState(FSM_MODE_YELLOW);
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
		}

		if (buttonPress(1)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG++;
			if (firstSEG > 99) firstSEG = 1;
			secondSEG++;
			if (secondSEG > 99) secondSEG = 1;
		}

		if (buttonPress(2)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG--;
			if (firstSEG < 1) firstSEG = 99;
			secondSEG--;
			if (secondSEG < 1) secondSEG = 99;
		}

		if (buttonPress(3)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			trafficRedDuration = firstSEG;
		}
		break;
	case FSM_MODE_YELLOW:
		if (getTimerFlag(1) == 1) {
			switch (trafficState[0]) {
			case Traffic_Off:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Yellow);
				trafficReState(1, Traffic_Yellow);
				break;
			case Traffic_Yellow:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Off);
				trafficReState(1, Traffic_Off);
				break;
			default:
				break;
			}
		}
		if (buttonPress(0)) {
			fsmReState(FSM_MODE_GREEN);
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
		}

		if (buttonPress(1)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG++;
			if (firstSEG > 99) firstSEG = 1;
			secondSEG++;
			if (secondSEG > 99) secondSEG = 1;
		}

		if (buttonPress(2)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG--;
			if (firstSEG < 1) firstSEG = 99;
			secondSEG--;
			if (secondSEG < 1) secondSEG = 99;
		}

		if (buttonPress(3)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			trafficYellowDuration = firstSEG;
		}
		break;
	case FSM_MODE_GREEN:
		if (getTimerFlag(1) == 1) {
			switch (trafficState[0]) {
			case Traffic_Off:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Green);
				trafficReState(1, Traffic_Green);
				break;
			case Traffic_Green:
				setTimer(1, TRAFFIC_BLINK_DUR);
				trafficReState(0, Traffic_Off);
				trafficReState(1, Traffic_Off);
				break;
			default:
				break;
			}
		}
		if (buttonPress(0)) {
			fsmReState(FSM_NORMAL);
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
		}

		if (buttonPress(1)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG++;
			if (firstSEG > 99) firstSEG = 1;
			secondSEG++;
			if (secondSEG > 99) secondSEG = 1;
		}

		if (buttonPress(2)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			firstSEG--;
			if (firstSEG < 1) firstSEG = 99;
			secondSEG--;
			if (secondSEG < 1) secondSEG = 99;
		}

		if (buttonPress(3)) {
			HAL_GPIO_WritePin(SIGNAL_LED_GPIO_Port, SIGNAL_LED_Pin, SET);
			trafficGreenDuration = firstSEG;
		}
		break;
	}
}
