/*
    BitzOS (BOS) V0.0.0 - Copyright (C) 2016 Hexabitz
    All rights reserved
		
    File Name     : H04R0.c
    Description   : Header file for module H04R0.
										Sound speaker (Knowles) with audio amp (TS4990IST) and headset port 
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef H04R0_H
#define H04R0_H

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"

/* Exported definitions -------------------------------------------------------*/

#define	modulePN		_H04R0

/* Define available ports */
#define _P1 
#define _P2 
#define _P4 
#define _P5 
#define _P6

/* Define available USARTs */
#define _Usart1 1
#define _Usart2 1
#define _Usart3 1
#define _Usart4 1
#define _Usart5 1
	
/* Port Definitions */
#define	USART1_TX_PIN		GPIO_PIN_9
#define	USART1_RX_PIN		GPIO_PIN_10
#define	USART1_TX_PORT	GPIOA
#define	USART1_RX_PORT	GPIOA
#define	USART1_AF				GPIO_AF1_USART1

#define	USART2_TX_PIN		GPIO_PIN_2
#define	USART2_RX_PIN		GPIO_PIN_3
#define	USART2_TX_PORT	GPIOA
#define	USART2_RX_PORT	GPIOA
#define	USART2_AF				GPIO_AF1_USART2

#define	USART3_TX_PIN		GPIO_PIN_10
#define	USART3_RX_PIN		GPIO_PIN_11
#define	USART3_TX_PORT	GPIOB
#define	USART3_RX_PORT	GPIOB
#define	USART3_AF				GPIO_AF4_USART3

#define	USART4_TX_PIN		GPIO_PIN_0
#define	USART4_RX_PIN		GPIO_PIN_1
#define	USART4_TX_PORT	GPIOA
#define	USART4_RX_PORT	GPIOA
#define	USART4_AF				GPIO_AF4_USART4

#define	USART5_TX_PIN		GPIO_PIN_3
#define	USART5_RX_PIN		GPIO_PIN_4
#define	USART5_TX_PORT	GPIOB
#define	USART5_RX_PORT	GPIOB
#define	USART5_AF				GPIO_AF4_USART5


/* Module-specific Definitions */
#define	_STDBY_PIN			GPIO_PIN_0
#define	_STDBY_PORT			GPIOB
#define	_DAC_PIN				GPIO_PIN_4
#define	_DAC_PORT				GPIOA

#define MusicNotesNumOfSamples	255

/* H01R0_Status Type Definition */  
typedef enum 
{
  H04R0_OK = 0,
	H04R0_ERR_UnknownMessage = 1,
} H04R0_Status;

/* Indicator LED */
#define _IND_LED_PORT		GPIOB
#define _IND_LED_PIN		GPIO_PIN_14

/* Exported variables */
extern const float notesFreq[12][9];

/* Macros for musical notes */
#define C4(t)		PlaySine(notesFreq[0][5], MusicNotesNumOfSamples, t)	

/* Export UART variables */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;



/* Define UART Init prototypes */
extern void MX_USART1_UART_Init(void);
extern void MX_USART2_UART_Init(void);
extern void MX_USART3_UART_Init(void);
extern void MX_USART4_UART_Init(void);
extern void MX_USART5_UART_Init(void);




/* -----------------------------------------------------------------------
	|														Message Codes	 														 	|
   ----------------------------------------------------------------------- 
*/



	
/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   ----------------------------------------------------------------------- 
*/

extern void H04R0_Init(void);
extern H04R0_Status H04R0_MessagingTask(uint16_t code, uint8_t port, uint8_t src, uint8_t dst);
extern void PlaySine(float freq, uint8_t NumOfSamples, uint32_t length);

/* -----------------------------------------------------------------------
	|															Commands																 	|
   ----------------------------------------------------------------------- 
*/




#endif /* H04R0_H */

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
