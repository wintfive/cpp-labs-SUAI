#ifndef MENU
#define MENU
#include "stack.h"

void   ClearScreen();
void   PrintMenu();
void   PauseMenu();
void   PauseMenu(int);
Stack* SelectOption(Stack* stack);
void   MenuRealization(Stack* stack);

#endif /* MENU */