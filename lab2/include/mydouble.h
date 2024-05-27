#ifndef MYDOUBLE
#define MYDOUBLE
#include <iostream>

class MyDouble {
private:
  double data;

public:
  MyDouble(double data);
  MyDouble();
  ~MyDouble();
  MyDouble(const MyDouble& original);
  MyDouble& operator=(const MyDouble& original);

  void                  SetData(double data);
  MyDouble              GetData() const;
  friend std::ostream&  operator<<(std::ostream&   out,
                                  const MyDouble& mydouble);
  const MyDouble&       operator+=(const MyDouble& rvalue);
  const MyDouble&       operator-=(const MyDouble& rvalue);
  const MyDouble&       operator*=(const MyDouble& rvalue);
  const MyDouble&       operator/=(const MyDouble& rvalue);
  MyDouble&             operator++();
  friend const MyDouble operator++(MyDouble& mydouble, int);
  MyDouble&             operator--();
  friend const MyDouble operator--(MyDouble& mydouble, int);
  const MyDouble        operator!() const;
};

#endif /* MYDOUBLE */