#include "gameboard.h"
#include "observer.h"
#include "subject.h"
#include "textObserver.h"
#include "graphicobserver.h"
#include "window.h"
#include "commandinterpreter.h"
#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"


int dropCurrBlock(GameBoard* board, GameBoard* board2){
    cout<< board->getScore() << endl;
    int rC = board->dropBlock();
    int p1HS = board->getScore();
    if (p1HS > board->getHighScore()){
        board->setHighScore(p1HS);
        board2->setHighScore(p1HS);
    }

    cout<< board->getScore() << endl;
    board->newBlock();
    if (board->getGameOver() == 0){
        board->render();
        cout<< "Game Over! " <<endl;
        return 2;
    }
    if(rC >=2){
        cout<<"Choose a punishment for your opponent?"<<endl;
        std::string punish;
        cin >> punish;
        if (punish == "blind"){
            board2->setBlind();
        } else if (punish == "heavy"){
            board2->setHeavy();
        } else if (punish == "force"){
            cout<<"What block would you like for your opponent?"<<endl; 
            char blockOpp;
            cin >> blockOpp; 
            board2->changeBlock(blockOpp);
        }
    }
    board->render();
    return 1;

}

int applyCommand(GameBoard* board, GameBoard* board2, string commandFromUser, commandInterpreter* ci){
    int multi = ci->multiplier(commandFromUser);
    std::string command = ci->process(commandFromUser);
    bool gameContinue;
    if (command == "drop") {
        return dropCurrBlock(board, board2);
    } else if (command == "right") {
        for(int i =0; i<multi; ++i){
            if (board->moveRight() && board->getHeavy() && !board->applyHeavy()) {
                return dropCurrBlock(board, board2);
            }
        }
        board->render();
    } else if (command == "left") {
        for(int i =0; i<multi; ++i){
            if (board->moveLeft() && board->getHeavy() && !board->applyHeavy()) {
                return dropCurrBlock(board, board2);
            }
        }
        board->render();
    } else if (command == "down") {
        for(int i =0; i<multi; ++i){
            if (!board->moveDown()) {
                return dropCurrBlock(board, board2);
            }
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
    } else if (command == "rename"){
        std::string toRename; 
        cin >> toRename;
        std::string cmd;
        cin >> cmd;
        ci->rename(toRename, cmd);
    } else if (command == "levelup") {
        for(int i =0; i<multi; ++i){
            board->levelUp();
        }
    } else if (command == "leveldown") {
        for(int i =0; i<multi; ++i){
            board->levelDown();
        }
    } else if (command == "norandom"){
        std::string fname;
        cin >> fname;
        if(board->getLevel() > 2){
            board->norandom(fname);
            board->render();
        }
        else{
            cout << "Error: you must be in level 3 or level 4 to run this command" << endl;
        }
    } else if (command == "random"){
        if(board->getLevel() > 2){
            board->random();
            board->render();                    
        }                
    } else if (command == "restart"){
        board->restart();
        board2->restart();
        board->render();
    } else if (command == "sequence"){
        std::string fileName;
        cin >> fileName;
        ifstream commands{fileName};
        string cmd;
        while(commands >> cmd){
            int cmdResult = applyCommand(board, board2, cmd, ci);
            if (cmdResult == 2){
                return 2;
            }
            else if (cmdResult == 1){
                return 1;
            }
        }
    } else if (command == "I"){
        board->changeBlock('i');
        board->render();
    } else if (command == "J"){
        board->changeBlock('j');
        board->render();
    } else if (command == "L"){
        board->changeBlock('l');
        board->render();
    } else if (command == "S"){
        board->changeBlock('s');
        board->render();
    } else if (command == "T"){
        board->changeBlock('t');
        board->render();
    } else if (command == "Z"){
        board->changeBlock('z');
        board->render();
    } else if (command == "O"){
        board->changeBlock('o');
        board->render();
    }
    return 0;
}


int main(int argc, char* argv[]) {
    srand(1);
    std::string file1 = "sequence1.txt";
    std::string file2 = "sequence2.txt";
    size_t userDefLevel = 0;
    int randomSeed = 0;
    bool textOnly=false;
    
    size_t currArg = 1;
    while(currArg < argc){
        if(std::string(argv[currArg]) == "-text"){
            textOnly = true;
            ++currArg;
        } else if(std::string(argv[currArg]) == "-seed"){
            ++currArg;
            randomSeed = std::stoi(std::string(argv[currArg]));
            srand(randomSeed);
            ++currArg;
        } else if(std::string(argv[currArg]) == "-scriptfile1"){
            ++currArg;
            file1 = std::string(argv[currArg]);
            ++currArg;            
        } else if(std::string(argv[currArg]) == "-scriptfile2"){
            ++currArg;
            file2 = std::string(argv[currArg]);
            ++currArg;            
        } else if(std::string(argv[currArg]) == "-startlevel"){
            ++currArg;
            userDefLevel = std::stoi(std::string(argv[currArg]));
            ++currArg;            
        } else {
            break;
        }
    }

    unique_ptr<GameBoard> g{new GameBoard{file1, userDefLevel, randomSeed}};
    GameBoard* board = g.get();

    unique_ptr<GameBoard> g2{new GameBoard{file2, userDefLevel, randomSeed}};
    GameBoard* board2 = g2.get();
    
    unique_ptr<Observer> o{new TextObserver{board,board2, 0, 0, 0, 0}};
    Observer* obs = o.get();

    int blockWidth = 25;
    Observer* graphics = nullptr; 

    if (textOnly == false){
        graphics = new GraphicObserver{blockWidth, board, board2};
    }


    board->newBlock();
    board2->newBlock();
    board->render();
    string commandFromUser;
    string command;
    commandInterpreter ci{};   
    commandInterpreter* ciptr = &ci;
    bool gameContinue;
    ifstream commands;
    // This was used to track which player's turn it is
    //size_t i =0;
    size_t playerOne = 0;
    //bool userFile=false;
    //bool *inputFromFile = &userFile;

    while(cin >> commandFromUser){
        int commandResult = 0;
        if (playerOne % 2 == 0){
            commandResult = applyCommand(board, board2, commandFromUser, ciptr);
        }
        else{
            commandResult = applyCommand(board2, board, commandFromUser, ciptr);
        }
/*
        int p1HS = board->getScore();
        int p2HS = board2->getScore();
        if (p1HS > p2HS){
            board->setHighScore(p1HS);
            board2->setHighScore(p1HS);
        }
        else{
            board->setHighScore(p2HS);
            board2->setHighScore(p2HS);
        }
*/
        if (commandResult == 2){
            // cin a new command
            int breakloop = 0;
            cout << "To exit, press any key, then press 'Enter'."<<endl;
            while (true){
                if (cin >> commandFromUser){
                    breakloop = 1;
                    break;
                }
            }
            if (breakloop == 1){
                break;
            }
        }
        playerOne += commandResult;
    }
    delete graphics;
/*
    while (cin >> commandFromUser){
        int multi = ci.multiplier(commandFromUser);
        command = ci.process(commandFromUser);
        if(i%2 == 0){
            if (command == "drop") {
                int rC = board->dropBlock();
                board->newBlock();
                gameContinue = board->getGameOver();
                if (gameContinue == 0){
                    cout<< "Game Over! :("<<endl;
                    break;
                }
                if(rC >=2){
                    cout<<"Choose a punishment for your opponent?"<<endl;
                    std::string punish;
                    cin >> punish;
                    if (punish == "blind"){
                        board2->setBlind();
                    } else if (punish == "heavy"){
                        board2->setHeavy();
                    } else if (punish == "force"){
                       cout<<"What block would you like for your opponent?"<<endl; 
                       char blockOpp;
                       cin >> blockOpp;
                       
                       board2->changeBlock(blockOpp);
                    }
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
                
            } else if (command == "rename"){
                std::string toRename; 
                cin >> toRename;
                
                std::string cmd;
                cin >> cmd;
                ci.rename(toRename, cmd);
            } else if (command == "levelup") {
                for(int i =0; i<multi; ++i){
                    board->levelUp();
                }
            } else if (command == "leveldown") {
                for(int i =0; i<multi; ++i){
                    board->levelDown();
                }
            } else if (command == "norandom"){
                std::string fname;
                cin >> fname;
                if(board->getLevel() > 2){
                    board->norandom(fname);
                    board->render();
                }
            } else if (command == "random"){
                if(board->getLevel() > 2){
                    board->random();
                    board->render();                    
                }                
            } else if (command == "restart"){
                board->restart();
                board2->restart();
                board->render();
            } else if (command == "sequence"){
                std::string fileName;
                cin >> fileName;
                ifstream commands{fileName};
                userFile = true;

            } else if (command == "I"){
                board->changeBlock('i');
                board->render();
            } else if (command == "J"){
                board->changeBlock('j');
                board->render();
            } else if (command == "L"){
                board->changeBlock('l');
                board->render();
            } else if (command == "S"){
                board->changeBlock('s');
                board->render();
            } else if (command == "T"){
                board->changeBlock('t');
                board->render();
            } else if (command == "Z"){
                board->changeBlock('z');
                board->render();
            } else if (command == "O"){
                board->changeBlock('o');
                board->render();
            }
        } else{
            if (command == "drop") {
                int rC = board2->dropBlock();
                board2->newBlock();
                gameContinue = board2->getGameOver();
                if (gameContinue == 0){
                    cout<< "Game Over! :("<<endl;
                    break;
                }
                if(rC >=2){
                    cout<<"Choose a punishment for your opponent?"<<endl;
                    std::string punish;
                    cin >> punish;
                    if (punish == "blind"){
                        board->setBlind();
                    } else if (punish == "heavy"){
                        board->setHeavy();
                    } else if (punish == "force"){
                       cout<<"What block would you like for your opponent?"<<endl; 
                       char blockOpp;
                       cin >> blockOpp;
                       
                       board->changeBlock(blockOpp);
                    }
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
                
            } else if (command == "rename"){
                std::string toRename; 
                cin >> toRename;
                
                std::string cmd;
                cin >> cmd;
                ci.rename(toRename, cmd);

            } else if (command == "levelup") {
                for(int i =0; i<multi; ++i){
                    board2->levelUp();
                }
            } else if (command == "leveldown") {
                for(int i =0; i<multi; ++i){
                    board2->levelDown();
                }
            } else if (command == "norandom"){
                std::string fname;
                cin >> fname;
                if(board2->getLevel() > 2){
                    board2->norandom(fname);
                    board2->render();
                }
            } else if (command == "random"){
                if(board2->getLevel() > 2){
                    board2->random();
                    board2->render();
                }                
            } else if (command == "restart"){
                board->restart();
                board2->restart();
                board2->render();
                continue;
            } else if (command == "I"){
                board2->changeBlock('i');
                board2->render();
            } else if (command == "J"){
                board2->changeBlock('j');
                board2->render();
            } else if (command == "L"){
                board2->changeBlock('l');
                board2->render();
            } else if (command == "S"){
                board2->changeBlock('s');
                board2->render();
            } else if (command == "T"){
                board2->changeBlock('t');
                board2->render();
            } else if (command == "Z"){
                board2->changeBlock('z');
                board2->render();
            } else if (command == "O"){
                board2->changeBlock('o');
                board2->render();
            }           
        }

    }*/

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
    //delete board;
    //delete obs;
}
