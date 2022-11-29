#include "level1.h"
#include <string>
#include "block.h"
#include <cstdlib>


Level1::Level1(){    
}

Block* Level1::getBlock(size_t i){
    int v1 = rand() % 12 + 1;
    Block* nB;
    if (v1 == 1){
        nB = new Block('s');
    }
    else if (v1 == 2 || v1 == 3){
        nB = new Block('i');
    }
    else if (v1 == 4 || v1 == 5){
        nB = new Block('j');
    }
    else if (v1 == 6 || v1 == 7){
        nB = new Block('l');
    }
    else if (v1 == 8 || v1 == 9){
        nB = new Block('o');
    }
    else if (v1 == 10 || v1 == 11){
        nB = new Block('t');
    }
    else if (v1 == 12){
        nB = new Block('z');
    }
    else {
        nB = nullptr;
    }
    return nB;
}

size_t Level1::getLevel(){
    return 1;
}

