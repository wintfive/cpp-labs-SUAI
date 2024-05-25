#include "../include/queue1.h"
#include <iostream>
#include <limits.h>

Queue1::Queue1() : Queue() {};

Queue1::~Queue1() {
  Queue::~Queue();
};

Queue1::Queue1(const Queue1& original) : Queue(original) {}

Queue1& Queue1::operator=(const Queue1& original) {
  if (this != &original) {
    Queue::operator=(original);
  }
  return *this;
}

/* метод вычисления размаха для элементов с нечетным порядковым номером
 */
int Queue1::Spread() {
  Element* current     = GetHead();
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
  Queue::Push(data);
}

int Queue1::Pop() {
  return Queue::Pop();
}

void Queue1::Print() const {
  Queue::Print();
}

void Queue1::Merge(Queue1* second) {
  Queue::Merge(second);
}
