#include <stdio.h>
#include <stdlib.h>
#include "lzebi.h"












struct acczeb* createacc(char nam[10]){
    acczeb* acc=(acczeb*)malloc(sizeof(acczeb));
    acc->name[10]=nam;
    acc->balance=0;
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
    printf("hello your at the bank ATM choose ur option");
    printf("press 1 if you want to create account");
    scanf("%d",&x);
    switch(x){
        case 1:
            scanf("enter the account name %c",&nam);
            createacc(nam);
            break;
        case 2:

    }
}
