// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char arr[3][50];
//     printf("enter the elements of the array");
//     for (int i = 0; i < 3; i++)
//     {
//         scanf("%s\n", &arr[i]);
//     }
//     printf("the elements of the array are");
//     for (int i = 0; i < 3; i++)
//     {
//         printf(" %s\n", arr[i]);
//     }
// }
#include <stdio.h>
#include <stdlib.h>

int main() {
    char arr[3][50];
    FILE *file = fopen("f:\\names.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the names of the students:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name %d: ", i + 1);
        scanf("%49s", arr[i]); // 49 to prevent buffer overflow
        fprintf(file, "%s\n", arr[i]);
    }

    printf("The names of the students are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }

    fclose(file);
    return 0;
}
