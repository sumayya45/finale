#include <stdio.h>
 
struct name {
    int member1;
    int member2;
 
};
 
int main()
{
    struct name *ptr, Harry;
 
    printf("Size of struct name: %zu bytes\n", sizeof(struct name));
    printf("Size of member1: %zu bytes\n", sizeof(Harry.member1));
    printf("Size of member2: %zu bytes\n", sizeof(Harry.member2));
    ptr=&Harry;
    printf("addres of name %zu",ptr);
    ptr=&Harry.member1;
    printf("address of Harry %zu",ptr); 

 
 
    return 0;
}
