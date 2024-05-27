#include "../include/stack.h"
#include <iomanip>
#include <iostream>

/* конструкторы для элемента и стека */
Stack::Element::Element(int data) : data(data), next(nullptr) {};
Stack::Stack() : head(nullptr) {};

int GetData(const Stack::Element* element) {
  return element->data;
}

Stack::Element* GetNext(const Stack::Element* element) {
  return element->next;
}

void SetData(int data, Stack::Element* element) {
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
void Stack::Push(int data) {
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
int Stack::Pop() {
  if (head == nullptr) {
    throw std::logic_error("Очередь пуста.");
  }
  Element* current = head;
  int      data    = GetData(head);
  head             = GetNext(head);
  delete current;
  return data;
}

/* метод вывода очереди на консоль */
void Stack::Print() const {
  Element* current = head;
  std::cout << "head: ";
  int first_iteration = 1;
  while (current != nullptr) {
    if (first_iteration) {
      std::cout << std::left << std::setw(16) << current->data << "^\n";
      first_iteration = 0;
    }
    else {
      std::cout << std::left << std::setw(22) << current->data << "|\n";
    }
    current = GetNext(current);
  }
}