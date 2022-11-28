#include "textObserver.h"
#include <vector>
#include <iostream>

TextObserver::TextObserver(GameBoard* iObserve, int top, int bottom, int left, int right): iObserve{iObserve}, top{top}, bottom{bottom}, left{left}, right{right} {
    iObserve->attach(this);
}

void TextObserver::notify() {
    bool blind = iObserve->getBlind();
    std::vector<std::vector <char>> board = iObserve->getState();
    for (int i = 0; i < 18; i++) {
        if (i < 10) std::cout << i << "      ";
        else std::cout << i << "     ";
        for (int j = 0; j < 11; j++) {
            if (blind && i>=3 && i<=12 && j>=3 && j<=9) {
                        std::cout<< '?' << " "; 
            } else {
            std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

TextObserver::~TextObserver() {
    iObserve->detach(this);
}
