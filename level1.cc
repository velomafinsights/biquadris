#include "level1.h"
#include <string>
#include "block.h"
#include <cstdlib>
#include "s.h"
#include "z.h"
#include "j.h"
#include "l.h"
#include "i.h"
#include "o.h"
#include "t.h"


Level1::Level1(){    
}

Block* Level1::getBlock(size_t i){
    int v1 = rand() % 12 + 1;
    Block* nB;
    if (v1 == 1){
        nB = new blockS();
    }
    else if (v1 == 2 || v1 == 3){
        nB = new blockI();
    }
    else if (v1 == 4 || v1 == 5){
        nB = new blockJ();
    }
    else if (v1 == 6 || v1 == 7){
        nB = new blockL();
    }
    else if (v1 == 8 || v1 == 9){
        nB = new blockO();
    }
    else if (v1 == 10 || v1 == 11){
        nB = new blockT();
    }
    else if (v1 == 12){
        nB = new blockZ();
    }
    else {
        nB = nullptr;
    }
    return nB;
}

size_t Level1::getLevel(){
    return 1;
}

