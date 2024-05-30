#include "../include/dollar.h"

Dollar::Dollar() : balance(Ruble::GetBalance() / 100.0), rate(100.0) {};
Dollar::Dollar(double rate)
  : balance(Ruble::GetBalance() * rate), rate(rate) {};

Dollar::Dollar(const Dollar& original) {
  balance = original.balance;
  rate    = original.rate;
};

Dollar& Dollar::operator=(const Dollar& original) {
  balance = original.balance;
  rate    = original.rate;
  return *this;
}

Dollar::~Dollar() = default;

double Dollar::GetBalance() const {
  return balance;
}

void Dollar::SetBalance(double balance) {
  this->balance = balance;
}

double Dollar::GetRate() const {
  return rate;
}

void Dollar::SetRate(double rate) {
  this->rate = rate;
}

std::string Dollar::GetCurrency() const {
  return currency;
}