#include <stdio.h>

e_resistance(float, float *);

float main()        //Ett test program f�r att v�lja E12 resistorer beroende p� vilken totalresistans som anges.
{
    float resistors[3], orig_resistance=18.0;     //Skriv in ett p�hittat v�rde i variabel orig_resistance som motsvarar det totala resistans v�rdet.
    float *res_array;

    res_array = &resistors;     //Tilldelar minnesadress till pekaren res_array

    int count = e_resistance(orig_resistance, res_array); //Skickar �ver minnesadress f�r resistorerna, �ndra variabel "orig_resistance" eller skriv in v�rdet direkt i funktions anropet

    for(int x=0; x < count; x++)
        printf("Resistor %d: %0.1f\n", x+1, res_array[x]);      //Skriv ut vilka E12 resistanser som valdes

    printf("\ncount = %d", count);      //Skriv ut v�rdet p� count

    return(0.0);        //Avsluta och retunera 0
}

int e_resistance(float orig_resistance, float *res_array)       //Funktionen
{
    int res_total = orig_resistance, temp_value = 0, count = 0, index_values = 0, x = 0, index = 0, values[12] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
    float *picked_values;
    double exponent = 0.0;

    picked_values = res_array;     //pekaren picked_values pekar mot pekare res_array, vilket �r resistors arrayen i main...
    picked_values[0] = 0;          //Initiering och nollst�llning av minnesv�rdena.
    picked_values[1] = 0;
    picked_values[2] = 0;

    for(int x = 0; x < 3; x++)      //Starta en for-loop som repeterar totalt 3 ggr.
    {
        temp_value = res_total;
        index = 0;
        index_values = 0;

        if(temp_value == 0)     //Om v�rdet som skickades var noll avsluta och retunera 0
            return(0);

        while(temp_value != 0)      //S� l�nge temp_value inte �r lika med noll..
        {
            index++;                //�ka index med 1 och dividera temp_value med 10 f�r varje repetition.
            temp_value /= 10;
        }
        index--;       //G� tillbaka ett steg

        if(index > 2)       //Om index har v�rdet 2 eller mer..
        {
            exponent = index - 1;       //St�ll exponenten till index-1
            temp_value = res_total;
            temp_value /= pow(10.0, exponent); //1000+ tal
        }
        else if(index == 2)
            temp_value = res_total / 10;   //100 tal
        else
            temp_value = res_total;      //Sub 100 tal

       while(temp_value >= values[index_values])   //S� l�nge tempv�rdet �r st�rre eller lika med E12 resistorn �ka index_values..
            index_values++;

        index_values--;     //G� tillbaka ett steg

        if(index > 2)
        {
            exponent = index - 1; //Konvertera int -> double
            temp_value = picked_values[x] = values[index_values] * pow(10.0, exponent); //E12-resistorv�rdet ber�knas med en tio potens av index v�rdet.
        }
        else if(index == 2)
            temp_value = picked_values[x] = values[index_values] * 10.0;        //Om index v�rdet �r lika med 2..
        else
        {
            if(res_total >= 8 && res_total < 10)        //Annars om index �r mindre �n 2... och resistans v�rdet �r st�rre/lika med 8 eller mindre �n 10..
            {
                picked_values[x] = 10.0;        //Anv�nd en avrundning och k�r med en 10 ohms resistor..
                count++;
            }
            else
                temp_value = picked_values[x] = values[index_values];       //Annars anv�nd E12 resistansen
        }

        count++;
        res_total %= temp_value;

        if(res_total == 0 || res_total <= 7)        //Kvar att g�ra.. problem om totalresistans v�rdet som skickas �r < 8.. skr�pv�rden retuneras.
            break;                                  //Om resistansen resten �r mellan 0 eller 7 avf�rda v�rdet...
    }

    return(count);      //Retunera komponent antalet...
}
