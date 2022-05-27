
#include "defs.h"

#include "stdio.h"


void CalculateChange(Customer *customers, int n) {
    for (int customer_i = 0; customer_i < n; customer_i++) {
        int aud = customers[customer_i].money[0];
        while (aud > 0) {
            if (aud >= 50) {
                customers[customer_i].audChange[0] += 1;
                aud -= 50;
                continue;
            }
            if (aud >= 20) {
                customers[customer_i].audChange[1] += 1;
                aud -= 20;
                continue;
            } 
            if (aud >= 10) {
                customers[customer_i].audChange[2] += 1;
                aud -= 10;
                continue;
            }
            if (aud >= 5) {
                customers[customer_i].audChange[3] += 1;
                aud -= 5;
                continue;
            }
        }
        int usd = customers[customer_i].money[1];
        while (usd > 0) {
            if (usd >= 50) {
                customers[customer_i].usdChange[0] += 1;
                usd -= 50;
                continue;
            }
            if (usd >= 25) {
                customers[customer_i].usdChange[1] += 1;
                usd -= 25;
                continue;
            } 
            if (usd >= 10) {
                customers[customer_i].usdChange[2] += 1;
                usd -= 10;
                continue;
            }
            if (usd >= 5) {
                customers[customer_i].usdChange[3] += 1;
                usd -= 5;
                continue;
            }
            if (usd >= 1) {
                customers[customer_i].usdChange[4] += 1;
                aud -= 1;
                continue;
            }
        }
        int eur = customers[customer_i].money[2];
        while (eur > 0) {
            if (eur >= 50) {
                customers[customer_i].eurChange[0] += 1;
                eur -= 50;
                continue;
            }
            if (eur >= 20) {
                customers[customer_i].eurChange[1] += 1;
                eur -= 20;
                continue;
            } 
            if (eur >= 10) {
                customers[customer_i].eurChange[2] += 1;
                eur -= 10;
                continue;
            }
            if (eur >= 5) {
                customers[customer_i].eurChange[3] += 1;
                eur -= 5;
                continue;
            }
            if (eur >= 2) {
                customers[customer_i].eurChange[4] += 1;
                eur -= 2;
                continue;
            }
            if (eur >= 1) {
                customers[customer_i].eurChange[5] += 1;
                eur -= 1;
                continue;
            }
        }
    }
}