/*
 * Semihosting example using NORTOS
 */
#include "nortos.h"
#include <TM4C123.h>
#include "mutex.h"
#include <stdio.h>

extern void initialise_monitor_handles();

uint32_t taskOneStack[128], taskTwoStack[128], taskThreeStack[128], idleStack[32];
NORTOS_Task taskOneTask, taskTwoTask, taskThreeTask;

void taskOne() {
    while(1) {
        printf("Hey from task 1\n");
        NORTOS_Delay(300U);
    }
}

void taskTwo() {
    while(1) {
        printf("Hey from task 2\n");
        NORTOS_Delay(500U);
    }
}

void taskThree() {
    while(1) {
        printf("Hey from task 3\n");
        NORTOS_Delay(1000U);
    }
}

int main(void) {
    SystemCoreClockUpdate();
    OnStartup();

    NORTOS_Init(idleStack, sizeof(idleStack));
    NORTOS_AddTask(&taskTwoTask, taskTwo, taskTwoStack, sizeof(taskTwoStack), 9);
    NORTOS_AddTask(&taskOneTask, taskOne, taskOneStack, sizeof(taskOneStack), 4);
    NORTOS_AddTask(&taskThreeTask, taskThree, taskThreeStack, sizeof(taskThreeStack), 1);

    NORTOS_Run();

    return 0;
}

void OnStartup() {
    initialise_monitor_handles();
    SysTick->LOAD = 1000;
    SysTick->VAL = 0U;

    NVIC_SetPriority(SysTick_IRQn, 0U);
    SysTick->CTRL = 0x3;
}
