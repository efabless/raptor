/* vectors.s */
;@ .cpu cortex-m0
.thumb

.word   0x20004000  /* stack top address */
.word   0x00000100      /* 1 Reset */
.word   hang        /* 2 NMI */
.word   hang        /* 3 HardFault */
.word   hang        /* 4 MemManage */
.word   hang        /* 5 BusFault */
.word   hang        /* 6 UsageFault */
.word   hang        /* 7 RESERVED */
.word   hang        /* 8 RESERVED */
.word   hang        /* 9 RESERVED*/
.word   hang        /* 10 RESERVED */
.word   hang        /* 11 SVCall */
.word   hang        /* 12 Debug Monitor */
.word   hang        /* 13 RESERVED */
.word   hang        /* 14 PendSV */
.word   hang        /* 15 SysTick */
.word   hang        /* 16 External Interrupt(0) */
.word   hang        /* 17 External Interrupt(1) */
.word   hang        /* 18 External Interrupt(2) */
.word   hang        /* 19 ...   */


.thumb_func
hang:   b .

.org 0x100
.thumb_func
.global _start
_start:
    ldr     r1, =0x20001000
    ldr     r2, =0x80000000
    ldr     r3, =0x80000004
    
    ldr     r0, =0
    str     r0, [r3]

    ldr     r0, =3
    str     r0, [r2]

    ldr     r0, =5
    str     r0, [r1]
    ldr     r0, [r1]

    str     r0, [r2]
     
    b .

.end
