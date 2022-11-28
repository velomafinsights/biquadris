#include "gameboard.h"
#include <vector>
#include <stdlib.h>
#include "blocks.h"

GameBoard::GameBoard() {
    for (int i = 0; i < 18; i++) {
        std::vector<char> row;
        for (int j = 0; j < 11; j++) {
            row.emplace_back('*');
        }
        board.emplace_back(row);
    }
}

void GameBoard::newBlock() {
    b = new BlockS{};
    std::vector<std::vector<int>> block = b->getStructure();
    char bChar = b->getBlockType();
    for (int i = 0; i < 4; i++) {
        board[block[i][0] + b->getX()][block[i][1] + b->getY()] = bChar;
    }
    notifyObservers();
}

void GameBoard::clearRow(int row) {
    for (int i = 0; i < 11; i++) {
        board[row][i] = '*';
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
            if (board[i][j] == '*') {
                rowClear = 0;
                break;
            }
        }
        if (rowClear) clearRow(i);
    }
}

void GameBoard::dropBlock() {
    std::vector<std::vector<int>> block = b->getStructure();
    int rowsToDropBy = 0;
    bool rowFound = 0;
    while (true) {
        for (auto it: b->getbottomMost()) {
            if (it[0] == 17 || board[it[0] + rowsToDropBy][it[1]] != '*') {
                rowFound = 1;
                break;
            }
        }
        if (rowFound) break;
        rowsToDropBy += 1;
    }
    for (int i = 0; i < 4; i++) {
        board[block[i][0]][block[i][1]] = '*';
        board[rowsToDropBy + block[i][0]][block[i][1]] = 'b';
    }
    clearFilledRows();
    newBlock();
}

void GameBoard::moveRight() {
    std::vector<std::vector <int>> block = b->getStructure();
    char symbol = b->getBlockType();
    bool canMoveRight = 1;
    for (auto it: block) {
        board[it[0]][it[1]] = '*';
    }
    for (auto it: block) {
        if (it[1] == 10 || board[it[0]][it[1] + 1] != '*') {
            canMoveRight = 0;
            break;
        }
    }
    if (canMoveRight) {
        b->moveBlockRight();
        block = b->getStructure();
    }
    for (auto it: block) {
        board[it[0]][it[1]] = symbol;
    }
}

void GameBoard::moveLeft() {
    std::vector<std::vector <int>> block = b->getStructure();
    char symbol = b->getBlockType();
    bool canMoveLeft = 1;
    for (auto it: block) {
        board[it[0]][it[1]] = '*';
    }
    for (auto it: block) {
        if (it[1] == 0 ||  board[it[0]][it[1] + 1] != '*') {
            canMoveLeft = 0;
            break;
        }
    }
    if (canMoveLeft) {
        b->moveBlockLeft();
        block = b->getStructure();
    }
    for (auto it: block) {
        board[it[0]][it[1]] = symbol;
    }
}

void GameBoard::moveDown() {
    std::vector<std::vector <int>> block = b->getStructure();
    std::vector<std::vector <int>> bottomMost = b->getbottomMost();
    char symbol = b->getBlockType();
    bool canMoveDown = 1;
    for (auto it: bottomMost) {
        if (it[0] == 0 || board[it[0] - 1][it[1]] != '*') {
            canMoveDown = 0;
            break;
        }
    }
    if (canMoveDown) {
        b->moveBlockDown();
        block = b->getStructure();
    }
    for (auto it: block) {
        board[it[0]][it[1]] = symbol;
    }
}

void GameBoard::rotate(bool clockwise) {
    std::vector<std::vector <int>> rotatedBlock;
    char symbol = b->getBlockType();
    if (clockwise) {
        rotatedBlock = b->getNextCWOrientation();
    } else {
        rotatedBlock = b->getNextCCWOrientation();
    }
    bool canRoate = 1;
    for (auto it: rotatedBlock) {
        if (it[0] == 18 || it[1] == 11 || it[1] == -1 || board[it[0]][it[1]] != '*') {
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
    std::vector<std::vector <int>> block = b->getStructure();
    for (auto it: block) {
        board[it[0]][it[1]] = symbol;
    }
}

std::vector<std::vector <char>> GameBoard::getState() {
    return board;
}
