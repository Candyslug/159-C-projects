#include "stdio.h"
#include "stdlib.h"

int checkArgs(const int argc, char *argv[]) {
  if (argc != 2) {
    printf("Invalid argc, expected one int.\n");
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[1]);
  //printf("N (from command line): %i\n\n", n);
  return n;
}

void initArray(int *A, const int n) {
  for (int i = 0; i < n; i++) {
    A[i] = 1 + (rand() % 20);
    //printf("A[%i] ---> %i\n", i, A[i]);
  }
}

void doAlgorithm(int *A, int *B, const int n) {
  for (int i = 0; i < n; i++) {
    int x = 1;
    //printf("B[%i] = ", i);
    for (int j = 0; j <= i; j++) {
      x *= A[j];
      /*if (j != 0)
        printf(" * ");*/
      //printf("%i", A[j]);
    }
    //printf(" = %i\n", x);
    B[i] = x;
  }
  //printf("\n");
  /*for (int i = 0; i < n; i++) {
    printf("B[%i] = %i\n", i, B[i]);
  }*/
}

void doAlgorithm2(int *A, int *B, const int n) {
  int buf = 1;
  for (int i = 0; i < n; i++) {
    buf *= A[i];
    B[i] = buf;
    buf = B[i];
  }
  /*for (int i = 0; i < n; i++) {
    printf("B[%i] = %i\n", i, B[i]);
  }*/
}
