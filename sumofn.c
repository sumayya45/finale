#include <stdio.h>
int sum(int n);

int sum(int n) {
    if (n != 0)
    //function calls itself
        return n + sum(n-1); 
    return n;
}
int main() {
    int number, result;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    result = sum(number);
    printf("sum = %d", result);
    return 0;
}
