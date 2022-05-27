#include "defs.h"
#include "customerFuncs.h"

#include "stdio.h"
#include "strings.h"


void GetNameInput(char *name) {
    printf("\nEnter Name:\n");
    char buff[255];
    printf("> ");
    scanf("%s", buff);
    fflush(stdin);
    strcpy(name, buff);
}

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
