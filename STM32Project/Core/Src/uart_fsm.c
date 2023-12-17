/*
 * uart_fsm.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Admin
 */


#include "uart_fsm.h"


uint8_t status = WAIT;
uint8_t adc[10] = "!ADC=";
uint8_t ADC_value = 0;
char str[20];

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE] = "!ADC=";
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART2){
		//HAL_UART_Transmit(&huart2, &temp, 1, 200);
		buffer[index_buffer++] = temp;
		if(index_buffer >= 30) index_buffer = 0;
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void uart_communiation_fsm(){
	switch (status){
	case WAIT:
		if(cmd_flag == 1){
			status = SEND;
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, 1000);
			ADC_value = HAL_ADC_GetValue(&hadc1);
		}
		break;
	case SEND:
		HAL_UART_Transmit(&huart2, (uint8_t *) "\r\n", 3, 1000);
		HAL_UART_Transmit(&huart2, adc, 5, 1000);
		HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d", ADC_value), 1000);
		HAL_UART_Transmit(&huart2, (uint8_t *) "#\r\n", 3, 1000);
		if(cmd_flag == 1){
			status = RESEND;
			setTimer0(300);
		} else {
			status = WAIT;
		}
		break;
	case RESEND:
		if(timer_flag0 == 1){
			HAL_UART_Transmit(&huart2, adc, 5, 1000);
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d", ADC_value), 1000);
			HAL_UART_Transmit(&huart2, (uint8_t *) "#\r\n", 3, 1000);
			setTimer0(300);
		}
		if(cmd_flag == 0){
			status = WAIT;
		}
		break;
	default:
		status = WAIT;
		break;
	}
}

