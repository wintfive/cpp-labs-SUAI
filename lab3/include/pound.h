#ifndef POUND
#define POUND
#include "ruble.h"

class Pound : public Ruble {
private:
  double      balance;
  double      rate     = 120.0;
  std::string currency = "GMP";

public:
  Pound();
  Pound(double rate);
  Pound(const Pound& original);
  Pound& operator=(const Pound& original);
  ~Pound();
  void        SetBalance(double balance) override;
  double      GetBalance() const override;
  void        SetRate(double rate) override;
  double      GetRate() const override;
  std::string GetCurrency() const override;
};

#endif /* POUND */