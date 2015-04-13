
main_O3.o:     file format elf32-littlearm


Disassembly of section .text.startup:

00000000 <main>:
   0:	4a06      	ldr	r2, [pc, #24]	; (1c <main+0x1c>)
   2:	2120      	movs	r1, #32
   4:	4b06      	ldr	r3, [pc, #24]	; (20 <main+0x20>)
   6:	7011      	strb	r1, [r2, #0]
   8:	781a      	ldrb	r2, [r3, #0]
   a:	f042 0220 	orr.w	r2, r2, #32
   e:	701a      	strb	r2, [r3, #0]
  10:	781a      	ldrb	r2, [r3, #0]
  12:	f002 02df 	and.w	r2, r2, #223	; 0xdf
  16:	701a      	strb	r2, [r3, #0]
  18:	e7f6      	b.n	8 <main+0x8>
  1a:	bf00      	nop
  1c:	2009c040 	.word	0x2009c040
  20:	2009c054 	.word	0x2009c054
