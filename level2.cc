#include "level2.h"
#include "s.h"
#include "z.h"
#include "j.h"
#include "l.h"
#include "i.h"
#include "o.h"
#include "t.h"

Block* Level2::getBlock(size_t i){
    int v1 = rand() % 7 + 1;
    Block* nB;
    if (v1 == 1){
        nB = new blockS();
    }
    else if (v1 == 2){
        nB = new blockI();
    }
    else if (v1 == 3){
        nB = new blockJ();
    }
    else if (v1 == 4){
        nB = new blockL();
    }
    else if (v1 == 5){
        nB = new blockO();
    }
    else if (v1 == 6){
        nB = new blockT();
    }
    else if (v1 == 7){
        nB = new blockZ();
    }
    else {
        nB = nullptr;
        cout<<"rand out of range"<<endl;
    }
    return nB;
}

size_t Level2::getLevel(){
    return 2;
}

