#include "graphicobserver.h"
#include "window.h"
#include <iostream>
#include <sstream>


using namespace std;

GraphicObserver::GraphicObserver(int blockWidth, GameBoard *p1, GameBoard *p2):
    blockWidth{blockWidth}, p1{p1}, p2{p2}{
        gHeight = blockWidth * 18;
        gWidth = blockWidth * 11;
        pieceWidth = blockWidth - 2;
        p1MarginLeft = blockWidth * 6;
        marginBtw = blockWidth * 8;
        marginTop = blockWidth * 8;
        p2MarginLeft = p1MarginLeft + gWidth + marginBtw;
        p2MarginRight = blockWidth * 6;
        wWidth = (2 * gWidth) + (2 * p1MarginLeft) + marginBtw;
        wHeight = gHeight + 2 *  marginBtw;
        p1->attach(this);
        p2->attach(this);
        win = new Xwindow{wWidth, wHeight};
        startGame();
    }

/*
GraphicObserver::GraphicObserver(int wWidth, int wHeight, int blockWidth,
                    int p1MarginLeft, int p2MarginLeft, int marginBtw, GameBoard *p1, GameBoard *p2):
    wWidth{wWidth}, wHeight{wHeight}, blockWidth{blockWidth}, gHeight{gHeight}, gWidth{gWidth}, 
    p1MarginLeft{p1MarginLeft}, p2MarginLeft{p2MarginLeft}, marginBtw{marginBtw}, p1{p1}, p2{p2} 
    {
        p1->attach(this);
        p2->attach(this);
        win = new Xwindow{wWidth, wHeight};
        startGame();
    }*/

void GraphicObserver::startGame(){
    std::string stuff(38, ' ');
    win->drawString(p1MarginLeft + gWidth + 80, marginTop/2 - 10, "BIQUADRIS");

    win->drawString(p1MarginLeft, marginTop/2 + 50 , "Level:" + stuff + "0");
    win->drawString(p2MarginLeft, marginTop/2 + 50, "Level:" + stuff + "0");
    
    win->drawString(p1MarginLeft, marginTop/2 + 75 , "Score:" + stuff + "0");
    win->drawString(p2MarginLeft, marginTop/2 + 75, "Score:" + stuff + "0");

    // change back to 1
    win->fillRectangle(p1MarginLeft - 2, marginTop, gWidth + 2, gHeight + 2, 1);
    win->fillRectangle(p2MarginLeft - 2, marginTop, gWidth + 2, gHeight + 2, 1);

    win->drawString(p1MarginLeft, marginTop + gHeight + 40, "Next: ");
    win->drawString(p2MarginLeft, marginTop + gHeight + 40, "Next: ");
    /*
    for (int z = 0; z < 18; ++z){
        for (int i = 0; i < 11; ++i){
            int y = marginTop + z * blockWidth + 2;
            int x = p2MarginLeft + i * blockWidth;
            win->fillRectangle(x, y, pieceWidth, pieceWidth, 3);
        }
    }*/
    //void drawString(int x, int y, std::string msg);
    // fillRectangle(int x, int y, int width, int height, int colour)
}

void GraphicObserver::notify(){

    std::vector<std::vector <char>> boardP1 = p1->getState();
    std::vector<std::vector <char>> boardP2 = p2->getState();
    bool blind1 = p1->getBlind();
    bool blind2 = p2->getBlind();

    for (int i = 0; i < 18; ++i){        
        int y = marginTop + i * blockWidth + 2;
        //Outputing Player 1's GameBoard
        for (int j = 0; j < 11; ++j){
            int x = p1MarginLeft + j * blockWidth;
            if (blind1 && i >= 3 && i <= 12 && j >= 3 && j <= 9){
                win->fillRectangle(x, y, pieceWidth, pieceWidth, 1); // changed from 0
            }
            else{
                win->fillRectangle(x, y, pieceWidth, pieceWidth, colourMap[boardP1[i][j]]);
            }
        }
    
         //Outputing Player 2's GameBoard
         for (int k = 0; k < 11; ++k) {
             int x = p2MarginLeft + k * blockWidth;
             if (blind2 && i>=3 && i<=12 && k>=3 && k<=9){
                win->fillRectangle(x, y, pieceWidth, pieceWidth, 1); // changed from 0
             }
             else{
                 win->fillRectangle(x, y, pieceWidth, pieceWidth, colourMap[boardP2[i][k]]);
             }
         }
    }
    std::stringstream p1L;
    std::stringstream p2L;
    std::stringstream p1S;
    std::stringstream p2S;
    std::string stuff(38, ' ');
    std::string erasedraw(39, ' ');
    p1L << p1->getLevel();
    std::string p1Level = p1L.str();

    int clearP1L = p1MarginLeft + 10 * blockWidth + 10;
    win->fillRectangle(clearP1L, marginTop/2 + 30, pieceWidth, pieceWidth, 0);

    win->drawString(p1MarginLeft, marginTop/2 + 50 , "Level:" + stuff + p1Level);

    p2L << p2->getLevel();
    std::string p2Level = p2L.str();

    int clearP2L = p2MarginLeft + 10 * blockWidth + 10;
    win->fillRectangle(clearP2L, marginTop/2 + 30, pieceWidth, pieceWidth, 0);

    win->drawString(p2MarginLeft, marginTop/2 + 50, "Level:" + stuff + p2Level);

    p1S << p1->getScore();
    std::string p1Score = p1S.str();

    int clearP1S = p1MarginLeft + 10 * blockWidth + 10;
    win->fillRectangle(clearP1S, marginTop/2 + 55, pieceWidth, pieceWidth, 0);

    win->drawString(p1MarginLeft, marginTop/2 + 75 , "Score:" + stuff + p1Score);

    p2S << p2->getScore();
    std::string p2Score = p2S.str();

    int clearP2S = p2MarginLeft + 10 * blockWidth + 10;
    win->fillRectangle(clearP2S, marginTop/2 + 55, pieceWidth, pieceWidth, 0);

    win->drawString(p2MarginLeft, marginTop/2 + 75, "Score:" + stuff + p2Score);

    // next block:
    std::vector<std::vector <char>> nextBoardP1 = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    Block* p1Next = p1->getNextBlock();
    char p1NextSym = p1Next->getBlockType();
    std::vector<std::vector <int>> p1strcut = p1Next->getStructure();
    int minRow = p1strcut[0][0];
    for (auto it: p1strcut){
        nextBoardP1[it[0] - minRow][it[1]] = p1NextSym;
    }

    std::vector<std::vector <char>> nextBoardP2 = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    Block* p2Next = p2->getNextBlock();
    char p2NextSym = p2Next->getBlockType();
    std::vector<std::vector <int>> p2strcut = p2Next->getStructure();
    minRow = p2strcut[0][0];
    for (auto it: p2Next->getStructure()) {
        nextBoardP2[it[0] - minRow][it[1]] = p2NextSym;
    }

    int p1N_x = p1MarginLeft;
    int p1N_y = marginTop + gHeight + 65;
    //win->fillRectangle(p1N_x, p1N_y, blockWidth * 4, blockWidth * 4, 1);
    for (int i = 0; i < 4; ++i){
        int newX = i * blockWidth; 
        for (int j = 0; j < 4; ++j){
            int newY = j * blockWidth;
            win->fillRectangle(p1N_x + newX, p1N_y + newY, pieceWidth, pieceWidth, colourMap[nextBoardP1[j][i]]);
        }
    }

    int p2N_x = p2MarginLeft;
    int p2N_y = marginTop + gHeight + 65;
    for (int i = 0; i < 4; ++i){
        int newX = i * blockWidth; 
        for (int j = 0; j < 4; ++j){
            int newY = j * blockWidth;
            win->fillRectangle(p2N_x + newX, p2N_y + newY, pieceWidth, pieceWidth, colourMap[nextBoardP2[j][i]]);
        }
    }

}

GraphicObserver::~GraphicObserver(){
    p1->detach(this);
    p2->detach(this);
    delete win;
}

