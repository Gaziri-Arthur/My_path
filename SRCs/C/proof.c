#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void checkNewlineInput(void);

int main(void)
{
    system("cls");
    checkNewlineInput();
    return 0;
}

void checkNewlineInput(void)
{
    printf("digite uma barra n: ");
    while (getchar() != '\n')
        ;
    getchar();
    printf("voce digitou um barra n");
}
