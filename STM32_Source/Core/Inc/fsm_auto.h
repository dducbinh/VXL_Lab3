/*
 * fsm_auto.h
 *
 *  Created on: Nov 6, 2024
 *      Author: doand
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#include "input_reading.h"
#include "software_timer.h"
#include "display_LED7SEG.h"
#include "display_TrafficLight.h"

enum FSM_STATE {FSM_NORMAL, FSM_MODE_RED, FSM_MODE_YELLOW, FSM_MODE_GREEN};

void fsmInitState(void);
void fsmReState(enum FSM_STATE state);
void fsmProcess(void);

#endif /* INC_FSM_AUTO_H_ */
