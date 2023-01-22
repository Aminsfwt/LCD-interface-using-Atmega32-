/*
 * lcd.h
 *
 * Created: 1/21/2023 3:58:03 AM
 *  Author: amen safwat
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../DIO.h"
#include <avr/io.h>
typedef unsigned char     uint8_t;

/**************LCD Controll and Direction*********************************/
#define LCD_Data_Dir DDRC
#define LCD          PORTC
#define LCD_Ctrl_Dir DDRD
#define LCD_Ctrl_Out PORTD

#define EN 4
#define RS 6


/**************LCD Command Codes*****************************************/
#define FOUR_Bit_Mode       0x28
#define CLEAR_COMMAND       0x01
#define CURSOR_OFF          0x0C
#define CURSOR_ON			0x0E
#define SET_CURSOR_1st_Line 0x80

/**************LCD FUNCTIONS*********************************************/
void LCD_Init();
void LCD_SendCommand(uint8_t data);
void LCD_DisplayString(uint8_t *str);
void LCD_ClearScreen();

#endif /* LCD_H_ */