#ifndef UTILS_H
#define UTILS_H

#include "defs.h"

void HandleMenuLoop(Customer *customers, int n);
void FormatString(const char *s, char *target);

// getNameInput(char*), 
// promptUserMenu(), 
// promptUserMenu()

// not declared here because
// they are only called here, locally in the program
// (only within utils.c)

#endif