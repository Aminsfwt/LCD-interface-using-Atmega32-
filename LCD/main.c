/*
 * LCD.c
 *
 * Created: 1/21/2023 3:40:07 AM
 * Author : amen safwat
 */ 

#include "LCD Drivers/lcd.h"

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000ul

int main(void)
{
	
	LCD_Init();

	LCD_SendCommand(0xC0);
    LCD_DisplayString(" Amin Safout ALi, Welcome AVR");
	_delay_ms(1000);

    while (1)
	{
		LCD_SendCommand(0x1C);
		_delay_ms(1500);
	} 
	return 0;	
}

