#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <functional>
#include <unordered_set>

class Algorithms {
public:
    template <typename T>
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
    template <typename T>
    std::unordered_set<T> calculatePossibleResults(T firstNumber, T secondNumber, const std::vector<std::function<T(T, T)>>& operations) const {
        auto results = std::unordered_set<T>{};
        for(const auto& operation : operations) {
            auto result = operation(firstNumber, secondNumber);
            results.insert(result);
        }
        return results;
}

};

#endif // ALGORITHMS_H