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

void DeleteExchanges(Ruble** exchanges) {
  for (int i = 0; i < 4; ++i) {
    delete exchanges[i];
  }
  delete[] exchanges;
}
