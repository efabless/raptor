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
	.file	"testcase2.c"
@ GNU C11 (15:6.3.1+svn253039-1build1) version 6.3.1 20170620 (arm-none-eabi)
@	compiled by GNU C version 7.2.0, GMP version 6.1.2, MPFR version 4.0.1-rc1, MPC version 1.1.0, isl version 0.15
@ warning: MPFR header version 4.0.1-rc1 differs from library version 4.0.1.
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -imultilib thumb/v6-m -D__USES_INITFINI__ testcase2.c
@ -mcpu=cortex-m0 -mthumb -auxbase-strip testcase2.s -g -O1 -Wall
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
	.file 1 "testcase2.c"
	.loc 1 4 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}	@
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 1 6 0
	movs	r0, #0	@,
	bl	gpio_set_dir	@
.LVL0:
.L8:
	.loc 1 9 0
	movs	r0, #3	@,
	bl	gpio_write	@
.LVL1:
	ldr	r3, .L15	@ ivtmp_1,
.LVL2:
.L2:
	subs	r3, r3, #1	@ ivtmp_1,
.LVL3:
	.loc 1 10 0 discriminator 3
	cmp	r3, #0	@ ivtmp_1,
	bne	.L2	@,
	.loc 1 11 0
	movs	r0, #5	@,
	bl	gpio_write	@
.LVL4:
	ldr	r3, .L15	@ ivtmp_2,
.LVL5:
.L3:
	subs	r3, r3, #1	@ ivtmp_2,
.LVL6:
	.loc 1 12 0 discriminator 3
	cmp	r3, #0	@ ivtmp_2,
	bne	.L3	@,
	.loc 1 13 0
	movs	r0, #9	@,
	bl	gpio_write	@
.LVL7:
	ldr	r3, .L15	@ ivtmp_3,
.LVL8:
.L4:
	subs	r3, r3, #1	@ ivtmp_3,
.LVL9:
	.loc 1 14 0 discriminator 3
	cmp	r3, #0	@ ivtmp_3,
	bne	.L4	@,
	.loc 1 15 0
	movs	r0, #6	@,
	bl	gpio_write	@
.LVL10:
	ldr	r3, .L15	@ ivtmp_4,
.LVL11:
.L5:
	subs	r3, r3, #1	@ ivtmp_4,
.LVL12:
	.loc 1 16 0 discriminator 3
	cmp	r3, #0	@ ivtmp_4,
	bne	.L5	@,
	.loc 1 17 0
	movs	r0, #10	@,
	bl	gpio_write	@
.LVL13:
	ldr	r3, .L15	@ ivtmp_5,
.LVL14:
.L6:
	subs	r3, r3, #1	@ ivtmp_5,
.LVL15:
	.loc 1 18 0 discriminator 3
	cmp	r3, #0	@ ivtmp_5,
	bne	.L6	@,
	.loc 1 19 0
	movs	r0, #12	@,
	bl	gpio_write	@
.LVL16:
	ldr	r3, .L15	@ ivtmp_6,
.LVL17:
.L7:
	subs	r3, r3, #1	@ ivtmp_6,
.LVL18:
	.loc 1 20 0 discriminator 3
	cmp	r3, #0	@ ivtmp_6,
	bne	.L7	@,
	b	.L8	@
.L16:
	.align	2
.L15:
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
	.4byte	0x17b
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF15
	.byte	0xc
	.4byte	.LASF16
	.4byte	.LASF17
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
	.4byte	.LASF18
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
	.uleb128 0xa
	.4byte	.LASF19
	.byte	0x1
	.byte	0x3
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x168
	.uleb128 0xb
	.ascii	"j\000"
	.byte	0x1
	.byte	0x5
	.4byte	0x68
	.4byte	.LLST0
	.uleb128 0xc
	.4byte	.LVL0
	.4byte	0x168
	.4byte	0xf9
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0xc
	.4byte	.LVL1
	.4byte	0x173
	.4byte	0x10c
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x33
	.byte	0
	.uleb128 0xc
	.4byte	.LVL4
	.4byte	0x173
	.4byte	0x11f
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x35
	.byte	0
	.uleb128 0xc
	.4byte	.LVL7
	.4byte	0x173
	.4byte	0x132
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x39
	.byte	0
	.uleb128 0xc
	.4byte	.LVL10
	.4byte	0x173
	.4byte	0x145
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x36
	.byte	0
	.uleb128 0xc
	.4byte	.LVL13
	.4byte	0x173
	.4byte	0x158
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.uleb128 0xe
	.4byte	.LVL16
	.4byte	0x173
	.uleb128 0xd
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1
	.byte	0x3c
	.byte	0
	.byte	0
	.uleb128 0xf
	.4byte	.LASF13
	.4byte	.LASF13
	.byte	0x4
	.byte	0x6
	.uleb128 0xf
	.4byte	.LASF14
	.4byte	.LASF14
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
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xc
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
	.uleb128 0xd
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.4byte	.LVL1-.Ltext0
	.4byte	.LVL2-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL2-.Ltext0
	.4byte	.LVL3-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL3-.Ltext0
	.4byte	.LVL4-1-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL4-.Ltext0
	.4byte	.LVL5-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL5-.Ltext0
	.4byte	.LVL6-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL6-.Ltext0
	.4byte	.LVL7-1-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL7-.Ltext0
	.4byte	.LVL8-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL8-.Ltext0
	.4byte	.LVL9-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL9-.Ltext0
	.4byte	.LVL10-1-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL10-.Ltext0
	.4byte	.LVL11-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL11-.Ltext0
	.4byte	.LVL12-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL12-.Ltext0
	.4byte	.LVL13-1-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL13-.Ltext0
	.4byte	.LVL14-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL15-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL15-.Ltext0
	.4byte	.LVL16-1-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11170
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL16-.Ltext0
	.4byte	.LVL17-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL17-.Ltext0
	.4byte	.LVL18-.Ltext0
	.2byte	0x9
	.byte	0xc
	.4byte	0x11171
	.byte	0x73
	.sleb128 0
	.byte	0x1c
	.byte	0x9f
	.4byte	.LVL18-.Ltext0
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
	.ascii	"gpio_write\000"
.LASF17:
	.ascii	"/home/jeffdi/raptor/firmware/power/testcase2\000"
.LASF13:
	.ascii	"gpio_set_dir\000"
.LASF12:
	.ascii	"sram\000"
.LASF4:
	.ascii	"unsigned char\000"
.LASF6:
	.ascii	"long unsigned int\000"
.LASF5:
	.ascii	"short unsigned int\000"
.LASF16:
	.ascii	"testcase2.c\000"
.LASF10:
	.ascii	"CLKCTRL_PLLTR\000"
.LASF11:
	.ascii	"CLKCTRL_CLKCR\000"
.LASF19:
	.ascii	"main\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF3:
	.ascii	"long long int\000"
.LASF1:
	.ascii	"short int\000"
.LASF18:
	.ascii	"uint32_t\000"
.LASF2:
	.ascii	"long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF15:
	.ascii	"GNU C11 6.3.1 20170620 -mcpu=cortex-m0 -mthumb -g -"
	.ascii	"O1 -ffreestanding\000"
	.ident	"GCC: (15:6.3.1+svn253039-1build1) 6.3.1 20170620"
