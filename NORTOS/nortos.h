/*  NORTOS PROJECT
 *
 *      File: nortos.h
 *      Author: Mohamed ElSayed
 *      email: m.elsayed4420@gmail.com
 * */

#ifndef NORTOS_H
#define NORTOS_H

#include <stdint.h>
#include <stdbool.h>

#define DEBUG

#ifdef DEBUG
#define OSASSERT(expr)					\
    if(!expr)							\
    OSAssertFailed(__FILE__, __LINE__);
#endif

typedef struct {
    void *sp;
    volatile uint16_t delay;
    uint16_t priority;
} NORTOS_Task;

typedef void (*NORTOS_TaskHwnd)();
void NORTOS_AddTask(NORTOS_Task*, NORTOS_TaskHwnd, void*, uint16_t, uint16_t);
void NORTOS_Init(void*, uint16_t);
void NORTOS_ContextSwitcher();
void NORTOS_Run();
void NORTOS_Delay(uint16_t);
extern void OnStartup();
__attribute__ ((naked, noreturn)) extern void OSAssertFailed(char const *, int);
__attribute__ ((naked)) uint8_t __getHPTask(uint32_t);

#endif
