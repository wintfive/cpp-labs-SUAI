#include "../include/array_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>
#include <limits>
#include <vector>

/* функция очистки экрана через консоли escape-последовательности */
void ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/* функция вывода меню на консоль */
void PrintMenuArray() {
  std::cout << "Задание №1\n"
            << "Пользовательское меню:\n"
            << "1 – Создание массива <int>, его вывод и нахождение "
               "среднего арифметического элементов;\n"
            << "2 – Создание массива <char>, его вывод и нахождение "
               "среднего арифметического элементов;\n"
            << "3 – Создание массива <float>, его вывод и нахождение "
               "среднего арифметического элементов;\n"
            << "4 – Создание массива <double>, его вывод и нахождение "
               "среднего арифметического элементов;\n"
            << "5 – Создание массива <char*> и нахождение "
               "среднего арифметического длин его элементов;\n"
            << "6 – Перейти к заданию №2.\n"
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
int SelectArray() {
  int                 option = StoiExceptionsProcessing(6);
  std::vector<int>    array_int;
  std::vector<char>   array_char;
  std::vector<float>  array_float;
  std::vector<double> array_double;
  std::vector<char*>  array_char_pointer;

  switch (option) {
  case 1:
    CreateArray<int>(array_int);
    PrintArray<int>(array_int);
    AverageArray<int>(array_int);
    break;
  case 2:
    CreateArray<char>(array_char);
    PrintArray<char>(array_char);
    AverageArray<char>(array_char);
    break;
  case 3:
    CreateArray<float>(array_float);
    PrintArray<float>(array_float);
    AverageArray<float>(array_float);
    break;
  case 4:
    CreateArray<double>(array_double);
    PrintArray<double>(array_double);
    AverageArray<double>(array_double);
    break;
  case 5:
    CreateArray<char*>(array_char_pointer);
    PrintArray<char*>(array_char_pointer);
    AverageArray<char*>(array_char_pointer);
    DeleteCharPointerArray(array_char_pointer);
    break;
  case 6:
    return 0;
    break;
  }
  PauseMenu();
  return 1;
}

/* функция реализации меню */
void MenuArrayRealization() {
  for (;;) {
    ClearScreen();
    PrintMenuArray();
    if (!SelectArray())
      break;
  }
}