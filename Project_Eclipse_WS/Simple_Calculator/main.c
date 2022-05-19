/**************************************************************************************************
 *
 * Author      : Mustafa Muhammad
 *
 * Description : Simple Calculator
 *
 **************************************************************************************************/

#include "Simple_Calculator.h"

int main(void)
{
	/*
	 * Initialization of LCD_Calculator
	 */
	LCD_Claculator_init();

	/*
	 * Variables Declaration
	 * key : returned number or operation from Keypad
	 * operator : calculation operator
	 * key_flag : flag to prevent displaying characters after calculated unless user clear screen
	 * result : result of number calculation
	 */
	uint8 key, operator, key_flag = 0;
	sint32 result;

	for(;;)
	{
		key = KEYPAD_getPressedKey();
		switch(key)
		{
		case 0:
			if(key_flag == 0)
			{
				LCD_intgerToString(0);
				Taking_numbers(0);
			}
			break;
		case 1:
			if(key_flag == 0)
			{
				LCD_intgerToString(1);
				Taking_numbers(1);
			}
			break;
		case 2:
			if(key_flag == 0)
			{
				LCD_intgerToString(2);
				Taking_numbers(2);
			}
			break;
		case 3:
			if(key_flag == 0)
			{
				LCD_intgerToString(3);
				Taking_numbers(3);
			}
			break;
		case 4:
			if(key_flag == 0)
			{
				LCD_intgerToString(4);
				Taking_numbers(4);
			}
			break;
		case 5:
			if(key_flag == 0)
			{
				LCD_intgerToString(5);
				Taking_numbers(5);
			}
			break;
		case 6:
			if(key_flag == 0)
			{
				LCD_intgerToString(6);
				Taking_numbers(6);
			}
			break;
		case 7:
			if(key_flag == 0)
			{
				LCD_intgerToString(7);
				Taking_numbers(7);
			}
			break;
		case 8:
			if(key_flag == 0)
			{
				LCD_intgerToString(8);
				Taking_numbers(8);
			}
			break;
		case 9:
			if(key_flag == 0)
			{
				LCD_intgerToString(9);
				Taking_numbers(9);
			}
			break;
		case 13:
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,5,"Simple");
			LCD_displayStringRowColumn(1,3,"Calculator");
			LCD_moveCursor(2, 0);
			num1 = 0;
			num2 = 0;
			num2_flag = 0;
			key_flag = 0;
			break;
		case '*':
			if(key_flag == 0)
			{
				LCD_displayCharacter('*');
				operator = '*';
				num2_flag++;
			}
			break;
		case '/':
			if(key_flag == 0)
			{
				LCD_displayCharacter('/');
				operator = '/';
				num2_flag++;
			}
			break;
		case '+':
			if(key_flag == 0)
			{
				LCD_displayCharacter('+');
				operator = '+';
				num2_flag++;
			}
			break;
		case '-':
			if(key_flag == 0)
			{
				LCD_displayCharacter('-');
				operator = '-';
				num2_flag++;
			}
			break;
		case '=':
			if(key_flag == 0)
			{
				LCD_moveCursor(3, 0);
				result = Claculation(num1, num2, operator);
				Result_Display(result);
				key_flag++;
			}
			break;
		}
		/*
		 * Delay to wait before take next character
		 */
		_delay_ms(500);
	}
}

