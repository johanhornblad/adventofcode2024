#include "maze_walker.h"


 MazeWalker::MazeWalker(const std::vector<std::string>& maze,  Direction heading, int posX, int posY) : 
    posX(posX),
    posY(posY),
    maze(maze),
    heading(heading){
        markPosAsVisited();
    };

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
}
