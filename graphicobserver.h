#ifndef GRAPHICOBSERVER_H
#define GRAPHICOBSERVER_H
#include "subject.h"
#include "observer.h"
#include "window.h"
#include "gameboard.h"
#include <map>
#include <string>

using namespace std;

class GraphicObserver: public Observer {
    Xwindow *win;
    GameBoard *p1;
    GameBoard *p2;
    //int top, bottom, left, right;  
    int wWidth, wHeight;  // window width and height when calling new Xwindow{width, height}
    int blockWidth;  // width (and height) of a single square block 
    int pieceWidth; // size of a piece = 2 less than blockWidth
    int gHeight, gWidth;  // individual game height
    int p1MarginLeft, p2MarginLeft, p2MarginRight;     // margin-left of the two boards
    int marginBtw;  // space between both boards
    int marginTop;  // general margin-top for spacing the gameboards from the top
    // colourMap: sets a colour for each character on GameBoard
    map<char, int>colourMap {{'.', 0}, {'?', 1}, {'i', 2}, {'j', 3}, {'l', 4}, 
                            {'o', 4}, {'s', 2}, {'z', 3}, {'t', 4}, {'*', 2}};
    public:
        GraphicObserver(int blockWidth, GameBoard *p1, GameBoard *p2);
        void startGame();
        void notify() override;
        ~GraphicObserver();
};

#endif
