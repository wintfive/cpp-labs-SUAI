#include "../include/euro.h"

Euro::Euro() : balance(Ruble::GetBalance() / 110.0), rate(110.0) {};
Euro::Euro(double rate)
  : balance(Ruble::GetBalance() * rate), rate(rate) {};

Euro::Euro(const Euro& original) {
  balance = original.balance;
  rate    = original.rate;
};

Euro& Euro::operator=(const Euro& original) {
  balance = original.balance;
  rate    = original.rate;
  return *this;
}

Euro::~Euro() = default;

double Euro::GetBalance() const {
  return balance;
}

void Euro::SetBalance(double) {
  this->balance = Ruble::GetBalance() * rate;
}

double Euro::GetRate() const {
  return rate;
}

void Euro::SetRate(double rate) {
  this->rate = rate;
}

std::string Euro::GetCurrency() const {
  return currency;
}