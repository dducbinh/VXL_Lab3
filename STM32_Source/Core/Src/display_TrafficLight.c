/*
 * display_TrafficLight.c
 *
 *  Created on: Nov 6, 2024
 *      Author: doand
 */

#include "display_TrafficLight.h"

int trafficRedDuration = 0;
int trafficYellowDuration = 0;
int trafficGreenDuration = 0;
enum Traffic_State trafficState[TRAFFIC_NUMS] = {0, 0};

static uint16_t trafficRedPins[TRAFFIC_NUMS] = {RED1_Pin, RED1_Pin};
static uint16_t trafficYellowPins[TRAFFIC_NUMS] = {YELLOW1_Pin, YELLOW2_Pin};
static uint16_t trafficGreenPins[TRAFFIC_NUMS] = {GREEN1_Pin, GREEN2_Pin};

void trafficInitState(void) {
	trafficRedDuration = 5;
	trafficGreenDuration = 3;
	trafficYellowDuration = 2;
	trafficReState(0, Traffic_Off);
	trafficReState(1, Traffic_Off);
}

void trafficReState(int idx, enum Traffic_State state) {
	if (idx < 0 || idx >= TRAFFIC_NUMS) return;

	switch (state) {
	case Traffic_Off:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[idx], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Off;
		break;
	case Traffic_Red:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[idx], GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[idx], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Red;
		break;
	case Traffic_Yellow:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[idx], GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[idx], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Yellow;
		break;
	case Traffic_Green:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[idx], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[idx], GPIO_PIN_SET);
		trafficState[idx] = Traffic_Green;
		break;
	default:
		break;
	}
}
