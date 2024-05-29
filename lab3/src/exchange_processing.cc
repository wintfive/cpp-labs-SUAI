#include "../include/exchange_processing.h"
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

void DeleteExchanges(Ruble** exchanges) {
  for (int i = 0; i < 4; ++i) {
    delete exchanges[i];
  }
  delete[] exchanges;
}
