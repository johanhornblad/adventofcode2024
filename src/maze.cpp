#include "maze.h"

#include <utility>

Maze::Maze(const std::vector<std::string>& matrix) :
 maze(matrix),
 maxX(matrix.size() - 1),
 maxY(maze[0].size() - 1),
 minX(0),
 minY(0){}

bool Maze::isObstacle(int posX, int posY) const  {
    return maze[posX][posY] == '#';
}

bool Maze::isEdge(int posX, int posY) const  {
   if(posX == maxX || posX == minX) return true;
   if(posY == maxY || posY == minY) return true; 
   return false;
}

bool Maze::isWithinMaze(int posX, int posY) const {
    if(posX <= maxX || posX >= minX) return true;
    if(posY <= maxY || posY >= minX) return true;
    return false;
}

std::vector<std::string> Maze::getMaze() const {
    return maze;
};
