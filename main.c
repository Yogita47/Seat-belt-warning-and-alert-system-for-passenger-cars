#include "stm32f1xx_hal.h"

// Function declarations
void SystemClock_Config(void);
void MX_GPIO_Init(void);
int check_seat_belt_status(void);
void trigger_alert(void);

#define ALERT_DURATION 5000 // milliseconds

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  while (1)
  {
    if (check_seat_belt_status() == GPIO_PIN_RESET) {
      trigger_alert();
    }
    HAL_Delay(100);
  }
}
