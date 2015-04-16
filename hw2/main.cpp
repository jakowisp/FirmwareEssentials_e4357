/* PWM test code to setup a 2Mhz signal 
 *
 *
 *  Based on http://openlpc.com/4e26f1/examples/pwm.lpc17xx
 *
 * */

// Load the memory map structure to ease configuration
//#include <mbed/TARGET_LPC1768/LPC17xx.h>
#include "mbed.h"
#include "SDFileSystem.h"
 
SDFileSystem sd(p5, p6, p7, p8, "sd"); // the pinout on the mbed Cool Components workshop board
FILE *fp;

unsigned char    sample0[16*1024] __attribute__((section("AHBSRAM1")));
unsigned char    sample1[16*1024] __attribute__((section("AHBSRAM0")));


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


void printbinary(unsigned char inputValue) {
    if(((unsigned int)inputValue & 1)> 0) {
          fprintf(fp,"1");
       } else {
          fprintf(fp,"0");
       }
}


void printVCDHeader(void){
   fprintf(fp,"\n\r$date\n\r");
   fprintf(fp,"$end\n\r");
   fprintf(fp,"$version\n\r");
   fprintf(fp,"Mbed Logic Analyzer 0.1\n\r");
   fprintf(fp,"$end\n\r");
   fprintf(fp,"$comment\n\r");
   fprintf(fp,"Developed by Dwayne Dilbeck\n\r");
   fprintf(fp,"$end\n\r");
   fprintf(fp,"$timescale 80ns\n\r");
   fprintf(fp,"$scope module logic $end\n\r");
   fprintf(fp,"$var wire 1 \( data0 $end\n\r");
   fprintf(fp,"$upscope $end\n\r");
   fprintf(fp,"$enddefinitions\n\r");
   
}

void generateDumpvars(){
    unsigned int i;
    unsigned char volatile previousValue;
    mkdir("/sd/vcds", 0777);
    
    fp = fopen("/sd/vcds/data0.vcd", "w");
    
    printVCDHeader();
    fprintf(fp,"$dumpvars\n\r"); 
    previousValue = sample0[0];
    printbinary(previousValue);
    fprintf(fp,"\(\n"); 
    fprintf(fp,"\r"); 
    fprintf(fp,"$end\n\r"); 
    for(i = 0; i < 16*1024; i++) {
       if(previousValue != sample0[i]) {
         previousValue = sample0[i];
         fprintf(fp,"\r#%d\n\r",i*2);
         printbinary(previousValue);
         fprintf(fp,"\(\n"); 
       }
       if(previousValue != sample1[i]) {
          previousValue = sample1[i];
          fprintf(fp,"\r#%d\n\r",i*2+1);
         printbinary(previousValue);
         fprintf(fp,"\(\n"); 
       }
    }
    fclose(fp);
}
 
 int main()
 {
    int i;
    setupPWM1();
    
    for(i = 0 ; i < 16*1024; i++) {
       sample0[i] = LPC_GPIO0->FIOPIN0;
       sample1[i] = LPC_GPIO0->FIOPIN0;
    }
    generateDumpvars();

    //error("unexpected Finish!!");
    while(1) {
    }
    return 0;
}
