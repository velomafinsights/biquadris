#include "gameboard.h"
#include <vector>
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
}

bool GameBoard::newBlock() {
    // delete b;
    //b = new BlockS{};
    //drawBlock();
    //notifyObservers();
       // call gameLost()

    b = currLevel->getBlock(turnNumber);
    ++turnNumber;
    if (!drawBlock()){
        // game is over;
        return 0;
    }
    //notifyObservers();
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

void GameBoard::clearFilledRows() {
    for (int i = 0; i < 18; i++) {
        bool rowClear = 1;
        for (int j = 0; j < 11; j++) {
            if (board[i][j] == '.') {
                rowClear = 0;
                break;
            }
        }
        if (rowClear) clearRow(i);
    }
}

void GameBoard::dropBlock() {
    while (moveDown()) {}
    if (blind) blind = false;
    clearFilledRows();
}

void GameBoard::clearBlock() {
    for (auto it: b->getStructure()) {
        board[it[0]][it[1]] = '.';
    }
}

bool GameBoard::drawBlock() {
    char symbol = b->getBlockType();
    for (auto it: b->getStructure()) {
        if (board[it[0]][it[1]] != '.'){
            return 0;
        }
        board[it[0]][it[1]] = symbol;
    }
    return 1;
}

/*void GameBoard::blindBoard() {
    if (blind) {
        for (int i = 3; i <= 12; i++) {
            for (int j = 3; j <= 9; j++) {
                board[i][j] = '?';
            }
        }
    }
}*/

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
    for (auto it: b->getStructure()) {
        if (it[1] == 10 || board[it[0]][it[1] + 1] != '.') {
            canMoveRight = 0;
            break;
        }
    }
    if (canMoveRight) {
        b->moveBlockRight();
    }
    drawBlock();
    //notifyObservers();
}

void GameBoard::moveLeft() {
    bool canMoveLeft = 1;
    clearBlock();
    for (auto it: b->getStructure()) {
        if (it[1] == 0 ||  board[it[0]][it[1] - 1] != '.') {
            canMoveLeft = 0;
            break;
        }
    }
    if (canMoveLeft) {
        b->moveBlockLeft();
    }
    drawBlock();
    //notifyObservers();
}

bool GameBoard::moveDown() {
    clearBlock();
    bool canMoveDown = 1;
    for (auto it: b->getbottomMost()) {
        if (it[0] == 17 || board[it[0] + 1][it[1]] != '.') {
            std::cout << it[0] << "-" << it[1] << std::endl;
            canMoveDown = 0;
            break;
        }
    }
    if (canMoveDown) {
        b->moveBlockDown();
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
        rotatedBlock = b->getNextCWOrientation();
    } else {
        rotatedBlock = b->getNextCCWOrientation();
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
            b->rotateClockWise();
        } else {
            b->rotateCounterClockWise();
        }
    }
    drawBlock();
    //notifyObservers();
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

std::vector<std::vector <char>> GameBoard::getState() {
    return board;
}

bool getBlind(){
    return blind;
}
