/******************************************************************************
 *
 * Module: Calculator
 *
 * Description: Source file for Calculator
 *
 *******************************************************************************/


#include "Simple_Calculator.h"

/*
 * division flag to check the division operation
 */
uint8 div_flag = 0;


/*
 * Description :
 * Initialization of LCD_Calculator
 */
void LCD_Claculator_init(void)
{
	/*
	 * Initialize the LCD
	 */
	LCD_init();

	/*
	 * print (Simple) on 1st row, begin from column 5
	 */
	LCD_displayStringRowColumn(0,5,"Simple");

	/*
	 * print (Simple) on 3rd row, begin from column 3
	 */
	LCD_displayStringRowColumn(1,3,"Calculator");

	/*
	 * begin displaying numbers in 2nd row, begin column 0
	 */
	LCD_moveCursor(2, 0);
}


/*
 * Description :
 * Display the result on LCD
 */
void Result_Display(sint32 res)
{
	/*
	 * checking if the operation is not a division
	 */
	if(div_flag == 0)
	{
		/*
		 * check if result is not a negative, so will print it without '-'
		 */
		if(res >= 0)
		{
			LCD_intgerToString(res);
		}
		/*
		 * check if result is a negative, so will print it with '-'
		 */
		else
		{
			LCD_displayCharacter('-');
			LCD_intgerToString(res);
		}
	}
	/*
	 * checking if the operation is a division
	 */
	else
	{
		/*
		 * check if divisor is 0, will print error
		 */
		if(num2 == 0)
		{
			LCD_displayString("ERROR, Divisor 0");
		}
		/*
		 * check if divisor is not 0, will print result
		 */
		else
		{
			/*
			 * check if result is not a negative, so will print it without '-'
			 */
			if(res >= 0)
			{
				LCD_intgerToString(res);
			}
			/*
			 * check if result is a negative, so will print it with '-'
			 */
			else
			{
				LCD_displayCharacter('-');
				LCD_intgerToString(res);
			}
		}
		div_flag = 0;
	}
}


/*
 * Description :
 * Calculate the number with operation
 */
sint32 Claculation(uint16 n1, uint16 n2, uint8 oper)
{
	sint32 result;
	switch(oper)
	{
	case '*':
		result = n1 * n2;
		break;
	case '/':
		result = n1 / n2;
		/*
		 * division flag to check the division operation
		 */
		div_flag++;
		break;
	case '+':
		result = n1 + n2;
		break;
	case '-':
		result = n1 - n2;
		break;
	}
	return result;
}


/*
 * Description :
 * Taking number from users & store them in variables
 */
void Taking_numbers(uint8 num)
{
	/* According to the flag, number will store in left or right of the operation */
	if(num2_flag == 0)
	{
		num1 = (num1*10) + num;
	}
	else
	{
		num2 = (num2*10) + num;
	}
}
