#include <stdio.h>
#include <stdlib.h>

struct acczeb {
    char name[10];
    int balance;
};
typedef struct acczeb acczeb;
struct acczeb* createacc(char name[10],int balance);
void print_balance(char nam[10]);
void deposit(char nam[10], int balance);

void withdraw(char nam[10], int balance);

void delacc(acczeb* acc);
