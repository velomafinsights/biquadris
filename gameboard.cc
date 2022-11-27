#include "gameboard.h"
#include <vector>
#include <stdlib.h>

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

void GameBoard::newBlock() {
    for (int i = 0; i < 4; i++) {
        board[block[i][0]][block[i][1]] = 'f';
    }
    notifyObservers();
}

void GameBoard::dropBlock() {
    int width = 3;
    int x = (rand() % 8);
    int y = 2;
    int rowToDrop = 3;
    bool rowFound = 0;
    for (int i = 3; i < 18; i++) {
        for (auto it: block) {
            if ((it[0] + i) == 18 || board[it[0] + i][it[1] + x] == 'b') {
                rowToDrop = i - 1;
                rowFound = 1;
                break;
            }
        }
        if (rowFound) break;
        rowToDrop += 1;
    }
    for (int i = 0; i < 4; i++) {
        board[rowToDrop + block[i][0]][block[i][1] + x] = 'b';
    }
    clearFilledRows();
    newBlock();
}

std::vector<std::vector <char>> GameBoard::getState() {
    return board;
}

void GameBoard::moveRight() {
    //find right-most item in each row
    //check right-hand side of each item
    // if blank and not on edge, move right
    // {{1,1}, {1, 2}, {2, 0}, {2, 1}}
    std::vector<std::vector <int>> rightPieces;
    int curRow = block[0][0];
    for (int i = 1; i < block.size(); i++) {
        if (curRow != block[i][0]) {
            rightPieces.emplace_back(block[i - 1][0]);
            curRow = block[i][0];
        }
    }
    rightPieces.emplace_back(block[block.size() - 1]);
    bool canMoveRight = 1;
    for (int i = 0; i < rightPieces.size(); i++) {
        if (rightPieces[i][1] == 10 || board[rightPieces[i][0]][rightPieces[i][1] + 1] != '*') {
            canMoveRight = 0;
            break;
        }
    }
    if (canMoveRight) {
        int x = 1;
        int width = 3;
        int col = x + width + 1;
        //remove from board
        //set x and y
        //redraw
    }
}

