#include <stdio.h>

#include "libcomponent.h"

int main ()
{

	float resistors[3], orig_resistance=0.0;     //Skriv in ett påhittat värde i variabel orig_resistance som motsvarar det totala resistans värdet.
    float *Ptr_resistors;


    Ptr_resistors = &resistors[0];     //Tilldelar pekaren Ptr.. första minnesadressen för arrayen.

	int count = e_resistance(orig_resistance, Ptr_resistors); //Skickar över minnesadress för resis    torerna, ändra variabel "orig_resistance" eller skriv in värdet direkt i funktions anropet
    for(int x=0; x < count; x++)
		printf("Resistor %d: %0.1f\n", x+1, resistors[x]);      //Skriv ut vilka E12 resistanser so    m valdes

    printf("\ncount = %d\n", count);      //Skriv ut värdet på count

}	//Main end

int e_resistance(float orig_resistance, float *res_array){       //Funktionen

	int temp_value = orig_resistance;	// dekleration av variabler
	int index = 0;
	int multiplier = 1000000;
	float *picked_values;
	double values[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

	picked_values = res_array;	 //pekaren picked_values pekar mot pekare res_array, vilket är re    sistors arrayen i main...

	picked_values[0] = 0;	// Initiering och nollställning av minnesvärde
	picked_values[1] = 0;
	picked_values[2] = 0;
	while(temp_value >= 1 && index < 3 ){	//startar en while loop som slutar när resistorvärdet är under 10 eller 3 st komponenter redan är valda

		for( int j = 0; j <= 3; j++){	//loop för att gå igenom alla resistorvärden i omfången 1 Ω till 1 MΩ
		


			for( int i = 11; i != -1; --i ){	//en baklänges loop som går igenom de 12 värderna ur E12 serien. 

				if(temp_value >= values[i] * multiplier){		// om temp är större än största E12 värdet, eller näst högsta osv osv
				temp_value -= values[i] * multiplier;	//trimmar temp med matchande E12 värde.
				picked_values[index] = values[i] * multiplier;	// sparar E12 i arrray, denna returneras senare till main. Om decimal värden av serien ska användas så kan den utkommenterade raden under användas 
				//picked_values[index] = (double)values[i]/10; 
				index++; // +1 på index för att lägga nästa resistorvärde i annan array slot
				break;	//break behövs för att låta while loopen kolla om index påståendet fortfarande är sant.
				}
			}	
			multiplier /= 10;	//Tar stegvis bort en nolla i resistorvärde
			break;
		}	
	}
	return(index);
}
