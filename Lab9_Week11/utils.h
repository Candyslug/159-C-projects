
#define maxEntryCount 100
int entryCount;
char names[maxEntryCount][100];
int ages[100]; 
float wages[100];

int countFileLines(const char *fileName);
int readDataFile(const char *fileName);
int writeDataFile(const char *fileName);
void DisplayEntry(const int index, const char *fileName);