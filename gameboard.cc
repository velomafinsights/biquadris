#include "gameboard.h"
#include <vector>
#include <utility>
#include <stdlib.h>
#include "blocks.h"

GameBoard::GameBoard(string inputFile, size_t lvl, int rSeed): turnNumber{1}, level{lvl}, score{0}, highScore{0}, blocksWithoutRowClear{0}, file{inputFile}, randomSeed{rSeed}, gameContinue{true} {
    for (int i = 0; i < 18; i++) {
        std::vector<char> row;
        for (int j = 0; j < 11; j++) {
            row.emplace_back(' ');
        }
        board.emplace_back(row);
    }
    if (level == 0) {
        currLevel = new Level0{file};
    } else if (level == 1) {
        currLevel = new Level1{};
    } else if (level == 2) {    
        currLevel = new Level2{};
    } else if (level == 3) {
        currLevel = new Level3{false};
        heavy = true;
    } else {
        currLevel = new Level4{false};
        heavy = true;
    }
}

void GameBoard::newBlock() {
    if (currBlock == nullptr) {
        currBlock = currLevel->getBlock(turnNumber);
        nextBlock = currLevel->getBlock(turnNumber + 1);
    } else {
        blocks.emplace_back(currBlock);
        currBlock = nextBlock;
        nextBlock = currLevel->getBlock(turnNumber + 1);
    }
    ++turnNumber;
    if (!drawBlock()){
        gameContinue = false;
    }
}

void GameBoard::clearRow(int row) {
    for (int i = 0; i < 11; i++) {
        board[row][i] = ' ';
    }
    for (int i = row; i > 0; i--) {
        for (int j = 0; j < 11; j++) {
            board[i][j] = board[i - 1][j];
        }
    }
}

size_t GameBoard::clearFilledRows() {
    size_t numberOfRowsCleared = 0;
    for (int i = 0; i < 18; i++) {
        bool rowClear = 1;
        for (int j = 0; j < 11; j++) {
            if (board[i][j] == ' ') {
                rowClear = 0;
                break;
            }
        }
        if (rowClear) {
            clearRow(i);
            for(auto it: blocks) {
                it->rowCleared(i);
                int blockRemove = it->blockRemoved();
                if (blockRemove >= 0) {
                    score += (blockRemove + 1) * (blockRemove + 1);
                }
            }
            numberOfRowsCleared++;
        }
    }
    if (numberOfRowsCleared > 0) {
        score += (level + numberOfRowsCleared) * (level + numberOfRowsCleared);
    }
    return numberOfRowsCleared;
}

int GameBoard::dropBlock() {
    while (moveDown()) {}
    currBlock->setCurrLevel(level);
    if (blind) blind = false;
    int rowsCleared = clearFilledRows();
    if (level == 4 && rowsCleared == 0) {
        blocksWithoutRowClear++;
        if (blocksWithoutRowClear % 5 == 0 && blocksWithoutRowClear >= 5) {
            for (int i = 0; i < 18; i++) {
                if (i == 0 && board[i][5] != ' ') {
                    gameContinue = false;
                    break;
                } else if (board[i][5] != ' ') {
                    Block* level4Block = new Block{'*'};
                    for (int j = 0; j < (i - 1); j++) {
                        level4Block->moveBlockDown();
                    }
                    blocks.emplace_back(level4Block);
                    board[i - 1][5] = '*';
                    break;
                } if (i == 17) {
                    Block* level4Block = new Block{'*'};
                    blocks.emplace_back(level4Block);
                    for (int j = 0; j < 17; j++) {
                        level4Block->moveBlockDown();
                    }
                    board[17][5] = '*';
                    break;
                }
            }
        }
    } else {
        blocksWithoutRowClear = 0;
    }
    return rowsCleared;
}

void GameBoard::clearBlock() {
    for (auto it: currBlock->getStructure()) {
        board[it[0]][it[1]] = ' ';
    }
}

bool GameBoard::drawBlock() {
    char symbol = currBlock->getBlockType();
    for (auto it: currBlock->getStructure()) {
        if (board[it[0]][it[1]] != ' '){
            return 0;
        }
        board[it[0]][it[1]] = symbol;
    }
    return 1;
}

bool GameBoard::applyHeavy() {
    for (int i = 0; i < 2; i++) {
        if (!moveDown()) {
            return false;
        }
    }
    return true;
}

bool GameBoard::moveRight() {
    clearBlock();
    for (auto it: currBlock->getStructure()) {
        if (it[1] == 10 || board[it[0]][it[1] + 1] != ' ') {
            drawBlock();
            return false;
        }
    }
    currBlock->moveBlockRight();
    drawBlock();
    return true;
}

bool GameBoard::moveLeft() {
    clearBlock();
    for (auto it: currBlock->getStructure()) {
        if (it[1] == 0 ||  board[it[0]][it[1] - 1] != ' ') {
            drawBlock();
            return false;
        }
    }
    currBlock->moveBlockLeft();
    drawBlock();
    return true;
}

bool GameBoard::moveDown() {
    clearBlock();
    for (auto it: currBlock->getbottomMost()) {
        if (it[0] == 17 || board[it[0] + 1][it[1]] != ' ') {
            drawBlock();
            return false;
        }
    }
    currBlock->moveBlockDown();
    drawBlock();
    return true;
}

void GameBoard::rotate(bool clockwise) {
    std::vector<std::vector <int>> rotatedBlock;
    if (clockwise) {
        rotatedBlock = currBlock->getNextCWOrientation();
    } else {
        rotatedBlock = currBlock->getNextCCWOrientation();
    }
    clearBlock();
    bool canRoate = 1;
    for (auto it: rotatedBlock) {
        if (it[0] == 18 || it[1] == 11 || it[1] == -1 || board[it[0]][it[1]] != ' ') {
            canRoate = 0;
            break;
        }
    }
    if (canRoate) {
        if (clockwise) {
            currBlock->rotateClockWise();
        } else {
            currBlock->rotateCounterClockWise();
        }
    }
    drawBlock();
}

void GameBoard::levelUp() {
    delete currLevel;
    heavy = false;
    if (level == 0) {
        currLevel = new Level1{};
    } else if (level == 1) {
        currLevel = new Level2{};
    } else if (level == 2) {
        currLevel = new Level3{true};
        heavy = true;
    } else if (level == 3) {
        currLevel = new Level4{true, "sequence1.txt"};
        heavy = true;
    }
    if (level != 4) {
        level++;
    }
}

void GameBoard::levelDown() {
    delete currLevel;
    heavy = false;
    if (level == 1) {
        currLevel = new Level0{"sequence1.txt"};
    } else if (level == 2) {
        currLevel = new Level1{};
    } else if (level == 3) {
        currLevel = new Level2{};
    } else if (level == 4) {
        currLevel = new Level3{true};
        heavy = true;
    }
    if (level != 0) {
        level--;
    }
}

void GameBoard::norandom(std::string filePass){
    delete currLevel;
    if(level == 3){
        currLevel = new Level3{true, filePass};
    } else {
        currLevel = new Level4{true, filePass};
    }
}

void GameBoard::random(){
    delete currLevel;
    if(level == 3){
        currLevel = new Level3{false};
    } else {
        currLevel = new Level4{false};
    }
}

void GameBoard::changeBlock(char block) {
    bool canPlace = true;
    int x = currBlock->getX();
    int y = currBlock->getY();
    Block* newBlock = new Block{block};
    while (x > 0) {
        newBlock->moveBlockRight();
        x--;
    }
    while (y > 0) {
        newBlock->moveBlockDown();
        y--;
    }
    clearBlock();
    char symbol = newBlock->getBlockType();
    for (auto it: newBlock->getStructure()) {
        if (board[it[0]][it[1]] != ' '){
            canPlace = 0;
            break;
        }
    }
    if (canPlace) {
        delete currBlock;
        currBlock = newBlock;
        newBlock = nullptr;
        drawBlock();
    } else {
        gameContinue = false;
    }
}

void GameBoard::restart() {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            board[i][j] = ' ';
        }
    }
    delete currBlock;
    delete nextBlock;
    for (auto it: blocks) {
        delete it;
    }
    blocks.clear();
    currBlock = nullptr;
    nextBlock = nullptr;
    delete currLevel;
    currLevel = new Level0{"sequence1.txt"};
    turnNumber = 1;
    level = 0;
    score = 0;
    blind = false;
    heavy = false;
    gameContinue = true;
    blocksWithoutRowClear = 0;
    this->newBlock();
}

size_t GameBoard::getLevel(){
    return level;
}

size_t GameBoard::getScore(){
    return score;
}

std::vector<std::vector <char>> GameBoard::getState() {
    return board;
}

bool GameBoard::getBlind(){
    return blind;
}

bool GameBoard::getGameOver() {
    return gameContinue;
}

Block* GameBoard::getNextBlock() {
    return nextBlock;
}

size_t GameBoard::getHighScore() {
    return highScore;
}
    
void GameBoard::setHighScore(size_t hScore) {
    highScore = hScore;
}

bool GameBoard::getHeavy() {
    return heavy;
}

void GameBoard::setBlind() {
    blind = true;
}

void GameBoard::setHeavy() {
    heavy = true;
}

void GameBoard::render(){
    notifyObservers();
}

GameBoard::~GameBoard() {
    delete currBlock;
    delete nextBlock;
    delete currLevel;
    for (auto it: blocks) {
        delete it;
    }
}
