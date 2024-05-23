// C code to find day of a given date
#include <stdio.h>

int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d)
           % 7;
}

// Driver function to test above function
int main()
{
    int dd,mm,yyyy;
    printf(" Enter the date (dd/mm/yyyy) : ");
    scanf("%d/%d/%d",&dd,&mm,&yyyy);
    printf("\n Day of the given date is : ");
    int day = dayofweek(dd, mm, yyyy);
    switch (day) {
    case 0:
        printf("Sunday\n");
        break;
    case 1:
        printf("MOnday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
    }

}