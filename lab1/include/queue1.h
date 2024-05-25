#ifndef QUEUE1
#define QUEUE1
#include "queue.h"

class Queue1 : public Queue {
private:
  Element* head;

public:
  int Spread();
};

#endif /* QUEUE1 */