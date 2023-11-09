#include <stdio.h>
#include <string.h>
void Showall(FILE *fileptr)
{
    char tempbuffer[100];
    while (fgets(tempbuffer, sizeof(tempbuffer), fileptr))
    {
       //this fgets has nice functionality, we use
       //it to have values get into buffer
        printf("%s", tempbuffer);
    }

    fclose(fileptr);
}
int main()
{

    FILE *fileptr = NULL;
    fileptr = fopen("1.txt", "r");

    if (fileptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    int operation;
    char buffer[100];
    printf("Let's implement a basic DBMS application in C\n which has CRUD Functionality\n");
    printf("Enter 1 for Creating entry\n2 for Reading entry\n3 for Updating\n4 for Delete and \n5 for show database:\t");
    scanf("%d", &operation);
    switch (operation)
    {
    case 5:
        Showall(fileptr);
        break;
    }
    fclose(fileptr);

    return 0;
}
