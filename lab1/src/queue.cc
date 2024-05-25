#include "../include/queue.h"
#include <iostream>

Queue::Element::Element(int data) : data(data), prev(nullptr) {};
Queue::Queue() : head(nullptr), tail(nullptr) {};

Queue::~Queue() {
  while (head != nullptr) {
    Element* current = head;
    head             = head->prev;
    delete current;
  }
};

Queue::Queue(const Queue& original) : head(nullptr), tail(nullptr) {
  Element* current = original.head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}

Queue& Queue::operator=(const Queue& original) {
  if (this != &original) {
    this->~Queue();
    new (this) Queue(original);
  }
  return *this;
}

Queue::Element* Queue::GetHead() {
  return head;
};

Queue::Element* Queue::GetTail() {
  return tail;
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

void Queue::Print() const {
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

void Queue::Merge(Queue* second) {
  Element* current = second->head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}
