#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

class Maze {
    public:
        Maze(const std::vector<std::string>& matrix);
        bool isObstacle(int posX, int posY) const;
        std::vector<std::string> getMaze() const;
        bool isEdge(int posX, int posY) const;
        bool isWithinMaze(int posX, int posY) const;

    private:
        std::vector<std::string> maze;
        int maxX;
        int maxY;
        int minX;
        int minY;
};

#endif  // MAZE_H
