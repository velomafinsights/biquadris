#include "textObserver.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "block.h"

TextObserver::TextObserver(GameBoard* iObserve, GameBoard* iObserve2, int top, int bottom, int left, int right): iObserve1{iObserve}, iObserve2{iObserve2},top{top}, bottom{bottom}, left{left}, right{right} {
    iObserve1->attach(this);
    iObserve2->attach(this);
}

void TextObserver::notify() {
    bool blind1 = iObserve1->getBlind();
    bool blind2 = iObserve2->getBlind();

    std::vector<std::vector <char>> boardP1 = iObserve1->getState();
    std::vector<std::vector <char>> boardP2 = iObserve2->getState();
    cout<<endl;
    cout<<endl;

    cout<<"  Level:    "<<iObserve1->getLevel();
    cout<<"                                   ";
    cout<<"Level:    "<<iObserve2->getLevel();
    std::cout << std::endl;

    cout<<"  Score:"<<setfill(' ')<<setw(5)<<iObserve1->getScore();
    cout<<"                                   ";
    cout<<"Score:"<<setfill(' ')<<setw(5)<<iObserve2->getScore();
    std::cout<<std::endl;
    std::cout<<std::endl;
    

    cout<<" - - - - - - - - - - - - -";
    cout<<"                      ";
    cout<<"- - - - - - - - - - - - -";
    std::cout << std::endl;

    for (int i = 0; i < 18; ++i) {
        cout<<"|  ";
        //Outputing Player 1's GameBoard
        for (int j = 0; j < 11; ++j) {
            if (blind1 && i>=3 && i<=12 && j>=3 && j<=9) {
                        std::cout<< '?' << " "; 
            } else {
                std::cout << boardP1[i][j] << " ";
            }
        }
        cout<<" |";
        cout<<"                    ";
        cout<<"|  ";
        //Outputing Player 2's GameBoard
        for (int k = 0; k < 11; ++k) {
            if (blind2 && i>=3 && i<=12 && k>=3 && k<=9) {
                        std::cout<< '?' << " "; 
            } else {
                std::cout << boardP2[i][k] << " ";
            }
        }
        cout<<" |";
        std::cout << std::endl;
    }

    cout<<" - - - - - - - - - - - - -";
    cout<<"                      ";
    cout<<"- - - - - - - - - - - - -";
    std::cout << std::endl;

    cout<<endl;
    cout<<" Next:      ";
    cout<<"                                   ";
    cout<<" Next:      ";
    std::cout << std::endl;

    std::vector<std::vector <char>> nextBoardP1 = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    Block* p1Next = iObserve1->getNextBlock();
    char p1NextSym = p1Next->getBlockType();
    std::vector<std::vector <int>> p1strcut = p1Next->getStructure();
    int minRow = p1strcut[0][0];
    for (auto it: p1strcut) {
        nextBoardP1[it[0] - minRow][it[1]] = p1NextSym;
    }
    std::vector<std::vector <char>> nextBoardP2 = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    Block* p2Next = iObserve2->getNextBlock();
    char p2NextSym = p2Next->getBlockType();
    std::vector<std::vector <int>> p2strcut = p2Next->getStructure();
    minRow = p2strcut[0][0];
    for (auto it: p2Next->getStructure()) {
        nextBoardP2[it[0] - minRow][it[1]] = p2NextSym;
    }

    for (int i = 0; i < 4; i++) {
        cout<<" ";
        for (int j = 0; j < 4; j++) {
            std::cout << nextBoardP1[i][j]<<" ";
        }
        
        cout<<"                                       ";
        for (int k = 0; k < 4; k++) {
            std::cout << nextBoardP2[i][k]<<" ";
        }
        std::cout << std::endl;
    }
}

TextObserver::~TextObserver() {
    iObserve1->detach(this);
    iObserve2->detach(this);
}

