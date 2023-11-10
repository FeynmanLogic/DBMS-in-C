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

void CreateEntry(FILE *fileptr) {
    char name[10], college[10];
    int id;
    int id_flag;
    // this is to check whether id is new or not
    // Rewind the file to the beginning after traversal
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
void ReadEntry(FILE* fileptr)
{
    int id,id_flag;
    char name[10], college[10];
    rewind(fileptr);
    printf("enter the id whose details you want\t");
    scanf("%d",&id);
   while (fscanf(fileptr, "%d,%9[^,],%9[^\n]\n", &id_flag, name, college) == 3) {
      
        if(id==id_flag)
        {
            printf("Name:%s\n",name);
            printf("College: %s",college);
             rewind(fileptr);
            return;
        }
    
    }
   

}
void UpdateEntry(FILE* fileptr) {
    int id,id_flag;
    char name[10], college[10],newname[10],newclg[10];
    rewind(fileptr);
    printf("enter the id whose details you want to update\t");
    scanf("%d",&id);
   while (fscanf(fileptr, "%d,%9[^,],%9[^\n]\n", &id_flag, name, college) == 3) {
      
        if(id==id_flag)
        {
            printf("Enter New name:%s\n",&newname);
            printf("Enter new College: %s",&newclg);
            fprintf(fileptr,"%d,%s,%s",id,newname,newclg);

            return;
        }
    
    }

}


int main() {
    FILE *fileptr = NULL;
    fileptr = fopen("1.txt", "r+");  // Open the file for reading and writing

    if (fileptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    int operation;
    
while(1){
    printf("Let's implement a basic DBMS application in C\nwhich has CRUD Functionality\n");
    printf("Enter 15 for stopping\nEnter 1 for Creating entry\n2 for Reading entry\n3 for Updating\n4 for Delete and \n5 for show database:\t");
    scanf("%d", &operation);
    if(operation==15)
    {
        break;
    }
    switch (operation) {
        case 5:
            Showall(fileptr);
            break;
        case 1:
            CreateEntry(fileptr);
            break;
        case 2:
            ReadEntry(fileptr);
            break;
        // Add other cases for different operations
        
    }

    

    
}
fclose(fileptr);
return 0;
}