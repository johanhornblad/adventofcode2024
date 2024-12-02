#include "file_handler.h"
#include "text_filter.h"

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


void day2(const FileHandler& fileHandler) {
  auto lines = fileHandler.readFileLines();
  auto textFilter = TextFilter{};
  auto isAscending = false;

  auto sum = 0;

  for(const auto& line : lines) {
    auto numbers = textFilter.findNumbers(line);



    for(std::size_t i = 0; i < numbers.size() - 1; i++) {
        if(numbers[i] > numbers[i+1]) {
            if(i > 0 && !isAscending){
                break;
            }
            isAscending = true;
        }
        else if(numbers[i] < numbers[i+1]) {
             if(i > 0 && isAscending){
                break;
            }
            isAscending = false;
        } 
        else break;

        auto difference = std::abs(numbers[i + 1] - numbers[i]);
        if(difference >= 1 && difference < 4) {
            if(i == numbers.size() - 2) {
                sum ++;
            }
        }
        else {
            break;
        }
    }

  }

  std::cout << "sum: " << sum << std::endl;



}

bool isOkayToRemove(const std::vector<int>& numbers, int index, int maxIndex) {
   if(index == 0) return true;

   if(index == maxIndex) return true;

    auto difference = std::abs(numbers[index - 1] - numbers[index + 1] );
    return difference >= 1 && difference < 4;
}

void day2b(const FileHandler& fileHandler) {
  auto lines = fileHandler.readFileLines();
  auto textFilter = TextFilter{};
  auto isAscending = false;

  auto sum = 0;

  for(const auto& line : lines) {
    auto numbers = textFilter.findNumbers(line);


    auto removedLevels = 0;
    for(std::size_t i = 0; i < numbers.size() - 1; i++) {
        if(i == 0) removedLevels = 0;
        if(numbers[i] > numbers[i+1]) {
            if(i > 0 && !isAscending){
                if(removedLevels == 0) {
                   removedLevels ++;
                } else {
                   break;
                }
            }
            isAscending = true;
        }
        else if(numbers[i] < numbers[i+1]) {
             if(i > 0 && isAscending){
                 if(removedLevels == 0) {
                   removedLevels ++;
                } else {
                   break;
                }
            }
            isAscending = false;
        } 
        else {
            if(removedLevels == 0 && isOkayToRemove(numbers, i,numbers.size() - 2)) {
               removedLevels ++;
            } else {
               break;
            }
        };

        auto difference = std::abs(numbers[i + 1] - numbers[i]);
        if(difference >= 1 && difference < 4) {
            if(i == numbers.size() - 2) {
                sum ++;
            }
        }
        else {
            if(removedLevels == 0) {
                removedLevels ++;
                if(i == numbers.size() - 2) {
                    sum ++;
                }
            } else {
                  break;
               }
        }
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

int main() {
    
    auto fileHandler = FileHandler{"inputFiles/day2.txt"};
    day2b(fileHandler);


    return 0;
}