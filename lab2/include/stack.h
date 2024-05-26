#ifndef STACK
#define STACK

class Stack {
private:
  struct Element {
    int      data;
    Element* next;
    Element(int data);
    friend int      GetData(const Element* element);
    friend Element* GetNext(const Element* element);
    friend void     SetData(int data, Element* element);
    friend void     SetNext(Element* next, Element* element);
  };
  Element* head;

public:
  Stack();
  ~Stack();
  Stack(const Stack& original);
  Stack& operator=(const Stack& original);
  void   Push(int data);
  int    Pop();
  void   Print() const;

  friend int      GetData(const Element* element);
  friend Element* GetNext(const Element* element);
  friend void     SetData(int data, Element* element);
  friend void     SetNext(Element* next, Element* element);
};

#endif /* STACK */