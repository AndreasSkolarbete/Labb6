#include <stdio.h>

float calc_resistance(int, char, float *);

int main()     //Ett test program för att beräkna resistansen
{
    float test[2], sum_denum=0, value=0;
    float *array = &test; //Pekare mot test array!
    int x = 0;

    test[0] = 20.0;     //Test värden..
    test[1] = 47.0;

    float Val = calc_resistance(2, 'P', array);
    printf("Value for a parallel curcuit: %0.2f Ohm\n", Val);       //Skriv ut parallelt resultat med två värde siffror

    Val = calc_resistance(2, 'S', array);
    printf("Value for a serial curcuit: %0.2f Ohm\n", Val);         //Skriv ut seriellt resultat med två värde siffror

    return(0);      //Avsluta och retunera 0
}

float calc_resistance(int count, char conn, float *array)   //Funktionen
{
    float return_value=0, sum_denum=0;
    int x;

    if(conn == 'P')         //Om connection är satt till parallel exekvera detta..
    {
        for(x=0; x < count; x++)
        {
            if(array[x] == 0)       //Om värdet är noll retunera 0
                return(0.0);
            else
                sum_denum += 1/array[x];        //Summera alla värden enligt formeln: 1/TOTres = 1/R1 + 1/R2 + 1/Rx ...
        }

        return_value = 1/sum_denum;

        return(return_value);
    }
    else if(conn == 'S')        //Om connection är satt till seriellt exekvera detta..
    {
        for(x=0; x < count; x++)
        {
            return_value += array[x];
        }

        return(return_value);
    }

    return(-1);             //Om metoden inte exekverar något av de två alternativen retunera -1 ( = Fel).
}
