// string_kata.cpp
// 3/9/2018
// Ryan Stonebraker
// The string calculator Kata following Agile and TDD.

#include "string_kata.h"
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

bool startsWithDelimiters(const std::string & raw_input) {
  return raw_input.substr(0, 2) == "//";
}

std::vector <std::string> getDelimitersInBrackets (std::string delimiterLine) {
  std::vector <std::string> delimiters {","};
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

      auto bracketsNotFound = (startBracket == std::string::npos || endBracket == std::string::npos);
      if (bracketsNotFound)
        break;
    }
  }
  return delimiters;
}

std::vector <std::string> getDelimiters(const std::string & inputStr) {
  std::vector <std::string> delimiters {","};

  if (startsWithDelimiters(inputStr)) {
    std::istringstream readDelimiters(inputStr);
    std::string delimiterLine = "";
    getline(readDelimiters, delimiterLine);

    delimiterLine.replace(0,2, "");

    delimiters = getDelimitersInBrackets(delimiterLine);

    std::string tempDelimiter = "";
    std::istringstream delimiterReader (delimiterLine);
    while (delimiterReader >> tempDelimiter) {
      delimiters.push_back(tempDelimiter);
    }
  }

  return delimiters;
}

std::string removeDelimiterLine(const std::string & raw_input) {
  auto argumentBuffer = raw_input;
  if (startsWithDelimiters(raw_input)) {
    auto firstNewLine = raw_input.find_first_of("\n") + 1;
    auto adjustedSize = raw_input.size() - firstNewLine;
    argumentBuffer = raw_input.substr(firstNewLine, adjustedSize);
  }

  return argumentBuffer;
}

std::string convertToSingleDelimiter(std::string argumentBuffer, const std::vector<std::string> & delimiters) {
  for (auto & delimiter : delimiters) {
    if (argumentBuffer.find(delimiter) != std::string::npos) {
      auto foundDelimiter = argumentBuffer.find(delimiter);
      while (foundDelimiter != std::string::npos) {
        argumentBuffer.replace(foundDelimiter, delimiter.size(), " ");
        foundDelimiter = argumentBuffer.find(delimiter);
      }
    }
  }

  return argumentBuffer;
}

std::vector <long> parseQualifiedNumbers (const std::string & argumentBuffer) {
  std::vector <long> numbers;

  std::istringstream strParse(argumentBuffer);

  long temp = 0;
  while (strParse >> temp) {

    if (temp > 1000)
      continue;

    if (temp < 0)
      throw(std::out_of_range("stringSum(const std::string &) : String number must be >= 0."));

    numbers.push_back(temp);
  }
  return numbers;
}

unsigned vectorSum(const std::vector <long> & numbers) {
  unsigned total = 0;
  for (auto & number : numbers) {
    total += number;
  }
  return total;
}

unsigned stringSum (const std::string & inputStr) {
  auto delimiters = getDelimiters(inputStr);
  auto argumentBuffer = removeDelimiterLine(inputStr);
  argumentBuffer = convertToSingleDelimiter(argumentBuffer, delimiters);

  auto numbers = parseQualifiedNumbers(argumentBuffer);

  return vectorSum(numbers);
}
