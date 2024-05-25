#ifndef QUEUE1
#define QUEUE1
#include "queue.h"

class Queue1 : private Queue {
public:
  Queue1();
  ~Queue1();
  Queue1(const Queue1& original);
  Queue1& operator=(const Queue1& original);
  int     Spread();
  void    Push(int data);
  int     Pop();
  void    Print() const;
  void    Merge(Queue1* second);
};

#endif /* QUEUE1 */