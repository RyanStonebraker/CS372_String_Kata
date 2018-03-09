#include "string_kata.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

long stringSum (const std::string & inputStr) {
  std::vector <long> numbers;
  unsigned total = 0;

  std::string argumentBuffer = inputStr;
  std::string delimiter = ",";
  if (argumentBuffer.find(delimiter)) {
    auto foundDelimiter = argumentBuffer.find(delimiter);
    while (foundDelimiter != std::string::npos) {
      argumentBuffer.replace(foundDelimiter, delimiter.size(), " ");
      foundDelimiter = argumentBuffer.find(delimiter);
    }
  }

  std::istringstream strParse(argumentBuffer);

  long temp = 0;
  while (strParse >> temp) {
    if (temp > 1000)
      continue;
    if (temp < 0)
      throw(std::out_of_range("stringSum(const std::string &) : String number must be >= 0."));

    numbers.push_back(temp);
  }

  for (auto & number : numbers) {
    total += number;
  }

  return total;
}
