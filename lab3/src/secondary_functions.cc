#include <iostream>
#include <limits>
#include <random>

/* функция получения числа, которое отвечает за пункт меню */
int StoiExceptionsProcessing(int) {
  std::string str    = "";
  int         number = 0;

  while (std::cin >> str) {
    try {
      number = std::stoi(str);
      if (number < 1 or number > 4)
        std::cerr << "Введено неподходящее число, попробуйте еще раз: ";
      else
        break;
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Введено не число, попробуйте еще раз: ";
    }
    catch (const std::out_of_range& e) {
      std::cerr
        << "Введено слишком большое число, попробуйте еще раз: ";
    }
  }

  return number;
}

/*  */
void StoiExceptionsProcessing() {
  std::string str = "";
  while (std::cin >> str) {
    if (str == "yes") {
      return;
    }
    else {
      throw std::logic_error("");
    }
  }
}

/* функция считывания действительного числа с консоли */
double ReadDouble() {
  double user_data = 0;
  std::cin >> user_data;
  while (std::cin.fail()) {
    std::cout
      << "Вы ввели что-то не то, попробуйте еще раз (необходимо "
         "действительное число через точку): ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> user_data;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return user_data;
}