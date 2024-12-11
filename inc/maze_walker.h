#ifndef MAZE_WALKER_H
#define MAZE_WALKER_H

#include "maze.h"

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class MazeWalker{

    public:
       MazeWalker(const std::vector<std::string>& maze,  Direction heading, int posX, int posY);
       // gets position X, Y
       std::pair<int, int> getPosition() const;
       Direction getHeading() const;
       void walk();
       void turnRight();
       //         X , Y
       std::pair<int, int> getNextPosition() const;
       const std::vector<std::string>& getVisitedMaze() const;

    private:
       int posX;
       int posY;
       std::vector<std::string> maze;
       Direction heading; 

       void walkWest();
       void walkNorth();
       void walkSouth();
       void walkEast();
       void markPosAsVisited();
};

#endif // MAZE_WALKER_H