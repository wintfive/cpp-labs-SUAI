#include "../include/queue.h"
#include "../include/element.h"
#include <iostream>
#include <limits.h>

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

int Queue::Spread() {
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