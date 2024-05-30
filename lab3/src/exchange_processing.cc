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

Ruble** ChangeRates(Ruble** exchanges, double new_rates[]) {
  double new_rate = 1.0;
  for (int i = 0; i < 4; ++i) {
    new_rate = new_rates[i];
    if (new_rate <= 0)
      new_rate = 1.0;
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

Ruble** ChangeBalance(Ruble** exchanges, double new_balance) {
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