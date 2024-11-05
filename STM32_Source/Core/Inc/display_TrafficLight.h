/*
 * display_TrafficLight.h
 *
 *  Created on: Nov 6, 2024
 *      Author: doand
 */

#ifndef INC_DISPLAY_TRAFFICLIGHT_H_
#define INC_DISPLAY_TRAFFICLIGHT_H_

#include "main.h"

#define TRAFFIC_NUMS 		2
#define TRAFFIC_SEC_DUR 	1000
#define TRAFFIC_BLINK_DUR 	500

enum Traffic_State {Traffic_Off, Traffic_Red, Traffic_Yellow, Traffic_Green};

extern int trafficRedDuration;
extern int trafficYellowDuration;
extern int trafficGreenDuration;
extern enum Traffic_State trafficState[TRAFFIC_NUMS];

void trafficInitState(void);
void trafficReState(int idx, enum Traffic_State state);

#endif /* INC_DISPLAY_TRAFFICLIGHT_H_ */
