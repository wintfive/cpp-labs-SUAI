#include "../include/ruble.h"

Ruble::Ruble() : balance(0.0) {};
Ruble::Ruble(double balance) : balance(balance) {};

Ruble::Ruble(const Ruble& original) {
  balance = original.balance;
};

Ruble& Ruble::operator=(const Ruble& original) {
  balance = original.balance;
  return *this;
}

Ruble::~Ruble() = default;

double Ruble::GetBalance() const {
  return balance;
}

void Ruble::SetBalance(double balance) {
  this->balance = balance;
}
