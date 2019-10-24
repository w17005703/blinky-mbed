#include "mbed.h"
#include "C12832.h"
#include <stdio.h>
 
/* for pinnames see https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */

C12832 lcd(D11, D13, D12, D7, D10);

DigitalOut red(LED_RED); 
DigitalOut AS_Red(D5,1);
DigitalOut AS_Green(D9,1);

DigitalIn Centre(D4);
DigitalIn Down(A3);
DigitalIn Left(A4);
DigitalIn Up(A2);
DigitalIn Right(A5);

AnalogIn Left_pot(A0);
AnalogIn Right_pot(A1);

int main() {
    lcd.cls();
    lcd.locate(0,0);

    while (true) {  /* while _super-loop_ */
        red = !red; /* toggle led state */
	AS_Green = !AS_Green; 
	
	lcd.locate(0,8);
	lcd.printf(" Left Pot: %.2f\n", (float)Left_pot);
	lcd.printf(" Right Pot: %.2f\n", (float)Right_pot);

	lcd.locate(0,0);
	if (int(Down)){
	lcd.printf("D\n");	
        }	

	else if (int(Up)){
	lcd.printf("U\n");	
        }	

	else if (int(Right)){
	lcd.printf("R\n");	
        }	

	else if (int(Centre)){
	lcd.printf("C\n");	
        }	
	
	else if (int(Left)){
	lcd.printf("L\n");
	}
	
     }
	wait(0.5);
 } 
