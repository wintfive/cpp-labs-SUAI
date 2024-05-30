#ifndef EURO
#define EURO
#include "ruble.h"

class Euro : public Ruble {
private:
  double      balance;
  double      rate     = 110.0;
  std::string currency = "EUR";

public:
  Euro();
  Euro(double rate);
  Euro(const Euro& original);
  Euro& operator=(const Euro& original);
  ~Euro();
  void        SetBalance(double balance) override;
  double      GetBalance() const override;
  void        SetRate(double rate) override;
  double      GetRate() const override;
  std::string GetCurrency() const override;
};

#endif /* EURO */