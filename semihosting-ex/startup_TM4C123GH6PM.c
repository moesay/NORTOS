extern int __stack_end__;

__attribute__ ((naked, noreturn)) void assert_failed(char const *module, int loc);

void Default_Handler(void);
void Reset_Handler(void);
void SystemInit(void);

void NMI_Handler        (void) __attribute__ ((weak, noreturn));
void HardFault_Handler  (void) __attribute__ ((weak));
void MemManage_Handler  (void) __attribute__ ((weak));
void BusFault_Handler   (void) __attribute__ ((weak));
void UsageFault_Handler (void) __attribute__ ((weak));

void SVC_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));

void GPIOPortA_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortB_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortC_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortD_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortE_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMFault_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen0_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen1_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen2_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq0_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq1_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq2_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq3_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Watchdog_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp0_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp1_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp2_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SysCtrl_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void FlashCtrl_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortF_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortG_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortH_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI1_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI1_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Hibernate_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen3_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAST_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAError_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq0_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq1_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq2_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq3_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortJ_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortK_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortL_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI2_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI3_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART6_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART7_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5A_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5B_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5A_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5B_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C4_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C5_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortM_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortN_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI2_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP0_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP1_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP2_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP3_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP4_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP5_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP6_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP7_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ0_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ1_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ2_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ3_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ4_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ5_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ6_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ7_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortR_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortS_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen0_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen1_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen2_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen3_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Fault_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));



__attribute__ ((section(".isr_vector")))
int const vecTable[] = {
    (int)&__stack_end__,          /* Top of Stack                 */
    (int)&Reset_Handler,          /* Reset Handler                */
    (int)&NMI_Handler,            /* NMI Handler                  */
    (int)&HardFault_Handler,      /* Hard Fault Handler           */
    (int)&MemManage_Handler,      /* The MPU fault handler        */
    (int)&BusFault_Handler,       /* The bus fault handler        */
    (int)&UsageFault_Handler,     /* The usage fault handler      */
    0,                            /* Reserved                     */
    0,                            /* Reserved                     */
    0,                            /* Reserved                     */
    0,                            /* Reserved                     */
    (int)&SVC_Handler,            /* SVCall handler               */
    (int)&DebugMon_Handler,       /* Debug monitor handler        */
    0,                            /* Reserved                     */
    (int)&PendSV_Handler,         /* The PendSV handler           */
    (int)&SysTick_Handler,        /* The SysTick handler          */

    /*IRQ handlers... */
    (int)&GPIOPortA_Handler,   /* GPIO Port A                     */
    (int)&GPIOPortB_Handler,   /* GPIO Port B                     */
    (int)&GPIOPortC_Handler,   /* GPIO Port C                     */
    (int)&GPIOPortD_Handler,   /* GPIO Port D                     */
    (int)&GPIOPortE_Handler,   /* GPIO Port E                     */
    (int)&UART0_Handler,       /* UART0 Rx and Tx                 */
    (int)&UART1_Handler,       /* UART1 Rx and Tx                 */
    (int)&SSI0_Handler,        /* SSI0 Rx and Tx                  */
    (int)&I2C0_Handler,        /* I2C0 Master and Slave           */
    (int)&PWMFault_Handler,    /* PWM Fault                       */
    (int)&PWMGen0_Handler,     /* PWM Generator 0                 */
    (int)&PWMGen1_Handler,     /* PWM Generator 1                 */
    (int)&PWMGen2_Handler,     /* PWM Generator 2                 */
    (int)&QEI0_Handler,        /* Quadrature Encoder 0            */
    (int)&ADCSeq0_Handler,     /* ADC Sequence 0                  */
    (int)&ADCSeq1_Handler,     /* ADC Sequence 1                  */
    (int)&ADCSeq2_Handler,     /* ADC Sequence 2                  */
    (int)&ADCSeq3_Handler,     /* ADC Sequence 3                  */
    (int)&Watchdog_Handler,    /* Watchdog timer                  */
    (int)&Timer0A_Handler,     /* Timer 0 subtimer A              */
    (int)&Timer0B_Handler,     /* Timer 0 subtimer B              */
    (int)&Timer1A_Handler,     /* Timer 1 subtimer A              */
    (int)&Timer1B_Handler,     /* Timer 1 subtimer B              */
    (int)&Timer2A_Handler,     /* Timer 2 subtimer A              */
    (int)&Timer2B_Handler,     /* Timer 2 subtimer B              */
    (int)&Comp0_Handler,       /* Analog Comparator 0             */
    (int)&Comp1_Handler,       /* Analog Comparator 1             */
    (int)&Comp2_Handler,       /* Analog Comparator 2             */
    (int)&SysCtrl_Handler,     /* System Control (PLL, OSC, BO)   */
    (int)&FlashCtrl_Handler,   /* FLASH Control                   */
    (int)&GPIOPortF_Handler,   /* GPIO Port F                     */
    (int)&GPIOPortG_Handler,   /* GPIO Port G                     */
    (int)&GPIOPortH_Handler,   /* GPIO Port H                     */
    (int)&UART2_Handler,       /* UART2 Rx and Tx                 */
    (int)&SSI1_Handler,        /* SSI1 Rx and Tx                  */
    (int)&Timer3A_Handler,     /* Timer 3 subtimer A              */
    (int)&Timer3B_Handler,     /* Timer 3 subtimer B              */
    (int)&I2C1_Handler,        /* I2C1 Master and Slave           */
    (int)&QEI1_Handler,        /* Quadrature Encoder 1            */
    (int)&CAN0_Handler,        /* CAN0                            */
    (int)&CAN1_Handler,        /* CAN1                            */
    (int)&CAN2_Handler,        /* CAN2                            */
    0,                         /* Reserved                        */
    (int)&Hibernate_Handler,   /* Hibernate                       */
    (int)&USB0_Handler,        /* USB0                            */
    (int)&PWMGen3_Handler,     /* PWM Generator 3                 */
    (int)&uDMAST_Handler,      /* uDMA Software Transfer          */
    (int)&uDMAError_Handler,   /* uDMA Error                      */
    (int)&ADC1Seq0_Handler,    /* ADC1 Sequence 0                 */
    (int)&ADC1Seq1_Handler,    /* ADC1 Sequence 1                 */
    (int)&ADC1Seq2_Handler,    /* ADC1 Sequence 2                 */
    (int)&ADC1Seq3_Handler,    /* ADC1 Sequence 3                 */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    (int)&GPIOPortJ_Handler,   /* GPIO Port J                     */
    (int)&GPIOPortK_Handler,   /* GPIO Port K                     */
    (int)&GPIOPortL_Handler,   /* GPIO Port L                     */
    (int)&SSI2_Handler,        /* SSI2 Rx and Tx                  */
    (int)&SSI3_Handler,        /* SSI3 Rx and Tx                  */
    (int)&UART3_Handler,       /* UART3 Rx and Tx                 */
    (int)&UART4_Handler,       /* UART4 Rx and Tx                 */
    (int)&UART5_Handler,       /* UART5 Rx and Tx                 */
    (int)&UART6_Handler,       /* UART6 Rx and Tx                 */
    (int)&UART7_Handler,       /* UART7 Rx and Tx                 */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    (int)&I2C2_Handler,        /* I2C2 Master and Slave           */
    (int)&I2C3_Handler,        /* I2C3 Master and Slave           */
    (int)&Timer4A_Handler,     /* Timer 4 subtimer A              */
    (int)&Timer4B_Handler,     /* Timer 4 subtimer B              */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    (int)&Timer5A_Handler,     /* Timer 5 subtimer A              */
    (int)&Timer5B_Handler,     /* Timer 5 subtimer B              */
    (int)&WideTimer0A_Handler, /* Wide Timer 0 subtimer A         */
    (int)&WideTimer0B_Handler, /* Wide Timer 0 subtimer B         */
    (int)&WideTimer1A_Handler, /* Wide Timer 1 subtimer A         */
    (int)&WideTimer1B_Handler, /* Wide Timer 1 subtimer B         */
    (int)&WideTimer2A_Handler, /* Wide Timer 2 subtimer A         */
    (int)&WideTimer2B_Handler, /* Wide Timer 2 subtimer B         */
    (int)&WideTimer3A_Handler, /* Wide Timer 3 subtimer A         */
    (int)&WideTimer3B_Handler, /* Wide Timer 3 subtimer B         */
    (int)&WideTimer4A_Handler, /* Wide Timer 4 subtimer A         */
    (int)&WideTimer4B_Handler, /* Wide Timer 4 subtimer B         */
    (int)&WideTimer5A_Handler, /* Wide Timer 5 subtimer A         */
    (int)&WideTimer5B_Handler, /* Wide Timer 5 subtimer B         */
    (int)&FPU_Handler,         /* FPU                             */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    (int)&I2C4_Handler,        /* I2C4 Master and Slave           */
    (int)&I2C5_Handler,        /* I2C5 Master and Slave           */
    (int)&GPIOPortM_Handler,   /* GPIO Port M                     */
    (int)&GPIOPortN_Handler,   /* GPIO Port N                     */
    (int)&QEI2_Handler,        /* Quadrature Encoder 2            */
    0,                         /* Reserved                        */
    0,                         /* Reserved                        */
    (int)&GPIOPortP0_Handler,  /* GPIO Port P (Summary or P0)     */
    (int)&GPIOPortP1_Handler,  /* GPIO Port P1                    */
    (int)&GPIOPortP2_Handler,  /* GPIO Port P2                    */
    (int)&GPIOPortP3_Handler,  /* GPIO Port P3                    */
    (int)&GPIOPortP4_Handler,  /* GPIO Port P4                    */
    (int)&GPIOPortP5_Handler,  /* GPIO Port P5                    */
    (int)&GPIOPortP6_Handler,  /* GPIO Port P6                    */
    (int)&GPIOPortP7_Handler,  /* GPIO Port P7                    */
    (int)&GPIOPortQ0_Handler,  /* GPIO Port Q (Summary or Q0)     */
    (int)&GPIOPortQ1_Handler,  /* GPIO Port Q1                    */
    (int)&GPIOPortQ2_Handler,  /* GPIO Port Q2                    */
    (int)&GPIOPortQ3_Handler,  /* GPIO Port Q3                    */
    (int)&GPIOPortQ4_Handler,  /* GPIO Port Q4                    */
    (int)&GPIOPortQ5_Handler,  /* GPIO Port Q5                    */
    (int)&GPIOPortQ6_Handler,  /* GPIO Port Q6                    */
    (int)&GPIOPortQ7_Handler,  /* GPIO Port Q7                    */
    (int)&GPIOPortR_Handler,   /* GPIO Port R                     */
    (int)&GPIOPortS_Handler,   /* GPIO Port S                     */
    (int)&PWM1Gen0_Handler,    /* PWM 1 Generator 0               */
    (int)&PWM1Gen1_Handler,    /* PWM 1 Generator 1               */
    (int)&PWM1Gen2_Handler,    /* PWM 1 Generator 2               */
    (int)&PWM1Gen3_Handler,    /* PWM 1 Generator 3               */
    (int)&PWM1Fault_Handler,   /* PWM 1 Fault                     */
};



void Reset_Handler(void) {
    extern int main(void);
    extern int __libc_init_array(void);
    extern unsigned __data_start;
    extern unsigned __data_end__;
    extern unsigned const __data_load;
    extern unsigned __bss_start__;
    extern unsigned __bss_end__;
    extern void software_init_hook(void) __attribute__((weak));

    unsigned const *src;
    unsigned *dst;

    SystemInit();

    /* copy the data segment initializers from flash to SRAM */
    src = &__data_load;
    for (dst = &__data_start; dst < &__data_end__; ++dst, ++src) {
        *dst = *src;
    }

    /* zero fill the .bss segment in RAM*/
    for (dst = &__bss_start__; dst < &__bss_end__; ++dst) {
        *dst = 0;
    }

    /* RTOS init_hook check */
    if (&software_init_hook != (void (*)(void))(0)) {
        software_init_hook();
    }
    else {
#ifdef __cplusplus
        __libc_init_array();
#endif
        (void)main();
    }

    assert_failed("Reset_Handler", __LINE__);
}


__attribute__((naked)) void NMI_Handler(void);
void NMI_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_nmi\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_nmi: .asciz \"NMI\"\n"
            "  .align 2\n"
            );
}

__attribute__((naked)) void MemManage_Handler(void);
void MemManage_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_mem\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_mem: .asciz \"MemManage\"\n"
            "  .align 2\n"
            );
}

__attribute__((naked)) void HardFault_Handler(void);
void HardFault_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_hrd\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_hrd: .asciz \"HardFault\"\n"
            "  .align 2\n"
            );
}

__attribute__((naked)) void BusFault_Handler(void);
void BusFault_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_bus\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_bus: .asciz \"BusFault\"\n"
            "  .align 2\n"
            );
}

__attribute__((naked)) void UsageFault_Handler(void);
void UsageFault_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_usage\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_usage: .asciz \"UsageFault\"\n"
            "  .align 2\n"
            );
}

__attribute__((naked)) void Default_Handler(void);
void Default_Handler(void) {
    __asm volatile (
            "    ldr r0,=str_dflt\n"
            "    mov r1,#1\n"
            "    b assert_failed\n"
            "str_dflt: .asciz \"Default\"\n"
            "  .align 2\n"
            );
}

__attribute__ ((naked, noreturn))
    void assert_failed(char const *module, int loc) {
        /* re-set the SP */
        __asm volatile (
                "  MOV sp,%0\n"
                /* disable the systick timer */
                "  MOV r2, #0xE000E000\n"
                "  LDR r3, [r4, #0x10]\n"
                "  MOV r4, #0x00\n"
                "  STR r4, [r2, #0x10]\n"
                /* infinite loop */
                "  inf:\n"
                "  NOP\n"
                "  B inf\n"
                : : "r" (&__stack_end__));
    }
