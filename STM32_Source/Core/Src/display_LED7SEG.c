/*
 * display_LED7SEG.c
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */


#include "display_LED7SEG.h"

int firstSEG;
int secondSEG;
int mode;

static void display7SEG(int number) {
	switch (number) {
	case 0:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b10000000; // GFEDCBA except bit 0
		break;
	case 1:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b11110011; // GFEDCBA
		break;
	case 2:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b01001001; // GFEDCBA
		break;
	case 3:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b01100001; // GFEDCBA
		break;
	case 4:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00110011; // GFEDCBA
		break;
	case 5:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00100101; // GFEDCBA
		break;
	case 6:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00000101; // GFEDCBA
		break;
	case 7:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b11110001; // GFEDCBA
		break;
	case 8:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00000001; // GFEDCBA
		break;
	case 9:
		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00100001; // GFEDCBA
		break;
	default:
		break;
	}
}

void led7SEGInitState(void) {
	firstSEG = 0;
	secondSEG = 0;
	mode = 1;

	HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
}

void led7SEGScan(void) {
	static int scan_idx = 0;

	HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);

	switch (scan_idx) {
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		display7SEG(firstSEG / 10);
		scan_idx = 1;
		break;
	case 1:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG(firstSEG % 10);
		scan_idx = 2;
		break;
	case 2:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		display7SEG(secondSEG / 10);
		scan_idx = 3;
		break;
	case 3:
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG(secondSEG % 10);
		scan_idx = 4;
		break;
	case 4:
		HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_SET);
		display7SEG(mode);
		scan_idx = 0;
		break;
	default:
		break;
	}
}
