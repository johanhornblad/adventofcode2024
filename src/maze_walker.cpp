#include "maze_walker.h"


 MazeWalker::MazeWalker(const std::vector<std::string>& maze,  Direction heading, int posX, int posY) : 
    posX(posX),
    posY(posY),
    maze(maze),
    mazeForLoops(maze),
    heading(heading){
        markPosAsVisited();
    };


bool MazeWalker::checkForLoop() {
    // > 2 to be completely sure its a loop
    // this function doesn't work so good but the aögotirhtm works any way
    if(loopCount > 2 && posX == loopStartX && posY == LoopstartY) {
        hasLoop = true;
        return true;
    }
    loopCount == 0;
    return false;

}

bool MazeWalker::getHasLoop() const {
    return hasLoop;
}


void MazeWalker::resetMazeWalker(int startX, int startY,const std::vector<std::string>& maze, Direction heading) {
    posX = startX;
    posY = startY;
    this->maze = maze;
    mazeForLoops = maze;
    loopStartX = -1;
    LoopstartY = -1;
    this->heading = heading;
    loopCount = 0;
    hasLoop = false;
}

bool MazeWalker::isLoop() const {
    auto& place = mazeForLoops[posX][posY];
    if(std::isdigit(place)) {
        int num = place + '0';
        return num > 5;

    }
    return false;
}

std::pair<int, int> MazeWalker::getPosition() const {
    return std::pair{posX, posY};
}

Direction MazeWalker::getHeading() const {
    return heading;
}

const std::vector<std::string>& MazeWalker::getVisitedMaze() const {
    return maze;
};

void MazeWalker::turnRight() {
    switch (heading)
    {
    case Direction::NORTH:
        heading = Direction::EAST;
        break;
    case Direction::SOUTH:
        heading = Direction::WEST;
        break;
    case Direction::EAST:
        heading = Direction::SOUTH;
        break;
    case Direction::WEST:
        heading = Direction::NORTH;
        break;
    
    default:
        break;
    }
}

std::pair<int, int> MazeWalker::getNextPosition() const {
    int x = posX;
    int y = posY;
        switch (heading)
    {
        case Direction::NORTH:
            x--;
            break;
        case Direction::SOUTH:
            x++;      
            break;
        case Direction::EAST:
            y++;
            break;
        case Direction::WEST:
            y--;
            break;

        default:
            break;
    }

    return std::pair{x, y};

}

void MazeWalker::walk() {
    switch (heading)
    {
        case Direction::NORTH:
            walkNorth();
            break;
        case Direction::SOUTH:
            walkSouth();        
            break;
        case Direction::EAST:
            walkEast();
            break;
        case Direction::WEST:
            walkWest();
            break;

        default:
            break;
    }
    markPosAsVisited();
}


void MazeWalker::walkEast() {
    posY += 1;
}

void MazeWalker::walkSouth() {
    posX += 1; 
}

void MazeWalker::walkWest() {
    posY -= 1;
}

void MazeWalker::walkNorth() {
    posX -= 1;
}

void MazeWalker::markPosAsVisited() {
    maze[posX][posY] = 'X';
    auto& mazeForLoopsPosition = mazeForLoops[posX][posY];
    if(mazeForLoopsPosition == '.' || mazeForLoopsPosition == '^') {
        mazeForLoopsPosition = '1';
        loopCount = 0;
    } else if(std::isdigit(mazeForLoopsPosition)) {
       // to get int from char
       int num  = mazeForLoopsPosition - '0'; 
       num++;
       // add it as a char;
       mazeForLoopsPosition = num + '0';

       if(num == 2 && loopCount == 0){
         loopStartX = posX;
         LoopstartY = posY; 
         loopCount++;
       } else if (num > 2) loopCount++;
    }



}
