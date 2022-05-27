#include <stdio.h>

int DoFib(int n_iters) {

    if (n_iters <= 0) {
        printf("Error: n_iters <= 0\n");
        return 0;
    }

    int term1 = 0;
    int term2 = 1;

    if (n_iters == 1) {
        return term2;
    }
    int nextTerm = term1 + term2;

    if (n_iters == 2) {
        return nextTerm;
    }

    int i;
    for (i = 3; i <= n_iters; i++) {
        term1 = term2;
        term2 = nextTerm;
        nextTerm = term1 + term2;
    }
    return nextTerm;
}

int main() {

    int n;
    printf("N Iterations: ");
    scanf("%d", &n);
    printf("\n");

    printf("%d\n", DoFib(n));

    return 0;
}