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
    Block* currBlock;
    Block* nextBlock;
    Level* currLevel;
    size_t turnNumber;
    size_t level;
    size_t score;
    size_t highScore;
    size_t blocksWithoutRowClear;
    string file;
    int randomSeed;
    bool blind;
    bool heavy;
    bool gameContinue;
    size_t clearFilledRows();
    void clearRow(int row);
    void clearBlock();
    bool drawBlock();
    void blindBoard();
 public:
    GameBoard(string inputFile, size_t lvl, int rSeed);
    void norandom(std::string filePass);
    void random();
    void newBlock();
    int dropBlock();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
    void setBlind();
    void setHeavy();
    void levelUp();
    void levelDown();
    void changeBlock(char block);
    void setHighScore(size_t hScore);
    bool rotate(bool clockwise);
    void render();
    void restart();
    std::vector<std::vector <char>> getState();
    bool getGameOver();
    Block* getNextBlock();
    bool getBlind();
    size_t getScore();
    size_t getLevel();
    size_t getHighScore();
    bool getHeavy();
    bool applyHeavy();
    ~GameBoard();
};

#endif
