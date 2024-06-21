#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include "array.h"

void initUi();

void endUi();

int showMenu(char* choices[], int);

void displayArray(Array& arr, int delay);

#endif // UI_H
