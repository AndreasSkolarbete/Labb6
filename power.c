#include <stdio.h>

float calc_power_i(float, float);
float calc_power_r(float, float);

void main() //Ett test program för att beräkna vilken effektutveckling som skapas av en krets
{
    float value1=0, value2=0;

    value1 = calc_power_i(20, 100);     //Test värden för calc_power_i
    value2 = calc_power_r(100, 20);     //Test värden för calc_power_r

    printf("P1= %0.2f W, P2= %0.2f W", value1, value2);
}

float calc_power_i(float current, float voltage)        //Funktions anrop för att beräkna effekten med ampere och spänningen.
{
    float P=0;

    P = current * voltage; //P = I * U

    return(P);

}

float calc_power_r(float resistance, float voltage)     //Funktions anrop för att beräkna effekten med resistans och spänningen.
{
    float P=0;

    P = pow(voltage, 2) / resistance;     //P = U^2/R

    return(P);
}
