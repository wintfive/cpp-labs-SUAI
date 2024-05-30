#include "../include/exchange_processing.h"
#include "../include/file_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>
#include <limits>

/* функция очистки экрана через консоли escape-последовательности */
void ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/* функция вывода меню на консоль */
void PrintMenu() {
  std::cout << "Пользовательское меню (изменять курс и баланс через "
               "файл input.txt):\n"
            << "1 – Вывод курсов валют;\n"
            << "2 – Вывод баланса;\n"
            << "3 – Восстановить файл input.txt\n"
            << "4 – Выход из программы.\n"
            << "Выберите вариант: ";
}

/* функции, которые ставят диалоговое окно на паузу */
void PauseMenu(int) {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PauseMenu() {
  std::cout << "Для продолжения программы нажмите на Enter...\n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* функция выбора опции и возврата ее численного значения */
Ruble** SelectOption(Ruble** exchanges) {
  int option = StoiExceptionsProcessing(0);
  exchanges  = InputFileProcessing(exchanges);
  switch (option) {
  case 1:
    PrintRates(exchanges);
    exchanges = ChangeRates(exchanges);
    PauseMenu();
    break;
  case 2:
    PrintBalance(exchanges);
    exchanges = ChangeBalance(exchanges);
    PauseMenu();
    break;
  case 3:
    FileRecovery();
    PauseMenu(0);
    break;
  case 4:
    std::cout << "Программа завершена.\n";
    DeleteExchanges(exchanges);
    exit(0);
    break;
  }
  OutputFileProcessing(exchanges);
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