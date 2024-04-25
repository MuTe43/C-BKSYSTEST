#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzebi.h"












acczeb* createacc(char nam[10]){
    acczeb* acc=(acczeb*)malloc(sizeof(acczeb));
    if (acc == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(acc->name, nam, sizeof(acc->name) - 1);
    acc->name[sizeof(acc->name) - 1] = '\0';
    acc->balance=0;
    return acc;
}
void print_balance(acczeb* acc,char nam[10]) {
    strncpy(acc->name, nam, sizeof(acc->name) - 1);
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
    acczeb* acc = createacc('abc');
    printf("hello your at the bank ATM choose ur option\n");
    printf("press 1 if you want to create account : \n");
    printf("press 2 if you want to create account : ");
    scanf("%d",&x);
    switch(x){
        case 1:
            printf("enter ur characters name\n");
            scanf(" enter the account name %c",&nam);
            createacc(nam);
            break;
        case 2:
            scanf(" enter the account name %c",&nam);
            print_balance(acc,nam);

    }
}
