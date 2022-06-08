
#include "defs.h"
#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include "stdlib.h"
//#include "ctype.h"

// Will count the number of unique entries in the file
// Unique: different people,
// Duplicate names may appear and should be skipped
int CountUniqueEntries(const char *fileName) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        printf("[CountUniqueEntries] Error: Error opening file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    int amount;
    char curr[255];
    char name_b[255];
    char names[255][10];
    int name_i = 0;
    int line = 0;
    while (fscanf(f, "%s  %d cents in %s", name_b, &amount, curr) != EOF) {
#ifdef DEBUG
        printf("\n\nTrying %s....\n", name_b);
#endif
        char name[255];
        FormatString(name_b, name);

        // Loop through the array of found names
        for (int i = 0; i < 10; i++) {
            if (!strcmp(names[i], name)) {
#ifdef DEBUG
                printf("    > Found name at names[%i].\n", i);
#endif
                break;
            }
            if (i >= 9)  {
#ifdef DEBUG
                printf("    > Name %s not found in names.\n", name);
                printf("    > Adding %s to names[%i].\n", name, name_i);
#endif
                

                strcpy(names[name_i], name);
                name_i++;
                break;
            }
        }
        line++;
    } 
    fclose(f);
    if (line > 10) {
        printf("[CountUniqueEntries] Error: Invalid number of lines (%i) in %s.\n", line, fileName);
        exit(EXIT_FAILURE);
    }
    if (name_i <= 0 || name_i > 10) {
        printf("[CountUniqueEntries] Error: Invalid number of entries (%i) in %s.\n", name_i, fileName);
        exit(EXIT_FAILURE);
    }
    return name_i;
}

// Function for debug purposes
// Displays all the customers and the relevant information
void DisplayCustomers(Customer *customers, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nCustomer %i: \"%s\"\n", i, customers[i].name);
        for (int c = 0; c < 3; c++) {
            printf("   > money[%i] : %3i   --->   (", c, customers[i].money[c]);
            if (c == 0) {
                for (int x = 0; x < 4; x++) {
                    printf("%3i,", customers[i].audChange[x]);
                }
            }
            else if (c == 1) {
                for (int x = 0; x < 5; x++) {
                    printf("%3i,", customers[i].usdChange[x]);
                }
            }
            else if (c == 2) {
                for (int x = 0; x < 6; x++) {
                    printf("%3i,", customers[i].eurChange[x]);
                }
            }
            printf(")\n");
        }
    }
}

// Searches the list for the customer's name
// returns the index of the customer's appearance in the list
int GetCustomerIDbyName(const char* name, Customer *customers, int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(customers[i].name, name)) {
#ifdef DEBUG
            printf("Name %s found at index %i.\n", name, i);
#endif
            return i;
        }
    }
#ifdef DEBUG
    printf("Name %s not found.\n", name);
#endif
    return -1;
}

// Reads the input file and loads the customers into the array
void LoadCustomers(const char *fileName, Customer *customers, int n) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        printf("[LoadCustomers] Error: Error opening file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    // buffers
    char name_b[255];
    int amount = 0;
    char curr[255];

    int lastI = 0;
    int curCur = 0;
    int lineNumber = 0;

    while (fscanf(f, "%s  %d cents in %s", name_b, &amount, curr) != EOF) {

        if (amount < 0) {
            printf("[LoadCustomers] Error: Invalid amount of currency (%i) detected on line %i in %s.\n", amount, lineNumber, fileName);
            exit(EXIT_FAILURE);
        }
        char name[255];
        FormatString(name_b, name);
        if (!strcmp(curr, "AU$"))
            curCur = 0;
        else if (!strcmp(curr, "US$"))
            curCur = 1;
        else if (!strcmp(curr, "EUR"))
            curCur = 2;
        else  {
            printf("[LoadCustomers] Error: Incorrect currency detected in %s on line %i \"%s\".\n", fileName, lineNumber, curr);
            exit(EXIT_FAILURE);
        }

        int foundID = GetCustomerIDbyName(name, customers, n);
        if (foundID == -1) {
            // Not found
            strcpy(customers[lastI].name, name);
            customers[lastI].money[curCur] += amount;
            lastI++;
        }
        else if (foundID != -1) {
            // Found
            customers[foundID].money[curCur] += amount;
        }
        lineNumber++;
    }
    fclose(f);
}

void DisplayCustomerChange(Customer customer) {
    int AUDcoins[4] = {50, 20, 10, 5};
    int USDcoins[5] = {50, 25, 10, 5, 1};
    int EURcoins[6] = {50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 3; i++) {
        if (customer.money[i] > 0) {
            printf("Customer:\n");
            break;
        }
    }

    if (customer.money[0] > 0) {
        printf("%s %i cents in AU$\n", 
            customer.name, 
            customer.money[0]);
        printf("\nChange:\n");
        for (int i = 0; i < 4; i++) {
            if (customer.audChange[i] > 0) {
                printf("%i cents: %i\n", AUDcoins[i], customer.audChange[i]);
            }
        }
        if (customer.money[1] > 0 || customer.money[2] > 0)
            printf("\n");
    }

    if (customer.money[1] > 0) {
        printf("%s %i cents in US$\n", 
            customer.name, 
            customer.money[1]);

        printf("\nChange:\n");
        for (int i = 0; i < 5; i++) {
            if (customer.usdChange[i] > 0) {
                printf("%i cents: %i\n", USDcoins[i], customer.usdChange[i]);
            }
        }
        if (customer.money[2] > 0)
            printf("\n");
    }

    if (customer.money[2] > 0) {
        printf("%s %i cents in EUR\n", 
            customer.name, 
            customer.money[2]);

        printf("\nChange:\n");
        for (int i = 0; i < 6; i++) {
            if (customer.eurChange[i] > 0) {
                printf("%i cents: %i\n", EURcoins[i], customer.eurChange[i]);
            }
        }
    }
}

void OutputCustomers(Customer *customers, int n) {
    const char *fileName = "change.csv";
    FILE *f = fopen(fileName, "w");
    if (f == NULL) {
        printf("[OutputCustomers] Error: %s could not be opened.\n", fileName);
        exit(EXIT_FAILURE);
    }

    char *currencies[3] = {"AU$", "US$", "EUR"};
    int coinCount[3] = {4, 5, 6};

    int first = 0; // Check to only print a newline after hte first line
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 3; c++) {
            if (customers[i].money[c] > 0) {
                fprintf(f, "%s, the change for %i cents in %s is ", 
                    customers[i].name,
                    customers[i].money[c],
                    currencies[c]);
                for (int x = 0; x < coinCount[c]; x++) {
                    if (c == 0) {
                        (x >= (coinCount[c]-1)) ? 
                            fprintf(f, "%i\n", customers[i].audChange[x]) : 
                            fprintf(f, "%i,", customers[i].audChange[x]);
                    }
                    if (c == 1) {
                        (x >= (coinCount[c]-1)) ? 
                            fprintf(f, "%i\n", customers[i].usdChange[x]) : 
                            fprintf(f, "%i,", customers[i].usdChange[x]);
                    }
                    if (c == 2) {
                        (x >= (coinCount[c]-1)) ? 
                            fprintf(f, "%i\n", customers[i].eurChange[x]) : 
                            fprintf(f, "%i,", customers[i].eurChange[x]);
                    }
                }
            }
        }
    }
    fclose(f);
}