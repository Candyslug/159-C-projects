#ifndef DEFS_H
#define DEFS_H

typedef struct Customer {
    char name[255];

    // Total currency in each currency
    int money[3]; // Indexes: AUD, USD, EUR

    // Coins for each currency
    int audChange[4]; // 50, 20, 10, 5
    int usdChange[5]; // 50, 25, 10, 5, 1
    int eurChange[6]; // 50, 20, 10, 5, 2, 1
} Customer;

#endif