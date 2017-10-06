#include <stdio.h>
#include <math.h>

#include "power.h"

int main() //Ett test program för att beräkna vilken effektutveckling som skapas av en krets
{
    float value1=0, value2=0;

    value1 = calc_power_i(20, 100);     //Test värden får calc_power_i
    value2 = calc_power_r(100, 20);     //Test värden får calc_power_r

    printf("P1=%0.2fW, P2=%0.2fW\n", value1, value2);
return 0;
}

float calc_power_i(float current, float voltage)        //Funktions anrop för att beräkna effekten med ampere och spänningen.
{
    float P=0;

    P = current * voltage; //P = I * U

    return P;

}

float calc_power_r(float resistance, float voltage)     //Funktions anrop för att beräkna effekten med resistans och spänningen.
{
    float P=0;
	
	
    P = pow(voltage, 2) / resistance;     //P = U^2/R
	
	/*
	// Debug help
	printf("\n\ncalc_power_r resistance:%.6f", resistance);
	printf("\ncalc_power_r voltage:%.6f", voltage);
	printf("\ncalc_power_r P:%.6f\n", P);
	*/
	
    return P;
}
