

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
    enum player {plus, minus};
    enum player gamer;
    int history[500];
    int throw;
    int d[7];
    int rand;
    int board = 10;
    int count=0;
    short winner=0;
    while((board != 1) && (board != 20))
    {

        gamer = minus;
        rand = dice_min_max(1,6);
        if((board - rand) < 1)
            board = board + rand;
        board = board - rand;
        history[count] = board;
        count++;

        if(board == 1){
            winner = 1;
            break;
        }

        gamer = plus;
        rand = dice_min_max(1,6);
        if((board + rand) > 20)
            board = board - rand;
        board = board + rand;
        history[count] = board;
        count++;
        if(board == 20)
        {
            winner=2;
            break;
        }
    }

    if(winner==1)
        printf("The winner is: Minus");
    else if(winner==2)
        printf("The winner is: Plus");
    else
        printf("Fehler");



    return 0;
}


