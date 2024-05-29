#ifndef RUBLE
#define RUBLE
#include <string>

class Ruble {
private:
  double balance;

public:
  Ruble();
  Ruble(double rate);
  Ruble(const Ruble& original);
  Ruble& operator=(const Ruble& original);
  virtual ~Ruble() = 0;
  virtual void        SetBalance(double balance);
  virtual double      GetBalance() const;
  virtual void        SetRate(double rate) = 0;
  virtual double      GetRate() const      = 0;
  virtual std::string GetCurrency() const  = 0;
};

#endif /* RUBLE */