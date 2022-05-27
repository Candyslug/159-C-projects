#ifndef DEFS_H
#define DEFS_H

// AU$
// US$
// EUR

// Bob 50 cents in EUR


typedef struct Customer {
    char name[255];
    int money[3]; // AUD, USD, EUR
    int audChange[4]; // 50, 20, 10, 5
    int usdChange[5]; // 50, 25, 10, 5, 1
    int eurChange[6]; // 50, 20, 10, 5, 2, 1
} Customer;

#endif