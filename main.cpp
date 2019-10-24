#include "mbed.h"
#include "C12832.h"
#include <stdio.h>
#include "MMA7660.h"
#include "LM75B.h" 
 
/* for pinnames see https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */

C12832 lcd(D11, D13, D12, D7, D10);
MMA7660 accel(I2C_SDA, I2C_SCL);
LM75B temperature(I2C_SDA, I2C_SCL);
PwmOut speaker(D6);

DigitalOut red(LED_RED); 
DigitalOut AS_Red(D5,1);
DigitalOut AS_Green(D9,1);

DigitalIn Centre(D4);
DigitalIn Down(A3);
DigitalIn Left(A4);
DigitalIn Up(A2);
DigitalIn Right(A5);
DigitalIn leftbtn(SW3);
AnalogIn Left_pot(A0);
AnalogIn Right_pot(A1);

int main() {
    lcd.cls();
    lcd.locate(0,0);    
    speaker.period_us(2273);
    speaker.write(0);

    while (true) {  /* while _super-loop_ */
        red = !red; /* toggle led state */
	AS_Green = !AS_Green; 
	
	if(leftbtn==0){
	speaker.write(0.5);
	}else{
	speaker.write(0.0);
	}

	   
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

	lcd.locate(0,8);
	lcd.printf(" Left Pot: %.2f\n", (float)Left_pot);
	lcd.printf(" Right Pot: %.2f\n", (float)Right_pot);

        lcd.locate(72,0);
        lcd.printf("Acc x: %.2f", accel.x() );
        lcd.locate(72,8);
        lcd.printf("Acc y: %.2f", accel.y() );
        lcd.locate(72,16);
        lcd.printf("Acc z: %.2f", accel.z() );
	
	lcd.locate(50,24);
	lcd.printf("Temp: %.2f\n", (float)temperature.read());
        wait(0.5); 
 }
} 
