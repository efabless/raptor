.syntax unified
    .arch armv6-m
    .code 16


    .section .stack
    .align 3
    .equ    Stack_Size, 0x1000
    .global    __StackTop
    .global    __StackLimit

//    __StackLimit:
//    .space    Stack_Size
//    .size __StackLimit, . - __StackLimit
//    __StackTop:
//    .size __StackTop, . - __StackTop


    .section .heap
    .align 3

    .equ    Heap_Size, 0
    .global    __HeapBase
    .global    __HeapLimit
    __HeapBase:
    .if    Heap_Size
    .space    Heap_Size
    .endif
    .size __HeapBase, . - __HeapBase
    __HeapLimit:
    .size __HeapLimit, . - __HeapLimit


    /* Vector Table */

    .section .isr_vector
    .align 2
    .global __isr_vector
    __isr_vector:
    .long   __StackTop                 /* Top of Stack                  */
    .long   Reset_Handler              /* Reset Handler                 */
    .long   NMI_Handler                /* NMI Handler                   */
    .long   HardFault_Handler          /* Hard Fault Handler            */
    .long   MemManage_Handler          /* Reserved                      */
    .long   BusFault_Handler           /* Reserved                      */
    .long   UsageFault_Handler         /* Reserved                      */
    .long   0                          /* Reserved                      */
    .long   0                          /* Reserved                      */
    .long   0                          /* Reserved                      */
    .long   0                          /* Reserved                      */
    .long   SVC_Handler                /* SVCall Handler                */
    .long   DebugMon_Handler           /* Debug Monitor Handler         */
    .long   0                          /* Reserved                      */
    .long   PendSV_Handler             /* PendSV Handler                */
    .long   SysTick_Handler            /* SysTick Handler               */

    /* External Interrupts */
    .long   UART_Handler
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0
    .long   0

    .size    __isr_vector, . - __isr_vector



    /* Reset Handler */
    .text
    .thumb
    .thumb_func
    .align 2
    .global    Reset_Handler
    .type    Reset_Handler, %function
    Reset_Handler:
    //ldr    r1, =0xE000E100
    //ldr    r0, =0x00000001
    //str    r0, [r1]
    ldr     r0, =0x0
    // Initialise core registers to avoid problems with X in simulation
    ldr r1, =__StackTop
    mov sp, r1
    mov r1, r0
    mov r2, r0

    mov r4, r0
    mov r5, r0
    mov r6, r0
    mov r7, r0
    mov r8, r0
    mov r9, r0

    // ldr r1, =0x80000004
    // str r0, [r1]
    // ldr r1, =0x80000000
    // ldr r0, =#1
    // str r0, [r1]

    // copy data section
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata
    cmp r1, r2
    bhs end_init
    loop_init:
    ldr r3, [r0]
    str r3, [r1]
    adds r0, #1
    adds r1, #1
    cmp r1, r2
    blo loop_init
    end_init:

    ldr r0,=main
    bx r0
    // b   main
    ldr r1, =0x80000004
    str r0, [r1]
    ldr r1, =0x80000000
    ldr r0, =#9
    str r0, [r1]
    b   .


    .thumb
    .thumb_func
    .align 2
    .global    Hard_Fault_Handler
    .type    Hard_Fault_Handler, %function
    Hard_Fault_Handler:
        ldr r1, =0x80000004
        str r0, [r1]
        ldr r1, =0x80000000
        ldr r0, =#9
        str r0, [r1]
        b .

    .pool
    .size Reset_Handler, . - Reset_Handler

    /*    Macro to define default handlers. Default handler
    *    will be weak symbol and just dead loops. They can be
    *    overwritten by other handlers */
    .macro    def_default_handler    handler_name
    .align 1
    .thumb_func
    .weak    \handler_name
    .type    \handler_name, %function
    \handler_name :
        ldr r1, =0x80000004
        str r0, [r1]
        ldr r1, =0x80000000
        ldr r0, =#9
        str r0, [r1]
        b .
    .size    \handler_name, . - \handler_name
    .endm

    //System Exception Handlers

    def_default_handler    NMI_Handler
    def_default_handler    HardFault_Handler
    def_default_handler    MemManage_Handler
    def_default_handler    BusFault_Handler
    def_default_handler    UsageFault_Handler
    def_default_handler    SVC_Handler
    def_default_handler    DebugMon_Handler
    def_default_handler    PendSV_Handler
    def_default_handler    SysTick_Handler

    //IRQ Handlers

    def_default_handler    UARTRX0_Handler
    def_default_handler    UARTTX0_Handler
    def_default_handler    UARTRX1_Handler
    def_default_handler    UARTTX1_Handler
    def_default_handler    UARTRX2_Handler
    def_default_handler    UARTTX2_Handler
    def_default_handler    PORT0_COMB_Handler
    def_default_handler    PORT1_COMB_Handler
    def_default_handler    TIMER0_Handler
    def_default_handler    TIMER1_Handler
    def_default_handler    DUALTIMER_HANDLER
    def_default_handler    SPI_ALL_Handler
    def_default_handler    UARTOVF_Handler
    def_default_handler    ETHERNET_Handler
    def_default_handler    I2S_Handler
    def_default_handler    DMA_Handler
    def_default_handler    PORT0_0_Handler
    def_default_handler    PORT0_1_Handler
    def_default_handler    PORT0_2_Handler
    def_default_handler    PORT0_3_Handler
    def_default_handler    PORT0_4_Handler
    def_default_handler    PORT0_5_Handler
    def_default_handler    PORT0_6_Handler
    def_default_handler    PORT0_7_Handler
    def_default_handler    PORT0_8_Handler
    def_default_handler    PORT0_9_Handler
    def_default_handler    PORT0_10_Handler
    def_default_handler    PORT0_11_Handler
    def_default_handler    PORT0_12_Handler
    def_default_handler    PORT0_13_Handler
    def_default_handler    PORT0_14_Handler
    def_default_handler    PORT0_15_Handler

    def_default_handler     UART_Handler



    .end
