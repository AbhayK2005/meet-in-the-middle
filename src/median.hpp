#pragma once
#include "dynamic_array.hpp"
#include <string>

bool read_csv_file(const std::string& filename, DynamicArray& arr);

double calculate_median(const DynamicArray& arr);
