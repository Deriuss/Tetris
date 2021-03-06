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
uint8_t L[32] ={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*
int8_t led_array[38][8]=
{

{0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//0
 {0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x7c},//1
 {0x7E,0x2,0x2,0x7E,0x40,0x40,0x40,0x7E},//2
 {0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},//3
 {0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},//4
 {0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},//5
 {0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x0},//6
 {0x3E,0x22,0x4,0x8,0x8,0x8,0x8,0x8},//7
 {0x0,0x3E,0x22,0x22,0x3E,0x22,0x22,0x3E},//8
 {0x3E,0x22,0x22,0x3E,0x2,0x2,0x2,0x3E},//9
 {0x18,0x24,0x42,0x42,0x7E,0x42,0x42,0x42},//A
 {0x3C,0x22,0x22,0x3c,0x22,0x22,0x3C,0x0},//B
 {0x3C,0x40,0x40,0x40,0x40,0x40,0x40,0x3C},//C
 {0x7C,0x22,0x22,0x22,0x22,0x22,0x22,0x7C},//D
 {0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C},//E
 {0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x40},//F
 {0x3C,0x40,0x40,0x40,0x4c,0x44,0x44,0x3C},//G
 {0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44},//H
 {0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x7C},//I
 {0x3C,0x8,0x8,0x8,0x8,0x8,0x48,0x30},//J
 {0x0,0x24,0x28,0x30,0x20,0x30,0x28,0x24},//K
 {0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C},//L
 {0x81,0xC3,0xA5,0x99,0x81,0x81,0x81,0x81},//M
 {0x0,0x42,0x62,0x52,0x4A,0x46,0x42,0x0},//N
 {0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
 {0x3C,0x22,0x22,0x22,0x3C,0x20,0x20,0x20},//P
 {0x1C,0x22,0x22,0x22,0x22,0x26,0x22,0x1D},//Q
 {0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
 {0x0,0x1E,0x20,0x20,0x3E,0x2,0x2,0x3C},//S
 {0x0,0x3E,0x8,0x8,0x8,0x8,0x8,0x8},//T
 {0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1C},//U
 {0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18},//V
 {0x0,0x49,0x49,0x49,0x49,0x2A,0x1C,0x0},//W
 {0x0,0x41,0x22,0x14,0x8,0x14,0x22,0x41},//X
 {0x41,0x22,0x14,0x8,0x8,0x8,0x8,0x8},//Y
 {0x0,0x7F,0x2,0x4,0x8,0x10,0x20,0x7F},//Z

 };

*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void write_byte (uint8_t byte)
 {
 	for (int i =0; i<8; i++)
 	{
 		HAL_GPIO_WritePin (Clock_GPIO_Port, Clock_Pin, 0);           // set the clock pin LOW
 		HAL_GPIO_WritePin (Clock_GPIO_Port, DATA_IN0_Pin, byte&0x80);  // write the MSB bit to the data pin
 		byte = byte<<1;                                   // shift left
 		HAL_GPIO_WritePin (Clock_GPIO_Port, GPIO_PIN_5, 1); 		// set the clock pin HIGH

 	}
 }

 void write_matrix (uint8_t address, uint8_t data)
 {
 	//HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);  // pull the CS pin LOW
 	write_byte (address);
 	write_byte (data);

 	//HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1); // pull the CS pin HIGH

 }

 void write_table (uint8_t mat1, uint8_t mat2, uint8_t mat3, uint8_t mat4)
 {

	 uint8_t L[32] = {mat4[0],mat3[0],mat2[0],mat1[0],mat4[1],mat3[1],mat2[1],mat1[1],mat4[2],mat3[2],mat2[2],mat1[2],mat4[3],mat3[3],mat2[3],mat1[3],mat4[4],mat3[4],mat2[4],mat1[4],mat4[5],mat3[5],mat2[5],mat1[5],mat4[6],mat3[6],mat2[6],mat1[6],mat4[7],mat3[7],mat2[7],mat1[7]};
/*	 for (int i ; i == 7 ;  i++)
	 {
		 if (i == 0)
		 {
		int** L[32] = {[0] = mat4[1]}; }


		 } */

/*		 uint8_t L.Add = mat4[i];
		 uint8_t L.Add = mat3[i];
		 uint8_t L.Add = mat2[i];
		 uint8_t L.Add = mat1[i];*/

	for (int j; j==7; j++) {
		if (j == 0){

			write_matrix(0x01,L[0]);
			write_matrix(0x01,L[1]);
			write_matrix(0x01,L[2]);
			write_matrix(0x01,L[3]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==1){

			write_matrix(0x02,L[4]);
			write_matrix(0x02,L[5]);
			write_matrix(0x02,L[6]);
			write_matrix(0x02,L[7]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==2){

			write_matrix(0x03,L[8]);
			write_matrix(0x03,L[9]);
			write_matrix(0x03,L[10]);
			write_matrix(0x03,L[11]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==3){

			write_matrix(0x04,L[12]);
			write_matrix(0x04,L[13]);
			write_matrix(0x04,L[14]);
			write_matrix(0x04,L[15]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==4){

			write_matrix(0x05,L[16]);
			write_matrix(0x05,L[17]);
			write_matrix(0x05,L[18]);
			write_matrix(0x05,L[19]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==5){

			write_matrix(0x06,L[20]);
			write_matrix(0x06,L[21]);
			write_matrix(0x06,L[22]);
			write_matrix(0x06,L[23]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==6){

			write_matrix(0x07,L[24]);
			write_matrix(0x07,L[25]);
			write_matrix(0x07,L[26]);
			write_matrix(0x07,L[27]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
		if (j==7){

			write_matrix(0x08,L[28]);
			write_matrix(0x08,L[29]);
			write_matrix(0x08,L[30]);
			write_matrix(0x08,L[31]);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
			HAL_Delay(10);
			HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
		}
 }
 }
 void matrix_init(void)
 {
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
  write_matrix(0x09, 0x00); //  no decoding
  write_matrix(0x09, 0x00); //  no decoding
  write_matrix(0x09, 0x00); //  no decoding
  write_matrix(0x09, 0x00); //  no decoding
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x0A, 0x05);       //  brightness
  write_matrix(0x0A, 0x05);       //  brightness
  write_matrix(0x0A, 0x05);       //  brightness
  write_matrix(0x0A, 0x05);       //  brightness
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);


  write_matrix(0x0B, 0x07);       //  scan limit = 8 LEDs
  write_matrix(0x0B, 0x07);       //  scan limit = 8 LEDs
  write_matrix(0x0B, 0x07);       //  scan limit = 8 LEDs
  write_matrix(0x0B, 0x07);       //  scan limit = 8 LEDs
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x0C, 0x01);       //  power down =0,normal mode = 1
  write_matrix(0x0C, 0x01);       //  power down =0,normal mode = 1
  write_matrix(0x0C, 0x01);       //  power down =0,normal mode = 1
  write_matrix(0x0C, 0x01);       //  power down =0,normal mode = 1
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x0F, 0x00);    //  no display test
  write_matrix(0x0F, 0x00);    //  no display test
  write_matrix(0x0F, 0x00);    //  no display test
  write_matrix(0x0F, 0x00);    //  no display test
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);



  write_matrix(0x01, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x01, 0x00);    //
  write_matrix(0x01, 0x00);    //
  write_matrix(0x01, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x02, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x02, 0x00);    //
  write_matrix(0x02, 0x00);    //
  write_matrix(0x02, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x03, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x03, 0x00);    //
  write_matrix(0x03, 0x00);    //
  write_matrix(0x03, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x04, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x04, 0x00);    //
  write_matrix(0x04, 0x00);    //
  write_matrix(0x04, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x05, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x05, 0x00);    //
  write_matrix(0x05, 0x00);    //
  write_matrix(0x05, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x06, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x06, 0x00);    //
  write_matrix(0x06, 0x00);    //
  write_matrix(0x06, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x07, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x07, 0x00);    //
  write_matrix(0x07, 0x00);    //
  write_matrix(0x07, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

  write_matrix(0x08, 0x00);    //  Set valeurs ?? 0
  write_matrix(0x08, 0x00);    //
  write_matrix(0x08, 0x00);    //
  write_matrix(0x08, 0x00);    //
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
  HAL_Delay(10);
  HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

 }

 /*void write_string () //(char *str)
 {

 	while (*str)
 	{
         for(int i=1;i<9;i++)
 		       {
 			       write_matrix (i,led_array[(*str - 55)][i-1]);
 			   }
 		str++;
 		HAL_Delay (500);
     }

 } */

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



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    matrix_init();

    while (1)
  {
 /*   	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);
    	 write_matrix (0x08,0x01);
    	 write_matrix (0x07,0x02);
    	 write_matrix (0x06,0x04);
    	 write_matrix (0x05,0x08);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
    	 HAL_Delay(500);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

    	 write_matrix (0x08,0x00);
    	 write_matrix (0x07,0x00);
    	 write_matrix (0x06,0x00);
    	 write_matrix (0x05,0x00);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
    	 HAL_Delay(10);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

    	 write_matrix (0x04,0x02);
    	 write_matrix (0x03,0x04);
    	 write_matrix (0x02,0x08);
		 write_matrix (0x01,0x10);
		 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
		 HAL_Delay(500);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 0);

    	 write_matrix (0x04,0x00);
    	 write_matrix (0x03,0x00);
    	 write_matrix (0x02,0x00);
    	 write_matrix (0x01,0x00);
    	 HAL_GPIO_WritePin (Load_GPIO_Port, Load_Pin, 1);
    	 HAL_Delay(10); */

    	 uint8_t mat1[8] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
    	 uint8_t mat2[8] = {0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02};
    	 uint8_t mat3[8] = {0x03,0x03,0x03,0x01,0x03,0x03,0x03,0x03};
    	 uint8_t mat4[8] = {0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04};

    	 write_table(*mat1,*mat2,*mat3,*mat4);




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  GPIO_InitTypeDef GPIO_InitStruct = {0} ;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Clock_Pin|DATA_IN0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Load_GPIO_Port, Load_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Clock_Pin DATA_IN0_Pin */
  GPIO_InitStruct.Pin = Clock_Pin|DATA_IN0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Button_High_Pin Button_Right_Pin Button_Low_Pin Button_Left_Pin */
  GPIO_InitStruct.Pin = Button_High_Pin|Button_Right_Pin|Button_Low_Pin|Button_Left_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : Load_Pin */
  GPIO_InitStruct.Pin = Load_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Load_GPIO_Port, &GPIO_InitStruct);

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
