#include <mutex.h>

__attribute__ ((naked)) void NORTOS_mutexLock(NORTOS_Mutex* mutex) {
    __asm volatile (
            //the mutex object lives in the .bss so its 0 by default, which means unlocked.
            "MOV r1, #1          \n"
            "mutUnlocked:        \n"
            //read the mutex object exclusively.
            "LDREX r2, [r0]      \n"
            //check its state.
            "CMP r2, r1          \n"
            //if the mutex is locked, jump to mutLocked.
            "BEQ mutLocked       \n"
            "ITTE NE             \n"
            //else, try to lock it.
            "STREXNE r2, r1, [r0]\n"
            //using the exc monitor to check if the strexe failed or not.
            "CMPNE r2, #1        \n"
            //if failed, retry. BLOCKING.
            "BEQ mutUnlocked     \n"
            "DMB                 \n"
            "BX lr               \n"
            "mutLocked:          \n"
            "WFE                 \n"
            "B mutUnlocked       \n"
            );
}

__attribute__ ((naked))void NORTOS_mutexUnlock(NORTOS_Mutex* mutex) {
    __asm volatile (
            "MOV r1, #0          \n"
            //to unmonitor the mutex after its released.
            "DMB                 \n"
            //unlock the mutex.
            "STR r1, [r0]        \n"
            //re-sync the memory access after dmb.
            "DSB                 \n"
            //signal the unlocking.
            "SEV                 \n"
            "BX lr               \n"
            );
}
