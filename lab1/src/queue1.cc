#include "../include/queue1.h"
#include <iostream>
#include <limits.h>

Queue1::Queue1() : head(nullptr), tail(nullptr) {};

Queue1::~Queue1() {
  while (head != nullptr) {
    Element* current = head;
    head             = head->prev;
    delete current;
  }
};

Queue1::Queue1(const Queue1& original) : head(nullptr), tail(nullptr) {
  Element* current = original.head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}


Queue1& Queue1::operator=(const Queue1& original) {
  if (this != &original) {
    this->~Queue1();
    new (this) Queue1(original);
  }
  return *this;
}

int Queue1::Spread() {
  Element* current     = head;
  int      max_element = INT_MIN;
  int      min_element = INT_MAX;

  if (current == nullptr) {
    throw std::logic_error("Очередь пуста.");
  }

  while (current != nullptr) {
    if (current->data > max_element) {
      max_element = current->data;
    }
    if (current->data < min_element) {
      min_element = current->data;
    }
    current = current->prev;
    if (current != nullptr) {
      current = current->prev;
    }
  }

  return max_element - min_element;
}

void Queue1::Push(int data) {
  Element* element = new Element(data);
  if (head == nullptr) {
    head = tail = element;
  }
  else {
    tail->prev = element;
    tail       = element;
  }
}

int Queue1::Pop() {
  if (head == nullptr) {
    throw std::logic_error("Очередь пуста.");
  }
  Element* current = head;
  int      data    = head->data;
  head             = head->prev;
  delete current;
  return data;
}

void Queue1::Print() const {
  Element* current = head;
  int      counter = 0;
  std::cout << "         head                       tail\n"
            << "         ------------------------------>\n"
            << "Очередь: ";
  while (current != nullptr) {
    ++counter;
    std::cout << current->data << " (" << counter << ") | ";
    current = current->prev;
  }
}

void Queue1::Merge(Queue1* second) {
  Element* current = second->head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}
