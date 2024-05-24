#include<stdio.h>
#include<stdlib.h>
int values(int n){
if(n==0) return 0;
return n+values(n-1);
}
int main(){
    int n;
    printf("enter n value");
scanf("%d",&n);
int sum=values(n);
printf("th tot sum is %d",sum);
}