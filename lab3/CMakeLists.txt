# необходима версия cmake 3.29
cmake_minimum_required(VERSION 3.29)

# проект, в котором использован язык C++
project(lab3 LANGUAGES CXX)

# поставлен стандарт языка С++11 и он требуется обязательным при сборке
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# поставлены флаги для компиляции при сборке
add_compile_options(-D CMAKE_CXX_COMPILER=clang++ -Werror -Wall -Wextra -Wpedantic)

# -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo

# sources - переменная названий всех файлов, которые используются в программе
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cc)

# создание исполняемого файла из переменной
add_executable(lab3 ${sources})

# директории, которые будут использованы при компиляции заданной цели (lab3)
target_include_directories(lab3 PRIVATE include)