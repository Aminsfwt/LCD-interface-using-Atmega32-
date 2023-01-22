/*
 * lcd.c
 *
 * Created: 1/21/2023 3:58:43 AM
 *  Author: amen safwat
 */ 
 #include <util/delay.h>
 #include "lcd.h"

/***************************************LCD INITIALIZATION****************************/
 void LCD_Init()
 {
	LCD_Data_Dir = 0xFF;
	LCD_Ctrl_Dir = 0xFF;
	Clear_Bit(LCD_Ctrl_Out, EN);

	LCD_SendCommand(0x33);
	LCD_SendCommand(0x32);
	LCD_SendCommand(FOUR_Bit_Mode);
	LCD_SendCommand(CURSOR_ON);
	LCD_SendCommand(CLEAR_COMMAND);
	_delay_ms(2);
 }

 /***************************************LCD Send COMMAND****************************/
 void LCD_SendCommand(uint8_t cmd)
 {
	Clear_Bit(LCD_Ctrl_Out, RS);                  //RS FOR COMMAND
	
	//Send Upper nibble
     LCD = cmd & 0xF0;
	  //Enable Pulse
	 Set_Bit(LCD_Ctrl_Out, EN);
	 _delay_ms(1);
	 Clear_Bit(LCD_Ctrl_Out, EN); 

	//Send Lower nibble
     LCD = cmd << 4;
      //Enable Pulse
	 Set_Bit(LCD_Ctrl_Out, EN);
	 _delay_ms(1);
	 Clear_Bit(LCD_Ctrl_Out, EN);

 }

 /***************************************LCD Char send ****************************/
 void LCD_SendCharacter(uint8_t data)
 {
	 Set_Bit(LCD_Ctrl_Out,RS);
	 
	 //Send Upper nibble
	 LCD = data & 0xF0;
	  //Enable Pulse
	 Set_Bit(LCD_Ctrl_Out, EN);
	 _delay_ms(1);
	 Clear_Bit(LCD_Ctrl_Out, EN);

	 //Send Lower nibble
	 LCD = data << 4;
	 //Enable Pulse
	 Set_Bit(LCD_Ctrl_Out, EN);
	 _delay_ms(1);
	 Clear_Bit(LCD_Ctrl_Out, EN);
 }

 /***************************************LCD DISPLAY STRING ****************************/
 void LCD_DisplayString(uint8_t *str)
 {
	uint8_t i = 0;
	while(str[i] != 0)
	{
		LCD_SendCharacter(str[i]);
		i++;
	}
 }

  /***************************************LCD CLEAR SCREEN ****************************/
 void LCD_ClearScreen()
 {
	LCD_SendCommand(CLEAR_COMMAND);
 }