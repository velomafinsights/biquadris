#include "level2.h"

Block* Level2::getBlock(size_t i){
    int v1 = rand() % 1 + 7;
    Block* nB;
    if (v1 == 1){
        nB = new Block('s');
    }
    else if (v1 == 2){
        nB = new Block('i');
    }
    else if (v1 == 3){
        nB = new Block('j');
    }
    else if (v1 == 4){
        nB = new Block('l');
    }
    else if (v1 == 5){
        nB = new Block('o');
    }
    else if (v1 == 6){
        nB = new Block('t');
    }
    else if (v1 == 7){
        nB = new Block('z');
    }
    else {
        nB = nullptr;
    }
    return nB;
}

size_t Level2::getLevel(){
    return 2;
}

