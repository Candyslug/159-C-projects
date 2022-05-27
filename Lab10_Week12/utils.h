
// Structure of each record
typedef struct Record {
    char name[20];
    int age;
    float wage;
} Record;

// Check to ensure the command line is valid
int checkArguments(const int argc);

// Count the number of lines in the file
int countFileLines(const char *fileName);

// Load the file contents into the dynamically allocated array
int loadFileContents(const char *fileName, Record *records);

// Get the number of valid records
int getRecordCount(Record *records);

// Check if a record is valid
int isValidRecord(Record r);

// (Debug) Display all the records in the array
void echoRecords(Record *records);

// Initalize defualt (blank) values for each record
void initRecords(Record *records);

// Output the valid records into the output file in reversed order
int outputRecords(Record *records);