/* PWM test code to setup a 2Mhz signal 
 *
 *
 *  Based on http://openlpc.com/4e26f1/examples/pwm.lpc17xx
 *
 * */

// Load the memory map structure to ease configuration
#include <mbed/TARGET_LPC1768/LPC17xx.h>

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
     
    // Disable pullups for P2.0
    LPC_PINCON->PINMODE4 = (LPC_PINCON->PINMODE4 & ~0x3) | 0x2;
 	
    // Set Prescale to divide CCLK by 24
    // 96MHZ/24= 4Mhz
    LPC_PWM1->PR = 23; 
    // Set the period for all PWM1 signals
    LPC_PWM1->MR0 = 2;             
    // Set the high time of the period
    // In this case 50/50
    LPC_PWM1->MR1 = 1;              
    //Set this value to ensure the changes are loaded into the PWM module
    LPC_PWM1->LER = 0x7;		      
 
    //Starts the PWM1 module
   LPC_PWM1->MCR = 0x2;               // reset on MR0
   LPC_PWM1->PCR = 1 << 9;            // enable PWM1 with single-edge operation
   LPC_PWM1->TCR = (1 << 3) | 1;      // enable PWM mode and counting
   
   
}
 
 int main()
 {
    setupPWM1();
    
    //loop forever
    while(1) {
    }

    return 0;
}

