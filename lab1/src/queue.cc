#include "../include/queue.h"
#include "../include/element.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {};
Queue::~Queue() {
  while (head != nullptr) {
    Element* current = head;
    head             = head->prev;
    delete current;
  }
};

void Queue::Push(int data) {
  Element* element = new Element(data);
  if (head == nullptr) {
    head = tail = element;
  }
  else {
    tail->prev = element;
    tail       = element;
  }
}

int Queue::Pop() {
  if (head == nullptr) {
    throw std::logic_error("Очередь пуста.");
  }
  Element* current = head;
  int      data    = head->data;
  head             = head->prev;
  delete current;
  return data;
}

void Queue::Print() {
  Element* current = head;
  std::cout << "head                       tail\n"
            << "------------------------------>\n";
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->prev;
  }
}