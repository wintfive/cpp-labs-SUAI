#include "../include/pound.h"

Pound::Pound() : balance(Ruble::GetBalance() / 120.0), rate(120.0) {};
Pound::Pound(double rate)
  : balance(Ruble::GetBalance() * rate), rate(rate) {};

Pound::Pound(const Pound& original) {
  balance = original.balance;
  rate    = original.rate;
};

Pound& Pound::operator=(const Pound& original) {
  balance = original.balance;
  rate    = original.rate;
  return *this;
}

Pound::~Pound() = default;

double Pound::GetBalance() const {
  return balance;
}

void Pound::SetBalance(double balance) {
  this->balance = balance;
}

double Pound::GetRate() const {
  return rate;
}

void Pound::SetRate(double rate) {
  this->rate = rate;
}

std::string Pound::GetCurrency() const {
  return currency;
}