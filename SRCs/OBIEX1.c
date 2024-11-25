#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

typedef struct{
    
    int grupo;
    int vitorias;
    
} Jogador;

Jogador *Lista = NULL;
int numjogador;

bool verifica(char op);
void menu();
bool validasimnao(char op);
void cadastro();
void limpamemoria();
void printer();
void saudacao();

bool verifica(char op)
{
    if(op != 'V' && op != 'P')
    {
        return false;
    }
    return true;
}

bool validasimnao(char op)
{
    if (op != 's' && op != 'n')
    {
        return false;
    }
    return true;
}

void cadastro()
{
    bool ver = false;
    char op = 'a';

    system("cls");
    printf("***Jogador numero %d***\n\n", numjogador + 1);
    if(numjogador < 1)
    {
        Lista = (Jogador *)malloc(1 * sizeof(Jogador));
    }
    else
    {
        Lista = (Jogador *)realloc(Lista, (numjogador + 1) * sizeof(Jogador));
    }
    Lista[numjogador].vitorias = 0; 

    printf("Identifique se o jogador ganhou ou perdeu (V/P)\n\n");
    for(int i = 0; i < 6; i++)
    {
        printf("Jogo %d: ", i + 1);
        while(!ver)
        {
            fflush(stdin);
            scanf(" %c", &op);
            fflush(stdin);
            ver = verifica(op);
            if(!ver)
            {
                printf("Operador invalido! Digite novamente: ");
            }
        }
        ver = false;
        if(op == 'V')
        {
            Lista[numjogador].vitorias++;

        }
    }

    if(Lista[numjogador].vitorias < 1)
    {
        Lista[numjogador].grupo = -1;
    } else if(Lista[numjogador].vitorias < 3)
    {
        Lista[numjogador].grupo = 3;
    } else if(Lista[numjogador].vitorias < 5)
    {
        Lista[numjogador].grupo = 2;
    } else 
    {
        Lista[numjogador].grupo = 1;
    }
    
    numjogador++;
    system("cls");
    printf("Deseja casdastrar outro jogador? (s/n): ");
    while(!ver)
    {
        scanf("%c", &op);
        ver = validasimnao(op);
        if(!ver)
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }
    if(op == 's')
    {
        cadastro();
    }
    else
    {
        menu();
    }
}

void limpamemoria()
{
    char word[] = "Obrigado por trabalhar com nossos produtos!";

    free(Lista);
    system("cls");
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(80);
    }
    exit(0);
}

void printer()
{
    for(int i = 0; i < numjogador; i++)
    {
        printf("Jogador %d:\nGrupo: %d\n\n", i + 1, Lista[i].grupo);
    }
    Sleep(1000);
    printf("Pressione ENTER para voltar: ");
    while (getchar() != '\n');
    getchar();
    menu();

}

void menu()
{
    char op = 'a';
    system("cls");
    printf("Digite 1 pra cadastrar um jogador\n");
    printf("Digite 2 para mostrar os resultados de grupo\n");
    printf("Digite 3 para sair\n: ");
    while(op != '1' && op != '2' && op != '3')
    {   
        fflush(stdin);
        scanf(" %c", &op);
        fflush(stdin);
        if(op != '1' && op != '2' && op != '3')
        {
            printf("Operador invalido! Digite novamente: ");
        }
    }
    
    switch(op){

        case '1':
            cadastro();
            break;
        case '2':
            if(numjogador < 1)
            {
                printf("Nao ha jogadores para serem exibidos!");
                Sleep(1000);
                menu();
            }
            else {
                printer();
            }
            
        case '3':
            limpamemoria();
    }


}

void saudacao()
{
    char word[] = "Hello, world!";

    system("cls");
    for (int i = 0; word[i] != '\0'; i++)
    {
        printf("%c", word[i]);
        Sleep(100);
    }
    Sleep(1000);
    system("cls");
    printf("***TORNEIO DE TENIS***\n\n");
    Sleep(2000);
    menu();
    
}
    
int main()
{
    saudacao();
}