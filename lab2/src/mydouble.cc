#include "../include/mydouble.h"
#include "../include/secondary_functions.h"
#include <iomanip>

MyDouble::MyDouble(double data) : data(data) {};
MyDouble::MyDouble() : data(0) {};
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

std::ostream& operator<<(std::ostream& out, const MyDouble& mydouble) {
  out << std::setprecision(15) << mydouble.data;
  return out;
}

MyDouble& MyDouble::operator++() {
  data += ReadDouble();
  return *this;
}

const MyDouble operator++(MyDouble& mydouble, int) {
  mydouble.data += RandomDouble();
  return mydouble.data;
}

MyDouble& MyDouble::operator--() {
  data -= RandomDouble();
  return *this;
}

const MyDouble operator--(MyDouble& mydouble, int) {
  mydouble.data -= ReadDouble();
  return mydouble.data;
}

const MyDouble MyDouble::operator!() {
  return -data;
}