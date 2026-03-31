#ifndef __LED_H
#define __LED_H
#include "stm32f4xx.h"

// 引脚定义：PA9 和 PA10
#define LED1_PIN  GPIO_Pin_9
#define LED2_PIN  GPIO_Pin_10
#define LED_PORT  GPIOF

// 函数声明
void LED_Init(void);       // LED初始化
void LED1_ON(void);        // LED1亮
void LED1_OFF(void);       // LED1灭
void LED1_Toggle(void);    // LED1翻转
void LED2_ON(void);        // LED2亮
void LED2_OFF(void);       // LED2灭
void LED2_Toggle(void);    // LED2翻转

#endif
