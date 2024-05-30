#ifndef YEN
#define YEN
#include "ruble.h"

class Yen : public Ruble {
private:
  double      balance;
  double      rate     = 0.5;
  std::string currency = "JPY";

public:
  Yen();
  Yen(double rate);
  Yen(const Yen& original);
  Yen& operator=(const Yen& original);
  ~Yen() override;
  void        SetBalance(double balance) override;
  double      GetBalance() const override;
  void        SetRate(double rate) override;
  double      GetRate() const override;
  std::string GetCurrency() const override;
};

#endif /* YEN */