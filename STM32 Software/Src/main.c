/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */

// - - - - - - - - - - - - - - - ------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - - | I N C L U D E S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - - ------------------- - - - - - - - - - - - - -//
// definicja bool
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// - - - - - - - - - - - - - - - ------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - - | I N C L U D E S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - - ------------------- - - - - - - - - - - - - -//

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | V A R I A B L E S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
//odebrany ciag
uint8_t receivedValue[5];

// wysylany ciag
uint8_t sentValue[2];

// oszukane wartosci akcelerometru (zakres od -1024 do 1024)
int16_t x, y, z;

// aktywnosc scian
uint8_t planeActive1, planeActive2, planeActive3, planeActive4, planeActive5;

// poprzednia sciana na gorze (domyslnie sciana 0 [x = 0, y = 0, z = (-1024-1024)])
uint8_t previousPlane;

// obecna sciana na gorze
uint8_t presentPlane;

// stan przycisku cofania
uint8_t buttonClicked;
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | V A R I A B L E S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | F U N C T I O N S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//



// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | F U N C T I O N S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

	// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
	// - - - - - - - - - - - - - - | V A R I A B L E S | - - - - - - - - - - - - -//
	// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//

	x = 0;
	y = 0;
	z = 0;

	planeActive1 = 0;
	planeActive2 = 0;
	planeActive3 = 0;
	planeActive4 = 0;
	planeActive5 = 0;

	previousPlane = 0;
	buttonClicked = 0;

	// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
	// - - - - - - - - - - - - - - | V A R I A B L E S | - - - - - - - - - - - - -//
	// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  //- - - - - - - - - - - - - - - -------------------- - - - - - - - - - - - - -//
  //- - - - - - - - - - - - - - - | M A I N  L O O P | - - - - - - - - - - - - -//
  //- - - - - - - - - - - - - - - -------------------- - - - - - - - - - - - - -//
  while (1)
  {
	  //nas�uchuj transmisji Bluetooth
	  if (HAL_UART_Receive_DMA(&huart1, receivedValue, 5)) {
		  // jesli pierwszy znak to "1" to zapal pierwsza sciane (ustaw jako aktywna)
		  if (receivedValue[0] == 49) {
			  HAL_GPIO_WritePin(LED_Blue_GPIO_Port, LED_Blue_Pin, SET);
			  planeActive1 = 1;
		  } else {
			  HAL_GPIO_WritePin(LED_Blue_GPIO_Port, LED_Blue_Pin, RESET);
			  planeActive1 = 0;
		  }
		  // jesli drugi znak to "1" to zapal druga sciane (ustaw jako aktywna)
		  if (receivedValue[1] == 49) {
			  HAL_GPIO_WritePin(LED_Green_GPIO_Port, LED_Green_Pin, SET);
			  planeActive2 = 1;
		  } else {
			  HAL_GPIO_WritePin(LED_Green_GPIO_Port, LED_Green_Pin, RESET);
			  planeActive2 = 0;
		  }
		  // gdyby bylo wiecej diod mozna wtedy zaprogramowac zapalanie wszystkich scian
	  }

	  // wyznaczenie sciany znajdujacej sie na gorze na podstawie wartosci z oszukanego akcelerometru
	  // Sciana gorna
	  if (x > -256 && x < 256) {
		  if (y > -256 && y < 256) {
			  presentPlane = 0;
		  }
	  }

	  // Sciana dolna
	  if ((x >= -1024 && x < -768) || (x > 768 && x <= 1024)) {
		  if (y > -256 && y < 256) {
			  if (planeActive1 == 1) {
				  presentPlane = 1;
			  }
		  }
	  }
	  if (x > -256 && x < 256) {
		  if ((y >= -1024 && y < -768) || (y > 768 && y <= 1024)) {
			  if (planeActive1 == 1) {
				  presentPlane = 1;
			  }
		  }
	  }

	  // Sciana lewa
	  if (x > 256 && x < 768) {
		  if (z > -256 && z < 256) {
			  if (planeActive2 == 1) {
				  presentPlane = 2;
			  }
		  }
	  }
	  if (x > -256 && x < 256) {
		  if ((y > -768 && y < -256) || (y > 256 && y < 768)) {
			  if (z > 256 && z < 768) {
				  if (planeActive2 == 1) {
					  presentPlane = 2;
				  }
			  }
		  }
	  }

	  // Sciana prawa
	  if (x > -768 && x < -256) {
		  if (z > -256 && z < 256) {
			  if (planeActive3 == 1) {
				  presentPlane = 3;
			  }
		  }
	  }
	  if (x > -256 && x < 256) {
		  if ((y > -768 && y < -256) || (y > 256 && y < 768)) {
			  if (z > -768 && z < -256) {
				  if (planeActive3 == 1) {
					  presentPlane = 3;
				  }
			  }
		  }
	  }

	  // Sciana przednia
	  if (y > 256 && y < 768) {
		  if (z > -256 && z < 256) {
			  if (planeActive4 == 1) {
				  presentPlane = 4;
			  }
		  }
	  }

	  // Sciana tylna
	  if (y > -768 && y < -256) {
		  if (z > -256 && z < 256) {
			  if (planeActive5 == 1) {
				  presentPlane = 5;
			  }
		  }
	  }

	  // sprawdzenie stanu przycisku cofania
	  if (HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET) {
		  buttonClicked = 1;
	  } else {
		  buttonClicked = 0;
	  }

	  if (buttonClicked == 1) {
		  // aktualizacja wysylanych danych
		  sprintf(sentValue, "%d%d", presentPlane, buttonClicked);

		  // wyslanie komunikatu do aplikacji
		  HAL_UART_Transmit_DMA(&huart1, sentValue, 2);

		  // prosty debounce
		  HAL_Delay(500);
	  }

	  // jesli obecna sciana na gorze kostki jest rozna od poprzedniej lub gdy wcisnieto przycisk
	  if (previousPlane != presentPlane) {
		  // aktualizacja wysylanych danych
		  sprintf(sentValue, "%d%d", presentPlane, buttonClicked);

		  // wyslanie komunikatu do aplikacji
		  HAL_UART_Transmit_DMA(&huart1, sentValue, 2);

		  // zapisanie aktualnej sciany jako poprzednia
		  previousPlane = presentPlane;
	  }
  //- - - - - - - - - - - - - - - -------------------- - - - - - - - - - - - - -//
  //- - - - - - - - - - - - - - - | M A I N  L O O P | - - - - - - - - - - - - -//
  //- - - - - - - - - - - - - - - -------------------- - - - - - - - - - - - - -//

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USART1 init function */
void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart1);

}

/** 
  * Enable DMA controller clock
  */
void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin : BUTTON_Pin */
  GPIO_InitStruct.Pin = BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Blue_Pin LED_Green_Pin */
  GPIO_InitStruct.Pin = LED_Blue_Pin|LED_Green_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_Blue_Pin|LED_Green_Pin, GPIO_PIN_RESET);

}

/* USER CODE BEGIN 4 */

// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | F U N C T I O N S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//



// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - | F U N C T I O N S | - - - - - - - - - - - - -//
// - - - - - - - - - - - - - - --------------------- - - - - - - - - - - - - -//

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
