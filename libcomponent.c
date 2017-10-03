#include <stdio.h>


#include "libcomponent.h"

int main ()
{

	float resistors[3], orig_resistance=0.0;     //Skriv in ett påhittat värde i variabel orig_resistance som motsvarar det totala resistans värdet.
    float *Ptr_resistors;


    Ptr_resistors = &resistors[0];     //Tilldelar pekaren Ptr.. första minnesadressen för arrayen.

	int count = e_resistance(orig_resistance, Ptr_resistors); //Skickar över minnesadress för resis    torerna, ändra variabel "orig_resistance" eller skriv in värdet direkt i funktions anropet
}	//Main end

int e_resistance(float orig_resistance, float *res_array){       //Funktionen

	int temp_value = orig_resistance;	// dekleration av variabler
	int index = 0;
	float *picked_values;
	int values[12] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};

	picked_values = res_array;	 //pekaren picked_values pekar mot pekare res_array, vilket är re    sistors arrayen i main...

	picked_values[0] = 0;	// Initiering och nollställning av minnesvärde
	picked_values[1] = 0;
	picked_values[2] = 0;
	while(temp_value >= 10 && index < 3 ){	//startar en while loop som slutar när resistorvärdet är under 10 eller 3 st komponenter redan är valda

	
	for( int i = 11; i != -1; --i ){	//en baklänges loop som går igenom de 12 värderna ur E12 serien. 

		if(temp_value > values[i]){		// om temp är större än största E12 värdet, eller näst högsta osv osv
			temp_value -= values[i];	//trimmar temp med matchande E12 värde.
			picked_values[index] = values[i];	// sparar E12 i arrray, denna returneras senare till main. Om decimal värden av serien ska användas så kan den utkommenterade raden under användas 
			//picked_values[index] = (double)values[i]/10; 
			index++; // +1 på index för att lägga nästa resistorvärde i annan array slot
			break;
	}
	}	
	
	}

   
	return(index);
}
