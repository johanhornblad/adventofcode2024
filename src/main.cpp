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
    
    auto fileHandler = FileHandler{"inputFiles/day1.txt"};
    day1b(fileHandler);


    return 0;
}