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
       bool isLoop() const;
       bool checkForLoop();
       void resetMazeWalker(int startX, int starY, const std::vector<std::string>& maze, Direction heading);
       bool getHasLoop() const;

    private:
       int posX;
       int posY;
       std::vector<std::string> maze;
       std::vector<std::string> mazeForLoops;
       Direction heading; 
       int loopStartX;
       int LoopstartY;
       int loopCount = 0;
       bool hasLoop = false;


       void walkWest();
       void walkNorth();
       void walkSouth();
       void walkEast();
       void markPosAsVisited();
};

#endif // MAZE_WALKER_H