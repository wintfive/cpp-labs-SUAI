#include "../include/queue.h"
#include <iostream>

/* конструкторы для элемента и очереди */
Queue::Element::Element(int data) : data(data), prev(nullptr) {};
Queue::Queue() : head(nullptr), tail(nullptr) {};

/* деструктор */
Queue::~Queue() {
  while (head != nullptr) {
    Element* current = head;
    head             = head->prev;
    delete current;
  }
};

/* конструктор копирования */
Queue::Queue(const Queue& original) : head(nullptr), tail(nullptr) {
  Element* current = original.head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}

/* перегруженный оператор присваивания */
Queue& Queue::operator=(const Queue& original) {
  if (this != &original) {
    this->~Queue();
    new (this) Queue(original);
  }
  return *this;
}

/* геттер для head */
Queue::Element* Queue::GetHead() {
  return head;
};

/* геттер для tail */
Queue::Element* Queue::GetTail() {
  return tail;
};

/* метод добавления элемента в очередь */
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

/* метод извлечения элемента из очереди */
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

/* метод вывода очереди на консоль */
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

/* метод слияния двух очередей (порядок сохранен) */
void Queue::Merge(Queue* second) {
  Element* current = second->head;
  while (current != nullptr) {
    Push(current->data);
    current = current->prev;
  }
}
