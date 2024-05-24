#include<stdio.h>

void prime(int a){
    if(a<=1){
     printf("%d is not prime",a);
     return ;  
    }
    int c=0;
    for(int i=1;i<=a;i++){
        if(a%i==0){
            c++;
        }
    }
    if(c==2){
        printf("%d is prime",a);
    }
    else
        printf("%d is not  prime",a);
 
}
int main(){
    int a;
    scanf("%d",&a);
    prime(a);
}