#include "stdio.h"
#include "stdlib.h"
#include "strings.h"

#include "customerFuncs.h"
#include "utils.h"
#include "coinFuncs.h"

// Uncomment the line below to enable the showing of additional information for debugging purposes
//#define DEBUG

int main() {

    // The program will only read the first 10 lines in coins.txt.


    // Declare the name of the input file
    const char *fileName = "coins.txt";
    // Count the number of unique customer names in that file
    int n = CountUniqueEntries(fileName);

#ifdef DEBUG
    printf("N unique entries in %s: %i\n", fileName, n);
#endif

    // Allocate the customer array with the size of the unique customers
    // (1 unique customer per array index)
    Customer *customers = (Customer*) malloc (sizeof(Customer) * n);

    // Load the customers from the input file and copy them into the array
    LoadCustomers(fileName, customers, n);
    // Compute the correct change coins for each customer in the array
    CalculateChange(customers, n);

#ifdef DEBUG
    DisplayCustomers(customers, n);
#endif

    // Display and respond to the user's input
    HandleMenuLoop(customers, n);

    // Free the memory used for the dynamically-allocated customer array
    free(customers);

    return 0;
}