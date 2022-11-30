#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include "commandinterpreter.h"
#include <iostream>
#include <string>
#include <memory>
#include <utility>

#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"


int main() {
    unique_ptr<GameBoard> g{new GameBoard{}};
    GameBoard* board = g.get();

    unique_ptr<GameBoard> g2{new GameBoard{}};
    GameBoard* board2 = g2.get();


    unique_ptr<Observer> o{new TextObserver{board,board2, 0, 0, 0, 0}};
    Observer* obs = o.get();

    board->newBlock();
    board2->newBlock();
    board->render();
    string commandFromUser;
    string command;
    commandInterpreter ci{};
    bool gameContinue;
    size_t i =0;
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
        if(i%2 == 0){
            if (command == "drop") {
                board->dropBlock();
                gameContinue = board->newBlock();
                if (gameContinue == 0){
                    cout<< "Game Over! :("<<endl;
                    break;
                }
                board->render();
                ++i;
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
        } else{
            if (command == "drop") {
                board2->dropBlock();
                gameContinue = board2->newBlock();
                if (gameContinue == 0){
                    cout<< "Game Over! :("<<endl;
                    break;
                }
                board2->render();
                ++i;
            } else if (command == "right") {
                for(int i =0; i<multi; ++i){
                    board2->moveRight();
                }
                board2->render();
                
            } else if (command == "left") {
                for(int i =0; i<multi; ++i){
                    board2->moveLeft();
                }
                board2->render();

            } else if (command == "down") {
                for(int i =0; i<multi; ++i){
                    board2->moveDown();
                }
                board2->render();

            } else if (command == "clockwise") {
                for(int i =0; i<multi; ++i){
                    board2->rotate(1);
                }
                board2->render();

            } else if (command == "counterclockwise") {
            for(int i =0; i<multi; ++i){
                    board2->rotate(0);
                }
                board2->render();

            } else if (command == "blind"){
                board2->setBlind();
                board2->render();

            } else if (command == "heavy"){
                board2->setHeavy();
                board2->render();
                
            } 
        }

    }
    //delete board;
    //delete obs;
}
