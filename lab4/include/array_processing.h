#ifndef ARRAY_PROCESSING
#define ARRAY_PROCESSING
#include <iostream>
#include <vector>

template <typename T>
void CreateArray(std::vector<T>& array);

template <typename T>
void PrintArray(std::vector<T>& array);

template <typename T>
void AverageArray(std::vector<T>& array);

void DeleteCharPointerArray(std::vector<char*>& array);
#include "array_processing.tpp"
#endif /* ARRAY_PROCESSING */