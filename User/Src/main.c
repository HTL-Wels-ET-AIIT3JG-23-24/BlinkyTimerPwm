/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * TODO: add description of project
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "blinky.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"
#include "ts_calibration.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static int GetUserButtonPressed(void);
static int GetTouchState (int *xCoord, int *yCoord);

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
	HAL_IncTick();
}

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* MCU Configuration--------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();

	blinkyInit();

	int cnt = 0;
	/* Infinite loop */
	while (1)
	{
		//execute main loop every 100ms
		HAL_Delay(100);

		// display timer
		cnt++;
		LCD_SetFont(&Font20);
		LCD_SetTextColor(LCD_COLOR_BLUE);
		LCD_SetPrintPosition(5, 0);
		printf("   Timer: %.1f", cnt/10.0);

		blinkyTask();

		// test touch interface
		int x, y;
		if (GetTouchState(&x, &y)) {
			LCD_FillCircle(x, y, 5);
		}


	}
}

/**
 * Check if User Button has been pressed
 * @param none
 * @return 1 if user button input (PA0) is high
 */
static int GetUserButtonPressed(void) {
	return (GPIOA->IDR & 0x0001);
}

/**
 * Check if touch interface has been used
 * @param xCoord x coordinate of touch event in pixels
 * @param yCoord y coordinate of touch event in pixels
 * @return 1 if touch event has been detected
 */
static int GetTouchState (int* xCoord, int* yCoord) {
	void    BSP_TS_GetState(TS_StateTypeDef *TsState);
	TS_StateTypeDef TsState;
	int touchclick = 0;

	TS_GetState(&TsState);
	if (TsState.TouchDetected) {
		*xCoord = TsState.X;
		*yCoord = TsState.Y;
		touchclick = 1;
		if (TS_IsCalibrationDone()) {
			*xCoord = TS_Calibration_GetX(*xCoord);
			*yCoord = TS_Calibration_GetY(*yCoord);
		}
	}

	return touchclick;
}


