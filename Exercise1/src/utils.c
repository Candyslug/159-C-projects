
#include "stdio.h"

void DisplayAUDcoins(const int coins[]) {
    printf("\n");
    printf("50c coins: %d\n", coins[0]);
    printf("20c coins: %d\n", coins[1]);
    printf("10c coins: %d\n", coins[2]);
    printf("5c coins: %d\n", coins[3]);
}

void CalculateAUDcoins(const int amount, int *c50, int *c20, int *c10, int *c5) {
    if (amount % 5 != 0) {
        printf("\n");
        printf("Invalid amount for AUD.\n");
        printf("Must be a multiple of 5.\n");
        return;
    }
    // AUD coins:
    // 50, 20, 10, 5
    // Indexed in that order
    int coins[4] = { 0, 0, 0, 0 };
    int a = amount;
    while (a > 0)  {
        if (a >= 50) {
            coins[0] += 1;
            a -= 50;
            continue;
        }
        if (a >= 20) {
            coins[1] += 1;
            a -= 20;
            continue;
        }
        if (a >= 10) {
            coins[2] += 1;
            a -= 10;
            continue;
        }
        if (a >= 5) {
            coins[3] += 1;
            a -= 5;
            continue;
        }
    }
    *c50 = coins[0];
    *c20 = coins[1];
    *c10 = coins[2];
    *c5 = coins[3];
}


void DisplayUSDcoins(const int coins[]) {
    printf("\n");
    printf("50c coins: %d\n", coins[0]);
    printf("25c coins: %d\n", coins[1]);
    printf("10c coins: %d\n", coins[2]);
    printf("5c coins: %d\n", coins[3]);
    printf("1c coins: %d\n", coins[4]);
}

void CalculateUSDcoins(const int amount, int *c50, int *c25, int *c10, int *c5, int *c1) {
    // USD coins:
    // 50, 25, 10, 5, 1
    // Indexed in that order
    int coins[5] = { 0, 0, 0, 0, 0 };
    int a = amount;
    while (a > 0)  {
        if (a >= 50) {
            coins[0] += 1;
            a -= 50;
            continue;
        }
        if (a >= 25) {
            coins[1] += 1;
            a -= 25;
            continue;
        }
        if (a >= 10) {
            coins[2] += 1;
            a -= 10;
            continue;
        }
        if (a >= 5) {
            coins[3] += 1;
            a -= 5;
            continue;
        }
        if (a >= 1) {
            coins[4] += 1;
            a -= 1;
            continue;
        }
    }
    *c50 = coins[0];
    *c25 = coins[1];
    *c10 = coins[2];
    *c5 = coins[3];
    *c1 = coins[4];
}

void DisplayEuroCoins(const int coins[]) {
    printf("\n");
    printf("50c coins: %d\n", coins[0]);
    printf("20c coins: %d\n", coins[1]);
    printf("10c coins: %d\n", coins[2]);
    printf("5c coins: %d\n", coins[3]);
    printf("2c coins: %d\n", coins[4]);
    printf("1c coins: %d\n", coins[5]);
}

void CalculateEuroCoins(const int amount, int *c50, int *c20, int*c10, int *c5, int *c2, int *c1) {
    // Euro coins:
    // 50, 20, 10, 5, 2, 1
    // Indexed in that order
    int coins[6] = { 0, 0, 0, 0, 0, 0 };
    int a = amount;
    while (a > 0)  {
        if (a >= 50) {
            coins[0] += 1;
            a -= 50;
            continue;
        }
        if (a >= 20) {
            coins[1] += 1;
            a -= 20;
            continue;
        }
        if (a >= 10) {
            coins[2] += 1;
            a -= 10;
            continue;
        }
        if (a >= 5) {
            coins[3] += 1;
            a -= 5;
            continue;
        }
        if (a >= 2) {
            coins[4] += 1;
            a -= 2;
            continue;
        }
        if (a >= 1) {
            coins[5] += 1;
            a -= 1;
            continue;
        }
    }
    *c50 = coins[0];
    *c20 = coins[1];
    *c10 = coins[2];
    *c5 = coins[3];
    *c2 = coins[4];
    *c1 = coins[5];
}