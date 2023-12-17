/*
 * cmd_fsm.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Admin
 */

#include "cmd_fsm.h"

uint8_t cmd_flag = 0;

uint8_t state = INIT;

void command_parser_fsm(){
	switch(state){
	case INIT:
		if(temp == '!'){
			state = FIRST_CHAR;
		}
		break;
	case FIRST_CHAR:
		if(temp == 'O'){
			state = OK1;
		} else if(temp == 'R'){
			state = RST1;
		} else state = INIT;
		break;
	case OK1:
		if(temp == 'K'){
			state = END_OK;
		} else state = INIT;
		break;
	case END_OK:
		if(temp == '#'){
			cmd_flag = 0;
		}
		state = INIT;
		break;
	case RST1:
		if(temp == 'S'){
			state = RST2;
		} else state = INIT;
		break;
	case RST2:
		if(temp == 'T'){
			state = END_RST;
		} else state = INIT;
		break;
	case END_RST:
		if(temp == '#'){
			cmd_flag = 1;
		}
		state = INIT;
		break;
	default:
		state = INIT;
		break;
	}
}
