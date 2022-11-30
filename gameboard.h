#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_
#include <vector>
#include <string>
#include "subject.h"
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

class GameBoard: public Subject {
    std::vector<std::vector <char>> board;
    std::vector<Block*> blocks;
    bool won;
    string winner;
    Block* currBlock;
    Block* nextBlock;
    Level* currLevel;
    size_t turnNumber;
    size_t level;
    size_t score;
    size_t highScore;
    size_t blocksWithoutRowClear;
    bool blind;
    bool heavy;
    bool gameContinue;
    size_t clearFilledRows();
    void clearRow(int row);
    void clearBlock();
    bool drawBlock();
    void blindBoard();
    void applyHeavy();
 public:
    GameBoard();
    void newBlock();
    int dropBlock();
    void moveRight();
    void moveLeft();
    bool moveDown();
    void setBlind();
    void setHeavy();
    void levelUp();
    void levelDown();
    void changeBlock(char block);
    size_t getScore();
    size_t getLevel();
    size_t getHighScore();
    void setHighScore(size_t hScore);
    void rotate(bool clockwise);
    void render();
    void restart();
    std::vector<std::vector <char>> getState();
    bool getBlind();
    ~GameBoard();
    bool getGameOver();
    std::vector<std::vector<int>> getNextBlock();
    bool getWon();
    string getWinner();
    void setWinner(string player);
};

#endif
