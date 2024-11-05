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

static uint16_t trafficRedPins[TRAFFIC_NUMBER] = {RED1_Pin_Pin, Red2_Pin};
static uint16_t trafficYellowPins[TRAFFIC_NUMBER] = {Yellow1_Pin, Yellow2_Pin};
static uint16_t trafficGreenPins[TRAFFIC_NUMBER] = {Green1_Pin, Green2_Pin};

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
	case TRAFFIC_OFF:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[index], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Off;
		break;
	case TRAFFIC_RED:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, trafficYelllowPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[index], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Red;
		break;
	case TRAFFIC_AMBER:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[index], GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[index], GPIO_PIN_RESET);
		trafficState[idx] = Traffic_Yellow;
		break;
	case TRAFFIC_GREEN:
		HAL_GPIO_WritePin(GPIOA, trafficRedPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficYellowPins[index], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, trafficGreenPins[index], GPIO_PIN_SET);
		trafficState[idx] = Traffic_Green;
		break;
	default:
		break;
	}
}
