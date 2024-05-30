#include "../include/yen.h"

Yen::Yen() : balance(Ruble::GetBalance() / 0.5), rate(0.5) {};
Yen::Yen(double rate)
  : balance(Ruble::GetBalance() * rate), rate(rate) {};

Yen::Yen(const Yen& original) {
  balance = original.balance;
  rate    = original.rate;
};

Yen& Yen::operator=(const Yen& original) {
  balance = original.balance;
  rate    = original.rate;
  return *this;
}

Yen::~Yen() = default;

double Yen::GetBalance() const {
  return balance;
}

void Yen::SetBalance(double) {
  this->balance = Ruble::GetBalance() * rate;
}

double Yen::GetRate() const {
  return rate;
}

void Yen::SetRate(double rate) {
  this->rate = rate;
}

std::string Yen::GetCurrency() const {
  return currency;
}