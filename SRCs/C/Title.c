#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void title(char *tile)
{
    int strlenght = strlen(tile);
    for (int i = 0; i < strlenght; i++)
    {
        printf("%c", tile[i]);
        Sleep(100);
    }
    Sleep(1500);
}

int main()
{
    char str[100];
    system("cls");
    char *key = "Stop";
    while (1)
    {
        printf("Type a title: ");
        gets(str);
        if(strcmp(str, key) == 0)
        {
            printf("Exiting...");
            break;
        }
        title(str);
        printf("!");
        system("cls");
    }

    return 0;
}