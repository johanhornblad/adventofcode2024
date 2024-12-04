#include "file_handler.h"
#include "text_filter.h"
#include "triple.h"

#include <iostream>
#include <map>



static void swap(std::vector<int> &numbers, int j)
{
    int tmp = numbers[j];
    numbers[j] = numbers[j + 1];
    numbers[j + 1] = tmp;
}

void bubbleSort(std::vector<int>& numbers) {

    for(std::size_t i  = 0; i < numbers.size(); i++) {
        for (std::size_t j  = 0; j < numbers.size() - i - 1; j++) {
            if(numbers[j] > numbers[j + 1] ) {
                //swap
                swap(numbers, j);
            }
        }
    }
    
}



bool isOkayToRemove(const std::vector<int>& numbers, int index, int maxIndex) {
   if(index == 0) return true;

   if(index == maxIndex) return true;

    auto difference = std::abs(numbers[index - 1] - numbers[index + 1] );
    return difference >= 1 && difference < 4;
}

/*void day2b(const FileHandler& fileHandler) {
  auto lines = fileHandler.readFileLines();
  auto textFilter = TextFilter{};
  auto ascOrDesc = 0;

  auto sum = 0;
  auto isValid = false;

  for(const auto& line : lines) {
    auto numbers = textFilter.findNumbers(line);
    auto removedLevels = 0;
    auto removedIndex = -1;

    for(std::size_t i = 0; i < numbers.size(); i++) {
        if(i == 0){
             if(valueIsValid(i, numbers[i], numbers[i + 1], ascOrDesc)){
                ascOrDesc = getAscOrDesc(numbers[i], numbers[i + 1]);
                isValid == true;
             }
             else {
                removedLevels++;
                removedIndex = i;
                isValid = false;
             }
             continue;
         }

        if(i == numbers.size() - 2) {

        }

         if(isValid) {
            
            if(valueIsValid(i, numbers[i], numbers[i + 1], ascOrDesc)) {
                isValid = true;
            } else {
                
                if(removedIndex == -1) {
                      if(valueIsValid(i -1, numbers[i - 1], numbers[i + 1], ascOrDesc)) {
                        isValid = true;
                      } else{ 
                        isValid = false;
                        break;
                      }
                } else {
                     isValid = false;
                    break;
                }
            }
         } else {
            if(ascOrDesc == 0) ascOrDesc = getAscOrDesc(numbers[i], numbers[i + 1]);
            if(removedIndex == -1) {
                  if(valueIsValid(i -1, numbers[i - 1], numbers[i + 1], ascOrDesc)) {
                    isValid = true;
                  } else{ 
                    isValid = false;
                    break;
                 }
            } else {
                 isValid = false;
                 break;
            }
         }

  }

  std::cout << "sum: " << sum << std::endl;



}*/

/*void day2(const FileHandler& fileHandler) {
  auto lines = fileHandler.readFileLines();
  auto textFilter = TextFilter{};
  auto isAscending = false;

  auto sum = 0;

  for(const auto& line : lines) {
    auto numbers = textFilter.findNumbers(line);
    if(checkSetIsValid(numbers)) sum++;

  }

  std::cout << "sum: " << sum << std::endl;



}*/


bool withinRange(int diff) {
    return (std::abs(diff) > 0) && (std::abs(diff) < 4);
}

bool valueIsValid(int index, int value, int nextValue, int ascOrDesc) {
   auto diff = nextValue - value;

   if(index == 0) return withinRange(diff);
   if ((ascOrDesc == 1 && diff > 0) || (ascOrDesc == -1 && diff < 0)) return withinRange(diff);
   return false;
}

int getAscOrDesc(int value, int nextValue) {
    auto diff = nextValue - value;
    if(diff > 0) return 1;
    if(diff < 0) return -1;
    return 0;
}

int checkLastStep(int index,  const std::vector<int>& numbers, int ascOrDesc) {
    if(valueIsValid(index, numbers[index - 1], numbers[index + 1], ascOrDesc)){
      return index;
    } else {
      return index + 1;
    }
}
bool checkSetIsValid(std::vector<int> numbers) {
    int ascOrDesc = 0;
    for (std::size_t i = 0; i < numbers.size() - 1; i++) {
        if (!valueIsValid(i, numbers[i], numbers[i + 1], ascOrDesc)) return false;
        if (i == 0) ascOrDesc = getAscOrDesc(numbers[i], numbers[i + 1]);
    }
    return true;
}

bool canBeMadeValidByRemovingOne(const std::vector<int>& numbers) {
    for (std::size_t i = 0; i < numbers.size(); i++) {
        std::vector<int> modifiedNumbers = numbers;
        modifiedNumbers.erase(modifiedNumbers.begin() + i);
        if (checkSetIsValid(modifiedNumbers)) return true;
    }
    return false;
}

void day2bb(const FileHandler& fileHandler) {
    auto lines = fileHandler.readFileLines();
    auto textFilter = TextFilter{};
    int sum = 0;

    for (const auto& line : lines) {
        auto numbers = textFilter.findNumbers(line);
        if (checkSetIsValid(numbers) || canBeMadeValidByRemovingOne(numbers)) {
            sum++;
        }
    }

    std::cout << "sum: " << sum << std::endl;

}

void day1(const FileHandler& fileHandler) {
    auto textFilter = TextFilter{};
    auto firstRow = std::vector<int>{};
    auto secondRow = std::vector<int>{};

    auto lines = fileHandler.readFileLines();
    for (const auto& line: lines) {
        auto numbers = textFilter.findNumbers(line);
        firstRow.push_back(numbers[0]);
        secondRow.push_back(numbers[1]);
    }

    bubbleSort(firstRow);
    bubbleSort(secondRow);
    auto sum = 0;
    auto differences = std::vector<int>{};
    for(std::size_t i = 0; i < firstRow.size(); i++) {
        auto difference =   std::abs(secondRow[i] - firstRow[i]);
      
        differences.push_back(difference);
        sum+=difference;
    }

    std::cout << "total: " << sum << std::endl; 

}

void day1b(const FileHandler& fileHandler) {
    auto textFilter = TextFilter{};
    auto firstRow = std::vector<int>{};
    auto secondRow = std::vector<int>{};

    auto lines = fileHandler.readFileLines();
    for (const auto& line: lines) {
        auto numbers = textFilter.findNumbers(line);
        firstRow.push_back(numbers[0]);
        secondRow.push_back(numbers[1]);
    }

    bubbleSort(firstRow);
    bubbleSort(secondRow);

    std::map<int, int> numberOFRepetitionfPerNumber{};
    for(const auto& number : secondRow ) {
        
        numberOFRepetitionfPerNumber[number] = numberOFRepetitionfPerNumber[number] * 1 + 1;
    }

    std::cout << numberOFRepetitionfPerNumber[37619] << std::endl;
    auto sum = 0;
   for(const auto& number : firstRow) {
    if(numberOFRepetitionfPerNumber.find(number) != numberOFRepetitionfPerNumber.end()){
      auto numbersOFReps = numberOFRepetitionfPerNumber.at(number);
      auto product = numbersOFReps * number;
      sum+=product;
    }
   }

   std::cout << "total: " << sum << std::endl;

}

void day3(const FileHandler& fileHandler) {
    auto text = fileHandler.readFile();
    auto filter = TextFilter{};
    std::regex pattern("mul\\(\\d+,\\d+\\)");
    auto multipliers = filter.getMatches(text, pattern);
    auto sum = 0;
    for(auto mul : multipliers) {
        auto numbers = filter.findNumbers(mul);
        auto product = numbers.front() * numbers.back();
        sum += product;
    }

    std::cout << "total sum: " << sum << std::endl;

}

int sumProductforDay3(std::vector<std::string> multipliers, const TextFilter filter) {
     auto sum = 0;
    for(auto mul : multipliers) {
        auto numbers = filter.findNumbers(mul);
        auto product = numbers.front() * numbers.back();
        sum += product;
    }
    return sum;
}


void day3b(const FileHandler& fileHandler) {
    auto text = fileHandler.readFile();
    auto filter = TextFilter{};
    std::regex patternMul("mul\\(\\d+,\\d+\\)");
    std::regex patternDont("don't\\(\\)");
    std::regex patternDo("do\\(\\)");
    std::regex patternDontOrDo("don't\\(\\)|do\\(\\)");
    auto sum = 0;

    auto textUntilDontOrDo = filter.getTextUntil(text, patternDontOrDo);
    auto multipliers = filter.getMatches(textUntilDontOrDo.first, patternMul);
    if (!multipliers.empty()) sum += sumProductforDay3(multipliers, filter);
    while (textUntilDontOrDo.second != "") {
        if (textUntilDontOrDo.third == "do()") {
            auto res = filter.getTextUntil(textUntilDontOrDo.second, patternDont);
            auto muls = filter.getMatches(res.first, patternMul);
            auto sumOFProduct = sumProductforDay3(muls, filter);
            sum += sumOFProduct;
            textUntilDontOrDo = res;
        } else if (textUntilDontOrDo.third == "don't()") {
            auto res = filter.getTextUntil(textUntilDontOrDo.second, patternDo);
            textUntilDontOrDo = res;
        }
    }
    std::cout << "total sum: " << sum << std::endl;
}


void day4(const FileHandler& fileHandler) {
   auto lines = fileHandler.readFileLines();
    auto filter = TextFilter{};
    std::regex patternXmas("XMAS");
    std::regex patternSamx("SAMX");
    int xmasInLine{0};
    int xmasInLineBackwards{0};
    int xmasInColumns{0};
    int xmasInColumnsBackwards{0};
    int xmasInDiagonals{0};
    int xmasInDiagonalsBackwards{0};

    // Count horizontal matches
    for(const auto& line : lines) xmasInLine += filter.getMatches(line, patternXmas).size();

    // Count horizontal backwards matches
    for(const auto& line : lines) xmasInLineBackwards += filter.getMatches(line, patternSamx).size();

    // Transpose matrix to count vertical matches
    auto transposedMatrix = filter.transposeColumnsToRows(lines);
    for(const auto& row : transposedMatrix) xmasInColumns += filter.getMatches(row, patternXmas).size();
    // Count vertical backwards matches
    for(const auto& row : transposedMatrix) xmasInColumnsBackwards += filter.getMatches(row, patternSamx).size();
     
    // Get diagonals to count diagonal matches
    auto diagonals = filter.getDiagonals(lines);
    for(const auto& row : diagonals) xmasInDiagonals += filter.getMatches(row, patternXmas).size();

    // Count diagonal backwards matches
    for(const auto& row : diagonals) xmasInDiagonalsBackwards += filter.getMatches(row, patternSamx).size();
     std::cout << xmasInDiagonalsBackwards << std::endl;
    
    // Sum all matches
    auto sumOfXmas = xmasInLine + xmasInLineBackwards + xmasInColumns + xmasInColumnsBackwards + xmasInDiagonals + xmasInDiagonalsBackwards;

    std::cout << "total sum: " << sumOfXmas << std::endl;
    

}
int main() {
    
    auto fileHandler = FileHandler{"inputFiles/day4.txt"};
    day4(fileHandler);


    return 0;
}