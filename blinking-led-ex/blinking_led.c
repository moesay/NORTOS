/*
 * Blinking LEDs example using NORTOS
 */
#include "nortos.h"
#include <TM4C123.h>
#include "mutex.h"

#define RED   (1 << 1)
#define GREEN (1 << 3)
#define BLUE  (1 << 2)

uint32_t redLEDStack[32], greenLEDStack[32], blueLEDStack[32], idleStack[32];
NORTOS_Task redLEDTask, greenLEDTask, blueLEDTask;

void redLED() {
    while(1) {
        GPIOF->DATA |= RED;
        NORTOS_Delay(500U);
        GPIOF->DATA &= ~RED;
        NORTOS_Delay(500U);
    }
}

void greenLED() {
    while(1) {
        GPIOF->DATA |= GREEN;
        NORTOS_Delay(1000U);
        GPIOF->DATA &= ~GREEN;
        NORTOS_Delay(1000U);
    }
}

void blueLED() {
    while(1) {
        GPIOF->DATA |= BLUE;
        NORTOS_Delay(1200U);
        GPIOF->DATA &= ~BLUE;
        NORTOS_Delay(1200U);
    }
}

int main(void) {
    SystemCoreClockUpdate();
    OnStartup();

    NORTOS_Init(idleStack, sizeof(idleStack));
    NORTOS_AddTask(&greenLEDTask, greenLED, greenLEDStack, sizeof(greenLEDStack), 2);
    NORTOS_AddTask(&redLEDTask, redLED, redLEDStack, sizeof(redLEDStack), 3);
    NORTOS_AddTask(&blueLEDTask, blueLED, blueLEDStack, sizeof(blueLEDStack), 10);

    NORTOS_Run();

    return 0;
}

void OnStartup() {
    SYSCTL->RCGCGPIO |= 1 << 5;
    while(!(SYSCTL->RCGCGPIO & (1 << 5)));

    SysTick->LOAD = 1000;
    SysTick->VAL = 0U;

    GPIOF->DIR |= (1 << 1) | (1 << 2) | (1 << 3);
    GPIOF->DEN |= (1 << 1) | (1 << 2) | (1 << 3);

    NVIC_SetPriority(SysTick_IRQn, 0U);
    SysTick->CTRL = 0x3;
}
