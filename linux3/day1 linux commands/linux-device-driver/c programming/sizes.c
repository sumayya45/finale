#include <stdio.h>
 
int main() {
    int array[5];
    int *ptr;
 
    ptr = array;
    printf("Size of the array                           : %zu bytes\n", sizeof(array));
    printf("Size of the pointer                         : %zu bytes\n", sizeof(ptr));
 
    printf("Size of an element in the array             : %zu bytes\n", sizeof(array[0]));
    printf("Size of an element pointed to by the pointer: %zu bytes\n", sizeof(ptr[0]));
 
 
    printf("Number of elements in the array             : %zu\n", sizeof(array) / sizeof(array[0]));
 
    return 0;
}