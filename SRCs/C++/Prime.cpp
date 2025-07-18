#include <iostream>
#include <windows.h>

bool isOdd(int n)
{
    if(n % 2 != 0)
    {
        return false;
    }
    return true;
}

bool isPrime(int n)
{

    if(n != 2 && isOdd(n))
    { 
        return false;
    }
    for(int i = n - 1; i > 2; i--)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    system("cls");
    printf("Enter a number: ");
    scanf("%d", &n);
    system("cls");
    if(isPrime(n))
    {
        printf("The number is prime!");
    }
    else{
        printf("Fuck you");
    }

    return 0;
}