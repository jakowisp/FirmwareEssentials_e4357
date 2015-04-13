
main.1.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b480      	push	{r7}
   2:	af00      	add	r7, sp, #0
   4:	4b09      	ldr	r3, [pc, #36]	; (2c <main+0x2c>)
   6:	2220      	movs	r2, #32
   8:	701a      	strb	r2, [r3, #0]
   a:	4a09      	ldr	r2, [pc, #36]	; (30 <main+0x30>)
   c:	4b08      	ldr	r3, [pc, #32]	; (30 <main+0x30>)
   e:	781b      	ldrb	r3, [r3, #0]
  10:	b2db      	uxtb	r3, r3
  12:	f043 0320 	orr.w	r3, r3, #32
  16:	b2db      	uxtb	r3, r3
  18:	7013      	strb	r3, [r2, #0]
  1a:	4a05      	ldr	r2, [pc, #20]	; (30 <main+0x30>)
  1c:	4b04      	ldr	r3, [pc, #16]	; (30 <main+0x30>)
  1e:	781b      	ldrb	r3, [r3, #0]
  20:	b2db      	uxtb	r3, r3
  22:	f023 0320 	bic.w	r3, r3, #32
  26:	b2db      	uxtb	r3, r3
  28:	7013      	strb	r3, [r2, #0]
  2a:	e7ee      	b.n	a <main+0xa>
  2c:	2009c040 	.word	0x2009c040
  30:	2009c054 	.word	0x2009c054
