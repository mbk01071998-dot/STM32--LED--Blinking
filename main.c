#include "stm32c0xx_hal.h"

#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA

int main(void)
{
    HAL_Init();

    // Enable GPIOA clock
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Configure LED pin as output
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

    // LED Blink
    while (1)
    {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
        HAL_Delay(1000);
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}