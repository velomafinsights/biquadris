#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include <iostream>

int main() {
    GameBoard* board = new GameBoard();
    Observer* obs = new TextObserver{board, 0, 0, 0, 0};
    board->newBlock();
    string command;
    while (cin >> command){
        if (command == "drop") {
            board->dropBlock();
        } else if (command == "right") {
            board->moveRight();
        } else if (command == "left") {
            board->moveLeft();
        } else if (command == "down") {
            board->moveDown();
        }
    }
    delete board;
}
