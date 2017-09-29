#include <stdio.h>

float calc_resistance(int, char, float *);

int main()     //Ett test program f�r att ber�kna resistansen
{
    float test[2], sum_denum=0, value=0;
    float *array = test; //Pekare mot test array!
    int x = 0;

    test[0] = 20.0;     //Test v�rden..
    test[1] = 47.0;

    float Val = calc_resistance(2, 'P', array);
    printf("Value for a parallel curcuit: %0.2f Ohm\n", Val);       //Skriv ut parallelt resultat med tv� v�rde siffror

    Val = calc_resistance(2, 'S', array);
    printf("Value for a serial curcuit: %0.2f Ohm\n", Val);         //Skriv ut seriellt resultat med tv� v�rde siffror

    return(0);      //Avsluta och retunera 0
}

float calc_resistance(int count, char conn, float *array)   //Funktionen
{
    float return_value=0, sum_denum=0;
    int x;

    if(conn == 'P')         //Om connection �r satt till parallel exekvera detta..
    {
        for(x=0; x < count; x++)
        {
            if(array[x] == 0)       //Om v�rdet �r noll retunera 0
                return(0.0);
            else
                sum_denum += 1/array[x];        //Summera alla v�rden enligt formeln: 1/TOTres = 1/R1 + 1/R2 + 1/Rx ...
        }

        return_value = 1/sum_denum;

        return(return_value);
    }
    else if(conn == 'S')        //Om connection �r satt till seriellt exekvera detta..
    {
        for(x=0; x < count; x++)
        {
            return_value += array[x];
        }

        return(return_value);
    }

    return(-1);             //Om metoden inte exekverar n�got av de tv� alternativen retunera -1 ( = Fel).
}
