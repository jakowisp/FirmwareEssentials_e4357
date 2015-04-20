/* Program Example 14.1 Sets up a digital output pin using control 
 * registers and flashes an led.
 * */


// define addresses of digital i/o control registers, 
// as pointers to volatile data

#define FIO2DIR0  (*(volatile unsigned char *)(0x2009c040))
#define FIO2SET   (*(volatile unsigned char *)(0x2009c058))
#define FIO2CLR   (*(volatile unsigned char *)(0x2009c05c))
#define FIO2PIN0  (*(volatile unsigned char *)(0x2009c054))

int main() {
   register const unsigned char mask = 0x20;
   FIO2DIR0=mask;
   while(1) {
       //FIO2PIN0 |= 0x20;
       //FIO2PIN0 &= ~0x20;
       FIO2SET = mask;
       FIO2CLR = mask;
   }
}

