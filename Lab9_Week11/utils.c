#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include <string.h>

int entryCount = -1;

int countFileLines(const char *fileName) {
  FILE *f = fopen(fileName, "r");
  if (f == NULL) {
    perror("(countFileLines) Error opening file");
    return -1;
  }
  int warning = 0;
  int lines = 0;
  int c = 0;
  while ((c = fgetc(f)) != EOF) {
    if (lines > 100) {
      if (warning == 0) {
        printf("Warning: Line count exceeding 100...\n");
        warning = 1;
      }
    }
    if (c == '\n') {
      lines++;
    }
  }
  fclose(f);
  if (lines <= 0) {
    printf("(countFileLines) %s has %i lines.\n", fileName, lines);
    return -1;
  } 
  if (lines >= maxEntryCount) {
      printf("(countFileLines) %s lines exceeded maximum entry count of %i\n", fileName, maxEntryCount);
      return -1;
  }
  printf("%s has %i lines.\n", fileName, lines);
  return lines;
}

int readDataFile(const char *fileName) {
  FILE *f = fopen(fileName, "r");
  if (f == NULL) {
    return -1;
  }
  int i = 0;

  printf("%s contents: \n", fileName);
  char cbuff[20];
  int ibuff;
  float fbuff;
  while (fscanf(f, "%s %d %f", cbuff, &ibuff, &fbuff) != EOF) {
    if (i >= entryCount) break;
    printf(" > Line %i: \"%s %d %f\"\n", i+1, cbuff, ibuff, fbuff);
    strncpy(names[i], (char*)cbuff, strlen(cbuff));
    ages[i] = ibuff;
    wages[i] = fbuff;
    i++;
  }
  fclose(f);
  return 0;
}

int writeDataFile(const char *fileName) {
  FILE *f = fopen(fileName, "w");
  if (f == NULL) {
    return -1;
  }
  printf("Writing to %s:\n", fileName);

  for (int i = 0; i < entryCount; i++) {
    printf(" > Line %i : \"%s,%i,%1.3f\"\n", i+1, names[i], ages[i], wages[i]);
    fprintf(f, "%s,%i,%1.3f\n", names[i], ages[i], wages[i]);
  }
  fclose(f);
  return 0;
}

void DisplayEntry(const int index, const char *fileName) {
  printf("Entry %i (Line %i in %s):\n", index, index+1, fileName);
  printf(" > Name: %s\n", names[index]);
  printf(" > Age: %i\n", ages[index]);
  printf(" > Wage: %1.3f\n", wages[index]);
}
