/*  NORTOS PROJECT
 *
 *      File: nortos.c
 *      Author: Mohamed ElSayed
 *      email: m.elsayed4420@gmail.com
 * */

#include "nortos.h"
#define MAX_TASKS 15

NORTOS_Task *__taskArr [MAX_TASKS+1];
uint16_t __tasksCount = 0U;
NORTOS_Task *volatile __currentTask, *volatile __nextTask;
bool __init = false;
uint32_t __readyTasksBM = 0U;
uint32_t __blockedTasksBM = 0U;

void idle() {
    while(1);
}

NORTOS_Task __idleTask;

void NORTOS_AddTask(NORTOS_Task* taskFrame, NORTOS_TaskHwnd hwnd, void* stack, uint16_t _stackSize, uint16_t priority) {
    OSASSERT((priority <= MAX_TASKS));
    OSASSERT(__init);
    uint32_t stackSize = _stackSize;

    OSASSERT((stackSize >= 17));

    uint32_t *sp __attribute__((aligned(8))) = (uint32_t*) ((uint32_t)stack + stackSize);

    *(--sp) = (1U << 24);                        //xPSR
    *(--sp) = (uint32_t) hwnd;                   //PC
    //The rest of the stack frame
    sp -= 14U;

    taskFrame->sp = sp;
    __readyTasksBM |= (1 << (uint32_t)priority);
    taskFrame->delay = 0U;
    taskFrame->priority = priority;

    uint32_t* stackBottom __attribute__((aligned(8))) = (uint32_t*)(uint32_t)stack;

    while(--sp >= stackBottom + 1 )
        *sp = 0x00000000;

    OSASSERT((__tasksCount < MAX_TASKS));

    OSASSERT((__taskArr[priority] == ((NORTOS_Task *)0)));
    __taskArr[priority] = taskFrame;
    __tasksCount++;
}

void NORTOS_Init(void* stack, uint16_t idleStackSize) {
    __init = true;

    NORTOS_AddTask(&__idleTask, idle, stack, idleStackSize, MAX_TASKS);

    //set PendSV to the lowest priority.
    *(uint32_t volatile*) 0xE000ED20 |= (0xFFU << 16);
}

void NORTOS_ContextSwitcher() {
    __nextTask = __taskArr[__getHPTask(__readyTasksBM)];

    if(__currentTask != __nextTask)
        *(uint32_t volatile*)0xE000ED04 = (1U << 28);
}

void NORTOS_Run() {
    NORTOS_ContextSwitcher();
    OSASSERT(false);
}

__attribute__ ((naked)) void PendSV_Handler(void) {
    __asm volatile (
            "  CPSID    I                               \n"
            /* check if there is a current task for which the sp must be saved */
            "  LDR	r1,=__currentTask               \n"
            "  LDR	r1,[r1]                         \n"
            /* if not, jump to InitState */
            "  CBZ	r1,InitState                    \n"
            /* else, push the regs to the stack and save the current stack pointer to the task object */
            "  PUSH	{r4-r11}                        \n"
            "  LDR	r1,=__currentTask               \n"
            "  LDR	r1,[r1]                         \n"
            "  STR	sp,[r1]                         \n"
            "InitState:                                 \n"
            /* set the machine sp to the sp of the __nextStack */
            "  LDR	r1,=__nextTask                  \n"
            "  LDR	r1,[r1]                         \n"
            "  LDR	sp,[r1]                         \n"
            /* perform the context switching */
            "  LDR	r1,=__nextTask                  \n"
            "  LDR	r1,[r1]                         \n"
            "  LDR	r2,=__currentTask               \n"
            "  STR	r1,[r2]                         \n"
            /* pop the registers back, re-enable the ints and return */
            "  POP	{r4-r11}                        \n"
            "  CPSIE    I                               \n"
            "  BX	lr                              \n"
            );
}


void NORTOS_Delay(uint16_t delay) {
    __asm ("cpsid i");
    __readyTasksBM &= (uint32_t)~(1 << __currentTask->priority);
    __blockedTasksBM |=  (uint32_t)(1 << __currentTask->priority);

    OSASSERT((__readyTasksBM & (1 << MAX_TASKS)))

    __taskArr[__currentTask->priority]->delay = delay;
    NORTOS_ContextSwitcher();
    __asm ("cpsie i");
}

void SysTick_Handler() {
    uint32_t temp = __blockedTasksBM;

    while(temp != 0) {
        NORTOS_Task *task = __taskArr[__getHPTask(temp)];
        task->delay --;

        if(task->delay == 0) {
            __readyTasksBM |= (uint32_t)(1 << task->priority);
            __blockedTasksBM &= (uint32_t)~(1 << task->priority);
        }

        temp &= ~(1 << task->priority);
    }
    __asm ("cpsid i");
    NORTOS_ContextSwitcher();
    __asm ("cpsie i");
}

__attribute__ ((naked, noreturn)) void OSAssertFailed(char const *file, int line) {
    __asm volatile (
            /* disable the systick timer as it will transfer the execution to the OS */
            "  MOV r2, #0xE000E000  \n"
            "  LDR r3, [r4, #0x10]  \n"
            "  MOV r4, #0x00        \n"
            "  STR r4, [r2, #0x10]  \n"
            "  BKPT              1  \n"
            /* infinite loop */
            "  inf:                 \n"
            "  NOP                  \n"
            "  B inf                \n"
            );
}

__attribute__ ((naked)) uint8_t __getHPTask(uint32_t param) {
    __asm volatile (
            "MOV   r1, r0                   \n"
            "RBIT  r2, r1                   \n"
            "CLZ   r0, r2                   \n"
            "BX lr                          \n"
            );
}
