#ifndef QUEUE
#define QUEUE
#include "element.h"

class Queue {
private:
  Element* head;
  Element* tail;

public:
  Queue();
  ~Queue();
  Queue(const Queue& original);
  Queue& operator=(const Queue& original);
  void   Push(int data);
  int    Pop();
  void   Print();
  int    Spread();
  void   Merge(Queue* second);
};

#endif /* QUEUE */