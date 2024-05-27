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

/* геттер и сеттер */
void MyDouble::SetData(double data) {
  this->data = data;
}

MyDouble MyDouble::GetData() const {
  return this->data;
}

/* функции перегрузки операторов */
std::ostream& operator<<(std::ostream& out, const MyDouble& mydouble) {
  out << std::setprecision(15) << mydouble.data;
  return out;
}

const MyDouble& MyDouble::operator+=(const MyDouble& rvalue) {
  data += rvalue.data;
  return *this;
}

MyDouble operator+(const MyDouble& lvalue, const MyDouble& rvalue) {
  MyDouble summ_data  = lvalue.GetData();
  return summ_data   += rvalue.GetData();
}

const MyDouble& MyDouble::operator-=(const MyDouble& rvalue) {
  data -= rvalue.data;
  return *this;
}

MyDouble operator-(const MyDouble& lvalue, const MyDouble& rvalue) {
  MyDouble sub_data  = lvalue.GetData();
  return sub_data   -= rvalue.GetData();
}

const MyDouble& MyDouble::operator*=(const MyDouble& rvalue) {
  data *= rvalue.data;
  return *this;
}

MyDouble operator*(const MyDouble& lvalue, const MyDouble& rvalue) {
  MyDouble mul_data  = lvalue.GetData();
  return mul_data   *= rvalue.GetData();
}

const MyDouble& MyDouble::operator/=(const MyDouble& rvalue) {
  data /= rvalue.data;
  return *this;
}

MyDouble operator/(const MyDouble& lvalue, const MyDouble& rvalue) {
  MyDouble div_data  = lvalue.GetData();
  return div_data   /= rvalue.GetData();
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

const MyDouble MyDouble::operator!() const {
  return -data;
}