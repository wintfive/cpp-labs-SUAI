#ifndef ELEMENT
#define ELEMENT

class Element {
  friend class Queue;

private:
  int      data;
  Element* prev;
  Element(int data);
};

#endif /* ELEMENT */