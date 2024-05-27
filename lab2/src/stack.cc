#include "../include/stack.h"
#include "../include/secondary_functions.h"
#include <iomanip>
#include <iostream>

/* конструкторы для элемента и стека */
Stack::Element::Element(MyDouble data) : data(data), next(nullptr) {};
Stack::Element::Element(int data) : data(data), next(nullptr) {};
Stack::Element::Element() : data(0), next(nullptr) {};
Stack::Element::~Element() = default;

/* конструктор копирования */
Stack::Element::Element(const Element& original) : data(0) {
  SetData(GetData(&original), this);
}

/* перегруженный оператор присваивания */
Stack::Element&
Stack::Element::operator=(const Stack::Element& original) {
  SetData(GetData(&original), this);
  return *this;
}

Stack::Stack() : head(nullptr) {};
Stack::Stack(int capacity) : head(nullptr) {
  for (int i = 0; i < capacity; ++i) {
    Push(RandomDouble(-100, 100));
  }
};

MyDouble GetData(const Stack::Element* element) {
  return element->data;
}

Stack::Element* GetNext(const Stack::Element* element) {
  return element->next;
}

void SetData(MyDouble data, Stack::Element* element) {
  element->data = data;
}

void SetNext(Stack::Element* next, Stack::Element* element) {
  element->next = next;
}

/* деструктор */
Stack::~Stack() {
  while (head != nullptr) {
    Element* current = head;
    head             = GetNext(head);
    delete current;
  }
};

/* конструктор копирования */
Stack::Stack(const Stack& original) : head(nullptr) {
  Element* current = original.head;
  while (current != nullptr) {
    Push(GetData(current));
    current = GetNext(current);
  }
}

/* перегруженный оператор присваивания */
Stack& Stack::operator=(const Stack& original) {
  if (this != &original) {
    this->~Stack();
    new (this) Stack(original);
  }
  return *this;
}

/* метод добавления элемента в очередь */
void Stack::Push(MyDouble data) {
  // Element  a = 5;
  // Element  a(5);
  Element* current = new Element(data);
  if (head == nullptr) {
    head = current;
  }
  else {
    SetNext(head, current);
    head = current;
  }
}

/* метод извлечения элемента из очереди */
MyDouble Stack::Pop() {
  if (head == nullptr) {
    throw std::logic_error("Очередь пуста.");
  }
  Element* current = head;
  MyDouble data    = GetData(head);
  head             = GetNext(head);
  delete current;
  return data;
}

/* метод вывода очереди на консоль */
void Stack::Print() const {
  Element* current = head;
  std::cout << "Стек:\nhead: ";
  int first_iteration = 1;
  while (current != nullptr) {
    if (first_iteration) {
      std::cout << std::left << std::setw(18) << GetData(current)
                << "^\n";
      first_iteration = 0;
    }
    else {
      std::cout << std::left << std::setw(24) << GetData(current)
                << "|\n";
    }
    current = GetNext(current);
  }
}