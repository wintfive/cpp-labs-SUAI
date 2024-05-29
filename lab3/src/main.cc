#include "../include/exchange_processing.h"
#include "../include/menu.h"
#include <iostream>

int main() {
  ClearScreen();
  Ruble** exchanges = CreateExchanges();
  MenuRealization(exchanges);
  return 0;
}