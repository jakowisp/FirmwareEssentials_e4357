/* Program Example 14.1 Sets up a digital output pin using control 
 * registers and flashes an led.
 * */


// define addresses of digital i/o control registers, 
// as pointers to volatile data

#define FIO2DIR0  (*(volatile unsigned char *)(0x2009c040))
#define FIO2PIN0  (*(volatile unsigned char *)(0x2009c054))

int main() {
   FIO2DIR0=0x20;
   while(1) {
       FIO2PIN0 |= 0x20;
       FIO2PIN0 &= ~0x20;
   }
}

