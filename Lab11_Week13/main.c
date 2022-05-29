#include "stdio.h"
#include "stdlib.h"

#include "utils.h"

int main(int argc, char *argv[]) {

  int n = checkArgs(argc, argv);

  int *A = (int*) malloc (sizeof(int) * n);
  int *B = (int*) malloc (sizeof(int) * n);

  initArray(A, n);

  //doAlgorithm(A, B, n);
  doAlgorithm2(A, B, n);

  free(B);
  free(A);

  return 0;
}
