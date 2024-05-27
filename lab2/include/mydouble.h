#ifndef MYDOUBLE
#define MYDOUBLE
#include <iostream>

class MyDouble {
private:
  double data;

public:
  MyDouble(double data);
  ~MyDouble();
  MyDouble(const MyDouble& original);
  MyDouble& operator=(const MyDouble& original);

  friend std::ostream&  operator<<(std::ostream&   out,
                                  const MyDouble& mydouble);
  MyDouble&             operator++();
  friend const MyDouble operator++(MyDouble& mydouble, int);
  MyDouble&             operator--();
  friend const MyDouble operator--(MyDouble& mydouble, int);
  const MyDouble        operator!();
};

#endif /* MYDOUBLE */