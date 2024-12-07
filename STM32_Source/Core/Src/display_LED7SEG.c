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
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b10000000; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_SET);

		break;
	case 1:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b11110011; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_SET);

		break;
	case 2:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b01001001; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 3:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b01100001; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 4:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00110011; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 5:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00100101; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 6:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00000101; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 7:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b11110001; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_SET);

		break;
	case 8:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00000001; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

		break;
	case 9:
//		GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF01) | 0b00100001; // GFEDCBA
		HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);

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

	// Clear
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
