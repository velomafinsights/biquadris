#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "subject.h"
#include "piece.h"
#include "block.h"

using namespace std;

// GameBoard is a concrete Subject
class GameBoard: public Subject {
    //vector<vector<Piece>> canvas;
    Block* currBlock;
    Block* nextBlock;
    size_t level;
    size_t currPlayer;
    // perhaps change gameOver field to gameStatus
    bool gameOver;

 public:
    // init Ctor:
    explicit GameBoard(size_t level, size_t currPlayer);
    void dropBlock();
    void moveBlockLeft();
    void moveBlockRight();
    void resetGame();
    bool lostGame();
    

};
#endif
