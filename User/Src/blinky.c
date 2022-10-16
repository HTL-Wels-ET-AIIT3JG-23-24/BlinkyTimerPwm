/**
 ******************************************************************************
 * @file           : blinky.c
 * @brief          : Various blink implementations
 ******************************************************************************
 * Description of project
 * Implement blinking of an LED with cyclic toggling, timer interrupt and
 * PWM
 *
 ******************************************************************************
 */


// Includes ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"
#include "ts_calibration.h"

#include "blinky.h"

// Variables ------------------------------------------------------------------
// TODO: global (static) variables, eg Timer Handles


// Function Declarations ------------------------------------------------------
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
	GpioInit();
	// TODO: Add init functions



	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
}

/**
 * Task function of module blinky.
 * @param None
 * @retval None
 */
void blinkyTask(void){
	// TODO: What has to be done in our main loop?
	/* This function is called every 100ms -> We count number of 
	 * function calls and toggle LED accordingly */


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
 * @brief  Configure PWM for the application
 * @param  None
 * @retval None
 */
static void Timer3PwmInit(void) {
	// TODO: Configure TIM3 PWM output


}

