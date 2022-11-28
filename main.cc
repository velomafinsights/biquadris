#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include <iostream>
#include <string>


int main() {
    GameBoard* board = new GameBoard();
    Observer* obs = new TextObserver{board, 0, 0, 0, 0};
    board->newBlock();
    string commandFromUser;
    string command;
    ifstream seq;


    while (cin >> commandFromUser){
        multi = commandinterpreter::multiplier(commandFromUser);
        command = commandinterpreter::process(commandFromUser);
        if (command == "drop") {
            board->dropBlock();
        } else if (command == "right") {
            for(int i =0; i<multi; ++i){
                board->moveRight();
            }
        } else if (command == "left") {
            for(int i =0; i<multi; ++i){
                board->moveLeft();
            }
        } else if (command == "down") {
            for(int i =0; i<multi; ++i){
                board->moveDown();
            }
        } else if (command == "clockwise") {
            for(int i =0; i<multi; ++i){
                board->rotate(1);
            }
        } else if (command == "counterclockwise") {
           for(int i =0; i<multi; ++i){
                board->rotate(0);
            }
        }
    }
    delete board;
}
