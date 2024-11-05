/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */


#include "software_timer.h"

int timer_flag[NUM_TIME];
int timer_counter[NUM_TIME];

void setTimer(int idx, int counter) {
	if (idx < NUM_TIME) {
		timer_flag[idx] = 0;
		timer_counter[idx] = counter / TICK;
	}
}

void clearTimer(int idx) {
	if (idx < NUM_TIME) {
		timer_flag[idx] = 0;
		timer_counter[idx] = 0;
	}
}

void timerRun() {
	for (int i = 0; i < NUM_TIME; i++) {
		if (timer_counter[i] >= 0) {
			timer_counter[i]--;
			if (timer_counter[i] == 0) timer_flag[i] = 1;
		}
	}
}

int getTimerFlag(int idx) {
	if (idx < NUM_TIME) {
		return timer_flag[idx];
	}
	return -1; // Xay ra loi
}
