
main.o:     file format elf32-littlearm


Disassembly of section .text._ZN12SDFileSystemD2Ev:

00000000 <_ZN12SDFileSystemD1Ev>:
   0:	b510      	push	{r4, lr}
   2:	4604      	mov	r4, r0
   4:	4b02      	ldr	r3, [pc, #8]	; (10 <_ZN12SDFileSystemD1Ev+0x10>)
   6:	6003      	str	r3, [r0, #0]
   8:	f7ff fffe 	bl	0 <_ZN13FATFileSystemD2Ev>
   c:	4620      	mov	r0, r4
   e:	bd10      	pop	{r4, pc}
  10:	00000008 	.word	0x00000008

Disassembly of section .text._Z9setupPWM1v:

00000000 <_Z9setupPWM1v>:
   0:	4b16      	ldr	r3, [pc, #88]	; (5c <_Z9setupPWM1v+0x5c>)
   2:	2002      	movs	r0, #2
   4:	f8d3 20c4 	ldr.w	r2, [r3, #196]	; 0xc4
   8:	4915      	ldr	r1, [pc, #84]	; (60 <_Z9setupPWM1v+0x60>)
   a:	f042 0240 	orr.w	r2, r2, #64	; 0x40
   e:	f8c3 20c4 	str.w	r2, [r3, #196]	; 0xc4
  12:	f8d3 21a8 	ldr.w	r2, [r3, #424]	; 0x1a8
  16:	f442 5280 	orr.w	r2, r2, #4096	; 0x1000
  1a:	f8c3 21a8 	str.w	r2, [r3, #424]	; 0x1a8
  1e:	f5a3 2364 	sub.w	r3, r3, #933888	; 0xe4000
  22:	22ff      	movs	r2, #255	; 0xff
  24:	6058      	str	r0, [r3, #4]
  26:	601a      	str	r2, [r3, #0]
  28:	690a      	ldr	r2, [r1, #16]
  2a:	f022 0203 	bic.w	r2, r2, #3
  2e:	f042 0201 	orr.w	r2, r2, #1
  32:	610a      	str	r2, [r1, #16]
  34:	6d0a      	ldr	r2, [r1, #80]	; 0x50
  36:	f022 0203 	bic.w	r2, r2, #3
  3a:	4302      	orrs	r2, r0
  3c:	650a      	str	r2, [r1, #80]	; 0x50
  3e:	2217      	movs	r2, #23
  40:	60da      	str	r2, [r3, #12]
  42:	2201      	movs	r2, #1
  44:	6198      	str	r0, [r3, #24]
  46:	61da      	str	r2, [r3, #28]
  48:	2207      	movs	r2, #7
  4a:	651a      	str	r2, [r3, #80]	; 0x50
  4c:	f44f 7200 	mov.w	r2, #512	; 0x200
  50:	6158      	str	r0, [r3, #20]
  52:	64da      	str	r2, [r3, #76]	; 0x4c
  54:	2209      	movs	r2, #9
  56:	605a      	str	r2, [r3, #4]
  58:	4770      	bx	lr
  5a:	bf00      	nop
  5c:	400fc000 	.word	0x400fc000
  60:	4002c000 	.word	0x4002c000

Disassembly of section .text._Z11printbinaryh:

00000000 <_Z11printbinaryh>:
   0:	4b04      	ldr	r3, [pc, #16]	; (14 <_Z11printbinaryh+0x14>)
   2:	f010 0f01 	tst.w	r0, #1
   6:	bf14      	ite	ne
   8:	2031      	movne	r0, #49	; 0x31
   a:	2030      	moveq	r0, #48	; 0x30
   c:	6819      	ldr	r1, [r3, #0]
   e:	f7ff bffe 	b.w	0 <fputc>
  12:	bf00      	nop
  14:	00000000 	.word	0x00000000

Disassembly of section .text._Z14printVCDHeaderv:

00000000 <_Z14printVCDHeaderv>:
   0:	b538      	push	{r3, r4, r5, lr}
   2:	4c1c      	ldr	r4, [pc, #112]	; (74 <_Z14printVCDHeaderv+0x74>)
   4:	4d1c      	ldr	r5, [pc, #112]	; (78 <_Z14printVCDHeaderv+0x78>)
   6:	6821      	ldr	r1, [r4, #0]
   8:	481c      	ldr	r0, [pc, #112]	; (7c <_Z14printVCDHeaderv+0x7c>)
   a:	f7ff fffe 	bl	0 <fputs>
   e:	6821      	ldr	r1, [r4, #0]
  10:	4628      	mov	r0, r5
  12:	f7ff fffe 	bl	0 <fputs>
  16:	6821      	ldr	r1, [r4, #0]
  18:	4819      	ldr	r0, [pc, #100]	; (80 <_Z14printVCDHeaderv+0x80>)
  1a:	f7ff fffe 	bl	0 <fputs>
  1e:	6821      	ldr	r1, [r4, #0]
  20:	4818      	ldr	r0, [pc, #96]	; (84 <_Z14printVCDHeaderv+0x84>)
  22:	f7ff fffe 	bl	0 <fputs>
  26:	6821      	ldr	r1, [r4, #0]
  28:	4628      	mov	r0, r5
  2a:	f7ff fffe 	bl	0 <fputs>
  2e:	6821      	ldr	r1, [r4, #0]
  30:	4815      	ldr	r0, [pc, #84]	; (88 <_Z14printVCDHeaderv+0x88>)
  32:	f7ff fffe 	bl	0 <fputs>
  36:	6821      	ldr	r1, [r4, #0]
  38:	4814      	ldr	r0, [pc, #80]	; (8c <_Z14printVCDHeaderv+0x8c>)
  3a:	f7ff fffe 	bl	0 <fputs>
  3e:	6821      	ldr	r1, [r4, #0]
  40:	4628      	mov	r0, r5
  42:	f7ff fffe 	bl	0 <fputs>
  46:	6821      	ldr	r1, [r4, #0]
  48:	4811      	ldr	r0, [pc, #68]	; (90 <_Z14printVCDHeaderv+0x90>)
  4a:	f7ff fffe 	bl	0 <fputs>
  4e:	6821      	ldr	r1, [r4, #0]
  50:	4810      	ldr	r0, [pc, #64]	; (94 <_Z14printVCDHeaderv+0x94>)
  52:	f7ff fffe 	bl	0 <fputs>
  56:	6821      	ldr	r1, [r4, #0]
  58:	480f      	ldr	r0, [pc, #60]	; (98 <_Z14printVCDHeaderv+0x98>)
  5a:	f7ff fffe 	bl	0 <fputs>
  5e:	6821      	ldr	r1, [r4, #0]
  60:	480e      	ldr	r0, [pc, #56]	; (9c <_Z14printVCDHeaderv+0x9c>)
  62:	f7ff fffe 	bl	0 <fputs>
  66:	6821      	ldr	r1, [r4, #0]
  68:	480d      	ldr	r0, [pc, #52]	; (a0 <_Z14printVCDHeaderv+0xa0>)
  6a:	e8bd 4038 	ldmia.w	sp!, {r3, r4, r5, lr}
  6e:	f7ff bffe 	b.w	0 <fputs>
  72:	bf00      	nop
  74:	00000000 	.word	0x00000000
  78:	0000000a 	.word	0x0000000a
  7c:	00000000 	.word	0x00000000
  80:	00000011 	.word	0x00000011
  84:	0000001c 	.word	0x0000001c
  88:	00000036 	.word	0x00000036
  8c:	00000041 	.word	0x00000041
  90:	0000005f 	.word	0x0000005f
  94:	00000071 	.word	0x00000071
  98:	0000008c 	.word	0x0000008c
  9c:	000000a7 	.word	0x000000a7
  a0:	000000b7 	.word	0x000000b7

Disassembly of section .text._Z16generateDumpvarsv:

00000000 <_Z16generateDumpvarsv>:
   0:	b573      	push	{r0, r1, r4, r5, r6, lr}
   2:	f240 11ff 	movw	r1, #511	; 0x1ff
   6:	482b      	ldr	r0, [pc, #172]	; (b0 <mkdir+0xb0>)
   8:	f7ff fffe 	bl	0 <mkdir>
   c:	492a      	ldr	r1, [pc, #168]	; (b8 <_Z16generateDumpvarsv+0xb8>)
   e:	482b      	ldr	r0, [pc, #172]	; (bc <_Z16generateDumpvarsv+0xbc>)
  10:	f7ff fffe 	bl	0 <fopen>
  14:	4d2a      	ldr	r5, [pc, #168]	; (c0 <_Z16generateDumpvarsv+0xc0>)
  16:	4e2b      	ldr	r6, [pc, #172]	; (c4 <_Z16generateDumpvarsv+0xc4>)
  18:	6028      	str	r0, [r5, #0]
  1a:	f7ff fffe 	bl	0 <_Z16generateDumpvarsv>
  1e:	6829      	ldr	r1, [r5, #0]
  20:	4829      	ldr	r0, [pc, #164]	; (c8 <_Z16generateDumpvarsv+0xc8>)
  22:	f7ff fffe 	bl	0 <fputs>
  26:	7833      	ldrb	r3, [r6, #0]
  28:	2400      	movs	r4, #0
  2a:	f88d 3007 	strb.w	r3, [sp, #7]
  2e:	f89d 0007 	ldrb.w	r0, [sp, #7]
  32:	f7ff fffe 	bl	0 <_Z16generateDumpvarsv>
  36:	6829      	ldr	r1, [r5, #0]
  38:	4824      	ldr	r0, [pc, #144]	; (cc <_Z16generateDumpvarsv+0xcc>)
  3a:	f7ff fffe 	bl	0 <fputs>
  3e:	6829      	ldr	r1, [r5, #0]
  40:	200d      	movs	r0, #13
  42:	f7ff fffe 	bl	0 <fputc>
  46:	4822      	ldr	r0, [pc, #136]	; (d0 <_Z16generateDumpvarsv+0xd0>)
  48:	6829      	ldr	r1, [r5, #0]
  4a:	f7ff fffe 	bl	0 <fputs>
  4e:	f89d 2007 	ldrb.w	r2, [sp, #7]
  52:	5d33      	ldrb	r3, [r6, r4]
  54:	429a      	cmp	r2, r3
  56:	d00e      	beq.n	76 <_Z16generateDumpvarsv+0x76>
  58:	491e      	ldr	r1, [pc, #120]	; (d4 <_Z16generateDumpvarsv+0xd4>)
  5a:	0062      	lsls	r2, r4, #1
  5c:	6828      	ldr	r0, [r5, #0]
  5e:	f88d 3007 	strb.w	r3, [sp, #7]
  62:	f7ff fffe 	bl	0 <fprintf>
  66:	f89d 0007 	ldrb.w	r0, [sp, #7]
  6a:	f7ff fffe 	bl	0 <_Z16generateDumpvarsv>
  6e:	4817      	ldr	r0, [pc, #92]	; (cc <_Z16generateDumpvarsv+0xcc>)
  70:	6829      	ldr	r1, [r5, #0]
  72:	f7ff fffe 	bl	0 <fputs>
  76:	4b18      	ldr	r3, [pc, #96]	; (d8 <_Z16generateDumpvarsv+0xd8>)
  78:	f89d 2007 	ldrb.w	r2, [sp, #7]
  7c:	5ce3      	ldrb	r3, [r4, r3]
  7e:	429a      	cmp	r2, r3
  80:	d00f      	beq.n	a2 <_Z16generateDumpvarsv+0xa2>
  82:	0062      	lsls	r2, r4, #1
  84:	4913      	ldr	r1, [pc, #76]	; (d4 <_Z16generateDumpvarsv+0xd4>)
  86:	3201      	adds	r2, #1
  88:	6828      	ldr	r0, [r5, #0]
  8a:	f88d 3007 	strb.w	r3, [sp, #7]
  8e:	f7ff fffe 	bl	0 <fprintf>
  92:	f89d 0007 	ldrb.w	r0, [sp, #7]
  96:	f7ff fffe 	bl	0 <_Z16generateDumpvarsv>
  9a:	480c      	ldr	r0, [pc, #48]	; (cc <_Z16generateDumpvarsv+0xcc>)
  9c:	6829      	ldr	r1, [r5, #0]
  9e:	f7ff fffe 	bl	0 <fputs>
  a2:	3401      	adds	r4, #1
  a4:	f5b4 4f80 	cmp.w	r4, #16384	; 0x4000
  a8:	d1d1      	bne.n	4e <_Z16generateDumpvarsv+0x4e>
  aa:	6828      	ldr	r0, [r5, #0]
  ac:	f7ff fffe 	bl	0 <fclose>
  b0:	b002      	add	sp, #8
  b2:	bd70      	pop	{r4, r5, r6, pc}
  b4:	000000c9 	.word	0x000000c9
  b8:	000000e5 	.word	0x000000e5
  bc:	000000d2 	.word	0x000000d2
	...
  c8:	000000e7 	.word	0x000000e7
  cc:	000000f3 	.word	0x000000f3
  d0:	0000000a 	.word	0x0000000a
  d4:	000000f6 	.word	0x000000f6
  d8:	00000000 	.word	0x00000000

Disassembly of section .text.startup.main:

00000000 <main>:
   0:	b508      	push	{r3, lr}
   2:	f7ff fffe 	bl	0 <main>
   6:	2300      	movs	r3, #0
   8:	4a06      	ldr	r2, [pc, #24]	; (24 <main+0x24>)
   a:	4907      	ldr	r1, [pc, #28]	; (28 <main+0x28>)
   c:	7d10      	ldrb	r0, [r2, #20]
   e:	54c8      	strb	r0, [r1, r3]
  10:	7d11      	ldrb	r1, [r2, #20]
  12:	4a06      	ldr	r2, [pc, #24]	; (2c <main+0x2c>)
  14:	54d1      	strb	r1, [r2, r3]
  16:	3301      	adds	r3, #1
  18:	f5b3 4f80 	cmp.w	r3, #16384	; 0x4000
  1c:	d1f4      	bne.n	ffffffec <_ZN12SDFileSystemD5Ev+0xffffffec>
  1e:	f7ff fffe 	bl	0 <main>
  22:	e7fe      	b.n	22 <main+0x22>
  24:	2009c000 	.word	0x2009c000
	...

Disassembly of section .text._ZN12SDFileSystemD0Ev:

00000000 <_ZN12SDFileSystemD0Ev>:
   0:	b510      	push	{r4, lr}
   2:	4604      	mov	r4, r0
   4:	f7ff fffe 	bl	0 <_ZN12SDFileSystemD0Ev>
   8:	4620      	mov	r0, r4
   a:	f7ff fffe 	bl	0 <_ZdlPv>
   e:	4620      	mov	r0, r4
  10:	bd10      	pop	{r4, pc}

Disassembly of section .text.startup._GLOBAL__sub_I_sd:

00000000 <_GLOBAL__sub_I_sd>:
   0:	b513      	push	{r0, r1, r4, lr}
   2:	4b09      	ldr	r3, [pc, #36]	; (28 <_GLOBAL__sub_I_sd+0x28>)
   4:	4c09      	ldr	r4, [pc, #36]	; (2c <_GLOBAL__sub_I_sd+0x2c>)
   6:	9300      	str	r3, [sp, #0]
   8:	4b09      	ldr	r3, [pc, #36]	; (30 <_GLOBAL__sub_I_sd+0x30>)
   a:	4620      	mov	r0, r4
   c:	9301      	str	r3, [sp, #4]
   e:	4909      	ldr	r1, [pc, #36]	; (34 <_GLOBAL__sub_I_sd+0x34>)
  10:	4a09      	ldr	r2, [pc, #36]	; (38 <_GLOBAL__sub_I_sd+0x38>)
  12:	4b0a      	ldr	r3, [pc, #40]	; (3c <_GLOBAL__sub_I_sd+0x3c>)
  14:	f7ff fffe 	bl	0 <_ZN12SDFileSystemC1E7PinNameS0_S0_S0_PKc>
  18:	4620      	mov	r0, r4
  1a:	4909      	ldr	r1, [pc, #36]	; (40 <_GLOBAL__sub_I_sd+0x40>)
  1c:	4a09      	ldr	r2, [pc, #36]	; (44 <_GLOBAL__sub_I_sd+0x44>)
  1e:	b002      	add	sp, #8
  20:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
  24:	f7ff bffe 	b.w	0 <__aeabi_atexit>
  28:	2009c006 	.word	0x2009c006
  2c:	00000000 	.word	0x00000000
  30:	000000fd 	.word	0x000000fd
  34:	2009c009 	.word	0x2009c009
  38:	2009c008 	.word	0x2009c008
  3c:	2009c007 	.word	0x2009c007
	...
