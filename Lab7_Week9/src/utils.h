#include "stdio.h"

struct WaterSample {
  float k; // kelvin  
  float c; // celcius
  float f; // fahrenheit
  const char* state;
};

float KelvinToCelcius(const float d);

float CelciusToFahrenheit(const float d);

float KelvinToFahrenheit(const float d);

void ComputeMeans(const struct WaterSample data[], const int l, float *k, float *c, float *f);

float ComputeMin(const float data[], const int l, int *id);

float ComputeMax(const float data[], const int l, int *id);

const char* GetWaterSampleState(const float c);

void InitSample(const float k, struct WaterSample *sample);

int GetSamplesLessThanThreshold(const struct WaterSample data[], const int l, const float threshold);
