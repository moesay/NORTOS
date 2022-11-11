#ifndef NORTOS_SVC_H
#define NORTOS_SVC_H
#include <stdint.h>
#include "nortos.h"

#define NORTOS_SysCall(sNum) __asm volatile("SVC %0" ::"M" (sNum))

typedef void (*NORTOS_SysCallHwnd)();
extern NORTOS_SysCallHwnd __syscallArr[32];

void NORTOS_RegSysCall(NORTOS_SysCallHwnd, uint8_t);
#endif
