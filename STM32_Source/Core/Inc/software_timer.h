/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 		10
#define NUM_TIME 	4

int getTimerFlag(int idx);

void setTimer(int idx, int counter);
void clearTimer(int idx);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
