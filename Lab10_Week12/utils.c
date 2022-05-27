#include "utils.h"

#include "stdio.h"
#include "strings.h"

int checkArguments(const int argc) {
    if (argc == 2) {
        // Correct number of arguments detected
        // Do nothing...
    }
    else if (argc > 2) {
        perror("(checkArguments) Error: Too many arguments supplied.\n");
        return -1;
    }
    else {
        perror("(checkArguments) Error: Argument expected\n");
        return -1;
    }
    // Exit function with no errors
    return 0;
}

int countFileLines(const char *fileName) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        // Exit the function with return value -1
        // Print error message
        printf("(countFileLines) Error: Error opening file %s\n", fileName);
        return -1;
    }
    int lines = 0;
    int c = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    fclose(f);
    // Check to ensure the line count is a valid amount
    // If the file is blank, cancel the function and return -1
    if (lines <= 0) {
        printf("(countFileLines) Error: line count %i is too low.\n", lines);
        return -1;
    }
    return lines;
}

int loadFileContents(const char *fileName, Record *records) {
    int fileLines = countFileLines(fileName);
    // Print a warning if the input file has too many lines/entries
    if (fileLines > 10)  {
        printf("(loadFileContents) Warning: %s has %i lines. Only first 10 will be read.\n", fileName, fileLines);
        fileLines = 10;
    }
    FILE *f = fopen(fileName, "r");
    // Exit the function and return -1 (error) back to the main function
    // if the file does not open correctly
    if (f == NULL) {
        printf("(loadFileContents) Error: Error opening file %s\n", fileName);
        return -1;
    }
    int line = 0;
    // Buffers to temporarily hold each record item
    char cbuff[20];
    int ibuff; 
    float fbuff; 
    while (fscanf(f, "%s %d %f", cbuff, &ibuff, &fbuff) != EOF && line < 10) {
        //printf(" > line %i : %s, %d, %1.3f\n", line + 1, cbuff, ibuff, fbuff);

        // Record buffer to temporarily hold each record entry (line)
        Record buff;
        strcpy(buff.name, cbuff);
        buff.age = ibuff;
        buff.wage = fbuff;
        // Copy that Record buffer into the array at the correct index
        records[line] = buff;
        // Increment the index
        line++;
    }
    fclose(f);
    // Function exit with no errors detected
    return 0;
}

int getRecordCount(Record *records) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        // Skip the current index if the record is invalid
        if (!isValidRecord(records[i])) {
            continue;
        }
        // Increment the count
        count++;
    }
    // Return the count of valid records
    return count;
}

int isValidRecord(Record r) {
    // Check if the record is valid by comparing the
    // name string to a blank string

    // The name string will be blank by default (init function)
    if (strcmp(r.name, "") == 0) return 0;  
    return 1;
}

// For debugging purposes
void echoRecords(Record *records) {
    // If there are no valid records print the message
    if (getRecordCount(records) <= 0) {
        printf("No records.\n");
        return;
    }
    // Loop through each entry in the record array
    printf("Records:\n");
    for (int i = 0; i < 10; i++) {
        // Skip records that are invalid
        if (!isValidRecord(records[i]))
            continue;
        // Print the information for the current record
        printf(" > [%i] : %s, %i, %1.3f\n", 
            i+1, 
            records[i].name, 
            records[i].age, 
            records[i].wage);
    }
}

void initRecords(Record *records) {
    // Loop through the records and copy default into the entries
    for (int i = 0; i < 10; i++) {
        // Blank (zero) name, age, wage
        strcpy(records[i].name, "");
        records[i].age = 0;
        records[i].wage = 0.0f;
    }
}

int outputRecords(Record *records) {
    const char *fileName = "output.csv";
    FILE *f = fopen("output.csv", "w");
    if (f == NULL) {
        // Return -1 (error) when the file does not open correctly
        printf("(outputRecords) Error: Error opening file %s\n", fileName);
        return -1;
    }
    int first = 0; // Check to only print a newline after the first line
    // Loop backward (10 -> 0)
    for (int i = 10; i >= 0; i--) {
        // Only output the records which are valid
        if (isValidRecord(records[i])) {
            if (first == 0) {
                fprintf(f, "%s,%i,%1.3f", records[i].name, records[i].age, records[i].wage);
                first = 1;
            }
            else {
                fprintf(f, "\n%s,%i,%1.3f", records[i].name, records[i].age, records[i].wage);
            }
        }
    }
    fclose(f);
    // Return 0 (function exit without error)
    return 0;
}