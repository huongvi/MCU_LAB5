/*
 * cmd_fsm.h
 *
 *  Created on: Dec 8, 2023
 *      Author: Admin
 */

#ifndef INC_CMD_FSM_H_
#define INC_CMD_FSM_H_

#include "global.h"

#define INIT	0
#define FIRST_CHAR	1
#define OK1		2
#define END_OK 	3
#define RST1 	4
#define RST2	5
#define RST3	6
#define END_RST	7


extern uint8_t cmd_flag;

void command_parser_fsm();

#endif /* INC_CMD_FSM_H_ */
