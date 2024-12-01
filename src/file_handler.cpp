#include "file_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

FileHandler::FileHandler(const std::string& filePath) : filePath(filePath) {
    
}

std::string FileHandler::readFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

std::vector<std::string> FileHandler::readFileLines() const {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    auto lines = std::vector<std::string>{};
    std::string line;
    while(std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}