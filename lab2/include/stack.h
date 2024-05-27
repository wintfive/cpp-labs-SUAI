#ifndef STACK
#define STACK
#include "mydouble.h"

class Stack {
private:
  struct Element {
    MyDouble data;
    Element* next;
    Element(MyDouble data);
    friend MyDouble GetData(const Element* element);
    friend Element* GetNext(const Element* element);
    friend void     SetData(MyDouble data, Element* element);
    friend void     SetNext(Element* next, Element* element);
  };
  Element* head;

public:
  Stack();
  ~Stack();
  Stack(const Stack& original);
  Stack&   operator=(const Stack& original);
  void     Push(MyDouble data);
  MyDouble Pop();
  void     Print() const;

  friend MyDouble GetData(const Element* element);
  friend Element* GetNext(const Element* element);
  friend void     SetData(MyDouble data, Element* element);
  friend void     SetNext(Element* next, Element* element);
};

#endif /* STACK */