#include "../include/file_processing.h"
#include <fstream>
#include <iostream>

Ruble** InputFileProcessing(Ruble** exchanges) {
  std::ifstream input_file("../data/input.txt");
  if (!input_file.is_open()) {
    std::cerr << "Файл не открылся. Ошибка.\n";
    exit(0);
  }
  input_file.close();
  return exchanges;
}

void OutputFileProcessing(Ruble** exchanges) {
  std::ofstream output_file("../data/output.txt");
  if (!output_file.is_open()) {
    std::cerr << "Файл не открылся. Ошибка.\n";
    exit(0);
  }
  output_file << "Курсы валют:\n";
  for (int i = 0; i < 4; ++i) {
    output_file << "1 " << exchanges[i]->GetCurrency() << " = "
                << exchanges[i]->GetRate() << " RUB " << '\n';
  }
  output_file << "Баланс составляет: "
              << exchanges[0]->Ruble::GetBalance() << " RUB\n";
  for (int i = 0; i < 4; ++i) {
    output_file << "или: " << exchanges[i]->GetBalance() << ' '
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
    << "Введите значение баланса (в RUB): 0\nВведите курс: 1 EUR = "
       "1\n"
       "Введите курс: 1 USD = 1\nВведите курс: 1 GMP = 1\nВведите "
       "курс: 1 JPY = 1";

  recover_output_file
    << "Курсы валют:\n1 EUR = 1 RUB\n1 USD = 1 RUB\n1 GMP = 1 RUB\n1 "
       "JPY = 1 RUB\nБаланс составляет: 0 RUB\nили: 0 EUR\nили: 0 "
       "USD\n"
       "или: 0 GMP\nили: 0 JPY";

  recover_input_file.close();
  recover_output_file.close();
  std::cout << "Файлы восстановлены!\n";
}