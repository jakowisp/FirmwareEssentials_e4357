
main.o:     file format elf32-littlearm


Disassembly of section .text.setupPWM1:

00000000 <setupPWM1>:
   0:	4b16      	ldr	r3, [pc, #88]	; (5c <setupPWM1+0x5c>)
   2:	2002      	movs	r0, #2
   4:	f8d3 20c4 	ldr.w	r2, [r3, #196]	; 0xc4
   8:	4915      	ldr	r1, [pc, #84]	; (60 <setupPWM1+0x60>)
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
  1c:	d1f4      	bne.n	8 <main+0x8>
  1e:	2000      	movs	r0, #0
  20:	bd08      	pop	{r3, pc}
  22:	bf00      	nop
  24:	2009c000 	.word	0x2009c000
	...
