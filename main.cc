#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include <iostream>

int main() {
    GameBoard* board = new GameBoard();
    Observer* obs = new TextObserver{board, 0, 0, 0, 0};
    board->newBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    board->dropBlock();
    // board->dropBlock();
    delete board;

    string command;
    while (cin >> command){
        // drop
        if (command == "drop") {
            // 
        }

        // left-right
    }
    return 0;
}
