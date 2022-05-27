#ifndef CUSTOMERFUNCS_H
#define CUSTOMERFUNCS_H

#include "defs.h"

int CountUniqueEntries(const char *fileName);
void DisplayCustomers(Customer *customers, int n);
int GetCustomerIDbyName(const char* name, Customer *customers, int n);
void LoadCustomers(const char *fileName, Customer *customers, int n);
void DisplayCustomerChange(Customer customer);
void OutputCustomers(Customer *customers, int n);

#endif