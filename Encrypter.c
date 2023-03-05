//Necessary libraries for program
#include <stdio.h>
#include <stdlib.h>

#define True 0
#define False 1

//Employee info stored in data structure
typedef struct employee{
    unsigned int ID;
    char* last_name;
    char* name;
    char* adress;
    float annual_income;
}employee;

unsigned short int get_input(char*);

int main(void){
    char file_path[32], employee_ID[16];
    FILE* fptr;
    unsigned short int no_error = False;

    //User input
    printf("Enter path to employee data: ");
    scanf("%s", file_path);

    //File handling
    while(no_error == False){
        no_error = True;
        fptr = fopen(file_path, "r");
        if (fptr == NULL) {
            perror("File opening failed: ");
            no_error = False;
        }
        if(no_error == False){
            if(get_input("File path invalid, do you wish to retry?") == 1){
                return 1;
            }
        }
    }

    fclose(fptr);

    no_error = False;
    while(no_error == False){
        printf("Enter employee ID of employee: ");
        scanf(" %s", employee_ID);
        if(strlen(employee_ID) == 8){
            no_error = True;
        }
        else{
            printf("Please enter a valid employee ID\n");
        }
    } 
}

unsigned short int get_input(char* question){
    unsigned short int awnser = False, valid = False;
    char temp;

    printf("%s [Y/N]", question);
    while(valid == False){
        awnser = True;
        scanf(" %c", temp);
        if(temp == 'N' || temp == 'n'){
            awnser = False;
            valid = True;
        }
        else if(temp == 'Y' || temp == 'y'){
            awnser = True;
            valid = True;
        }
        else{
            printf("Please enter a valid input");
        }
    }
    return awnser;
}