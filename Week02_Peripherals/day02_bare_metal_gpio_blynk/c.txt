#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 1. Define the register addresses you found
#define GPIO_ENABLE_W1TS_REG_ADDR   (*((volatile uint32_t *)0x3FF44024))
#define GPIO_OUT_W1TS_REG_ADDR      (*((volatile uint32_t *)0x3FF44008))
#define GPIO_OUT_W1TC_REG_ADDR      (*((volatile uint32_t *)0x3FF4400C  ))

// 2. Define which GPIO pin your LED is connected to
#define BLINK_GPIO 2 // The built-in LED on many ESP32 boards is on GPIO 2

void app_main(void)
{
    // 3. Configure the pin as an output
    // Use the ENABLE register and a bitwise operation
    // YOUR CODE HERE
  GPIO_ENABLE_W1TS_REG_ADDR = GPIO_ENABLE_W1TS_REG_ADDR | (1 << BLINK_GPIO);

  while(1){
    GPIO_OUT_W1TS_REG_ADDR = (1 << BLINK_GPIO);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    GPIO_OUT_W1TC_REG_ADDR = (1 << BLINK_GPIO);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }

}