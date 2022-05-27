#include "stdio.h"
#include "utils.h"

float KelvinToCelcius(const float d) {
  return d - 273.0f;
}

float CelciusToFahrenheit(const float d) {
  return 9.0f * d / 5.0f + 32.0f;
}

float KelvinToFahrenheit(const float d) {
  return 90.f * (d - 273.0f) / 5.0f + 32.0f;
  //return 9.0f * (KelvinToCelcius(d)) / 5.0f + 32.0f;
}

void ComputeMeans(const struct WaterSample data[], const int l, float *k, float *c, float *f) {
  float kk = 0.0f;
  float cc = 0.0f;
  float ff = 0.0f;
  for (int i = 0; i < l; i++) {
    kk += data[i].k;
    cc += data[i].c;
    ff += data[i].f;
  }

  *k = (kk / (float)l);
  *c = (cc / (float)l);
  *f = (ff / (float)l);
}

float ComputeMin(const float data[], const int l, int *id) {
  float min = data[0];
  for (int i = 0; i < l; i++) {
    if (data[i] < min) {
        *id = i;
        min = data[i];
    }
  }
  return min;
}

float ComputeMax(const float data[], const int l, int *id) {
  float max = data[0];
  for (int i = 0; i < l; i++) {
    if (data[i] > max) {
        *id = i;
        max = data[i];
    }
  }
  return max;
}

const char* GetWaterSampleState(const float c) {
  // c is temperature (celcius)
  if (c <= 0) {
    return "Solid";
  }
  else if (c >= 100) {
    return "Gas";
  }
  else {
    return "Liquid";
  }
}

void InitSample(const float k, struct WaterSample *sample) {
  struct WaterSample ret;

  ret.k = k;
  ret.c = KelvinToCelcius(ret.k);
  ret.f = CelciusToFahrenheit(ret.c);
  ret.state = GetWaterSampleState(ret.c);

  *sample = ret;
}

int GetSamplesLessThanThreshold(const struct WaterSample data[], const int l, const float threshold) {
  // threshold is kelvin degrees
  int count = 0;
  for (int i = 0; i < l; i++) {
    if (data[i].k < threshold) {
      count++;
    }
  }
  return  count;
}
