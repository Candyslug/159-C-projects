#include "stdlib.h"

#include "utils.h"

int main(int argc, char *argv[]) {

    // Check for valid command line arguments
    if (checkArguments(argc) == -1) {
        return -1; // Close the program when error detected
    }
    // Get the file name from the command line
    const char *fileName = argv[1];

    // Get the number of lines in the file
    int lineCount = countFileLines(fileName);
    if (lineCount == -1) {
        return -1; // Close the program when error detected
    }

    // Create a dynamically allocated array of records
    Record *records = (Record*) malloc (sizeof(Record) * lineCount);
    // Create default (blank) values for the records 
    initRecords(records);

    // Load the records from the desired file
    if (loadFileContents(fileName, records) == -1) {
        return -1; // Close the program when error detected
    }

    // Output the records to output.csv
    if(outputRecords(records) == -1) {
        return -1; // Close the program when error detected
    }

    // Free the memory allocated for the records array
    free(records);

    return 0;
}