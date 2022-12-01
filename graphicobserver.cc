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

    win->fillRectangle(p1MarginLeft, marginTop, gWidth, gHeight, 1);
    win->fillRectangle(p2MarginLeft, marginTop, gWidth, gHeight, 1);

    win->drawString(p1MarginLeft, marginTop + gHeight + 50, "Next: ");
    win->drawString(p2MarginLeft, marginTop + gHeight + 50, "Next: ");

    /*
    win->fillRectangle(p1MarginLeft + 50, marginTop + gHeight + 50, pieceWidth, pieceWidth, colourMap[boardP1[i][j]]);
    win->fillRectangle(p2MarginLeft + 50, marginTop + gHeight + 50, pieceWidth, pieceWidth, colourMap[boardP2[i][j]]);
*/
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
                win->fillRectangle(x, y, pieceWidth, pieceWidth, 0);
            }
            else{
                // translation from character to int colour
                win->fillRectangle(x, y, pieceWidth, pieceWidth, colourMap[boardP1[i][j]]);
            }
        }

         //Outputing Player 2's GameBoard
         for (int k = 0; k < 11; ++k) {
             int x = p2MarginLeft + k * blockWidth;
             if (blind2 && i>=3 && i<=12 && k>=3 && k<=9){
                win->fillRectangle(x, y, pieceWidth, pieceWidth, 0);
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
    p1L << p1->getLevel();
    std::string p1Level = p1L.str();
    win->drawString(p1MarginLeft, marginTop/2 + 50 , "Level:" + stuff + p1Level);
    p2L << p2->getLevel();
    std::string p2Level = p2L.str();
    win->drawString(p2MarginLeft, marginTop/2 + 50, "Level:" + stuff + p2Level);
    p1S << p1->getScore();
    std::string p1Score = p1S.str();
    win->drawString(p1MarginLeft, marginTop/2 + 75 , "Score:" + stuff + p1Score);
    p2S << p2->getScore();
    std::string p2Score = p2S.str();
    win->drawString(p2MarginLeft, marginTop/2 + 75, "Score:" + stuff + p2Score);

}

GraphicObserver::~GraphicObserver(){
    p1->detach(this);
    p2->detach(this);
    delete win;
}

