#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>

int random()
{   
    int count = 0;
    srand(time(NULL));
    for(int i; i !=69; i = (rand() % 100) + 1, count ++);
    printf("%d\n", count);
    return count;
}

int main()
{   
    long int bigcount = 0;
    for(int i = 0; i < 100; i++)
    {
        bigcount += random();
    }

    printf("\n\n%li eh a media de geracoes que aleatorias que o programa faz ate gerar 69 (100)\n", bigcount);
}