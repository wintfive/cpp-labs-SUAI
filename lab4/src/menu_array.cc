#include "../include/menu_stack.h"
#include "../include/secondary_functions.h"
#include <iostream>
#include <vector>

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
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
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