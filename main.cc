#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include "commandinterpreter.h"
#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include "level.h"
#include "level0.h"
#include "level1.h"

void updateHighScore(int score, size_t *highScore) {
    if (score > *highScore) {
        *highScore = score;
    }
}

int main() {
    size_t highScore = 0;
    size_t score = 0;
    std::unique_ptr <GameBoard> board1{new GameBoard{}};
    std::unique_ptr <GameBoard> board2{new GameBoard{}};
    
    GameBoard* b1 = *board1;
    GameBoard* b2 = *board2;
    Observer* obs = new TextObserver{b1, b2, 0, 0, 0, 0};
    board->newBlock();
    board->render();
    string commandFromUser;
    string command;
    commandInterpreter ci{};
    bool gameContinue;
    /*
    Level0 lev0 = Level0{"sequence1.txt"};
    Level1 lev1 =  Level1();

    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev0.getBlock(i);
        cout<< "Level 0: "<< i << "th block:" << gb->c<<endl;
    }

    for (size_t i = 1; i <= 12; ++i){
        Block* gb = lev1.getBlock(i);
        cout<< "Level 1: "<< i << "th block:" << gb->c<<endl;
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
            score = board->getScore();
            updateHighScore(score, &highScore);
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
