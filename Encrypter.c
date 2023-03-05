//Necessary libraries for program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define True 0
#define False 1

//Employee info stored in data structure
typedef struct employee{
    unsigned int ID;
    char last_name[64];
    char name[64];
    char adress[64];
    char annual_income[64];
}employee;

unsigned short int get_input(char*);
void get_employee_info(char*);
void put_employee_info(char*);
int enc0(int i, int x, char c);
int enc1(int i, int x, char c);
int enc2(int i, int x, char c);
int enc3(int i, int x, char c);
int enc4(int i, int x, char c);
int enc5(int i, int x, char c);
int enc6(int i, int x, char c);
int enc7(int i, int x, char c);
int enc8(int i, int x, char c);
int enc9(int i, int x, char c);

int main(void){
    char employee_ID[16];
    unsigned short int no_error = False;

    printf("Do you wish to (0) read or (1) write employee data?: ");
    unsigned short int rr;
    no_error = False;
    while(no_error == False){
        scanf("  %i", &rr);
        if(rr != 0 && rr != 1){
            printf("Please enter a valid input: ");
        }
        else{
            no_error = True;
        }
    }

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

    if(rr = 0){
        get_employee_info(employee_ID);
    }
    else{
        put_employee_info(employee_ID);
    }
    return 0;
}

unsigned short int get_input(char* question){
    unsigned short int awnser, valid = False;
    char temp;

    printf("%s [Y/N]: ", question);
    while(valid == False){
        scanf("  %c", &temp);
        if(temp == 'N' || temp == 'n'){
            awnser = False;
            valid = True;
        }
        else if(temp == 'Y' || temp == 'y'){
            awnser = True;
            valid = True;
        }
        else{
            printf("Please enter a valid input: ");
        }
    }
    return awnser;
}

void get_employee_info(char* employee_ID){
    char file_path[32];
    FILE* fptr;
    unsigned short int no_error = False;

    //User input
    printf("Enter path to employee data: ");
    scanf(" %s", file_path);

    //File handling
    while(no_error == False){
        no_error = True;
        fptr = fopen(file_path, "rb");
        if (fptr == NULL) {
            perror("File opening failed: ");
            no_error = False;
        }
        if(no_error == False){
            if(get_input("File path invalid, do you wish to retry?") == 1){
                exit(1);
            }
        }
    }

    int ID[8];
    employee buffer;

    for(int i = 0; i < 8; i++){
        ID[i] = (int) employee_ID[i]/48;
    }
    switch(ID[0]){
        /*case 0:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 1:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 2:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 3:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 4:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 5:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 6:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 7:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 8:
            fread(buffer, sizeof(employee), 1, fptr);
            break;
        case 9:
            fread(buffer, sizeof(employee), 1, fptr);
            break;*/
    }
    fclose(fptr);
}

void put_employee_info(char* employee_ID){
    char file_path[32];
    FILE* fptr;
    unsigned short int no_error = False;

    //File handling
    while(no_error == False){
        //User input
        printf("Enter path to employee data (or new path if one does not exist): ");
        scanf(" %s", file_path);
        no_error = True;
        fptr = fopen(file_path, "ab");
        if (fptr == NULL) {
            perror("File opening or creating failed: ");
            no_error = False;
        }
        if(no_error == False){
            if(get_input("File path invalid, do you wish to retry?") == 1){
                exit(1);
            }
        }
    }

    int ID[8], i;
    employee buffer;

    printf("What is the employee's last name, name, adress, annual income? \n");
    //scanf(" %s, %s, %s, %s", buffer.last_name, buffer.name, buffer.adress, buffer.annual_income);

    strncpy(buffer.adress, "Hello", 6*sizeof(char));
    strncpy(buffer.annual_income, "Hello", 6*sizeof(char));
    strncpy(buffer.last_name, "Hello", 6*sizeof(char));
    strncpy(buffer.name, "Hello", 6*sizeof(char));

    for(int i = 0; i < 8; i++){
        ID[i] = ((int) employee_ID[i])-48;
    }
    if(ID[0] == 0){
        for(i = 0; i < strlen(buffer.last_name - 1);i++){
            buffer.last_name[i] = enc0(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc0(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc0(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc0(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 1){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc1(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc1(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc1(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc1(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 2){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc2(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc2(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc2(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc2(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 3){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc3(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc3(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc3(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc3(i%16, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 4){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc4(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc4(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc4(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc4(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
     else if(ID[0] == 5){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc5(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc5(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc5(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc5(i%4, ID[i%8], buffer.annual_income[i]);
        }
     }
    else if(ID[0] == 6){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc6(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc6(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc6(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc6(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 7){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc7(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc7(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc7(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc7(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 8){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc8(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc8(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc8(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc8(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
    else if(ID[0] == 9){
        for(i = 0; i < strlen(buffer.last_name);i++){
            buffer.last_name[i] = enc9(i%4, ID[i%8], buffer.last_name[i]);
        }
        for(i = 0; i < strlen(buffer.name);i++){
            buffer.name[i] = enc9(i%4, ID[i%8], buffer.name[i]);
        }
        for(i = 0; i < strlen(buffer.adress);i++){
            buffer.adress[i] = enc9(i%4, ID[i%8], buffer.adress[i]);
        }
        for(i = 0; i < strlen(buffer.annual_income);i++){
            buffer.annual_income[i] = enc9(i%4, ID[i%8], buffer.annual_income[i]);
        }
    }
        fwrite(&buffer, sizeof(employee), 1, fptr);

        fclose(fptr);
}

int enc0(int i, int x, char c){
    int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = c - x;
            break;
        case 2:
            ret = c * x;
            break;
        case 3:
            ret = pow(c, x);
            break;
    }
    return ret;
}

int enc1(int i, int x, char c){
    int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = c * x;
            break;
        case 2:
            ret = c - x;
            break;
        case 3:
            ret = pow(c, x);
            break;
    }
    return ret;
}

int enc2(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = c * x;
            break;
        case 2:
            ret = pow(c, x);
            break;
        case 3:
            ret = c - x;
            break;
    }
    return ret;
}

int enc3(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = pow(c, x);
            break;
        case 2:
            ret = c * x;
            break;
        case 3:
            ret = c - x;
            break;
    }
    return ret;
}

int enc4(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = c - x;
            break;
        case 2:
            ret = pow(c, x);
            break;
        case 3:
            ret = c * x;
            break;
    }
    return ret;
}

int enc5(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c + x;
            break;
        case 1:
            ret = pow(c, x);
            break;
        case 2:
            ret = c - x;
            break;
        case 3:
            ret = c * x;
            break;
    }
    return ret;
}

int enc6(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c - x;
            break;
        case 1:
            ret = c + x;
            break;
        case 2:
            ret = c * x;
            break;
        case 3:
            ret = pow(c, x);
            break;
    }
    return ret;
}

int enc7(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c - x;
            break;
        case 1:
            ret = c + x;
            break;
        case 2:
            ret = pow(c, x);
            break;
        case 3:
            ret = c * x;
            break;
    }
    return ret;
}

int enc8(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c - x;
            break;
        case 1:
            ret = c * x;
            break;
        case 2:
            ret = c + x;
            break;
        case 3:
            ret = pow(c, x);
            break;
    }
    return ret;
}

int enc9(int i, int x, char c){
        int ret = 0;
    switch(i){
        case 0:
            ret = c - x;
            break;
        case 1:
            ret = c * x;
            break;
        case 2:
            ret = pow(c, x);
            break;
        case 3:
            ret = c + x;
            break;
    }
    return ret;
}
