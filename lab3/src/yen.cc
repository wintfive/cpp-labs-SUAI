#include "../include/yen.h"

Yen::Yen() : balance(Ruble::GetBalance()), rate(1.0) {};
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

void Yen::SetBalance(double balance) {
  this->balance = balance;
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