#include "stm32f1xx_hal.h"

#define SEAT_BELT_SENSOR_PIN GPIO_PIN_2
#define SEAT_BELT_SENSOR_PORT GPIOA
#define ALERT_PIN GPIO_PIN_13
#define ALERT_PORT GPIOB

int check_seat_belt_status(void)
{
  return HAL_GPIO_ReadPin(SEAT_BELT_SENSOR_PORT, SEAT_BELT_SENSOR_PIN);
}

void trigger_alert(void)
{
  HAL_GPIO_WritePin(ALERT_PORT, ALERT_PIN, GPIO_PIN_SET);
  HAL_Delay(5000);
  HAL_GPIO_WritePin(ALERT_PORT, ALERT_PIN, GPIO_PIN_RESET);
}

void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Seat Belt Sensor Pin (PA2)
  GPIO_InitStruct.Pin = SEAT_BELT_SENSOR_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SEAT_BELT_SENSOR_PORT, &GPIO_InitStruct);

  // Alert Pin (PB13)
  GPIO_InitStruct.Pin = ALERT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ALERT_PORT, &GPIO_InitStruct);
}
