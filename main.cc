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
    GameBoard* b1 = board1.get();
    GameBoard* b2 = board2.get();
    GameBoard* currentPlayer = b1;
    Observer* obs = new TextObserver{b1, b2, 0, 0, 0, 0};
    currentPlayer->newBlock();
    currentPlayer->render();
    string commandFromUser;
    string command;
    commandInterpreter ci{};
    bool gameContinue;

    while (cin >> commandFromUser){
        int multi = ci.multiplier(commandFromUser);
        command = ci.process(commandFromUser);
        if (command == "drop") {
            int rowsCleared = currentPlayer->dropBlock();
            gameContinue = currentPlayer->newBlock();
            if (gameContinue == 0){
                cout<< "Game Over! :("<<endl;
                break;
            }
            score = currentPlayer->getScore();
            updateHighScore(score, &highScore);
            currentPlayer->render();
            if (currentPlayer == b1) {
                currentPlayer = b2;
            } else {
                currentPlayer = b1;
            }
            std::cout << "reached" << std::endl;
            if (rowsCleared >= 2) {
                cin >> commandFromUser;
                string punish = ci.process(commandFromUser);
                if (punish == "blind") {
                    currentPlayer->setBlind();
                } else if (punish == "heavy") {
                    currentPlayer->setHeavy();
                } else if (punish == "force") {
                    cin >> commandFromUser;
                    string blockType = ci.process(commandFromUser);
                    if (!currentPlayer->changeBlock(blockType[0])) {
                        if (currentPlayer == b1) {
                            currentPlayer->setWinner("player 2");
                            b2->setWinner("player 1");
                        } else {
                            currentPlayer->setWinner("player 1");
                            b1->setWinner("player 1");
                        }
                    }
                }
            }
            currentPlayer->render();
            currentPlayer->newBlock();
            std::cout << "after render" << std::endl;
        } else if (command == "right") {
            for(int i =0; i<multi; ++i){
                currentPlayer->moveRight();
            }
            currentPlayer->render();
        } else if (command == "left") {
            for(int i =0; i<multi; ++i){
                currentPlayer->moveLeft();
            }
            currentPlayer->render();
        } else if (command == "down") {
            for(int i =0; i<multi; ++i){
                currentPlayer->moveDown();
            }
            currentPlayer->render();
        } else if (command == "clockwise") {
            for(int i =0; i<multi; ++i){
                currentPlayer->rotate(1);
            }
            currentPlayer->render();
        } else if (command == "counterclockwise") {
           for(int i =0; i<multi; ++i){
                currentPlayer->rotate(0);
            }
            currentPlayer->render();
        } else if (command == "blind"){
            currentPlayer->setBlind();
            currentPlayer->render();
        } else if (command == "heavy"){
            currentPlayer->setHeavy();
            currentPlayer->render();
            
        }


    }
}
