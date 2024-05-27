#ifndef STACK
#define STACK
#include "mydouble.h"

class Stack {
private:
  struct Element {
    MyDouble data;
    Element* next;
    Element(MyDouble data);
    explicit Element(int data);
    Element();
    ~Element();
    Element(const Element& original);
    Element& operator=(const Element& original);
    Element& operator+=(const Element& rvalue);
    Element& operator-=(const Element& rvalue);
    Element& operator*=(const Element& rvalue);
    Element& operator/=(const Element& rvalue);
  };
  Element* head;

public:
  Stack();
  Stack(int capacity);
  ~Stack();
  Stack(const Stack& original);
  Stack&          operator=(const Stack& original);
  void            Push(MyDouble data);
  MyDouble        Pop();
  void            Print() const;
  void            TestOverloadOperators();
  friend MyDouble GetData(const Element* element);
  friend Element* GetNext(const Element* element);
  friend void     SetData(MyDouble data, Element* element);
  friend void     SetNext(Element* next, Element* element);
  friend Element  operator+(const Stack::Element& lvalue,
                           const Stack::Element& rvalue);
  friend Element  operator-(const Stack::Element& lvalue,
                           const Stack::Element& rvalue);
  friend Element  operator*(const Stack::Element& lvalue,
                           const Stack::Element& rvalue);
  friend Element  operator/(const Stack::Element& lvalue,
                           const Stack::Element& rvalue);
};

#endif /* STACK */