#include "string_kata.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

long stringSum (const std::string & inputStr) {
  std::vector <long> numbers;
  std::istringstream strParse(inputStr);

  unsigned total = 0;

  long temp = 0;
  while (strParse >> temp) {
    if (temp < 0)
      throw(std::out_of_range("stringSum(const std::string &) : String number must be >= 0."));
    numbers.push_back(temp);
  }

  for (auto & number : numbers) {
    total += number;
  }

  return total;
}
