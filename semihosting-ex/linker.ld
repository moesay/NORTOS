/*  NORTOS PROJECT
 *
 *      File: linker.ld
 *      Author: Mohamed ElSayed
 *      email: m.elsayed4420@gmail.com
 * */

ENTRY(Reset_Handler)

STACK_SIZE = 1024;
HEAP_SIZE = 256;

MEMORY {
    FLASH(rx): ORIGIN = 0x00000000, LENGTH = 256K
    SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 32K
}

SECTIONS {
    .text : {
        KEEP(*(.isr_vector))
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata*)
        *(.init)
        *(.fini)
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    .stack : {
        __stack_start__ = .;
        . = . + STACK_SIZE;
        . = ALIGN(4);
        __stack_end__ = .;
    } >SRAM

    .data : AT(_etext) {
        __data_load = LOADADDR (.data);
        __data_start = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        __data_end__ = .;
    }

    .bss : {
        __bss_start__ = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > SRAM

    .heap : {
        __heap_start__ = .;
        . = . + HEAP_SIZE;
        . = ALIGN(4);
        __heap_end__ = .;
        PROVIDE(end = __heap_end__);
    } >SRAM
}
