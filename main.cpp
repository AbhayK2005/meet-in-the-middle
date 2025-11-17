#include <iostream>
#include <string>
#include "src/median.hpp"

int main() {
  std::string filename;
  std::cout << "Enter the filename: ";
  std::getline(std::cin, filename);
  DynamicArray data;
  if (!read_csv_file(filename, data)) {
    std::cerr << "Error: Could not read file '" << filename << "'" << std::endl;
    return 1;
  }
  if (data.is_empty()) {
    std::cerr << "Error: File contains no data" << std::endl;
    return 1;
  }
  try {
    double median = calculate_median(data);
    std::cout << "The median of the dataset is " << median << "." << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error calculating median: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
