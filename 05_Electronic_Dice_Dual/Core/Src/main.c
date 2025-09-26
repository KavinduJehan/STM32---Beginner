/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body - Dual Electronic Dice
  ******************************************************************************
  * @attention
  *
  * This example demonstrates dual electronic dice using two 7-segment displays
  * Target: STM32F103C8T6 (Blue Pill)
  * 
  * First 7-segment display connected to GPIOB (PB0-PB6 for segments a-g)
  * Second 7-segment display connected to GPIOC (PC0-PC6 for segments a-g)
  * Switch connected to PA0 (with internal pull-down)
  * 
  * Pin mapping for 7-segment displays:
  * Display 1 (GPIOB): PB0->a, PB1->b, PB2->c, PB3->d, PB4->e, PB5->f, PB6->g
  * Display 2 (GPIOC): PC0->a, PC1->b, PC2->c, PC3->d, PC4->e, PC5->f, PC6->g
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdlib.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// 7-segment display patterns for numbers 1-6
#define DICE_1  0b00000110  // segments b,c
#define DICE_2  0b01011011  // segments a,b,d,e,g
#define DICE_3  0b01001111  // segments a,b,c,d,g
#define DICE_4  0b01100110  // segments b,c,f,g
#define DICE_5  0b01101101  // segments a,c,d,f,g
#define DICE_6  0b01111101  // segments a,c,d,e,f,g
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t dice_patterns[6] = {DICE_1, DICE_2, DICE_3, DICE_4, DICE_5, DICE_6};
uint8_t last_switch_state = GPIO_PIN_RESET;
uint32_t random_seed = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void Display_Number_Dice1(uint8_t number);
void Display_Number_Dice2(uint8_t number);
uint8_t Generate_Random_Number(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/**
  * @brief  Display number on first 7-segment display (GPIOB)
  * @param  number: Number to display (1-6)
  * @retval None
  */
void Display_Number_Dice1(uint8_t number)
{
  if (number >= 1 && number <= 6)
  {
    uint8_t pattern = dice_patterns[number - 1];
    
    // Set each segment according to the pattern
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (pattern & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET); // a
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (pattern & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET); // b
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (pattern & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET); // c
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (pattern & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET); // d
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (pattern & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET); // e
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (pattern & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET); // f
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (pattern & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET); // g
  }
}

/**
  * @brief  Display number on second 7-segment display (GPIOC)
  * @param  number: Number to display (1-6)
  * @retval None
  */
void Display_Number_Dice2(uint8_t number)
{
  if (number >= 1 && number <= 6)
  {
    uint8_t pattern = dice_patterns[number - 1];
    
    // Set each segment according to the pattern
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, (pattern & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET); // a
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (pattern & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET); // b
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, (pattern & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET); // c
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, (pattern & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET); // d
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, (pattern & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET); // e
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, (pattern & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET); // f
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, (pattern & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET); // g
  }
}

/**
  * @brief  Generate pseudo-random number between 1-6
  * @retval Random number between 1-6
  */
uint8_t Generate_Random_Number(void)
{
  // Simple pseudo-random number generator
  random_seed = (random_seed * 1103515245 + 12345) & 0x7fffffff;
  return (random_seed % 6) + 1;
}

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
  /* USER CODE BEGIN 2 */
  
  // Initialize random seed with a value based on system tick
  random_seed = HAL_GetTick();
  
  // Display initial values
  Display_Number_Dice1(1);
  Display_Number_Dice2(1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    
    GPIO_PinState current_switch_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
    
    // Update random seed continuously for better randomness
    random_seed += HAL_GetTick();
    
    // Detect switch press (rising edge)
    if (current_switch_state == GPIO_PIN_SET && last_switch_state == GPIO_PIN_RESET)
    {
      // Switch just pressed - roll both dice
      uint8_t dice1_value, dice2_value;
      
      // Show rolling animation for both dice
      for (int i = 0; i < 15; i++)
      {
        Display_Number_Dice1(Generate_Random_Number());
        Display_Number_Dice2(Generate_Random_Number());
        HAL_Delay(80);
      }
      
      // Generate final results
      dice1_value = Generate_Random_Number();
      dice2_value = Generate_Random_Number();
      
      // Display final results
      Display_Number_Dice1(dice1_value);
      Display_Number_Dice2(dice2_value);
    }
    
    last_switch_state = current_switch_state;
    
    HAL_Delay(10); // Debounce delay
  }
  /* USER CODE END 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level - Turn off all segments initially */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB0-PB6 (First 7-segment display) */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                       |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0-PC6 (Second 7-segment display) */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                       |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 (Switch) */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */