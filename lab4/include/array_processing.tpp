#include "../include/secondary_functions.h"
#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
void CreateArray(std::vector<T>& array) {
  int size = 0;
  std::cout << "Напишите размер массива: ";
  try {
    size = StoiExceptionsProcessing();
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
  }
  array.resize(size);
  for (int i = 0; i < size; ++i) {
    if constexpr (std::is_same<T, char*>::value) {
      char* random_str = RandomString(0, 50);
      array[i]         = random_str;
    }
    else
      array[i] = RandomDouble(0, 50);
  }
}

template <typename T>
void PrintArray(std::vector<T>& array) {
  std::cout << "Массив: ";
  for (T value : array) {
    if constexpr (std::is_same<T, char>::value)
      std::cout << value << " (" << static_cast<int>(value) << ") | ";
    else if constexpr (std::is_same<T, char*>::value)
      std::cout << value << " (" << std::strlen(value) << ") | ";
    else
      std::cout << value << " | ";
  }
  std::cout << '\n';
};

template <typename T>
void AverageArray(std::vector<T>& array) {
  double average = 0.0;
  for (T value : array) {
    if constexpr (std::is_same<T, char*>::value)
      average += std::strlen(value);
    else
      average += value;
  }
  average /= array.size();
  std::cout << "Среднее арифметическое элементов массива равно: "
            << average;
  std::cout << '\n';
};

void DeleteCharPointerArray(std::vector<char*>& array) {
  for (char* str : array) {
    delete[] str;
  }
}