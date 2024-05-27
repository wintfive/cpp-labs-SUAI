#include "../include/mydouble.h"
#include "../include/secondary_functions.h"
#include <iomanip>

MyDouble::MyDouble(double data) : data(data) {};
MyDouble::~MyDouble() = default;

/* конструктор копирования */
MyDouble::MyDouble(const MyDouble& original) : data(0) {
  data = original.data;
}

/* перегруженный оператор присваивания */
MyDouble& MyDouble::operator=(const MyDouble& original) {
  data = original.data;
  return *this;
}

