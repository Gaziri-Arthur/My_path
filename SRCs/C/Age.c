#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

void ask();


void printer(bool drink, bool vote, bool work, bool sexwadult, bool drive, int limitdatingage)
{
    system("cls");
    if(drink)
    {
        printf("Voce pode beber!\n");
    }
    else
    {
        printf("Voce nao pode beber!\n");
    }
    if(vote)
    {
        printf("Voce pode votar!\n");
    }
    else
    {
        printf("Voce nao pode votar!\n");
    }
    if(work)
    {
        printf("Voce pode trabalhar!\n");
    }
    else
    {
        printf("Voce nao pode trabalhar!\n");
    }
    if(sexwadult)
    {
        printf("Voce pode legalmente ter transar com adultos!\n");
    }
    else
    {
        printf("Voce nao pode legalmente ter transar com adultos!\n");
    }
    if(drive)
    {
        printf("Voce pode dirigir!\n");
    }
    else
    {
        printf("Voce nao pode dirigir!\n");
    }
    printf("A idade minima com que voce pode se relacionar e: %d\n", limitdatingage);

    Sleep(5000);
    printf("Deseja testar outra idade?(s/n): ");
    char op = 'a';
    while (op != 's' && op != 'n')
    {
        scanf(" %c", &op);
        if (op != 's' && op != 'n')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }

    if (op == 's')
    {
        ask();
    }
    char word[] = "Obrigado por trabalhar com nossos produtos!";
    system("cls");
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(80);
    }
    exit(0);

}

void process(int num)
{
    bool drink = false, vote = false, work = false, sexwadult = false, drive = false;
    int limitdatingage = 0;

    if(num >= 18){drink = true; drive = true;}
    if(num >= 16){vote = true;}
    if(num >= 14){sexwadult = true; work = true;} 
    limitdatingage = (num/2) + 7;

    printer(drink, vote, work, sexwadult, drive, limitdatingage);

}

void ask()
{   
    int num = 0;
    system("cls");
    printf("Digite sua idade: ");  
    while(num <= 0 || num > 112)
    {
        scanf("%d", &num);
        if(num <= 0 || num > 112)
        {
            printf("Idade invalida! Digite novamente: ");
        }
    }     
    system("cls");
    printf("Processando");
    for(int i = 0; i < 3; i++)
    {
        Sleep(400);
        printf(".");
    }
    process(num);
}

int main()
{
    ask();
}