#include <stdio.h>
#include <string.h>
void create();
void view();
void edit();
void delete();
void choice();


void choice(){
    int choic;
    printf("\nWELCOME TO OMG COMPANY\n");
    start:
    printf("--------------------------------\n");
    printf("Press 1 to Create a new Data\n");
    printf("Press 2 to View the Data\n");
    printf("Press 3 to edit the Data\n");
    printf("Press 4 to delete the Data\n");
    printf("Press 5 to exit the Program...!\n");
    printf("--------------------------------\n");

    int choice;
    scanf("%d",&choice);

    if(choice==5){
        printf("Exiting the Program...\n");
        return ;
    }
    switch (choice)
    {
    case 1:
        create();
        printf("Do you wish to continue? 1 for Yes 0 for No\n");
        scanf("%d",&choic);

        if(choic==1){
            goto start;
        }
        else if(choic==0){
            printf(" exiting the program......!\n");
        }
        break;
    case 2:
        view();
        printf("Do you wish to continue? 1 for Yes 0 for No\n");
        scanf("%d",&choic);

        if(choic==1){
            goto start;
        }
        else if(choic==0){
            printf(" exiting the program......!\n");
        }
        break;
    case 3:
        edit();
        printf("Do you wish to continue? 1 for Yes 0 for No\n");
        scanf("%d",&choic);

        if(choic==1){
            goto start;
        }
        else if(choic==0){
            printf(" exiting the program......!\n");
        }
        break;
    case 4:
        delete();
        printf("Do you wish to continue? 1 for Yes 0 for No\n");
        scanf("%d",&choic);

        if(choic==1){
            goto start;
        }
        else if(choic==0){
            printf(" exiting the program......!\n");
        }
        break;
    default:
        break;
    }
}
struct emp
{
    int id;
    char name[30];
    int age;
    char branch[20];
    char designation[20];
}emp;
void create(){
    struct emp p1;
    FILE *fp=fopen("F:\\Demo1.txt", "a");
    if(fp==NULL){
        printf("Error opening File");
        return ;
    }
    printf("\nEnter Employee Id:");
    scanf("%d",&p1.id);
    // fflush(stdin);

    printf("\nEnter Employee name: ");
    scanf("%s", p1.name);
    strcpy (p1.name, p1.name);

    printf("\nEnter Employee Age: ");
    scanf("%d", &p1.age);

    printf("\nEnter Employee Branch:");
    scanf("%s", p1.branch);

    printf("\nEnter Employee Designation:");
    scanf("%s", p1.designation);


    //fprintf(fp,"Employee Id:%d\n Employee Name:%s\n Employee Age: %d \n Employee Branch:%s\n Employee Designation :%s\n\n ",p1.id,p1.name,p1.age,p1.branch,p1.designation);
    fwrite(&p1,sizeof(emp),1,fp);
    printf("Data Uploaded Successfully\n");
    fclose(fp);
}

void view(){
    struct emp p1;
    FILE *ptr;
    ptr=fopen("F:\\Demo1.txt", "r");
    if(ptr==NULL){
        printf("Failed to open File\n");
        return;
    }
    while(fread(&p1,sizeof(emp),1,ptr)){
        printf("%d %s %d %s %s\n",p1.id,p1.name,p1.age,p1.branch,p1.designation);
    }
    fclose(ptr);
}

void edit(){
     struct emp p1;
    FILE *ptr, *ptr1;
    int c = 0;
    int a;

    ptr = fopen("F:\\Demo1.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file for reading\n");
        return ;
    }

    ptr1 = fopen("F:\\temp.txt", "w");
    if (ptr1 == NULL) {
        printf("Error opening file for writing\n");
        fclose(ptr);
        return ;
    }

    printf("Enter the Employee Id to Modify the Data:\n");
    scanf("%d", &a);

    while (fread(&p1, sizeof(struct emp), 1, ptr)) {
        if (a == p1.id) {
            c = 1;
            printf("Enter New Employee name: \n");
            scanf("%s", p1.name);

            printf("Enter New Employee Age: \n");
            scanf("%d", &p1.age);

            printf("Enter New Employee Branch:\n");
            scanf("%s", p1.branch);

            printf("Enter New Employee Designation:\n");
            scanf("%s", p1.designation);
        }
        fwrite(&p1, sizeof(struct emp), 1, ptr1);
    }

    fclose(ptr);
    fclose(ptr1);

    if (c == 0) {
        printf("Employee Not found\n");
    } else {
        ptr1 = fopen("F:\\temp.txt", "r");
        ptr = fopen("F:\\Demo1.txt", "w");
        if (ptr == NULL) {
            printf("Error opening file for writing\n");
            fclose(ptr1);
            return ;
        }
        if (ptr1 == NULL) {
            printf("Error opening file for reading\n");
            fclose(ptr);
            return ;
        }

        while (fread(&p1, sizeof(struct emp), 1, ptr1)) {
            fwrite(&p1, sizeof(struct emp), 1, ptr);
        }

        fclose(ptr);
        fclose(ptr1);
        remove("F:\\temp.txt");
    }

}

void delete(){
    FILE *ptr, *ptr1;
    struct emp p1;

    ptr = fopen("F:\\Demo1.txt", "r");
    ptr1 = fopen("F:\\temp.txt", "w");

    if(ptr == NULL){
        printf("Error opening files for deleting\n");
        fclose(ptr);

        return;
    }
    if(ptr1==NULL){
        printf("Error opening files for deleting\n");
        fclose(ptr1);
        return ;
    }
    printf("Enter the employee id to delete\n");
    int a;
    scanf("%d", &a);
    int c = 0;
    while (fread(&p1, sizeof(struct emp), 1, ptr)){
        printf("%d",p1.id);
        if(a == p1.id){
            c = 1;
        } else {
            fwrite(&p1, sizeof(struct emp), 1, ptr1);
        }
    }
    fclose(ptr1);
    fclose(ptr);

    if(c == 1){
        ptr = fopen("F:\\temp.txt", "r");
        ptr1 = fopen("F:\\Demo1.txt", "w");

        if(ptr == NULL || ptr1 == NULL){
            printf("Failed to open the file\n");
            if(ptr) fclose(ptr);
            if(ptr1) fclose(ptr1);
            return;
        }

        while(fread(&p1, sizeof(struct emp), 1, ptr)){
            fwrite(&p1, sizeof(struct emp), 1, ptr1);
        }
        fclose(ptr1);
        fclose(ptr);
        remove("F:\\temp.txt");
        printf("Deleted the employee successfully\n");
    } else {
        printf("Record not found\n");
    }
}
int main()
{
    choice();
}