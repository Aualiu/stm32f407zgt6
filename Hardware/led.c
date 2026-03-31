#include "led.h"

// 简单延时函数（约几十ms，根据主频168M调整）
void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}

// LED初始化函数
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 1. 使能 GPIOA 时钟 (挂在 AHB1 总线)
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    // 2. 配置 PA9 和 PA10 为推挽输出
    GPIO_InitStructure.GPIO_Pin   = LED1_PIN | LED2_PIN;  // 同时配置两个引脚
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        // 输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;         // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      // 速度
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;      // 无上下拉
    GPIO_Init(LED_PORT, &GPIO_InitStructure);

    // 3. 默认熄灭两个LED (假设低电平点亮，这里先拉高)
    GPIO_SetBits(LED_PORT, LED1_PIN | LED2_PIN);
}

// LED1 亮 (PA9)
void LED1_ON(void)
{
    GPIO_ResetBits(LED_PORT, LED1_PIN); // 低电平点亮
}

// LED1 灭
void LED1_OFF(void)
{
    GPIO_SetBits(LED_PORT, LED1_PIN);
}

// LED1 翻转
void LED1_Toggle(void)
{
    GPIO_ToggleBits(LED_PORT, LED1_PIN);
}

// LED2 亮 (PA10)
void LED2_ON(void)
{
    GPIO_ResetBits(LED_PORT, LED2_PIN);
}

// LED2 灭
void LED2_OFF(void)
{
    GPIO_SetBits(LED_PORT, LED2_PIN);
}

// LED2 翻转
void LED2_Toggle(void)
{
    GPIO_ToggleBits(LED_PORT, LED2_PIN);
}
