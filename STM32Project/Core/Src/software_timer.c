/*
 * software_timer.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Admin
 */

#include "software_timer.h"

int timer_counter0 = 0;
int timer_flag0 = 0;

void setTimer0(int duration){
	timer_counter0 = duration;
	timer_flag0 = 0;
}

void timerRun(){
	if(timer_counter0> 0){
		timer_counter0--;
		if(timer_counter0 <= 0){
			timer_flag0 = 1;
		}
	}
}
