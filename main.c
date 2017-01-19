

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



int dice_min_max(int min, int max)
{
    int throw, ticks1, ticks2;
    ticks1=ticks2= clock();
    while (ticks2< ticks1+1)
    {
        ticks2=clock();
    }
    srand(ticks2);
    double range = max - min + 1;
    throw = rand() % (int) range + min;
    return throw;
}



int main()
{
    enum spieler {plus, minus};
    enum spieler gamer;
    int verlauf[500];
    int wurf;
    int d[7];
    int rand;
    int feld = 10;
    int zaehl=0;
    while((feld != 1) && (feld != 20))
    {

        gamer = minus;
        rand = dice_min_max(1,6);
        if((feld - rand) < 1)
            feld = feld + rand;
        feld = feld - rand;
        verlauf[zaehl] = feld;
        zaehl++;

        if(feld == 1){
            break;
        }

        gamer = plus;
        rand = dice_min_max(1,6);
        if((feld + rand) > 20)
            feld = feld - rand;
        feld = feld + rand;
        verlauf[zaehl] = feld;
        zaehl++;
        if(feld == 20)
        {
            break;
        }
    }




    return 0;
}


