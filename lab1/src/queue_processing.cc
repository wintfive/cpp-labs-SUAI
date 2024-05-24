#include "../include/queue.h"
#include "../include/secondary_functions.h"
#include <iostream>

Queue* CreateQueue() {
  Queue* queue = new Queue();
  return queue;
};

Queue* PushQueue(Queue* queue) {
  int data = 0;
  while (true) {
    std::cout << "Напишите значение добавляемого элемента или напишите "
                 "exit, если хотите перестать добавлять элементы: ";
    try {
      data = StoiExceptionsProcessing();
    }
    catch (const std::logic_error& e) {
      std::cerr << e.what() << '\n';
      break;
    }
    queue->Push(data);
    std::cout << "Добавлен элемент со значением: " << data << '\n';
  }
  return queue;
};

void PrintQueue(Queue* queue) {
  queue->Print();
  std::cout << '\n';
}

void DeleteQueue(Queue* queue) {
  delete queue;
}