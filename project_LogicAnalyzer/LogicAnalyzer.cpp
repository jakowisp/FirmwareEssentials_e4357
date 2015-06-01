#include "LogicAnalyzer.h"
#include "mbed.h"


LogicAnalyzer::LogicAnalyzer(unsigned char * ptr) {
   printf("Init LA\n\r");
   this->ptr = ptr;
   this->triggerMode=-1;

   // GPIO config
   // Set GPIO port 0 to input
   LPC_GPIO0->FIODIR0 = 0x00;
   // Enable 6 bits
   LPC_GPIO0->FIOPIN0 = 0xF3;
   // setup timer1
   LPC_SC->PCONP |= 1 << 2; // Power up GDMA
   LPC_SC->PCLKSEL0 |= 0x01 << 4; // CCLK , 96MHZ clock selected.
    
   // Disable pullups for P2.0
   LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3) | 0x2;

   //Timer rate set to 6Mhz
   LPC_TIM1->MR0 = 16;
   LPC_TIM1->MR1 = 1;

   LPC_TIM1->MCR = 1 << 1; // reset on Match Compare 0
   LPC_TIM1->TCR = 0x01; // start timer.
}

void LogicAnalyzer::setScanRate(unsigned int rate) {
   printf("Rate set to %d\n\r",rate);
   //TODO: possible bug.. What happens if scan rate changed during a scan
   LPC_TIM1->TCR = 0x00; // start timer.
   LPC_TIM1->MR0 = rate;
   LPC_TIM1->TCR = 0x01; // start timer.
}

void LogicAnalyzer::setTrigger(int mode) {
   printf("set trigger mode to: %x\n\r", mode);
   this->triggerMode = mode;
}

void LogicAnalyzer::start(void) {
   printf("Starting trigger wait\n\r");
   if( this->triggerMode == -1 ) {
      LPC_GPDMACH0->DMACCConfig |= 1; //enable ch0
   }
}

void LogicAnalyzer::stop(void){
   printf("Stopping trigger wait\n\r");
   LPC_GPDMACH0->DMACCConfig = 0; // stop ch0 dma
   LPC_TIM1->TCR = 0x00; // start timer.
}

void LogicAnalyzer::DMAInit(void) {
   LPC_SC->PCONP |= 1 << 29; // Power up DMA
	
   LPC_GPDMACH0->DMACCConfig = 0; // stop ch0 dma

   LPC_GPDMA->DMACConfig |= 1 << 0; // enable DMA
   LPC_GPDMA->DMACSync &= ~(1 << 10); // use sync for MAT1.0 DMA
   LPC_SC->DMAREQSEL |= 1 << 2; // Timer1 Match Compare 0 as DMA request

   LPC_GPDMA->DMACIntErrClr |= 0xff;
   LPC_GPDMA->DMACIntTCClear |= 0xff;

   LPC_GPDMACH0->DMACCSrcAddr = (uint32_t) &(LPC_GPIO0->FIOPIN0); 
   LPC_GPDMACH0->DMACCDestAddr = (uint32_t) &ptr[0]; 
   LPC_GPDMACH0->DMACCLLI = 0;
   /* 11:0 transfer size
   *  14:12 - Src burst size
   *  17:15 Dst burst
   *  20:18 Src widht
   *  23:21 dst width
   *  26 src increment
   *  27 dst increment
   */
   LPC_GPDMACH0->DMACCControl = 1024 | (0 << 12) |  (0 << 15) |( 1 << 27 ); // Transfer size = 200 bytes and enable source increment.
   LPC_GPDMACH0->DMACCConfig = ( 10 << 6 ) | ( 1 << 11); // Set MAT1.0 as destination request peripheral and the type pf transfer as Memory to Peripheral.
	
}



