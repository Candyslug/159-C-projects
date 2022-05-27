#include "stdio.h"

#include "utils.h"




int main() {

    int running = 1;
    while (running) {

        // get input to choose which currency
        // AUD, USD, EURO

        // Get selection
        printf("Enter choice of currency. (Example: '1' for AUD))\n");
        printf("1. AUD\n");
        printf("2. USD\n");
        printf("3. EURO\n\n");
        printf("Input: ");
        int selection;
        scanf(" %d", &selection);
        if (selection < 1 || selection > 3) {
            printf("Selection input error.\n");
            running = 0;
            break;
        }

        // Show selection
        printf("Selected Currency: ");
        if (selection == 1) {
            printf("AUD cents\n");
        }
        else if (selection == 2) {
            printf("USD cents\n");
        }
        else if (selection == 3) {
            printf("EURO cents\n");
        }

        // Get amount of money
        printf("\nAmount of money (1-95): ");
        int amount = 0;
        scanf(" %d", &amount);

        // Check the amount and run the display the coins
        if (amount < 1 || amount > 95) {
            printf("Invalid amount. Must be between 1 and 95 (inclusive).\n");
        }
        else {
            if (selection == 1) {
                int coins[4] = { 0, 0, 0, 0 };
                CalculateAUDcoins(amount, &coins[0], &coins[1], &coins[2], &coins[3]);
                DisplayAUDcoins(coins);
            }
            else if (selection == 2) {
                int coins[5] = { 0, 0, 0, 0, 0 };
                CalculateUSDcoins(amount, &coins[0], &coins[1], &coins[2], &coins[3], &coins[4]);
                DisplayUSDcoins(coins);
            }
            else if (selection == 3) {
                int coins[6] = { 0, 0, 0, 0, 0, 0 };
                CalculateEuroCoins(amount, &coins[0], &coins[1], &coins[2], &coins[3], &coins[4], &coins[5]);
                DisplayEuroCoins(coins);
            }
        }

        printf("\n");
        printf("Would you like to continue?\n");
        int response = 0; // 0 = waiting
        char c;
        fflush(stdin);
        while (response == 0) {
            //c = getchar();
          printf("y/n: ");
            scanf(" %c", &c);
            fflush(stdin);
            if (c == 'y') {
                response = 1;
            }
            else if (c == 'n') {
                running = 0;
                response = 1;
            }
            else {
                printf("Invalid response. Try again.\n");
        
            }
        }
        printf("\n");
    }

    printf("Exiting\n");
    system("pause");
    return 0;
}
