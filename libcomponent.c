#include <stdio.h>
#include <math.h>

#include "libcomponent.h"

int main()        //Ett test program för att välja E12 resistorer beroende på vilken totalresistans som anges.
{
    float resistors[3], orig_resistance=0.0;     //Skriv in ett påhittat värde i variabel orig_resistance som motsvarar det totala resistans värdet.
    float *Ptr_resistors;

    Ptr_resistors = &resistors[0];     //Tilldelar pekaren Ptr.. första minnesadressen för arrayen.

    int count = e_resistance(orig_resistance, Ptr_resistors); //Skickar över minnesadress för resistorerna, ändra variabel "orig_resistance" eller skriv in värdet direkt i funktions anropet

    for(int x=0; x < count; x++)
        printf("Resistor %d: %0.1f\n", x+1, resistors[x]);      //Skriv ut vilka E12 resistanser som valdes

    printf("\ncount = %d", count);      //Skriv ut värdet på count

    return(0);        //Avsluta och retunera 0
}

int e_resistance(float orig_resistance, float *res_array)       //Funktionen
{
    int res_total = orig_resistance, temp_value = 0, count = 0, index_values = 0, x = 0, index = 0, values[12] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
    float *picked_values;
    double exponent = 0.0;

    picked_values = res_array;     //pekaren picked_values pekar mot pekare res_array, vilket är resistors arrayen i main...
    picked_values[0] = 0;          //Initiering och nollställning av minnesvärdena.
    picked_values[1] = 0;
    picked_values[2] = 0;

    for(int x = 0; x < 3; x++)      //Starta en for-loop som repeterar totalt 3 ggr.
    {
        temp_value = res_total;
        index = 0;
        index_values = 0;

        if(temp_value == 0)     //Om värdet som skickades var noll avsluta och retunera 0
            return(0);

        while(temp_value != 0)      //Så länge temp_value inte är lika med noll..
        {
            index++;                //Öka index med 1 och dividera temp_value med 10 för varje repetition.
            temp_value /= 10;
        }
        index--;       //Gå tillbaka ett steg

        if(index > 2)       //Om index har värdet 2 eller mer..
        {
            exponent = index - 1;       //Ställ exponenten till index-1
            temp_value = res_total;
            temp_value /= pow(10.0, exponent); //1000+ tal
        }
        else if(index == 2)
            temp_value = res_total / 10;   //100 tal
        else
            temp_value = res_total;      //Sub 100 tal

       while(temp_value >= values[index_values])   //Så länge tempvärdet är större eller lika med E12 resistorn öka index_values..
            index_values++;

        index_values--;     //Gå tillbaka ett steg

        if(index > 2)
        {
            exponent = index - 1; //Konvertera int -> double
            temp_value = picked_values[x] = values[index_values] * pow(10.0, exponent); //E12-resistorvärdet beräknas med en tio potens av index värdet.
        }
        else if(index == 2)
            temp_value = picked_values[x] = values[index_values] * 10.0;        //Om index värdet är lika med 2..
        else
        {
            if(res_total >= 8 && res_total < 10)        //Annars om index är mindre än 2... och resistans värdet är större/lika med 8 eller mindre än 10..
            {
                picked_values[x] = 10.0;        //Använd en avrundning och kör med en 10 ohms resistor..
                count++;
            }
            else
                temp_value = picked_values[x] = values[index_values];       //Annars använd E12 resistansen
        }

        count++;
        res_total %= temp_value;

        if(res_total == 0 || res_total <= 7)        //Kvar att göra.. problem om totalresistans värdet som skickas är < 8.. skräpvärden retuneras.
            break;                                  //Om resistansresten är mellan 0 eller 7 avfärda värdet...
    }

    return(count);      //Retunera komponent antalet...
}
