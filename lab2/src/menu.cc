#include "../include/secondary_functions.h"
#include "../include/stack.h"
#include "../include/stack_processing.h"
#include <iostream>

/* функция очистки экрана через консоли escape-последовательности */
void ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/* функция вывода меню на консоль */
void PrintMenu() {
  std::cout << "Пользовательское меню:\n"
            << "1 – Добавление элемента в стек;\n"
            << "2 – Извлечение элемента из стека;\n"
            << "3 – Вывод стека на экран;\n"
            << "4 – Выход из программы.\n"
            << "Выберите вариант: ";
}

/* функция, которая ставит диалоговое окно на паузу */
void ContinueMenu() {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.get();
  std::cin.ignore(256, '\n');
}

/* функция выбора опции и возврата ее численного значения */
Stack* SelectOption(Stack* stack) {
  int option = StoiExceptionsProcessing(0);
  switch (option) {
  case 1:
    stack = PushStack(stack);
    break;
  case 2:
    stack = PopStack(stack);
    break;
  case 3:
    PrintStack(stack);
    break;
  case 4:
    std::cout << "Программа завершена.\n";
    DeleteStack(stack);
    exit(0);
    break;
  }
  ContinueMenu();
  return stack;
}

/* функция реализации меню */
void MenuRealization(Stack* stack) {
  for (;;) {
    ClearScreen();
    PrintMenu();
    stack = SelectOption(stack);
  }
}