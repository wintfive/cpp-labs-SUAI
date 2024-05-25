#include "../include/queue.h"
#include "../include/queue1.h"
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
                 "'exit', если хотите перестать добавлять элементы: ";
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

Queue* PopQueue(Queue* queue) {
  int data = 0;
  while (true) {
    std::cout
      << "Напишите 'yes', если хотите извлечь элемент или напишите "
         "'exit', если хотите перестать извлекать элементы: ";
    try {
      StoiExceptionsProcessing('a');
      data = queue->Pop();
    }
    catch (const std::logic_error& e) {
      std::cerr << e.what() << '\n';
      break;
    }
    std::cout << "Извлечен элемент со значением: " << data << '\n';
  }
  return queue;
};

void PrintQueue(Queue* queue) {
  queue->Print();
  std::cout << '\n';
}

void FindSpread(Queue1* queue1) {
  int spread = 0;
  try {
    spread = queue1->Spread();
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
    return;
  }
  std::cout
    << "Размах для элементов с нечетным порядковым номером равен: "
    << spread << '\n';
}

Queue* CopyQueue(Queue* queue) {
  Queue* copied_queue = new Queue(*queue);
  return copied_queue;
}

Queue* MergeQueues(Queue* first, Queue* second) {
  Queue* merged_queue = new Queue(*first);
  merged_queue->Merge(second);
  return merged_queue;
}

void DeleteQueue(Queue* queue) {
  delete queue;
}