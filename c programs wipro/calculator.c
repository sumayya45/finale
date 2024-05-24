#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a, b;
    int val;
    printf("enter 1st value :");
    scanf("%d", &a);
    printf("enter 2nd value :");
    scanf("%d", &b);
    printf("enter 1 if you want to perform addition \n");
    printf("enter 2 if you want to perform subtraction \n");
    printf("enter 3 if you want to perform multiplication \n");
    printf("enter 4 if you want to perform division \n");
    scanf("%d", &val);
    switch (val)
    {
    case 1:
        printf("addition of %d %d is :%d", a, b, a + b);
        break;
    case 2:
        printf("subtraction of %d %d is :%d", a, b, a - b);
        break;
    case 3:
        printf("multiplication of %d %d is :%d", a, b, a * b);
        break;
    case 4:
        printf("division of %d %d is :%d", a, b, a / b);
        break;
    default:
        printf("noen of the above");
    }
}