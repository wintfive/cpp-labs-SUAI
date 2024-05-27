#ifndef MENU
#define MENU
#include "stack.h"

void   ClearScreen();
void   PrintMenu();
void   PauseMenu();
Stack* SelectOption(Stack* stack);
void   MenuRealization(Stack* stack);

#endif /* MENU */