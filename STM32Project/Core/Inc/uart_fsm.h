/*
 * uart_fsm.h
 *
 *  Created on: Dec 8, 2023
 *      Author: Admin
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include "global.h"

#define MAX_BUFFER_SIZE 	30

#define WAIT 	0
#define SEND	1
#define RESEND	2

extern uint8_t buffer_flag;
extern uint8_t temp;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void uart_communiation_fsm();

#endif /* INC_UART_FSM_H_ */
