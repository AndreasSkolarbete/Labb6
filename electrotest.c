#include <stdio.h>
#include <stdlib.h>

#include "libcomponent.h"
#include "libcomponent.c"
#include "calc.c"
#include "calc.h"
#include "power.c"
#include "power.h"

/*
Todo: 
Felkorrigering som läser av inmatade värden, och kontrollerar att dessa är korrekt syntax.
Göras om till ett terminal/meny program med aktiva val av algoritmer?
*/

int main()
{
	float *resistorValues, *ptr_e12values, e12Values[3] = { 0.0f, 0.0f ,0.0f};
	float input = 0.0f, in_voltage = 0.0f, sumResValue = 0.0f;
	float ret_e_res = 0.0f, ret_power = 0.0f, ret_calc = 0.0f;
	char in_conn;
	int count = 0;

	//Pekaren tilldelas mål
	ptr_e12values = &e12Values[0];

	//Fråga efter spänningen
	printf("Ange spanningskallan i V: ");	//Lägg till felkorrigering
	scanf("%f", &in_voltage);

	//Kopplings typ
	printf("\nAnge koppling [S | P]: ");
	scanf("%s", &in_conn);

	//Antalet resistorer
	printf("Ange antalet resistanser:");	
	scanf("%d", &count);

	//Allokera ledigt minne för calloc!	
	resistorValues = (float *) calloc(count, sizeof(float));

	for(int x = 0; x < count; x++)
	{
		printf("\nResistor %d varde i Ohm: ", x + 1);
		scanf("%f", &resistorValues[x]);
	}
	
	//Ersättningsresistans!
	ret_e_res = calc_resistance(count, in_conn, resistorValues); //float calc_resistance(int count, char conn, float *array)

	//Effekt
	ret_power = calc_power_r(ret_e_res, in_voltage); //float calc_power_r(float resistance, float voltage)
	
	//E12 resistanser
	count = e_resistance(ret_e_res, ptr_e12values);
	free(resistorValues);

	//Resultat!
	printf("Ersattningsresistans: %0.1f Ohm\n", ret_e_res);
	printf("Effekt: %0.1f W\n", ret_power);
	printf("E12 varden:\n");
	
	for(int q = 0; q < count; q++)
		printf("%0.1f Ohm\n", e12Values[q]);
	
	return(0);
}
