#ifndef TEXT_FILTER_H
#define TEXT_FILTER_H

#include <vector>
#include <string>
#include <regex>


class TextFilter {
    public:
        std::vector<int> findNumbers(const std::string& text) const;
        std::vector<std::string> getMatches(const std::string& text, std::regex pattern) const;

    private:


};


#endif // TEXT_FILTER_H