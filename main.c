#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzebi.h"



acczeb* createacc(char nam[10],int balance){
    FILE* facc;
    acczeb* acc=(acczeb*)malloc(sizeof(acczeb));
    if (acc == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memmove(acc->name, nam, sizeof(acc->name) - 1);
    acc->name[sizeof(acc->name) - 1] = '\0';
    acc->balance=balance;
    printf("Account name: '%s'\n", acc->name);
    facc= fopen("acc.txt","a");
    fprintf(facc, "Name: %s\n", acc->name);
    fprintf(facc, "Balance: %d\n", acc->balance);
    fclose(facc);
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
    acczeb* acc = {'abs',0};
    printf("hello your at the bank ATM choose ur option\n");

    printf("press 1 if you want to create account : \n");

    printf("press 2 if you want to create account : ");

    scanf("%d",&x);
    switch(x){
        case 1:
            printf("enter ur characters name\n");
            scanf("%s",&nam);
            scanf("%d",&balance);
            createacc(nam,balance);
            break;
        case 2:
            scanf("%s",&nam);
            print_balance(acc,nam);
            break;
    free(acc);
    }
}
