#include "../include/exchange_processing.h"
#include "../include/secondary_functions.h"
#include <iostream>

Ruble** CreateExchanges() {
  Euro*   euro      = new Euro();
  Dollar* dollar    = new Dollar();
  Pound*  pound     = new Pound();
  Yen*    yen       = new Yen();
  Ruble** exchanges = new Ruble*[4]{euro, dollar, pound, yen};
  return exchanges;
}

void PrintRates(Ruble** exchanges) {
  std::cout << "Курсы валют:\n";
  for (int i = 0; i < 4; ++i) {
    std::cout << "1 " << exchanges[i]->GetCurrency() << " = "
              << exchanges[i]->GetRate() << " RUB " << '\n';
  }
}

Ruble** ChangeRates(Ruble** exchanges) {
  double new_rate = 0.0;
  std::cout << "Напишите 'yes', если хотите поменять курсы валют, в "
               "ином случае напишите что угодно: ";
  try {
    StoiExceptionsProcessing();
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what();
    return exchanges;
  }

  for (int i = 0; i < 4; ++i) {
    std::cout << "Напишите новое значение курса для валюты "
              << exchanges[i]->GetCurrency()
              << " (отрицательное значение - оставить имеющийся): ";
    new_rate = ReadDouble();
    if (new_rate < 0) {
      continue;
    }
    exchanges[i]->SetRate(new_rate);
    exchanges[i]->SetBalance(exchanges[0]->Ruble::GetBalance()
                             / new_rate);
  }
  return exchanges;
}

void PrintBalance(Ruble** exchanges) {
  std::cout << "Баланс составляет: "
            << exchanges[0]->Ruble::GetBalance() << " RUB\n";
  for (int i = 0; i < 4; ++i) {
    std::cout << "или: " << exchanges[i]->GetBalance() << ' '
              << exchanges[i]->GetCurrency() << '\n';
  }
}

Ruble** ChangeBalance(Ruble** exchanges) {
  std::cout << "Напишите 'yes', если хотите поменять баланс, в "
               "ином случае напишите что угодно: ";
  try {
    StoiExceptionsProcessing();
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what();
    return exchanges;
  }

  std::cout << "Напишите новое значение баланса в RUB: ";
  double new_balance = ReadDouble();
  exchanges[0]->Ruble::SetBalance(new_balance);
  for (int i = 0; i < 4; ++i) {
    exchanges[i]->SetBalance(new_balance / exchanges[i]->GetRate());
  }
  return exchanges;
}

void DeleteExchanges(Ruble** exchanges) {
  for (int i = 0; i < 4; ++i) {
    delete exchanges[i];
  }
  delete[] exchanges;
}