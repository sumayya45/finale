#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int fact=1;
    printf("enter the value to calculate the factorial of : ");
    scanf("%d",&n);
    if(n==0){
        printf("enter tha value other than 0");
    }
    else{
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    printf("the factorial of %d is %d",n,fact);
}
}