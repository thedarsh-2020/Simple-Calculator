/******************************************************************************
 *
 * Module: Calculator
 *
 * Description: Header file for Calculator
 *
 *******************************************************************************/


#ifndef SIMPLE_CALCULATOR_H_
#define SIMPLE_CALCULATOR_H_

#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "lcd.h"
#include "std_types.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Numbers used in calculation
 */
uint16 num1, num2;

/*
 * Flag refer to user enter second number after operation
 */
uint8 num2_flag;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialization of LCD_Calculator
 */
void LCD_Claculator_init(void);

/*
 * Description :
 * Display the result on LCD
 */
void Result_Display(sint32 result);

/*
 * Description :
 * Calculate the number with operation
 */
sint32 Claculation(uint16 n1, uint16 n2, uint8 oper);

/*
 * Description :
 * Taking number from users & store them in variables
 */
void Taking_numbers(uint8 num);


#endif /* SIMPLE_CALCULATOR_H_ */
