
main_Os.o:     file format elf32-littlearm


Disassembly of section .text.startup:

00000000 <main>:
   0:	4b05      	ldr	r3, [pc, #20]	; (18 <main+0x18>)
   2:	2220      	movs	r2, #32
   4:	701a      	strb	r2, [r3, #0]
   6:	4b05      	ldr	r3, [pc, #20]	; (1c <main+0x1c>)
   8:	781a      	ldrb	r2, [r3, #0]
   a:	f042 0220 	orr.w	r2, r2, #32
   e:	701a      	strb	r2, [r3, #0]
  10:	781a      	ldrb	r2, [r3, #0]
  12:	f002 02df 	and.w	r2, r2, #223	; 0xdf
  16:	e7f5      	b.n	4 <main+0x4>
  18:	2009c040 	.word	0x2009c040
  1c:	2009c054 	.word	0x2009c054
