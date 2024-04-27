#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzebi.h"

int searchnam(char nam[10]){
    FILE* file;
    file= fopen("acc.txt","r");
    char nom[10] = "Name: ";  // this is a work around because I'm lazy
    char line[50];
    strcat(nom,nam);  // Added this as a way to not confuse the strstr method ( let's say abc is acc, a will return acc exists without this)
    if (file==NULL){
        perror("empty file");
        exit(EXIT_FAILURE);
    }
    while(fgets(line, sizeof(line), file)){
        line[strcspn(line, "\n")] = '\0';
        if (strstr(line, nom) && strcmp(line, nom)==0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
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
void print_balance(acczeb* acc,char nam[10]) {
    if (acc == NULL) {
        fprintf(stderr, "Invalid account pointer.\n");
        return;
    }
    printf("Balance of account '%s': %d\n", acc->name, acc->balance);
}

void deposit(acczeb* acc,int balance){
    acc->balance+=balance;
}

void withdraw(acczeb* acc, int balance){
    acc->balance-=balance;
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

    printf("press 2 if you want to create account : ");

    scanf("%d",&x);
    switch(x){
        case 1:
            printf("enter ur characters name\n");
            scanf("%s",nam);
            if (searchnam(nam)==1){printf("account exists");}
            else{
            scanf("%d",&balance);
            acc = createacc(nam,balance);
            }
            break;
        case 2:
            scanf("%s",&nam);
            print_balance(acc,nam);
            break;
    free(acc);
    }
}
