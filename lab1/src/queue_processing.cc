#include "../include/queue1.h"
#include "../include/secondary_functions.h"
#include <iostream>

/* функция создания очереди (объект класса Queue1) */
Queue1* CreateQueue() {
  Queue1* queue = new Queue1();
  return queue;
};

/* функция добавления элемента в очередь */
Queue1* PushQueue(Queue1* queue) {
  int data = 0;
  for (;;) {
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

/* функция извлечения элемента из очереди */
Queue1* PopQueue(Queue1* queue) {
  int data = 0;
  for (;;) {
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

/* функция вывода очереди на консоль */
void PrintQueue(Queue1* queue) {
  queue->Print();
  std::cout << '\n';
}

/* функция вычисления размаха (разности между максимальным и минимальным
 * элементами) для элементов с нечетным порядковым номером */
void FindSpread(Queue1* queue) {
  int spread = 0;
  try {
    spread = queue->Spread();
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
    return;
  }
  std::cout
    << "Размах для элементов с нечетным порядковым номером равен: "
    << spread << '\n';
}

/* функция копирования очереди (порядок сохранен)*/
Queue1* CopyQueue(Queue1* queue) {
  Queue1* copied_queue = new Queue1(*queue);
  return copied_queue;
}

/* функция объединения очередей (порядок сохранен) */
Queue1* MergeQueues(Queue1* first, Queue1* second) {
  Queue1* merged_queue = new Queue1(*first);
  merged_queue->Merge(second);
  return merged_queue;
}

/* функция удаления очереди */
void DeleteQueue(Queue1* queue) {
  delete queue;
}