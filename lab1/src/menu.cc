#include "../include/queue1.h"
#include "../include/queue_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>

Queue1* copied_queue = new Queue1();
Queue1* merged_queue = new Queue1();

/* функция очистки экрана через консоли escape-последовательности */
void ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/* функция вывода меню на консоль */
void PrintMenu() {
  std::cout
    << "Пользовательское меню:\n"
    << "1 – Добавление элемента очереди;\n"
    << "2 – Извлечение элемента очереди;\n"
    << "3 – Вывод очереди на экран;\n"
    << "4 – Вычисление размаха (разности между максимальным и "
       "минимальным элементами) для элементов с нечетным порядковым "
       "номером;\n"
    << "5 – Создание копии очереди;\n"
    << "6 – Слияние оригинальной очереди с копией и вывод результата "
       "на экран;\n"
    << "7 – Выход из программы.\n"
    << "Выберите вариант: ";
}

/* функция, которая ставит диалоговое окно на паузу */
void ContinueMenu() {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.get();
  std::cin.ignore(256, '\n');
}

/* функция выбора опции и возврата ее численного значения */
Queue1* SelectOption(Queue1* queue) {
  int option = StoiExceptionsProcessing(0);
  switch (option) {
  case 1:
    queue = PushQueue(queue);
    break;
  case 2:
    queue = PopQueue(queue);
    break;
  case 3:
    PrintQueue(queue);
    break;
  case 4:
    FindSpread(queue);
    break;
  case 5:
    copied_queue = CopyQueue(queue);
    std::cout << "Очередь была успешно скопирована!\n";
    PrintQueue(copied_queue);
    break;
  case 6:
    merged_queue = MergeQueues(queue, copied_queue);
    std::cout << "Слияние очередей прошло успешно!\n";
    PrintQueue(merged_queue);
    break;
  case 7:
    std::cout << "Программа завершена.\n";
    DeleteQueue(queue);
    exit(0);
  }
  ContinueMenu();
  return queue;
}

/* функция реализации меню */
void MenuRealization(Queue1* queue) {
  for (;;) {
    ClearScreen();
    PrintMenu();
    queue = SelectOption(queue);
  }
}