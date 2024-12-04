#include <vector>
#include <regex>
#include "text_filter.h"
#include <iostream>

std::vector<int> TextFilter::findNumbers(const std::string& text) const {
    std::regex numberRegex("(\\d+)");
    std::smatch matches;
    auto numbers = std::vector<int>{};
    auto searchStart = text.cbegin();

    while(std::regex_search(searchStart, text.cend(), matches, numberRegex)) {
        numbers.push_back(std::stoi(matches[0].str()));
        searchStart = matches.suffix().first;
    }
    return numbers;

}

std::vector<std::string> TextFilter::getMatches(const std::string& text, std::regex pattern) const {
    std::vector<std::string> results{};

    std::smatch matches;
    auto searchStart = text.cbegin();
    while(std::regex_search(searchStart, text.cend(), matches, pattern)) {
        results.push_back(matches[0].str());
        searchStart = matches.suffix().first;
    }
    return results;
}

std::string TextFilter::getTextwithinRange(const std::string& text, std::regex startPattern, std::regex endPatterns) const {
    std::string result;
    std::smatch firstMatch;
    std::smatch secondMatch;
    std::string::const_iterator searchstart = text.cbegin();
    if(std::regex_search(searchstart, text.cend(), firstMatch, startPattern)) {
        //gets pointer to the first value of the string after the match.
        searchstart = firstMatch.suffix().first;
    }
    if (std::regex_search(searchstart, text.cend(), secondMatch, endPatterns)) {
        //gets pointer to the last value of the string before the match.
        result = std::string(searchstart, secondMatch.prefix().second);
    }
    return result;
}

triple<std::string, std::string, std::string> TextFilter::getTextUntil(const std::string& text, std::regex pattern) const {
    //         string until, string after, match
    triple<std::string, std::string, std::string> result;
    std::smatch match;
    std::string::const_iterator searchstart = text.cbegin();
    if(std::regex_search(searchstart, text.cend(), match, pattern)) {
        //gets pointer to the first value of the string after the match.
        result.first= std::string(searchstart, match.prefix().second);
        result.second = std::string(match.suffix().first, match.suffix().second);
        result.third = match[0].str();
    } else {
        result.first = text;
        result.second = "";
        result.third = "";
    }
    return result;
}

std::vector<std::string> TextFilter::transposeColumnsToRows(const std::vector<std::string>& matrix) const {
    if (matrix.empty() || matrix[0].empty()) return {};
    auto transposedMatrix = std::vector<std::string>(matrix[0].size(), std::string(matrix.size(), ' '));
    for(std::size_t i = 0; i < matrix.size(); i++) {
        for(std::size_t j = 0; j < matrix[i].size(); j++) {
           transposedMatrix[j][i] = matrix[i][j];
        }
    } 
    return transposedMatrix;
}

std::vector<std::string> TextFilter::getDiagonals(const std::vector<std::string>& matrix ) const {
    std::vector<std::string> diagonals{};

  
    auto maxRows = matrix.size();
    if (maxRows == 0) return diagonals;
    auto maxCols = matrix[0].size();

    // Top-left to bottom-right
    for (std::size_t col = 0; col < maxCols; col++) {
        std::string diagonal;
        for (std::size_t row = 0; row < maxRows && col + row < maxCols; row++) {
            diagonal += matrix[row][col + row];
        }
        diagonals.push_back(diagonal);
    }
    for (std::size_t row = 1; row < maxRows; row++) {
        std::string diagonal;
        for (std::size_t col = 0; col < maxCols && row + col < maxRows; col++) {
            diagonal += matrix[row + col][col];
        }
        diagonals.push_back(diagonal);
    }

    // Top-right to bottom-left
    for (int col = maxCols - 1; col >= 0; col--) {
        std::string diagonal;
        for (std::size_t row = 0; row < maxRows && col - row >= 0; row++) {
            diagonal += matrix[row][col - row];
        }
        diagonals.push_back(diagonal);
    }
    for (std::size_t row = 1; row < maxRows; row++) {
        std::string diagonal;
        for (int col = maxCols - 1; col >= 0 && row + (maxCols - 1 - col) < maxRows; col--) {
            diagonal += matrix[row + (maxCols - 1 - col)][col];
        }
        diagonals.push_back(diagonal);
    }

    return diagonals;
}