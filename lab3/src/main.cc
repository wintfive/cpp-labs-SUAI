#include "../include/exchange_processing.h"
#include "../include/file_processing.h"
#include "../include/menu.h"
#include <iostream>

int main() {
  FileRecovery();
  ClearScreen();
  Ruble** exchanges = CreateExchanges();
  MenuRealization(exchanges);
  return 0;
}