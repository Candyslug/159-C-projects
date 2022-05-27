#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include "ctype.h"

int GetValidSize() {
  int max;
  printf("Enter a number (n <= 100)\n> ");
  scanf("%d", &max);
  fflush(stdin);
  if (max <= 0) {
    printf("Error: number <= 0\n");
    return -1;
  }
  else if (max > 100) {
    printf("Error: number > 100\n");
    return -1;
  }
  return max;
}

int GetValidString(char *text, const int n) {
  printf("Input a string (length <= %i)\n> ", n);
  fgets(text, MAX_SIZE-1, stdin);
  fflush(stdin);
  unsigned long l = strlen(text); // length of input string
  if (l <= 0) {
    printf("Error: string length <= 0\n");
    return -1;
  }
  else if (l > n) {
    printf("Error: string length > %i\n", n);
    return -1;
  }
  printf("New string: %s\n", text);
  return 0;
}

int GetVowelCount(const char* text, const int n) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int a = 0; a < 5; a++) {
      if (text[i] == VOWELS[a]) {
        ret += 1;
      }
    }
  }
  return ret;
}

void GetVowels(const char *text, const int n, int *counter) {
  for (int i = 0; i < n; i++) {
    for (int a = 0; a < 5; a++) {
      if (text[i] == VOWELS[a]) {
        counter[a] += 1;
      }
    }
  }
}

void CopyVowels(const char *text, const int n, char* out) {
  int index = 0;    
  for (int i = 0; i < n; i++) {
    for (int a = 0; a < 5; a++) {
      if (tolower((unsigned char)text[i]) == VOWELS[a]) {
        out[index] = tolower((unsigned char) VOWELS[a]);
        //out[index] = VOWELS[a];
        index += 1;
      }
    }
  }
}

void PrintVowelCounter(const int *counter) {
  for (int i = 0; i < 5; i++) {
    printf("%c: %i\n", VOWELS[i], counter[i]);
  }
}

void GetVowelAppearanceIndexes(const char *text, const int n, int *indexes) {
  for (int a = 0; a < 5; a++) {
    for (int i = 0; i < n; i++) {
      if (text[i] == VOWELS[a]) {
        indexes[a] = i;  
        break;
      }
    }
  }
}

void PrintVowelIndexes(const int *indexes) {
  for (int i = 0; i < 5; i++) {
    if (indexes[i] == -1) {
      printf("%c: Not in text\n", VOWELS[i]);
    }
    else {
      printf("%c: %i\n", VOWELS[i], indexes[i]);
    }
  }
}
