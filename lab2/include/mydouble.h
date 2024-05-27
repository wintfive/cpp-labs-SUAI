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

};

#endif /* MYDOUBLE */