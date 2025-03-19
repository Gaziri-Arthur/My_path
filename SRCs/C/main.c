#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char const *argv[])
{
    int vet[10];

    for(int i = 0; i < 10; i++)
    {
        printf("Digite um valor para a %d posicao do vetor: ", i + 1);
        scanf("%d", &vet[i]);
    }

    return 0;
}