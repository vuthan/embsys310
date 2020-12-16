/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

uint32_t g_uiState = 0;
uint32_t g_InterruptNeedService = 0;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

TIM_HandleTypeDef htim2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
void vSetPWMValue(uint16_t value);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
 int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
  uint32_t uiOutputModeInit = 0;
  uint32_t uiAFModeInit = 0;
  uint32_t uiAFFastModeInit = 0;
  int16_t iStep = 0;
  uint16_t uiPWMValue = 0;

  
  while (1)
  {

    switch (g_uiState)
    {
        case 0:
          
            if (!uiOutputModeInit)
            { 
                // GPIOA Pin5 Output mode is 01 - output mode 
                GPIOA->MODER |= GPIO_MODER_MODE5_0;
                GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
                uiOutputModeInit = 1;
                uiAFModeInit = 0;
            }
            GPIOA->ODR &= ~GPIO_ODR_OD5;
            
            break;
            
        case 1:
            if (!uiOutputModeInit)
            { 
                // GPIOA Pin5 Output mode is 01 - output mode 
                GPIOA->MODER |= GPIO_MODER_MODE5_0;
                GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
                uiOutputModeInit = 1;
                uiAFModeInit = 0;
            }
            GPIOA->ODR |= GPIO_ODR_OD5;
            
            break;
            
        case 2:
            if (!uiOutputModeInit)
            { 
                // GPIOA Pin5 Output mode is 01 - output mode 
                GPIOA->MODER |= GPIO_MODER_MODE5_0;
                GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
                uiOutputModeInit = 1;
                uiAFModeInit = 0;
            }
            GPIOA->ODR |= GPIO_ODR_OD5;
            HAL_Delay(2000);
            GPIOA->ODR &= ~GPIO_ODR_OD5;
            HAL_Delay(2000);
        
            break;
            
        case 3:
          
            if (!uiOutputModeInit)
            {  
                // GPIOA Pin5 Output mode is 01 - output mode
                GPIOA->MODER |= GPIO_MODER_MODE5_0;
                GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
                uiOutputModeInit = 1;
                uiAFModeInit = 0;
            }
  
            GPIOA->ODR |= GPIO_ODR_OD5;
            HAL_Delay(500);
            GPIOA->ODR &= ~GPIO_ODR_OD5;
            HAL_Delay(500);
 
            break;
            
        case 4:
      
            if (!uiAFModeInit)
            {  
                // config GPIOA pin5 to AF TIM2_CH1
                HAL_TIM_MspPostInit(&htim2);
                uiOutputModeInit = 0;
                uiAFModeInit = 1;
            }

            if (uiAFFastModeInit)
            { 
                // fast mode
                htim2.Init.Period = 2000;
                if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
                {
                    Error_Handler();
                }
                uiAFFastModeInit = 0;
            }

            HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    
            HAL_Delay(100); 
            if(uiPWMValue == 0) 
              iStep = 100;
            if(uiPWMValue == 2000) 
              iStep = -100;
            uiPWMValue += iStep;
            vSetPWMValue(uiPWMValue);
            break;
            
        case 5:

            if (!uiAFFastModeInit)
            { 
                // fast mode
                htim2.Init.Period = 200;
                if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
                {
                    Error_Handler();
                }
                uiAFFastModeInit = 1;
            }
            
            HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
            
            HAL_Delay(10); 
            if(uiPWMValue == 0) 
              iStep = 10;
            if(uiPWMValue == 200) 
              iStep = -10;
            uiPWMValue += iStep;
            vSetPWMValue(uiPWMValue);
            
            break;
            default:
            
            // GPIOA Pin5 Output mode is 01 - output mode 
            GPIOA->MODER |= GPIO_MODER_MODE5_0;
            GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
            uiOutputModeInit = 1;
            uiAFModeInit = 0;
        
            GPIOA->ODR &= ~GPIO_ODR_OD5;
            
        }
        
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}


/**
  * @brief  Stop PWM, set Pulse Value (power deliver to LED to control brightness of an LED)
  *         then restart PWM
  * @retval none
  */
void vSetPWMValue(uint16_t value)
{
    TIM_OC_InitTypeDef sConfigOC;
  
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1); 
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);  
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}
/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1000;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 2000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
