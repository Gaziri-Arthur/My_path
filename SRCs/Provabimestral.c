#include <stdio.h>
#define A 4//constante alunos
#define B 3//constante data
#define C 2//constante linha
#define L 100 
void nasc();
int validarconceito23(int i, int j);
int validarconceito24(int i, int j);        
int validecoef(int coef);
int valide_data(int dias, int mes, int ano);
char conc23[A][A], conc24[A][A];
int coef[C][A];

int main ()
{
    char alunos24[A][L], alunos23[A][L];
    int i, j = 0, aux, nasc23[A][B], nasc24[A][B], res, melhor23, melhor24;
    float med1 = 0, med2 = 0, med3 = 0, coef23[A], coef24[A], maior23 = 0, maior24 = 0;
    
    printf("DIGITE O NOME DOS ALUNOS DE INFO23:\n");
    for (i = 0; i < A; i++)//nomear alunos 23
    {
        printf("\nNome do aluno (%d) de info 23: ", i + 1);
        gets(alunos23[i]);
        fflush(stdin);
    }
    printf("DIGITE O NOME DOS ALUNOS DE INFO24:\n");
    for (i = 0; i < A; i++)//nomear alunos 24
    {
        printf("\nNome do aluno (%d) de info 24: ", i + 1);
        gets(alunos24[i]);
        fflush(stdin);
    }
    
    printf("\nDIGITE CONCEITOS PARA OS ALUNOS DE INFO 23 (A, B, C, D.)\n\n");
    for(i = 0; i < A; i++) // Conceituar alunos 23
    {
    j = 0;
        while(j < A)
        {
            printf("Digite o conceito do %d° bimestre do aluno\n", j + 1);
            puts(alunos23[i]);
            scanf(" %c", &conc23[i][j]); //posição da matriz
            aux = validarconceito23(i, j);//invoca função validar conceito
            if (aux == 1)
            {
                j++;
            }
        }
    }

    printf("\nDIGITE CONCEITOS PARA OS ALUNOS DE INFO 24 (A, B, C, D.)\n\n");    
    for(i = 0; i < A; i++) // Conceituar alunos 23
    {
        j = 0;
        while(j < A)
        {
            printf("Digite o conceito do %d° bimestre do aluno\n", j + 1);
            puts(alunos24[i]);
            scanf(" %c", &conc24[i][j]); 
            aux = validarconceito24(i, j);
            if (aux == 1)
            {
                j++;
            }
        }
    }
    
    for(i=0; i<A; i++)//ler data info23
    {
        nasc();
        puts (alunos23[i]);
        scanf("%d%d%d", &nasc23[i][0], &nasc23[i][1], &nasc23[i][2]);
        res = valide_data(nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        while (res == 0)
        {
            printf("Valor invalido, digite outro numero: ");
            scanf("%d%d%d", &nasc23[i][0], &nasc23[i][1], &nasc23[i][2]);
            res = valide_data(nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        }
    }
    for(i=0; i<A; i++)//info24
    {
        nasc();//Função de print
        puts (alunos24[i]);
        scanf("%d%d%d", &nasc24[i][0], &nasc24[i][1], &nasc24[i][2]);
        res = valide_data(nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        while (res == 0)
        {
            printf("Valor invalido, digite outro numero: ");
            scanf("%d%d%d", &nasc24[i][0], &nasc24[i][1], &nasc24[i][2]);
            res = valide_data(nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        }
    }
    
    printf("\nDIGITE COEFICIENTES DE RENDIMENTO PARA OS ALUNOS DE INFO23\n\n");//INFO23
    for(i=0; i<A; i++)
    {
        printf("COEFICIENTE DO ALUNO ");
        puts(alunos23[i]);
        scanf("%f", &coef23[i]);
    }
    printf("\nDIGITE COEFICIENTES DE RENDIMENTO PARA OS ALUNOS DE INFO24\n\n");//INFO23
    for(i=0; i<A; i++)
    {
        printf("COEFICIENTE DO ALUNO ");
        puts(alunos24[i]);
        scanf("%f", &coef24[i]);
    }
    for (i = 0; i < A; i++)
    {
        if (maior23 < coef23[i])
        {
            maior23 = coef23[i];
            melhor23 = i;
        }
    }
    printf ("%d", melhor23);
    for (i = 0; i < A; i++)
    {
        if (maior24 < coef24[i])
        {
            maior24 = coef24[i];
            melhor24 = i;
        }
    }
    for(i=0;i<A;i++)//mediador1
    {
        med1 += coef23[i];  
        med2 += coef24[i];
    }
    
    med1 = med1/4;
    med2 = med2/4;
    med3 = med1 + med2;
    med3 = med3/2;
    
///////////////////////////////////////////////////////////////////////////////////////////
    
    printf("\n\n\n*EXIBIÇÃO FINAL*\n\n");
    
    for(i=0;i<A;i++)//print23
    {
        puts(alunos23[i]);
        printf("NASCIDO EM (%d/%d/%d)\n", nasc23[i][0], nasc23[i][1], nasc23[i][2]);
        printf("SEUS CONCEITOS FORAM: ");
        for(j=0;j<A;j++)
        {
            printf("%c ", conc23[i][j]);
        }
        printf("\nSEU COEFICIENTE FOI: %.2f.", coef23[i]);
        printf("\n\n");
    } 
    
    for(i=0;i<A;i++)//print24
    {
        puts(alunos24[i]);
        printf("NASCIDO EM (%d/%d/%d)\n", nasc24[i][0], nasc24[i][1], nasc24[i][2]);
        printf("SEUS CONCEITOS FORAM: ");
        for(j=0;j<A;j++)
        {
            printf("%c ", conc24[i][j]);
        }
        printf("\nSEU COEFICIENTE FOI: %.2f.", coef24[i]);
        printf("\n\n");
    } 
    if (maior23 > maior24)
    {
        printf("O MAIOR COEFICIENTE FOI %.2f DO ALUNO ", maior23);
        puts(alunos23[melhor23]);
    }
    else
    {
        printf("O MAIOR COEFICIENTE FOI %.2f DO ALUNO ", maior24);
        puts(alunos24[melhor24]);
    }
    printf("\nA MÉDIA DE COEFICIENTES DA TURMA INFO23 FOI %.2f\n", med1);
    printf("\nA MÉDIA DE COEFICIENTES DA TURMA INFO24 FOI %.2f\n", med2);
    printf("\nA MÉDIA DE COEFICIENTES DAS TURMAS JUNTAS FOI %.2f\n", med3);
    
}

int validarconceito23(int i, int j)
{
    if(conc23[i][j] == 'A' || conc23[i][j] == 'B' || conc23[i][j] == 'C' || conc23[i][j] == 'D')
    {
        return 1;
    }
    return 0;
}
int validarconceito24(int i, int j)
{
    if(conc24[i][j] == 'A' || conc24[i][j] == 'B' || conc24[i][j] == 'C' || conc24[i][j] == 'D')
    {
        return 1;
    }
    return 0;
}

int valide_data(int dias, int mes, int ano)
{
    if (mes > 12 || mes <= 0)
    {
        return 0;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dias <= 0 || dias > 31)
        {
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dias <= 0 || dias > 30)
        {
            return 0;
        }
    }
    if (ano % 4 == 0 && mes == 2)
    {
        if (dias <= 0 || dias > 29)
        {
            return 0;
        }
    }
    else if (mes == 2)
    {
        if (dias <= 0 || dias > 28)
        {
            return 0;
        }
    }
    return 1;
}
void nasc()
{
    printf("Digite o dia, mes e o ano para a data de nascimento do aluno:");
}
int validecoef(int coef)
{
    if(coef > 10 || coef < 0)
    {
        return 0;
    }
    return 1;
}