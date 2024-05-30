#include "../include/file_processing.h"
#include "../include/exchange_processing.h"
#include <fstream>
#include <iostream>
#include <sstream>

Ruble** InputFileProcessing(Ruble** exchanges) {
  std::ifstream input_file("../data/input.txt");
  std::string   str          = "";
  std::string   sub_str      = "";
  double        new_balance  = 0.0;
  double        new_rate     = 1.0;
  double        new_rates[4] = {0, 0, 0, 0};
  if (!input_file.is_open()) {
    std::cerr << "Файл не открылся. Ошибка.\n";
    exit(0);
  }

  std::getline(input_file, str);
  if (str.size() < 32)
    CorruptedFile();
  sub_str = str.substr(32);
  std::istringstream iss(sub_str);
  iss >> new_balance;
  if (iss.fail())
    CorruptedFile();
  else
    exchanges = ChangeBalance(exchanges, new_balance);

  for (int i = 0; i < 4; ++i) {
    std::getline(input_file, str);
    if (str.size() < 31)
      CorruptedFile();
    sub_str = str.substr(31);
    iss.clear();
    iss.str(sub_str);
    iss >> new_rate;
    if (iss.fail())
      CorruptedFile();
    else
      new_rates[i] = new_rate;
  }
  ChangeRates(exchanges, new_rates);

  input_file.close();
  return exchanges;
}

void OutputFileProcessing(Ruble** exchanges) {
  std::ofstream output_file("../data/output.txt");
  if (!output_file.is_open()) {
    std::cerr << "Файл не открылся. Ошибка.\n";
    exit(0);
  }
  output_file << "Exchange rates:\n";
  for (int i = 0; i < 4; ++i) {
    output_file << "1 " << exchanges[i]->GetCurrency() << " = "
                << exchanges[i]->GetRate() << " RUB " << '\n';
  }
  output_file << "Balance is: " << exchanges[0]->Ruble::GetBalance()
              << " RUB\n";
  for (int i = 0; i < 4; ++i) {
    output_file << "or: " << exchanges[i]->GetBalance() << ' '
                << exchanges[i]->GetCurrency() << '\n';
  }
  output_file.close();
}

void FileRecovery() {
  std::ofstream recover_input_file("../data/input.txt");
  std::ofstream recover_output_file("../data/output.txt");
  if (!recover_input_file.is_open() or !recover_output_file.is_open()) {
    std::cerr << "Какой-то из файлов не открылся. Ошибка.\n";
    exit(0);
  }

  recover_input_file
    << "Enter a balance value (in RUB): 0\nEnter a exchange rate: 1 "
       "EUR = 1\nEnter a exchange rate: 1 USD = 1\nEnter a exchange "
       "rate: 1 GMP = 1\nEnter a exchange rate: 1 JPY = 1";

  recover_output_file
    << "Exchange rates:\n1 EUR = 1 RUB\n1 USD = 1 RUB\n1 GMP = "
       "1 RUB\n1 JPY = 1 RUB\nBalance is: 0 RUB\nor: 0 EUR\nor: 0 "
       "USD\nor: 0 GMP\nor: 0 JPY";

  recover_input_file.close();
  recover_output_file.close();
  std::cout << "Файлы восстановлены!\n";
}

void CorruptedFile() {
  std::cerr << "Файл поврежден. Ошибка.\n";
  exit(0);
}