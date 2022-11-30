#include "gameboard.h"
#include <vector>
#include <memory>
#include <utility>
#include <stdlib.h>
#include "blocks.h"

GameBoard::GameBoard() {
    for (int i = 0; i < 18; i++) {
        std::vector<char> row;
        for (int j = 0; j < 11; j++) {
            row.emplace_back('.');
        }
        board.emplace_back(row);
    }
    currLevel = new Level0{"sequence1.txt"};
    turnNumber = 1;
    level = 0;
    score = 0;
}

bool GameBoard::newBlock() {
    if (currBlock != nullptr) {
        blocks.emplace_back(currBlock);
    }
    currBlock = currLevel->getBlock(0);
    /*
    if (currBlock == nullptr) {
        currBlock = new Block{'i'};
        nextBlock = new Block{'j'};
    } else {
        Block* temp = currBlock;
        currBlock = nextBlock;
        nextBlock = new Block{'s'};
        delete temp;
    }*/
    ++turnNumber;
    if (!drawBlock()){
        return 0;
    }
    return 1;
}

void GameBoard::clearRow(int row) {
    for (int i = 0; i < 11; i++) {
        board[row][i] = '.';
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
            if (board[i][j] == '.') {
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
    score += (level + numberOfRowsCleared) * (level + numberOfRowsCleared);
    return numberOfRowsCleared;
}

int GameBoard::dropBlock() {
    while (moveDown()) {}
    currBlock->setCurrLevel(level);
    if (blind) blind = false;
    int rowsCleared = clearFilledRows();
    return rowsCleared;
}

void GameBoard::clearBlock() {
    for (auto it: currBlock->getStructure()) {
        board[it[0]][it[1]] = '.';
    }
}

bool GameBoard::drawBlock() {
    char symbol = currBlock->getBlockType();
    for (auto it: currBlock->getStructure()) {
        if (board[it[0]][it[1]] != '.'){
            return 0;
        }
        board[it[0]][it[1]] = symbol;
    }
    return 1;
}

void GameBoard::applyHeavy() {
    for (int i = 0; i < 2; i++) {
        if (!moveDown()) {
            dropBlock();
            break;
        }
    }
}

void GameBoard::moveRight() {
    bool canMoveRight = 1;
    clearBlock();
    for (auto it: currBlock->getStructure()) {
        if (it[1] == 10 || board[it[0]][it[1] + 1] != '.') {
            canMoveRight = 0;
            break;
        }
    }
    if (canMoveRight) {
        currBlock->moveBlockRight();
    }
    drawBlock();
    if (heavy) applyHeavy();
}

void GameBoard::moveLeft() {
    bool canMoveLeft = 1;
    clearBlock();
    for (auto it: currBlock->getStructure()) {
        if (it[1] == 0 ||  board[it[0]][it[1] - 1] != '.') {
            canMoveLeft = 0;
            break;
        }
    }
    if (canMoveLeft) {
        currBlock->moveBlockLeft();
    }
    drawBlock();
    if (heavy) applyHeavy();
}

bool GameBoard::moveDown() {
    clearBlock();
    bool canMoveDown = 1;
    for (auto it: currBlock->getbottomMost()) {
        if (it[0] == 17 || board[it[0] + 1][it[1]] != '.') {
            std::cout << "OUT OF INDEX";
            std::cout << it[0] << "-" << it[1] << std::endl;
            canMoveDown = 0;
            break;
        }
    }
    if (canMoveDown) {
        currBlock->moveBlockDown();
    }
    drawBlock();
    notifyObservers();
    if (canMoveDown) {
        return true;
    }
    return false;
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
        if (it[0] == 18 || it[1] == 11 || it[1] == -1 || board[it[0]][it[1]] != '.') {
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
    // delete level
    if (level == 0) {
    } else if (level == 1) {
    } else if (level == 2) {
    } else if (level == 3) {
    }
    if (level != 4) {
        currLevel++;
    }
}

void GameBoard::levelDown() {
    // delete level
    if (level == 1) {
    } else if (level == 2) {
    } else if (level == 3) {
    } else if (level == 4) {
    }
    if (level != 0) {
        currLevel--;
    }
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

GameBoard::~GameBoard() {
    delete currBlock;
    delete nextBlock;
    delete currLevel;
    for (auto it: blocks) {
        delete it;
    }
}
