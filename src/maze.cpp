#include "maze.h"

#include <utility>
#include <iostream>

Maze::Maze(const std::vector<std::string>& matrix) :
 maze(matrix),
 maxX(static_cast<int>(matrix.size()) - 1),
 maxY(static_cast<int>(matrix[0].size()) - 1),
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

    if(posX >= minX && posX <= maxX && posY >= minY && posY <= maxY) {
        return true;
    }
    return false;
}

std::vector<std::string> Maze::getMaze() const {
    return maze;
};

void Maze::placeAnObstacle(int posX, int posY) {
    maze[posX][posY] = '#';
}

void Maze::removeAnObstacle(int posX, int posY) {
    maze[posX][posY] = '.';
}

