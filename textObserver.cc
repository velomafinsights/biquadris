#include "textObserver.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

TextObserver::TextObserver(GameBoard* iObserve1, GameBoard* iObserve2, int top, int bottom, int left, int right): iObserve1{iObserve1}, iObserve2{iObserve2}, top{top}, bottom{bottom}, left{left}, right{right} {
    iObserve1->attach(this);
    iObserve2->attach(this);
}

void TextObserver::notify() {
    bool blind1 = iObserve1->getBlind();
    bool blind2 = iObserve2->getBlind();
    std::vector<std::vector <char>> boardP1 = iObserve1->getState();
    std::vector<std::vector <char>> boardP2 = iObserve2->getState();

    //Player 1's Score and Level
    cout<<"Level:    "<<iObserve1->getLevel();
    cout<<"Score:"<<setfill(' ')<<setw(4)<<iObserve1->getScore();
    cout<<"-----------";

    cout<<"               ";

    //Player 2's Score and Level
    cout<<"Level:    "<<iObserve2->getLevel();
    cout<<"Score:"<<setfill(' ')<<setw(4)<<iObserve2->getScore();
    cout<<"-----------";

    std::cout << std::endl;
    for (int i = 0; i < 18; i++) {
        if (i < 10) std::cout << i << "      ";
        else std::cout << i << "     ";

        //Outputing Player 1's GameBoard
        for (int j = 0; j < 11; j++) {
            if (blind1 && i>=3 && i<=12 && j>=3 && j<=9) {
                        std::cout<< '?' << " "; 
            } else {
                std::cout << boardP1[i][j] << " ";
            }
        }
        cout<<"               ";

        //Outputing Player 2's GameBoard
        for (int j = 0; j < 11; j++) {
            if (blind2 && i>=3 && i<=12 && j>=3 && j<=9) {
                        std::cout<< '?' << " "; 
            } else {
                std::cout << boardP2[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    cout<<"-----------";
    cout<<"               ";
    cout<<"-----------";
    std::cout << std::endl;

    cout<<"Next:      ";
    cout<<"               ";
    cout<<"Next:      ";
    std::cout << std::endl;

    std::cout << std::endl;
}

TextObserver::~TextObserver() {
    iObserve1->detach(this);
    iObserve2->detach(this);
}
