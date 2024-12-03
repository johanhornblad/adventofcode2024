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