#include <stdio.h>
#include <stdlib.h>

struct acczeb {
    char name[10];
    int balance;
};
typedef struct acczeb acczeb;
acczeb* createacc(char name[10],int balance);

void deposit(acczeb* acc, int balance);

void withdraw(acczeb* acc, int balance);

void delacc(acczeb* acc);
