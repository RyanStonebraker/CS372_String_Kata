#include "string_kata.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

#include <iostream>
// #include <string>
// int main () {
//   std::string test = "_[abc][123]_";
//   // std::cout << test.substr(test.find("["), test.find("]"));
//   test.replace(1, 5, "");
//   std::cout << test << std::endl;
// }

long stringSum (const std::string & inputStr) {
  std::vector <long> numbers;
  unsigned total = 0;

  std::vector <std::string> delimiters {","};

  std::string argumentBuffer = inputStr;

  if (inputStr.substr(0, 2) == "//") {
    std::istringstream readDelimiters(inputStr);
    std::string delimiterLine = "";
    getline(readDelimiters, delimiterLine);

    delimiterLine.replace(0,2, "");

    auto startBracket = delimiterLine.find_first_of("[");
    if (startBracket != std::string::npos) {
      while (true) {
        auto endBracket = delimiterLine.find_first_of("]");
        if (startBracket >= endBracket)
          break;

        if (endBracket != std::string::npos) {
          if (endBracket > startBracket + 1)
            delimiters.push_back(delimiterLine.substr(startBracket+1, endBracket-startBracket-1));

          delimiterLine.replace(startBracket, endBracket-startBracket+1, "");
        }
        startBracket = delimiterLine.find_first_of("[");
        if (startBracket == std::string::npos || endBracket == std::string::npos)
          break;
      }
    }

    std::string tempDelimiter = "";
    std::istringstream delimiterReader (delimiterLine);
    while (delimiterReader >> tempDelimiter) {
      delimiters.push_back(tempDelimiter);
    }

    argumentBuffer = argumentBuffer = inputStr.substr(inputStr.find_first_of("\n") + 1, inputStr.size() - inputStr.find_first_of("\n"));
  }

  for (auto & delimiter : delimiters) {
    if (argumentBuffer.find(delimiter) != std::string::npos) {
      auto foundDelimiter = argumentBuffer.find(delimiter);
      while (foundDelimiter != std::string::npos) {
        argumentBuffer.replace(foundDelimiter, delimiter.size(), " ");
        foundDelimiter = argumentBuffer.find(delimiter);
      }
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
