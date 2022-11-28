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
    block = {{1,1}, {1, 2}, {2, 0}, {2, 1}};
}

void GameBoard::newBlock() {
    b = new BlockS{};
    std::vector<std::vector<int>> bStruct = b->getStructure();
    char bChar = b->getBlockType();
    for (int i = 0; i < 4; i++) {
        board[bStruct[i][0] + b->getX()][bStruct[i][1] + b->getY()] = bChar;
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
    int x = 0;
    int y = 0;
    std::vector<std::vector <int>> mostBottom = {{2,2}, {3,0}, {3,1}};
    int rowsToDropBy = 0;
    bool rowFound = 0;
    while (true) {
        for (auto it: mostBottom) {
            if ((it[0] + x) == 18 || board[it[0] + x][it[1] + y] != '*') {
                rowFound = 1;
                break;
            }
        }
        if (rowFound) break;
        rowsToDropBy += 1;
    }
    std::vector<std::vector<int>> bStruct = b->getStructure();
    for (int i = 0; i < 4; i++) {
        board[block[i][0] + b->getY()][block[i][1] + b->getX()] = '*';
        board[rowsToDropBy + block[i][0] + b->getY()][block[i][1] + b->getX()] = 'b';
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
    std::vector<std::vector <int>> bottomMost = b->getStructure();
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
    if (clockwise) {
        rotatedBlock = b->getStructure();
    } else {
        rotatedBlock = b->getStructure();
    }
    char symbol = b->getBlockType();
    bool canRoate = 1;
    for (auto it: rotatedBlock) {
        if (it[0] == 18 || it[1] == 11 || it[1] == -1 || board[it[0]][it[1]] != '*') {
            canRoate = 0;
            break;
        }
    }
    if (canRoate) {
        if (clockwise) {
            b->moveBlockDown();
        } else {
            b->moveBlockDown();
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
