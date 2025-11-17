#include "median.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

bool read_csv_file(const std::string& filename, DynamicArray& arr) {
   std::ifstream file(filename);
   if (!file.is_open()) {
      return false;
   }
   std::string line;
   if (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string token;

      while (std::getline(ss, token, ',')) {
         try {
            int value = std::stoi(token);
            arr.push_back(value);
         } catch (const std::exception& e) {
            file.close();
            return false;
         }
      }
   }
   file.close();
   return true;
}

double calculate_median(const DynamicArray& arr) {
   if (arr.is_empty()) {
      throw std::invalid_argument("Cannot calculate median of empty array");
   }
   size_t n = arr.get_size();
   if (n % 2 == 1) {
      // Odd number of elements - return the middle element
      return static_cast<double>(arr.get(n / 2));
   } else {
      // Even number of elements - return average of two middle elements
      size_t mid1 = n / 2 - 1;
      size_t mid2 = n / 2;
      return (arr.get(mid1) + arr.get(mid2)) / 2.0;
   }
}