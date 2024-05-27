#include "../include/menu.h"
#include "../include/mydouble.h"
#include "../include/secondary_functions.h"
#include <iomanip>
#include <iostream>

void OperationsWithMyDouble() {
  std::cout << "Задание №1" << '\n';
  MyDouble value(ReadDouble());
  // MyDouble value;
  std::cout << "Искомое число: " << value << '\n';
  ++value;
  std::cout << "Префиксная форма инкремента: " << value << '\n';
  value++;
  std::cout << "Постфиксная форма инкремента: " << value << '\n';
  --value;
  std::cout << "Префиксная форма декремента: " << value << '\n';
  value--;
  std::cout << "Постфиксная форма декремента: " << value << '\n';
  MyDouble reversed_value = !value;
  std::cout << "Оператор логического отрицания: " << reversed_value
            << '\n';
}