#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>

class FileHandler {
    public:
        FileHandler(const std::string& filePath);

        std::string readFile();
        std::vector<std::string> readFileLines();
    private:
        std::string filePath;
};
#endif // FILE_HANDLER_H