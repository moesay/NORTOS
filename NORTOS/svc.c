#include "svc.h"

NORTOS_SysCallHwnd __syscallArr[32];

void NORTOS_RegSysCall(NORTOS_SysCallHwnd syscall, uint8_t id) {
    OSASSERT((id <= 32));
    __syscallArr[id] = syscall;
}

__attribute__((naked)) void SVC_Handler() {
    __asm volatile (
            "TST    lr, #4              \n"
            "ITE    EQ                  \n"
            "MRSEQ  r0, msp             \n"
            "MRSNE  r0, psp             \n"

            "ADDS   r0, #24             \n"
            "LDR    r0, [r0, #0]        \n"
            "SUBS   r0, #2              \n"
            "LDRB   r0, [r0, #0]        \n"

            "LDR    r1, =__syscallArr   \n"
            "MOV    r2, #4              \n"
            "MUL    r0, r2              \n"
            "ADD    r1, r0              \n"
            "LDR    r1, [r1]            \n"
            "CMP    r1, #0              \n"
            "IT     NE                  \n"
            "MOVNE  pc, r1              \n"
            "BEQ    OSAssertFailed      \n"
            );
}
