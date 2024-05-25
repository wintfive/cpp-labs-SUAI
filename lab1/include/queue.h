#ifndef QUEUE
#define QUEUE

class Queue {
protected:
  struct Element {
    int      data;
    Element* prev;
    Element(int data);
  };

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
  void   Print() const;
  void   Merge(Queue* second);
};

#endif /* QUEUE */