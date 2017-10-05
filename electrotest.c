#include <stdio.h>
#include <stdlib.h>

#include "libcomponent.h"
#include "calc.h"
#include "power.h"

/*
Todo:
Felkorrigering som läser av inmatade värden, och kontrollerar att dessa är korrekt syntax.
Göras om till ett terminal/meny program med aktiva val av algoritmer?
Ska inte kunna...
..ange bokstäver istället för siffror för komponenter/värden.
*/

int main()
{
	float *resistorValues = NULL;
	float *ptr_e12values = NULL;
	float e12Values[3] = { 0.0f, 0.0f ,0.0f};
	float input = 0.0f;
	float in_voltage = 0.0f;
	float sumResValue = 0.0f;
	float ret_e_res = 0.0f;
	float ret_power = 0.0f;
	float ret_calc = 0.0f;
	char in_conn;
	int count = 0;

	//Pekaren tilldelas mål
	ptr_e12values = &e12Values[0];

	do 
	{
		//Fråga efter spänningen
		printf("Ange spänningskälla i V: ");	//Lägg till felkorrigering
		scanf("%f", &in_voltage);
		if (in_voltage < 0)
		{
			printf("Fel: Spänningskällan måste ha ett positivt värde\n");
		} 
	}
	while (in_voltage < 0);
	
	do
	{
		//Kopplings typ
		printf("Ange koppling[S | P]: ");
		scanf("%s", &in_conn);
		if (in_conn != 'S' && in_conn != 'P') 
		{
			printf("Fel: tillåtna värden för koppling är: 'S' och 'P'\n");
		}
	}
	while (in_conn != 'S' && in_conn != 'P');
	
	do
	{
		//Antalet resistorer
		printf("Antal komponenter: ");
		scanf("%d", &count);
		if (count <= 0)
		{
			printf("Fel: måsta finnas minst en komponent");
		}
	}
	while (count <= 0);
	

	//Allokera ledigt minne för calloc!
	resistorValues = (float *) calloc(count, sizeof(float));
	for(int x = 0; x < count; x++)
	{
		do
		{
			printf("Komponent %d i ohm: ", x + 1);
			scanf("%f", &resistorValues[x]);
			if (resistorValues[x] <= 0)
			{
				printf("Fel: komponenten måste ha ett positivt värde.\n");
			}
		}
		while (resistorValues[x] <= 0); 
	}

	//Ersättningsresistans!
	ret_e_res = calc_resistance(count, in_conn, resistorValues); //float calc_resistance(int count, char conn, float *array)

	//Effekt
	ret_power = calc_power_r(ret_e_res, in_voltage); //float calc_power_r(float resistance, float voltage)

	//E12 resistanser
	count = e_resistance(ret_e_res, ptr_e12values);
	free(resistorValues);

	//Resultat!
	printf("Ersättningsresistans:\n%0.1f ohm\n", ret_e_res);
	printf("Effekt:\n%0.2f W\n", ret_power);
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

	for(int q = 0; q < count; q++)
	{
		printf("%0.0f\n", e12Values[q]);
	}
	return(0);
}
