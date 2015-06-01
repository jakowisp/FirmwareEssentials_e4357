/* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * THE AUTHORS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. USE IT AT YOUR OWN RISK */

#include "mbed.h"
#include "vcd.h"
#include "LogicAnalyzer.h"

Serial sr1(USBTX,USBRX);
char cmd[80];

void substring(char *s,char *d,int pos,int len) {
//usage: substring(Source,Destination,pos,len);
 
    char *t;
 
    s=s+(pos-1);
    t=s+len;
    while (s!=t) {
        *d=*s;
        s++;
        d++;
    }
    *d='\0';
}


unsigned char    sample0[16*1024] __attribute__((section("AHBSRAM1")));
LogicAnalyzer la(&sample0[0]);


int main (void) 
{
    char sub[10];
    char temp[30];
    int rate=0;
    int i=0;
    sr1.baud(115200);
    sr1.printf("Mbed Logic Analyzer\r\n");

    la.DMAInit();
    while(1) {
       if (sr1.readable())  {
            cmd[i]=sr1.getc();
            if(cmd[i++] == 0xd) {
               sr1.putc('\n');
               sr1.putc('\r');
               sr1.putc('>');
               cmd[i]='\0';
               i=0;
               substring(cmd,sub,1,4);
               if (strcmp(sub,"rate")==0) {
                   sscanf(cmd,"rate %d",&rate);
                   sr1.printf("rate = %d\n\r",rate);
                   la.setScanRate(rate);
               } else {
                  if (strcmp(sub,"trig")==0) {
                   sscanf(cmd,"trigger %s",temp);
                   sr1.printf("trigger = %s\n\r",temp);
                   la.setTrigger(-1);
                  }  else {
                     if (strcmp(sub,"star")==0) {
                        sr1.printf("GO start\n\r",temp);
                        la.start();
                     }  else {
                        if (strcmp(sub,"stop")==0) {
                           sr1.printf("Go stop\n\r",temp);
                           la.stop();
                           break;
                        }
                     }
                  }
               }
            } else {
                sr1.putc(cmd[i-1]);
            }
        }
        wait_ms(1);
    }       
        vcd *newfile = new vcd(&sample0[0],1024);
        newfile->generateDumpvars();
	return 0;


}





