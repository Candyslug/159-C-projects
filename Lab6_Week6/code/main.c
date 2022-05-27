#include <stdio.h>

#include "myMath.h"

int main() {

    // 3 numbers to take in as input
    int nums[3];
    printf("1st number: ");
    scanf("%d", &nums[0]);

    printf("\n2nd number: ");
    scanf("%d", &nums[1]);

    printf("\n3rd number: ");
    scanf("%d", &nums[2]);

    printf("\n");

    // display the results
    printf("max: %d\n", GetMax(nums));
    printf("min: %d\n", GetMin(nums));
    printf("mean: %1.3f\n", GetMean(nums));
    printf("range: %d\n", GetRange(nums));
    printf("mean->max range: %1.3f\n", GetMeanMaxRange(nums));
    printf("abs min: %d\n", GetAbs(GetMin(nums)));

    return 0;
}