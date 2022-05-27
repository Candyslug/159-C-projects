#include "stdio.h"
#include "stdlib.h"
#include "strings.h"

#include "customerFuncs.h"
#include "utils.h"
#include "coinFuncs.h"

#define DEBUGx

int main() {

    const char *fileName = "coins.txt";
    int n = CountUniqueEntries(fileName);

#ifdef DEBUG
    printf("N unique entries in %s: %i\n", fileName, n);
#endif

    Customer *customers = (Customer*) malloc (sizeof(Customer) * n);
    LoadCustomers(fileName, customers, n);
    CalculateChange(customers, n);

#ifdef DEBUG
    DisplayCustomers(customers, n);
#endif


    HandleMenuLoop(customers, n);

    free(customers);

    return 0;
}