#include "stm32f4xx.h"
#include "led.h"

int main(void)
{
    // 1. 初始化LED
    LED_Init();

    while (1)
    {
        // 流水灯逻辑：LED1亮 -> 延时 -> LED1灭LED2亮 -> 延时 -> 循环
//        LED1_ON();
        LED2_OFF();
        Delay(0x7FFFFF); // 延时

//        LED1_OFF();
        LED2_ON();
        Delay(0x7FFFFF); // 延时
    }
}
