#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>

float soma(float a, float b){
    return a + b;
    
}
float subtracao(float a, float b){
    return a - b;
    
}
float multiplicacao(float a, float b){
    return a * b;
    
}
float divisao(float a, float b){
    return a / b;
    
}

void coleta()
{

    system("cls");
    int num;
    float a, b;
    printf("Digite 1 para soma\n");
    printf("Digite 2 para subtracao\n");
    printf("Digite 3 para multiplicacao\n");
    printf("Digite 4 para divisao\n");
    printf("Digite 5 para sair\n: ");
    
    while(num < 1 || num > 5)
    {
        scanf("%d", &num);
        if(num < 1 || num > 5)
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    system("cls");

    printf("Digite os numeros que deseja calcular: ");
    scanf("%f %f", &a, &b);

    switch(num){
        case 1:
            printf("Resultado: %.2f", soma(a, b));
            break;
        case 2:
            printf("Resultado: %.2f", subtracao(a, b));
            break;
        case 3:
            printf("Resultado: %.2f", multiplicacao(a, b));
            break;
        case 4:
            printf("Resultado: %.2f", divisao(a, b));
            break;
        case 5:
            exit(0);
            break;
    }
    Sleep(3000);

    printf("\n\nDeseja fazer outra operacao?(s/n): ");
    char op;
    while(op != 's' && op != 'n')
    {
        fflush(stdin);
        scanf(" %c", &op);
        fflush(stdin);
        if(op != 's' && op != 'n')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    if(op == 's')
    {
        coleta();
    } else {
        exit(0);
    }
}

int main(){
    coleta();
}