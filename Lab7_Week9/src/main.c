#include "stdio.h"
#include "utils.h"

int main() {
  printf("Enter 10 Kelvin temperatures.\n");
  printf("Example:   300 320 294 404 378 345 303 421 278 360\n");

  // get inputs
  float inputs[10];
  printf("> ");
  scanf("%f %f %f %f %f %f %f %f %f %f", 
    &inputs[0], 
    &inputs[1], 
    &inputs[2], 
    &inputs[3], 
    &inputs[4], 
    &inputs[5], 
    &inputs[6], 
    &inputs[7], 
    &inputs[8], 
    &inputs[9]); 

  printf("\n");
  printf("Enter threshold T (Kelvin degrees).\n");
  printf("Example:   300.521\n");

  float t = 0.0f; // threshold T
  printf("> ");
  scanf("%f", &t);
  printf("\n");

  // get min/max id
  int minIndex;
  int maxIndex;
  const float min = ComputeMin(inputs, 10, &minIndex);
  const float max = ComputeMax(inputs, 10, &maxIndex);

  // create water samples from inputs
  struct WaterSample samples[10];
  for (int i = 0; i < 10; i++) {
    struct WaterSample buff;
    InitSample(inputs[i], &buff);
    samples[i] = buff;
  }

  // display each sample row
  for (int i = 0; i < 10; i++) {
    printf("Sample %2i :  %12.5f K  |  %12.5f c  |  %12.5f F  |  %s\n",
      i + 1,
      samples[i].k,
      samples[i].c,
      samples[i].f,
      samples[i].state);
  }

  // other computations
  printf("\n");
  printf("Sample %2i has the minimum temperature of %0.5f.\n", minIndex + 1, min);
  printf("Sample %2i has the maximum temperature of %0.5f.\n", maxIndex + 1, max);

  // mean computations
  float meanK;
  float meanC;
  float meanF;
  ComputeMeans(samples, 10, &meanK, &meanC, &meanF);
  printf("\n");
  printf("Mean Temperatures\n");
  printf("Kelvin     : %12.5f K\n", meanK);
  printf("Celcius    : %12.5f c\n", meanC);
  printf("Fahrenheit : %12.5f F\n", meanF);

  // display amount of water samples less than threshold T
  printf("\n");
  printf("Number of samples less than threshold T (%0.3f K):   %i\n", 
    t, GetSamplesLessThanThreshold(samples, 10, t)); 

  return 0;
}
