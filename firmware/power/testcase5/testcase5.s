	.cpu cortex-m0
	.eabi_attribute 20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute 21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute 23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute 24, 1	@ Tag_ABI_align8_needed
	.eabi_attribute 25, 1	@ Tag_ABI_align8_preserved
	.eabi_attribute 26, 1	@ Tag_ABI_enum_size
	.eabi_attribute 30, 1	@ Tag_ABI_optimization_goals
	.eabi_attribute 34, 0	@ Tag_CPU_unaligned_access
	.eabi_attribute 18, 4	@ Tag_ABI_PCS_wchar_t
	.file	"testcase5.c"
@ GNU C11 (15:6.3.1+svn253039-1build1) version 6.3.1 20170620 (arm-none-eabi)
@	compiled by GNU C version 7.2.0, GMP version 6.1.2, MPFR version 4.0.1-rc1, MPC version 1.1.0, isl version 0.15
@ warning: MPFR header version 4.0.1-rc1 differs from library version 4.0.1.
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -imultilib thumb/v6-m -D__USES_INITFINI__ testcase5.c
@ -mcpu=cortex-m0 -mthumb -auxbase-strip testcase5.s -g -O1 -Wall
@ -Wno-unused-value -ffreestanding -fverbose-asm
@ options enabled:  -faggressive-loop-optimizations -fauto-inc-dec
@ -fbranch-count-reg -fchkp-check-incomplete-type -fchkp-check-read
@ -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
@ -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
@ -fchkp-use-static-const-bounds -fchkp-use-wrappers
@ -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
@ -fdefer-pop -fdelete-null-pointer-checks -fdwarf2-cfi-asm
@ -fearly-inlining -feliminate-unused-debug-types -fforward-propagate
@ -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique
@ -fguess-branch-probability -fident -fif-conversion -fif-conversion2
@ -finline -finline-atomics -finline-functions-called-once -fipa-profile
@ -fipa-pure-const -fipa-reference -fira-hoist-pressure
@ -fira-share-save-slots -fira-share-spill-slots -fivopts
@ -fkeep-static-consts -fleading-underscore -flifetime-dse
@ -flto-odr-type-merging -fmath-errno -fmerge-constants
@ -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
@ -fpeephole -fplt -fprefetch-loop-arrays -freg-struct-return
@ -freorder-blocks -fsched-critical-path-heuristic
@ -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
@ -fsched-last-insn-heuristic -fsched-pressure -fsched-rank-heuristic
@ -fsched-spec -fsched-spec-insn-heuristic -fsched-stalled-insns-dep
@ -fsection-anchors -fsemantic-interposition -fshow-column -fshrink-wrap
@ -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop
@ -fssa-phiopt -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls
@ -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
@ -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
@ -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
@ -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
@ -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pta
@ -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra
@ -ftree-ter -funit-at-a-time -fvar-tracking -fvar-tracking-assignments
@ -fverbose-asm -fzero-initialized-in-bss -mlittle-endian
@ -mpic-data-is-text-relative -msched-prolog -mthumb
@ -mvectorize-with-neon-quad

	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	1
	.global	main
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
.LFB0:
	.file 1 "testcase5.c"
	.loc 1 11 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}	@
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
.LVL0:
	.loc 1 19 0
	ldr	r2, .L10	@ tmp154,
	ldr	r3, .L10+4	@ tmp155,
	cmp	r2, r3	@ tmp154, tmp155
	bcs	.L2	@,
	ldr	r3, .L10+8	@ tmp159,
	ldr	r2, .L10+4	@ tmp157,
	adds	r2, r2, #3	@ tmp156,
	subs	r2, r2, r3	@ tmp158, tmp156, tmp159
	lsrs	r2, r2, #2	@ tmp160, tmp158,
	adds	r2, r2, #1	@ tmp161,
	lsls	r2, r2, #2	@ _43, tmp161,
	movs	r3, #0	@ ivtmp.17,
	.loc 1 20 0
	ldr	r0, .L10	@ tmp163,
	ldr	r1, .L10+12	@ tmp165,
.LVL1:
.L3:
	ldr	r4, [r1, r3]	@ tmp178, MEM[symbol: _sidata, index: ivtmp.17_34, offset: 0B]
	str	r4, [r0, r3]	@ tmp178, MEM[symbol: _sdata, index: ivtmp.17_34, offset: 0B]
	adds	r3, r3, #4	@ ivtmp.17,
.LVL2:
	.loc 1 19 0
	cmp	r3, r2	@ ivtmp.17, _43
	bne	.L3	@,
.LVL3:
.L2:
	.loc 1 24 0
	ldr	r2, .L10+16	@ tmp167,
	ldr	r3, .L10+20	@ tmp168,
	cmp	r2, r3	@ tmp167, tmp168
	bcs	.L4	@,
	movs	r3, r2	@ ivtmp.14, tmp167
	mvns	r2, r2	@ tmp172, ivtmp.14
	ldr	r1, .L10+20	@ tmp170,
	adds	r2, r2, r1	@ tmp171, tmp172, tmp170
	movs	r1, #3	@ tmp174,
	bics	r2, r1	@ tmp173, tmp174
	adds	r2, r2, #4	@ tmp175,
	adds	r2, r2, r3	@ _33, tmp175, ivtmp.14
	.loc 1 25 0
	movs	r1, #0	@ tmp177,
.LVL4:
.L5:
	stmia	r3!, {r1}	@ MEM[base: _8, offset: 0B], tmp177
.LVL5:
	.loc 1 24 0
	cmp	r3, r2	@ ivtmp.14, _33
	bne	.L5	@,
.LVL6:
.L4:
	.loc 1 28 0
	movs	r0, #0	@,
	bl	gpio_set_dir	@
.LVL7:
	.loc 1 29 0
	movs	r0, #15	@,
	bl	gpio_write	@
.LVL8:
	ldr	r3, .L10+24	@ ivtmp_6,
.LVL9:
.L6:
	subs	r3, r3, #1	@ ivtmp_6,
.LVL10:
	.loc 1 31 0 discriminator 3
	cmp	r3, #0	@ ivtmp_6,
	bne	.L6	@,
	.loc 1 32 0
	@ sp needed	@
	pop	{r4, pc}
.L11:
	.align	2
.L10:
	.word	_sdata
	.word	_edata
	.word	_sdata+4
	.word	_sidata
	.word	_sbss
	.word	_ebss
	.word	70000
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.comm	CLKCTRL_CLKCR,4,4
	.comm	CLKCTRL_PLLTR,4,4
	.comm	CLKCTRL_PLLCR,4,4
.Letext0:
	.file 2 "../../sw/clkctrl.h"
	.file 3 "../../raptor.h"
	.file 4 "../../sw/gpio_drv.h"
	.file 5 "/usr/lib/gcc/arm-none-eabi/6.3.1/include/stdint-gcc.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x187
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF21
	.byte	0xc
	.4byte	.LASF22
	.4byte	.LASF23
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x3
	.4byte	.LASF24
	.byte	0x5
	.byte	0x34
	.4byte	0x5a
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x5
	.4byte	0x6f
	.uleb128 0x6
	.4byte	.LASF9
	.byte	0x2
	.byte	0xb
	.4byte	0x92
	.uleb128 0x5
	.byte	0x3
	.4byte	CLKCTRL_PLLCR
	.uleb128 0x7
	.byte	0x4
	.4byte	0x76
	.uleb128 0x8
	.4byte	0x8c
	.uleb128 0x6
	.4byte	.LASF10
	.byte	0x2
	.byte	0xc
	.4byte	0x92
	.uleb128 0x5
	.byte	0x3
	.4byte	CLKCTRL_PLLTR
	.uleb128 0x6
	.4byte	.LASF11
	.byte	0x2
	.byte	0xd
	.4byte	0x92
	.uleb128 0x5
	.byte	0x3
	.4byte	CLKCTRL_CLKCR
	.uleb128 0x9
	.4byte	.LASF12
	.byte	0x3
	.byte	0x17
	.4byte	0x4f
	.uleb128 0x9
	.4byte	.LASF13
	.byte	0x1
	.byte	0x4
	.4byte	0x5a
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x1
	.byte	0x5
	.4byte	0x5a
	.uleb128 0x9
	.4byte	.LASF15
	.byte	0x1
	.byte	0x6
	.4byte	0x5a
	.uleb128 0x9
	.4byte	.LASF16
	.byte	0x1
	.byte	0x7
	.4byte	0x5a
	.uleb128 0x9
	.4byte	.LASF17
	.byte	0x1
	.byte	0x8
	.4byte	0x5a
	.uleb128 0xa
	.4byte	.LASF25
	.byte	0x1
	.byte	0xa
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x16e
	.uleb128 0xb
	.ascii	"x\000"
	.byte	0x1
	.byte	0xc
	.4byte	0x68
	.uleb128 0xc
	.ascii	"j\000"
	.byte	0x1
	.byte	0xc
	.4byte	0x68
	.4byte	.LLST0
	.uleb128 0xb
	.ascii	"src\000"
	.byte	0x1
	.byte	0xd
	.4byte	0x16e
	.uleb128 0xc
	.ascii	"dst\000"
	.byte	0x1
	.byte	0xd
	.4byte	0x16e
	.4byte	.LLST1
	.uleb128 0xd
	.4byte	.LASF18
	.byte	0x1
	.byte	0xd
	.4byte	0x16e
	.uleb128 0xe
	.4byte	.LVL7
	.4byte	0x174
	.4byte	0x15e
	.uleb128 0xf
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x10
	.4byte	.LVL8
	.4byte	0x17f
	.uleb128 0xf
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x3f
	.byte	0
	.byte	0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x5a
	.uleb128 0x11
	.4byte	.LASF19
	.4byte	.LASF19
	.byte	0x4
	.byte	0x6
	.uleb128 0x11
	.4byte	.LASF20
	.4byte	.LASF20
	.byte	0x4
	.byte	0x8
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST0:
	.4byte	.LVL8-.Ltext0
	.4byte	.LVL9-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL9-.Ltext0
	.4byte	.LVL10-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL10-.Ltext0
	.4byte	.LFE0-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	0
	.4byte	0
.LLST1:
	.4byte	.LVL4-.Ltext0
	.4byte	.LVL5-.Ltext0
	.2byte	0x3
	.byte	0x73
	.sleb128 4
	.byte	0x9f
	.4byte	.LVL5-.Ltext0
	.4byte	.LVL6-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF9:
	.ascii	"CLKCTRL_PLLCR\000"
.LASF14:
	.ascii	"_sdata\000"
.LASF16:
	.ascii	"_sbss\000"
.LASF17:
	.ascii	"_ebss\000"
.LASF20:
	.ascii	"gpio_write\000"
.LASF23:
	.ascii	"/home/jeffdi/raptor/firmware/power/testcase5\000"
.LASF19:
	.ascii	"gpio_set_dir\000"
.LASF12:
	.ascii	"sram\000"
.LASF4:
	.ascii	"unsigned char\000"
.LASF15:
	.ascii	"_edata\000"
.LASF13:
	.ascii	"_sidata\000"
.LASF6:
	.ascii	"long unsigned int\000"
.LASF5:
	.ascii	"short unsigned int\000"
.LASF10:
	.ascii	"CLKCTRL_PLLTR\000"
.LASF22:
	.ascii	"testcase5.c\000"
.LASF11:
	.ascii	"CLKCTRL_CLKCR\000"
.LASF25:
	.ascii	"main\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF18:
	.ascii	"dstend\000"
.LASF3:
	.ascii	"long long int\000"
.LASF1:
	.ascii	"short int\000"
.LASF24:
	.ascii	"uint32_t\000"
.LASF2:
	.ascii	"long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF21:
	.ascii	"GNU C11 6.3.1 20170620 -mcpu=cortex-m0 -mthumb -g -"
	.ascii	"O1 -ffreestanding\000"
	.ident	"GCC: (15:6.3.1+svn253039-1build1) 6.3.1 20170620"
