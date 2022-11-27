#ifndef TEXTOBS_H
#define TEXTOBS_H
#include "observer.h"
#include "gameboard.h"

class TextObserver: public Observer {
    public:
        GameBoard* iObserve;
        int top, bottom, left, right;
    public:
        TextObserver(GameBoard* iObserve, int top, int bottom, int left, int right);
        void notify() override;
        ~TextObserver();
};

#endif
