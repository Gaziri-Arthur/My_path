#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>


int f(int x)
{
    return 2 * pow(3, x);
}

int g(int x)
{
    return pow(5, x) - 2;
}

int h(int x)
{
    return pow(5, (x - 2));
}

int main(){
    
    int op = 0;
    int x = 0;

    system("cls");
    while(op != 4)
    {
        printf("Choose an option:\n");
        printf("1. f(x)\n");
        printf("2. g(x)\n");
        printf("3. h(x)\n");
        printf("4. Exit\n");
        scanf("%d", &op);

        if(op >= 1 && op <= 3) {
            printf("Enter x: ");
            scanf("%d", &x);
        }

        switch(op) {
            case 1:
                printf("f(%d) = %d\n", x, f(x));
                break;
            case 2:
                printf("g(%d) = %d\n", x, g(x));
                break;
            case 3:
                printf("h(%d) = %d\n", x, h(x));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
        system("pause");
        system("cls"); 

    }
    return 0;
}