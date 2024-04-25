#include <stdio.h>
#include <stdlib.h>

struct acczeb {
    char name[10];
    int balance;
};
typedef struct acczeb acczeb;
struct acczeb* createacc(char name[10]);
void print_balance(acczeb* acc);
void deposit(acczeb* acc, int balance);

void withdraw(acczeb* acc, int balance);

void delacc(acczeb* acc);
