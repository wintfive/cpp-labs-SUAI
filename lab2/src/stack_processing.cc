#include "../include/menu.h"
#include "../include/secondary_functions.h"
#include "../include/stack.h"
#include <iostream>

/* функция создания стека (объект класса Stack) */
Stack* CreateStack() {
  Stack* stack = new Stack();
  return stack;
};

/* функция добавления элемента в стек */
Stack* PushStack(Stack* stack) {
  MyDouble data = 0;
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
    stack->Push(data);
    std::cout << "Добавлен элемент со значением: " << data << '\n';
  }
  return stack;
};

/* функция извлечения элемента из стека */
Stack* PopStack(Stack* stack) {
  MyDouble data = 0;
  while (true) {
    std::cout
      << "Напишите 'yes', если хотите извлечь элемент или напишите "
         "'exit', если хотите перестать извлекать элементы: ";
    try {
      StoiExceptionsProcessing('a');
      data = stack->Pop();
    }
    catch (const std::logic_error& e) {
      std::cerr << e.what() << '\n';
      break;
    }
    std::cout << "Извлечен элемент со значением: " << data << '\n';
  }
  return stack;
};

/* функция вывода стека на консоль */
void PrintStack(Stack* stack) {
  stack->Print();
  std::cout << '\n';
}

/* функция удаления стека */
void DeleteStack(Stack* stack) {
  delete stack;
}