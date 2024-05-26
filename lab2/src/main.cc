#include "../include/menu.h"
#include "../include/stack_processing.h"

int main() {
  Stack* stack = CreateStack();
  MenuRealization(stack);
  return 0;
}