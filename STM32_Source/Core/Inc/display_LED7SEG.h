/*
 * display_LED7SEG.h
 *
 *  Created on: Nov 5, 2024
 *      Author: doand
 */

#ifndef INC_DISPLAY_LED7SEG_H_
#define INC_DISPLAY_LED7SEG_H_

#include "main.h"
#include "software_timer.h"

#define LED7SEG_SCAN_DUR 	10
#define LED_7 				5

extern int firstSEG;
extern int secondSEG;
extern int mode;

void led7SEGInitState(void);
void led7SEGScan(void);

#endif /* INC_DISPLAY_LED7SEG_H_ */
