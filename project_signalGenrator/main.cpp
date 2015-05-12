/* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * THE AUTHORS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. USE IT AT YOUR OWN RISK */

#include "mbed.h"

unsigned char    sample0[16*1024] __attribute__((section("AHBSRAM1")));
unsigned char    sample1[16*1024] __attribute__((section("AHBSRAM0")));
void DMAInit();
void setupPWM1(void);


int main (void) 
{
	
	// GPIO config
	LPC_GPIO0->FIODIR0 = 0xFF;
	LPC_GPIO0->FIOPIN0 = 3;
	
	// setup timer1
	LPC_SC->PCONP |= 1 << 2; // Power up GDMA
        LPC_SC->PCONP |= 1 << 6; //Power up PWM
	LPC_SC->PCLKSEL0 |= 0x01 << 4; // CCLK
	LPC_SC->PCLKSEL0 |= 0x01 << 12; // CCLK
        LPC_PWM1->TCR = 2;
        LPC_PWM1->IR = 0xff;
        // Dwayne Dilbeck 5/4/2015 changed the MR0 and MR1 values to give the
        // burst transfer time.

    LPC_PINCON->PINSEL4 = (LPC_PINCON->PINSEL4 & ~(0x3 << 0)) | (0x1 << 0);
     
    // Disable pullups for P2.0
    LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3) | 0x2;

	LPC_PWM1->MR0 = 2;
        LPC_PWM1->MR1 = 1;
	LPC_TIM1->MR0 = 2;
        LPC_TIM1->MR1 = 1;

        //Set this value to ensure the changes are loaded into the PWM module
         LPC_PWM1->LER = 0x7;		      
	LPC_TIM1->MCR = 1 << 1; // reset on Match Compare 0
 
        //Starts the PWM1 module
        LPC_PWM1->PCR = 1 << 9;            // enable PWM1 with single-edge operation
		
	uint32_t i;
	
	for(i=0;i<1024;i++)
	{
           if(i%2 < 1) {
		sample0[i] = 0xFF;
		sample1[i] = 0x01;
           } else { 
		sample0[i] = 0;
		sample1[i] = 0;
	   }
        }


	DMAInit();
        LPC_PWM1->TCR = (1 << 3) | 1;      // enable PWM mode and counting
	LPC_TIM1->TCR = 0x01; // start timer.
	
	while(1)
	{
        
	}
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
		
	LPC_GPDMACH0->DMACCDestAddr = (uint32_t) &(LPC_GPIO0->FIOPIN0); // LED is connected to P1.29.
        // the array where alternating 1's and 0's. are stored
        LPC_GPDMACH0->DMACCSrcAddr = (uint32_t) &sample0[0]; 
	LPC_GPDMACH0->DMACCLLI = 0;
	
	LPC_GPDMACH0->DMACCControl = 1024 | (0 << 12) |  (0 << 15) |( 1 << 26 ); // Transfer size = 200 bytes and enable source increment.
	
	LPC_GPDMACH0->DMACCConfig = ( 10 << 6 ) | ( 1 << 11); // Set MAT1.0 as destination request peripheral and the type pf transfer as Memory to Peripheral.
	
	LPC_GPDMACH0->DMACCConfig |= 1; //enable ch0



/* DMA on reverse trigger1 */	
	LPC_GPDMACH1->DMACCDestAddr = (uint32_t) &(LPC_GPIO0->FIOPIN0); // LED is connected to P1.29.
        // the array where alternating 1's and 0's. are stored
        LPC_GPDMACH1->DMACCSrcAddr = (uint32_t) &sample1[0]; 
	LPC_GPDMACH1->DMACCLLI = 0;
	LPC_GPDMACH1->DMACCControl = 1024 | (0 << 12) |  (0 << 15) |( 1 << 26 ); // Transfer size = 200 bytes and enable source increment.
	
	LPC_GPDMACH1->DMACCConfig = ( 11 << 6 ) | ( 1 << 11); // Set MAT1.1 as destination request peripheral and the type pf transfer as Memory to Peripheral.
	
	//LPC_GPDMACH1->DMACCConfig |= 1; //enable ch1
}


void setupPWM1(void){
    // ensure PWM peripheral is powered on (it is powered on by default)
    LPC_SC->PCONP |= 1 << 6;
    // Select SystemClock as PCLK. By default after reset PCLK = CLK/4
    // [PCLKSEL0[13:12] = 2'b00 selects CCLK.  Table 42 of user manual
    LPC_SC->PCLKSEL0 |= 1<<12;
 
    //Keep the PWM halted while setting up configuration
    LPC_PWM1->TCR = 2;                      // bring PWM module into reset
    LPC_PWM1->IR = 0xff;                    // clear any pending interrupts
    
    // configure P2.0 for PWM1.1 - O - Pulse Width Modulator 1, channel 1 output.
    LPC_PINCON->PINSEL4 = (LPC_PINCON->PINSEL4 & ~(0x3 << 0)) | (0x1 << 0);
    LPC_PINCON->PINSEL4 = (LPC_PINCON->PINSEL4 & ~(0x3 << 4)) | (0x1 << 4);
     
    // Disable pullups for P2.0
    LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3 << 0) | (0x2 << 0);
    LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3 << 4) | (0x2 << 4);
 	
    // Set Prescale to divide CCLK by 24
    // 96MHZ/24= 4Mhz
    // TC is incremented every PR+1 value. Default is 0.
    //LPC_PWM1->PR = 23; 
    // Set the period for all PWM1 signals
    LPC_PWM1->MR0 = 512;             
    // Set the high time of the period
    // In this case 50/50
    LPC_PWM1->MR1 = 256;

    LPC_PWM1->MR3 = 256;
    LPC_PWM1->MR4 = 512;              
    //Set this value to ensure the changes are loaded into the PWM module
    LPC_PWM1->LER = 0x7;		      
 
    //Starts the PWM1 module
    LPC_PWM1->MCR = 0x2;               // reset on MR0
    // enable PWM1 with single-edge operation
    // enable PWM3
    // Configure PWM3 for dual edge operation
    LPC_PWM1->PCR = 1<<11| 1 << 9 | 1<<3;            
    LPC_PWM1->TCR = (1 << 3) | 1;      // enable PWM mode and counting
}

