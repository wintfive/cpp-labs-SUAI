#ifndef DOLLAR
#define DOLLAR
#include "ruble.h"

class Dollar : public Ruble {
private:
  double      balance;
  double      rate     = 100.0;
  std::string currency = "USD";

public:
  Dollar();
  Dollar(double rate);
  Dollar(const Dollar& original);
  Dollar& operator=(const Dollar& original);
  ~Dollar();
  void        SetBalance(double balance) override;
  double      GetBalance() const override;
  void        SetRate(double rate) override;
  double      GetRate() const override;
  std::string GetCurrency() const override;
};

#endif /* DOLLAR */