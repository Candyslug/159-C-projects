const int MAX_SIZE;
const char VOWELS[5];

int GetValidSize();

int GetValidString(char *text, const int n);

int GetVowelCount(const char* text, const int n);

void GetVowels(const char *text, const int n, int *counter);

void CopyVowels(const char *text, const int n, char* out);

void PrintVowelCounter(const int *counter);

void GetVowelAppearanceIndexes(const char *text, const int n, int *indexes);

void PrintVowelIndexes(const int *indexes);
