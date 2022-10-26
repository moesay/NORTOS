#ifndef MUTEX_H
#define MUTEX_H

#include "nortos.h"

#define MUT_UNLOCKED 0
#define MUT_LOCKED   1

typedef uint32_t NORTOS_Mutex;

__attribute__ ((naked)) void NORTOS_mutexLock(NORTOS_Mutex*);
__attribute__ ((naked)) void NORTOS_mutexUnlock(NORTOS_Mutex*);

#endif
