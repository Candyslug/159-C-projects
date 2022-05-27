#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include "stdlib.h"

const int MAX_SIZE = 100;
const char VOWELS[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {

  // ----Inputs----- //
  
  // Get size n input
  int max = GetValidSize();
  if (max == -1) 
    return 0;

  // Get string input
  char text[MAX_SIZE];
  if (GetValidString(text, max) == -1)
    return 0;

  // --------------- //
 
  unsigned long n = strlen(text);

  // Get total number of vowels
  int vowel_count = GetVowelCount(text, n);

  // Copy vowels into new string 
  char* output = (char*) malloc (sizeof(char) * n);
  CopyVowels(text, n, output);

  // Get count of each individual vowel
  int vowel_counter[] = { 0, 0, 0, 0, 0 };
  GetVowels(output, n, vowel_counter);

  // Get vowel appearance indexes
  int indexes[] = { -1, -1, -1, -1, -1 }; 
  GetVowelAppearanceIndexes(output, n, indexes);

  printf("\n");
  printf("String with only vowels:\n");
  printf("> %s\n", output);

  printf("\n");
  printf("Count of each vowel:\n");
  PrintVowelCounter(vowel_counter);

  printf("\n");
  printf("Index of each vowel appearance:\n");
  PrintVowelIndexes(indexes);  

  free(output);

  return 0;
}
