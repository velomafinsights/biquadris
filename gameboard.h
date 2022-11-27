#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <vector>
#include <string>
#include "subject.h"
#include "block.h"

class GameBoard: public Subject {
    std::vector<std::vector <char>> board;
    std::vector< std::vector<int>> block;
    void clearFilledRows();
    void clearRow(int row);
 public:
    GameBoard();
    void newBlock();
    void dropBlock();
    void moveRight();
    // void moveLeft();
    // void moveDown();
    std::vector<std::vector <char>> getState();
    ~GameBoard() = default;
};

#endif
