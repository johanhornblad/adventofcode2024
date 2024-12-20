#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>

class FileHandler {
    public:
        FileHandler(const std::string& filePath);

        std::string readFile() const;
        std::vector<std::string> readFileLines() const;
    private:
        std::string filePath;
};
#endif // FILE_HANDLER_H