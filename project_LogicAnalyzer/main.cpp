/* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * THE AUTHORS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. USE IT AT YOUR OWN RISK */

#include "mbed.h"
#include "vcd.h"
#include "LogicAnalyzer.h"

unsigned char    sample0[16*1024] __attribute__((section("AHBSRAM1")));
LogicAnalyzer la(&sample0[0]);


int main (void) 
{
	la.DMAInit();
        la.setScanRate(96);
        la.setTrigger(-1);
        la.start();
        for(int i=0;;i++) 	
	{
           if (i>600000) 
              break;
	}
        la.stop();
        vcd *newfile = new vcd(&sample0[0],1024);
        newfile->generateDumpvars();
	return 0;
}





