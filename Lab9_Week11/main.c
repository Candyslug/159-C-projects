#include "utils.h"

#include "stdio.h"
#include "strings.h"
#include <string.h>


int main(int argc, char *argv[]) {

  if (argc == 2) {
    //printf("Argument supplied: %s\n", argv[1]);
  }
  else if (argc > 2) {
    perror("Too many arguments supplied.\n");
    return -1;
  }
  else {
    perror("Argument expected");
    return -1;
  }
  //
  // ------------------- //

  const char *fileName = argv[1];
  entryCount = countFileLines(fileName);
  if (entryCount == -1) {
    return -1;
  }
  if (entryCount >= 1000) {
    perror("Entry limit exceeded 1000.\n");
    return -1;
  }
  //printf("Line count: %i\n", entryCount);

  // ------------------- //

  // save file data to arrays
  printf("\n");
  readDataFile(fileName);
  
  printf("\n");
  printf("Data has been copied to multiple arrays.\n");
  // ------------------- //

  /*printf("===============\n");
  for (int i = 0; i < entryCount; i++) {
    printf("%i : %s, %i, %1.3f\n", i, names[i], ages[i], wages[i]);
  }
  printf("===============\n");*/

  // write file data to new file
  printf("\n");
  writeDataFile("output.csv");

  // ------------------- //
  
  // get name from user input
  char buff[20];
  printf("\nEnter a name to search\n");
  printf(" > ");
  fgets(buff, 20, stdin);
  printf("\n");
  unsigned int l = strlen(buff);
  if (l > 20) {
    perror("Error: Input name length exceeding 20");
    return -1;
  }
  if (l <= 0) {
    perror("Error: Input name length <= 0");
    return -1;
  }
  // remove newline from string
  if (buff[l-1] == '\n') {
    buff[l-1] = '\0';
  }

  // ------------------- //
    
  // search for the name in the array
  int index = -1;
  for (int i = 0; i < entryCount; i++) {
    //printf("[%i] %s == %s ? \n", i, buff, names[i]);
    if (strcmp(buff, names[i]) == 0) {
      //printf("Name found at index %i.\n", i);
      index = i;
      // Will return the first instance of the name found
      break;
    }
  }
  if (index == -1) {
    printf("Name \"%s\" not found.\n", buff);
    return 0;
  }
  DisplayEntry(index, fileName);


  return 0;
}
