#include <stdio.h>
#include <string.h>

void Showall(FILE *fileptr) {
    char tempbuffer[100];
    while (fgets(tempbuffer, sizeof(tempbuffer), fileptr)) {
        // this fgets has nice functionality, we use
        // it to have values get into buffer
        printf("%s", tempbuffer);
    }
    fclose(fileptr);
}

void AddEntry(FILE *fileptr) {
    char name[10], college[10];
    int id;
    int id_flag;
    // this is to check whether id is new or not

    // Rewind the file to the beginning
    rewind(fileptr);

    printf("Enter ID: ");
    scanf("%d", &id);

    // Check if id is already existing or not
    while (fscanf(fileptr, "%d, ", &id_flag) == 1) {
        // Process the integer, string1, and string2 as needed
        if(id==id_flag)
        {
            printf("Entry already existing");
            return;
        }
        while (fgetc(fileptr) != '\n') {
            // Consume characters until a newline is found
        }
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter college: ");
    scanf("%s", college);
    
    fprintf(fileptr, "%d,%s,%s\n", id, name, college);
}

void UpdateEntry(FILE* fileptr) {
    // some code
}

int main() {
    FILE *fileptr = NULL;
    fileptr = fopen("1.txt", "r+");  // Open the file for reading and writing

    if (fileptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    int operation;
    printf("Let's implement a basic DBMS application in C\n which has CRUD Functionality\n");
    printf("Enter 1 for Creating entry\n2 for Reading entry\n3 for Updating\n4 for Delete and \n5 for show database:\t");
    scanf("%d", &operation);

    switch (operation) {
        case 5:
            Showall(fileptr);
            break;
        case 1:
            AddEntry(fileptr);
            break;
        // Add other cases for different operations

    }

    fclose(fileptr);

    return 0;
}
