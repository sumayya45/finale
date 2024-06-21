#include<stdio.h>
#include<stdlib.h>
int values(int n){
if(n==0) return 0;
printf("%d\n",n);
values(n-1);
// values(n+1);

}
int main(){
    int n;
    printf("enter n value");
scanf("%d",&n);
values(n);
}