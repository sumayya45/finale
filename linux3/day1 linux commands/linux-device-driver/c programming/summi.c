// C Program to illustrate file opening
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n;
    FILE *fptr;
    fptr = fopen("F:\\my c programs\\news.txt", "a");
    if (fptr == NULL)
    {
        printf("the program doesnt exist ...");
    }

    printf("enter number %d");
    scanf("%d", &n);
    fprintf(fptr, "%d", n);
    fclose(fptr);
}
