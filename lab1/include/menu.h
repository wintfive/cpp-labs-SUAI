#ifndef MENU
#define MENU
#include "queue.h"

void   ClearScreen();
void   PrintMenu();
void   ContinueMenu();
Queue* SelectOption(Queue* queue);
void   MenuRealization(Queue* queue);
#endif /* MENU */