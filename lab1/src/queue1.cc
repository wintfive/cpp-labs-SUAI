#include "../include/queue1.h"
#include <iostream>
#include <limits.h>

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