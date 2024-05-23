#include <stdio.h>
#include <conio.h>
#include <string.h>
struct emp
{
    char name[30];
    int age;
    float salary;
    };

void main()
{
    struct emp p1;
    strcpy (p1.name, "myname");
    p1.age = 27;
    p1.salary = 10000;
    printf("Name:: %s", p1.name);
    printf("\nage:: %d", p1.age);
    printf("\nSalary:: %.2f",p1.salary);
}