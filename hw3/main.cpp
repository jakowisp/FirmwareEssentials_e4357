#include "mbed.h"
BusOut leds(LED1,LED2);

DigitalIn sw1(p20);
DigitalIn sw2(p19);
Serial async_port(p9,p10);
unsigned char outByte;
unsigned char inByte;


int main(){
     async_port.baud(9600);
     while(true){
        outByte =0xa0;
        outByte |= sw1;
        outByte |= sw2<<1; 
        if(async_port.readable()==1) {
           inByte = async_port.getc();
        
           leds = inByte & 0x03;
        
        }
        async_port.putc(outByte);   
    }
    
}

