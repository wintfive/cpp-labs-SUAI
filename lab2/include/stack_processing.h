#ifndef STACK_PROCESSING
#define STACK_PROCESSING
#include "stack.h"

Stack* CreateStack();
Stack* PushStack(Stack* stack);
Stack* PopStack(Stack* stack);
void   PrintStack(Stack* stack);
void   DeleteStack(Stack* stack);

#endif /* STACK_PROCESSING */