/* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * THE AUTHORS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. USE IT AT YOUR OWN RISK */

#include "mbed.h"
#include "vcd.h"

unsigned char    sample0[16*1024] __attribute__((section("AHBSRAM1")));
void DMAInit();



int main (void) 
{
	
	// GPIO config
	LPC_GPIO0->FIODIR0 = 0xF0;
	LPC_GPIO0->FIOPIN0 = 3;
	
	// setup timer1
	LPC_SC->PCONP |= 1 << 2; // Power up GDMA
        LPC_SC->PCONP |= 1 << 6; //Power up PWM
	LPC_SC->PCLKSEL0 |= 0x01 << 4; // CCLK
	LPC_SC->PCLKSEL0 |= 0x01 << 12; // CCLK

     
    // Disable pullups for P2.0
         LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3) | 0x2;

	LPC_TIM1->MR0 = 2;
        LPC_TIM1->MR1 = 1;

	LPC_TIM1->MCR = 1 << 1; // reset on Match Compare 0
		
	DMAInit();
	LPC_TIM1->TCR = 0x01; // start timer.
        for(int i=0;;i++) 	
	{
           if (i>6000000) 
              break;
        
	}
        vcd *newfile = new vcd(&sample0[0],1024);
        newfile->generateDumpvars();
	return 0;
  
}


void DMAInit()
{
	LPC_SC->PCONP |= 1 << 29; // Power up DMA
	
//	LPC_GPDMACH0->DMACCConfig = 0; // stop ch0 dma
	
	LPC_GPDMA->DMACConfig |= 1 << 0; // enable DMA
	LPC_GPDMA->DMACSync &= ~(1 << 10); // use sync for MAT1.0 DMA
	LPC_GPDMA->DMACSync &= ~(1 << 11); // use sync for MAT1.1 DMA
	LPC_SC->DMAREQSEL |= 1 << 2; // Timer1 Match Compare 0 as DMA request
	LPC_SC->DMAREQSEL |= 1 << 3; // Timer1 Match Compare 0 as DMA request
	
	LPC_GPDMA->DMACIntErrClr |= 0xff;
	LPC_GPDMA->DMACIntTCClear |= 0xff;
		
	LPC_GPDMACH0->DMACCSrcAddr = (uint32_t) &(LPC_GPIO0->FIOPIN0); 
        // the array where alternating 1's and 0's. are stored
        LPC_GPDMACH0->DMACCDestAddr = (uint32_t) &sample0[0]; 
	LPC_GPDMACH0->DMACCLLI = 0;
        /* 14:12 - Src burst size
 *  11:0 transfer size
 *  17:15 Dst burst
 *  20:18 Src widht
 *  23:21 dst width
 *  26 src increment
 *  27 dst increment
 */

	
	LPC_GPDMACH0->DMACCControl = 1024 | (0 << 12) |  (0 << 15) |( 1 << 27 ); // Transfer size = 200 bytes and enable source increment.
	
	LPC_GPDMACH0->DMACCConfig = ( 10 << 6 ) | ( 1 << 11); // Set MAT1.0 as destination request peripheral and the type pf transfer as Memory to Peripheral.
	
	LPC_GPDMACH0->DMACCConfig |= 1; //enable ch0



}



