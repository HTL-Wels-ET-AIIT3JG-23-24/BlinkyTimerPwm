/*
 * AIIT template for STM32F429I-Discovery board
 * Project: Timer
 */


// Includes ------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ioe.h"

#include "blinky.h"

// Variables ------------------------------------------------------------------

// Function Declarations ------------------------------------------------------
static void LcdInit(void);
static void GpioInit(void);
static void Timer3Init(void);
static void Timer3PwmInit(void);

// Functions ------------------------------------------------------------------

/**
  * Initialization Code for module blinky
	* @param None
  * @retval None
  */
void blinkyInit(void) {
	LcdInit();
	GpioInit();
	
	GPIO_ResetBits(GPIOG, GPIO_Pin_13 | GPIO_Pin_14);
}

/**
  * Task function of module blinky.
	* @param None
  * @retval None
  */
void blinkyTask(void){
	// TODO: What has to be done in our main loop?
}

/**
  * Initialize LCD and print default text
	* @param None
  * @retval None
  */
static void LcdInit(void) {
  LCD_Init();					// LCD initialization
  LCD_LayerInit(); 		// LCD Layer initialization
  LTDC_Cmd(ENABLE);  	// Enable the LTDC 
  LCD_SetLayer(LCD_FOREGROUND_LAYER);	// Set LCD foreground layer
  LCD_Clear(LCD_COLOR_BLUE);
  LCD_SetColors(LCD_COLOR_YELLOW, LCD_COLOR_BLUE); // TextColor,BackColor
 
  LCD_SetFont(&Font16x24);				//  line: 0...12	, column: 0...14		(default)
  LCD_SetPrintPosition(1,0);      // line 1, column 0
  printf("   HTL-WELS    ");

  LCD_SetFont(&Font8x8);					// line: 0...39	, column: 0...29
  LCD_SetPrintPosition(39,0);			// line 39, column 0
  LCD_SetColors(LCD_COLOR_MAGENTA, LCD_COLOR_BLUE); // TextColor,BackColor
  printf("  (c) Bernhard Breinbauer  ");

  LCD_SetFont(&Font16x24);
  LCD_SetColors(LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
}

/**
  * @brief  Configure GPIOs
  * @param  None
  * @retval None
  */
static void GpioInit(void)
{
	// TODO: What GPIOs do we need? -> Configure them!

}

/**
  * @brief  Configure Timer 3 for our application
  * @param  None
  * @retval None
  */
static void Timer3Init(void) {
	// TODO: Configure Timers

}

/**
  * @brief  Configure PWM
  * @param  None
  * @retval None
  */
static void Timer3PwmInit(void) {
	// TODO: Configure TIM3 PWM output

}

