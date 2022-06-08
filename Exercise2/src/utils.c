#include "defs.h"
#include "customerFuncs.h"
#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include "ctype.h"
#include "stdlib.h"

// Function to get the input name from the user
void GetNameInput(char *name) {
    printf("\nEnter Name:\n");
    char buff[255];
    printf("> ");
    scanf("%s", buff);
    fflush(stdin);
    char formatted[strlen(buff)];
    FormatString(buff, formatted);
    strcpy(name, formatted);
}

// Displays the menu and awaits a response from the user
int PromptUserMenu() {
    // Returns a valid response for the menu selection
    printf("\n1. Enter name\n");
    printf("2. Exit\n");
    int responded = 0;
    int response = 0;
    while (responded == 0) {
        printf("> ");
        scanf("%d", &response);
        if (response != 1 && response != 2) {
            fflush(stdin);
            printf("Invalid response. Try again.\n");
            response = 0;
            // loop will repeat
        }
        else {
            responded = 1;
        }
    }
    return response;
}

// Responds to the user's choice in the menu
void HandleMenuResponse(Customer *customers, char *name, int n) {
    printf("\n");
    int i = GetCustomerIDbyName(name, customers, n);
    if (i == -1) {
        printf("Name: %s\n", name);
        printf("Not found\n");
    }
    else {
        DisplayCustomerChange(customers[i]);
    }
}

// Main loop of the program
// When this function ends, the main loop is broken
// And the program will continue in the main function
void HandleMenuLoop(Customer *customers, int n) {
    int running = 1;
    while (running == 1) {
        int r = PromptUserMenu();
        // 1 = Enter name
        // 2 = Exit program
        if (r == 2) {
            // Set finished to 1 to break the loop
            OutputCustomers(customers, n);
            running = 0;
            // Break the menu loop (continues in main function)
            break; 
        }
        else if (r == 1) {
            char name[255];
            GetNameInput(name);
            HandleMenuResponse(customers, name, n);
        }
    }
}

// Format strings so they all start with a capital letter
// and each following letter is lowercase
void FormatString(const char *s, char *target) {
    char *new = (char*) malloc (sizeof(char) * strlen(s));
    for (int i = 0; i < strlen(s); ++i) {
        new[i] = tolower((unsigned char) s[i]);
    }
    new[0] = toupper(new[0]);
    strcpy(target, new);
    free(new);
}