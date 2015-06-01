#include "vcd.h"
#include "mbed.h"

   vcd::vcd(unsigned char *ptr,unsigned int length) {
      this->ptr=ptr;
      this->len = length;
   }

   void vcd::printbinary(unsigned char inputValue) {
      unsigned int temp;
      for(int i=7;i<0;i--) {
         temp = (unsigned int)inputValue & 1<<i;
         if(temp > 0) {
             printf("1");
         } else {
             printf("0");
         }
      }
   }


   void vcd::printVCDHeader(void){
      printf("\n\r$date\n\r");
      printf("$end\n\r");
      printf("$version\n\r");
      printf("Mbed Logic Analyzer 0.1\n\r");
      printf("$end\n\r");
      printf("$comment\n\r");
      printf("Developed by Dwayne Dilbeck\n\r");
      printf("$end\n\r");
      printf("$timescale 80ns\n\r");
      printf("$scope module logic $end\n\r");
      printf("$var wire 1 \( data0 $end\n\r");
      printf("$upscope $end\n\r");
      printf("$enddefinitions\n\r");
   }

   void vcd::generateDumpvars(){
      unsigned int i;
      unsigned char volatile previousValue;
    
      this->printVCDHeader();
      printf("$dumpvars\n\r"); 
      previousValue = ptr[0];
      printbinary(previousValue);
      printf("\(\n"); 
      printf("\r"); 
      printf("$end\n\r"); 
      for(i = 0; i < this->len; i++) {
         if(previousValue != ptr[i]) {
            previousValue = ptr[i];
            printf("\r#%d\n\r",i);
            printbinary(previousValue);
            printf("\(\n"); 
         }
      }
   }


 

