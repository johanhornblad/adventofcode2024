#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <functional>
#include <unordered_set>
#include <concepts>
#include <type_traits>
#include <string>


template<typename T>
concept IntOrLong = std::same_as<T, int> || std::same_as<T, long>;

class Algorithms {
public:
    template <IntOrLong T>
    bool dynamicProgramingEquation(T answer, const std::vector<T>& numbers, const std::vector<std::function<T(T, T)>>& operations) const {

        auto sizeOfnumbers = static_cast<int>(numbers.size());
        auto dpTable = std::vector<std::unordered_set<T>>(sizeOfnumbers);

        for(int i = 0; i < sizeOfnumbers; i++) {
            if(i == 0) {
                dpTable[i].insert(numbers[i]);
                continue;
            }

            for(const auto& result : dpTable[i-1]) {
                auto possibleResults = calculatePossibleResults(result, numbers[i], operations);
                dpTable[i].insert(possibleResults.begin(), possibleResults.end());
            }
        }

        auto finalAnswers = dpTable.back();
        return finalAnswers.find(answer) != finalAnswers.end();
    }

private: 
    
    
    template <IntOrLong T>
    T glueTwoNumbersTogether(T firstNumber, T secondNumber) const{

        std::string firstNumerAsText = std::to_string(firstNumber);
        std::string secondNumerAsText = std::to_string(secondNumber);

        auto mashedNumbers = firstNumerAsText + secondNumerAsText;
        T resultNumber;
        if(std::same_as<T, int>) {
            resultNumber = std::stoi(mashedNumbers);
        } else {
            resultNumber = std::stol(mashedNumbers);
        }

        return resultNumber;

    }
    
    template <IntOrLong T>
    std::unordered_set<T> calculatePossibleResults(T firstNumber, T secondNumber, const std::vector<std::function<T(T, T)>>& operations) const {
        auto results = std::unordered_set<T>{};
        for(const auto& operation : operations) {
            auto result = operation(firstNumber, secondNumber);
            results.insert(result);
        }
        results.insert(glueTwoNumbersTogether(firstNumber, secondNumber));
        return results;
    }

};

#endif // ALGORITHMS_H