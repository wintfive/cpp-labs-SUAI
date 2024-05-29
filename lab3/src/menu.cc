#include "../include/exchange_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>
#include <limits>

/* функция очистки экрана через консоли escape-последовательности */
void ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/* функция вывода меню на консоль */
void PrintMenu() {
  std::cout << "Пользовательское меню:\n"
            << "1 – Вывод и изменение курсов валют;\n"
            << "2 – Вывод и изменение баланса;\n"
            << "3 – Выход из программы.\n"
            << "Выберите вариант: ";
}

/* функции, которые ставят диалоговое окно на паузу */
void PauseMenu() {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PauseMenu(int) {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* функция выбора опции и возврата ее численного значения */
Ruble** SelectOption(Ruble** exchanges) {
  int option = StoiExceptionsProcessing();
  switch (option) {
  case 1:
    PrintRates(exchanges);
    break;
  case 2:
    break;
  case 3:
    std::cout << "Программа завершена.\n";
    DeleteExchanges(exchanges);
    exit(0);
    break;
  }
  PauseMenu();
  return exchanges;
}

/* функция реализации меню */
void MenuRealization(Ruble** exchanges) {
  for (;;) {
    ClearScreen();
    PrintMenu();
    exchanges = SelectOption(exchanges);
  }
}