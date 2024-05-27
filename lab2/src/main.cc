#include "../include/menu.h"
#include "../include/mydouble_processing.h"
#include "../include/stack_processing.h"

int main() {
  ClearScreen();
  OperationsWithMyDouble();
  PauseMenu(0);
  Stack* stack = CreateStack();
  MenuRealization(stack);
  return 0;
}