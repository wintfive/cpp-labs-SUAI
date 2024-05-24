#include "../include/queue.h"
#include "../include/secondary_functions.h"
#include <iostream>

Queue* CreateQueue() {
  Queue* queue = new Queue();
  return queue;
};

Queue* PushQueue(Queue* queue) {
  std::cout << "Напишите значение добавляемого элемента: ";
  int data = StoiExceptionsProcessing();
  queue->Push(data);
  std::cout << "Добавлен элемент со значением: " << data << "\n";
  return queue;
};

void PrintQueue(Queue* queue) {
  queue->Print();
  std::cout << "\n";
}

void DeleteQueue(Queue* queue) {
  delete queue;
}