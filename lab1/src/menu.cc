#include "../include/queue.h"
#include "../include/queue_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>

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
Queue* SelectOption(Queue* queue) {
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
    break;
  case 5:
    break;
  case 6:
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
void MenuRealization(Queue* queue) {
  for (;;) {
    ClearScreen();
    PrintMenu();
    queue = SelectOption(queue);
  }
}