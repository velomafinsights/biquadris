#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <vector>
#include <string>
#include "subject.h"
#include "block.h"
#include "level.h"
#include "level0.h"

class GameBoard: public Subject {
    std::vector<std::vector <char>> board;
    Block* b;
    bool blind;
    size_t turnNumber;
    Level* currLevel;
    bool heavy;
    void clearFilledRows();
    void clearRow(int row);
    void clearBlock();
    bool drawBlock();
    void blindBoard();
    void applyHeavy();
 public:
    GameBoard();
    bool newBlock();
    void dropBlock();
    void moveRight();
    void moveLeft();
    bool moveDown();
    void setBlind();
    void setHeavy();
    void rotate(bool clockwise);
    std::vector<std::vector <char>> getState();
    ~GameBoard() = default;
};

#endif
