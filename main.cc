#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include "commandinterpreter.h"
#include <iostream>
#include <string>

#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"


int main() {
    GameBoard* board = new GameBoard();
    Observer* obs = new TextObserver{board, 0, 0, 0, 0};
    board->newBlock();
    board->render();
    string commandFromUser;
    string command;
    commandInterpreter ci{};
    bool gameContinue;
    /* TESTING LEVELS
    Level0 lev0 = Level0{"sequence1.txt"};
    Level1 lev1 =  Level1();
    Level2 lev2 = Level2();

    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev0.getBlock(i);
        cout<< "Level 0: "<< i << "th block:" << gb->c<<endl;
    }

    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev1.getBlock(i);
        cout<< "Level 1: "<< i << "th block:" << gb->c<<endl;
    }

    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev2.getBlock(i);
        cout<< "Level 2: "<< i << "th block:" << gb->c<<endl;
    }
    Level3 lev3 = Level3(true, "sequence2.txt");
    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev3.getBlock(i);
        cout<< "Level 3: "<< i << "th block:" << gb->c<<endl;
    }
    
    
    */
    
    while (cin >> commandFromUser){
        int multi = ci.multiplier(commandFromUser);
        command = ci.process(commandFromUser);
        if (command == "drop") {
            board->dropBlock();
            gameContinue = board->newBlock();
            if (gameContinue == 0){
                cout<< "Game Over! :("<<endl;
                break;
            }
            board->newBlock();
            board->render();
        } else if (command == "right") {
            for(int i =0; i<multi; ++i){
                board->moveRight();
            }
            board->render();
            
        } else if (command == "left") {
            for(int i =0; i<multi; ++i){
                board->moveLeft();
            }
            board->render();

        } else if (command == "down") {
            for(int i =0; i<multi; ++i){
                board->moveDown();
            }
            board->render();

        } else if (command == "clockwise") {
            for(int i =0; i<multi; ++i){
                board->rotate(1);
            }
            board->render();

        } else if (command == "counterclockwise") {
           for(int i =0; i<multi; ++i){
                board->rotate(0);
            }
            board->render();

        } else if (command == "blind"){
            board->setBlind();
            board->render();

        } else if (command == "heavy"){
            board->setHeavy();
            board->render();
            
        }


    }
    delete board;
}
