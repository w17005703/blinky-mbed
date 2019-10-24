#include "mbed.h"
#include "C12832.h"
#include <stdio.h>
 
/* for pinnames see https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */
DigitalOut red(LED_RED); 

DigitalOut AS_Red(D5,1);

DigitalOut AS_Green(D9,1);


int main() {
    while (true) {  /* while _super-loop_ */
        red = !red; /* toggle led state */
	AS_Green = !AS_Green; 
        wait(0.5);    /* pause for 0.5s */
    }
}
 
