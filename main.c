#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headhhXD.h"


/*void filehandle(char mode){
    FILE* file;
    file= fopen("acc.txt",mode);
    if (file==NULL){
        perror("empty fag");
        exit(EXIT_FAILURE);
    }
} idk seems unoptimal might do it later*/

int searchnam(char nam[10]){
    FILE* file;
    file= fopen("acc.txt","r");
    char nom[10] = "Name: ";  // this is a work around because I'm lazy
    char line[50];
    strcat(nom,nam);  // Added this as a way to not confuse the strstr method ( let's say abc is acc, a will return acc exists without this)
    if (file==NULL){    //strcat function stores "Name: + nam" into nom :)
        perror("empty file");
        exit(EXIT_FAILURE);
    }
    while(fgets(line, sizeof(line), file)){
        line[strcspn(line, "\n")] = '\0'; //removes the \n from the line so it compares successfully
        if (strstr(line, nom) && strcmp(line, nom)==0){ //idk we can put only strcmp in here but whatever.
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}


int searchbal(char nam[10]){
    FILE* file;
    file= fopen("acc.txt","r");
    char nom[10] = "Name: ";  
    char line[50];
    int balance;
    strcat(nom,nam);  
    if (file==NULL){    
        perror("empty file");
        exit(EXIT_FAILURE);
    }
    while(fgets(line, sizeof(line), file)){ //keeps skipping lines until the while loop fullfills
        line[strcspn(line, "\n")] = '\0'; 
        if (strstr(line, nom) && strcmp(line, nom)==0){ //here we check if the account name we're looking for is in this line
            fgets(line, sizeof(line), file);    //here we go down a line to the balance line
            sscanf(line, "Balance: %d", &balance); //we scan the number after 'Balance: '
            break;
        }
    }
    fclose(file);
    return balance;
}


acczeb* createacc(char nam[10],int balance){
    FILE* facc; //creating the file :)
    acczeb* acc=(acczeb*)malloc(sizeof(acczeb));
    if (acc == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memmove(acc->name, nam, sizeof(acc->name) - 1); // memmove is safer than strncpy (avoids buffer overflow)
    acc->name[sizeof(acc->name) - 1] = '\0';
    acc->balance=balance;
    printf("Account name: '%s'\n", acc->name);
    facc= fopen("acc.txt","a"); //file open :)
    fprintf(facc, "Name: %s\n", acc->name); //file print name
    fprintf(facc, "Balance: %d\n", acc->balance); //file print balance
    fclose(facc); //closing the shit show :D
    return acc;
}
void print_balance(char nam[10]) {
    if (searchnam(nam) == 0) {
        fprintf(stderr, "Invalid account pointer.\n");
        return;
    }
    else{
        printf("Account balance is: %d", searchbal(nam));
    }
}

void deposit(char nam[10], int balance) {
    if (searchnam(nam) == 0) {
        printf("Account not found\n");
        return;
    }
    
    FILE* file = fopen("acc.txt", "r+");
    if (file == NULL) {
        perror("Empty file");
        exit(EXIT_FAILURE);
    }

    char nom[20] = "Name: ";
    strcat(nom, nam);

    char line[50];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; 
        if (strstr(line, nom) && strcmp(line, nom) == 0) {
            fgets(line, sizeof(line), file);
            int currbal = searchbal(nam);
            int newbal = currbal + balance;

            // Move the file pointer to the beginning of the balance line
            fseek(file, -strlen(line)-1, SEEK_CUR);

            // Write the new balance to the file including the prefix "Balance: "
            fprintf(file, "Balance: %d\n", newbal);
            break;
        }
    }
    fclose(file);
}

void withdraw(char nam[10], int balance){
    deposit(nam,-balance); //just call the deposit function with a negative argument
}

void delacc(acczeb* acc){
    free(acc);
}
void main(){
    int x,balance;
    char nam[10];
    acczeb* acc = NULL;
    printf("hello your at the bank ATM choose ur option\n");

    printf("press 1 if you want to create account : \n");

    printf("press 2 if you want to see your account's balance : \n");

    printf("press 3 if you want to deposit money into your account : \n");

    printf("press 4 if you want to withdraw money into your account : \n");

    scanf("%d",&x);
    switch(x){
        case 1:
            printf("enter ur characters name\n");
            scanf("%s",nam);
            if (searchnam(nam)==1){
                printf("account exists\n");
                searchbal(nam);
            }
            else{
            scanf("%d",&balance);
            acc = createacc(nam,balance);
            }
            break;
        case 2:
            scanf("%s",&nam);
            print_balance(nam);
            break;
        case 3:
            scanf("%s",&nam);
            scanf("%d",&balance);
            deposit(nam,balance);
            break;
        case 4:
            scanf("%s",&nam);
            scanf("%d",&balance);
            withdraw(nam,balance);
            break;        
    delacc(acc);
    }
}
