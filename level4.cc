#include "level4.h"
#include "s.h"
#include "z.h"
#include "j.h"
#include "l.h"
#include "i.h"
#include "o.h"
#include "t.h"

Level4::Level4(bool queueFromFile, std::string seqOneSource): 
    seqOneSource{seqOneSource}, queueFromFile{queueFromFile}, seqOneLength{0} {
        setBlockQueue();
    }


void Level4::setBlockQueue(){
    seqOne.open(seqOneSource);
    string blockQItem;
    while(seqOne >> blockQItem){
        blockQueue.emplace_back(blockQItem);
        ++seqOneLength;
    }
}

Block* Level4::getBlock(size_t i){
    Block* nB = nullptr;
    if (queueFromFile){
        size_t pos = (i-1) % seqOneLength;
        if (blockQueue[pos] == "S") nB = new blockS();
        else if (blockQueue[pos] == "I") nB = new blockI();
        else if (blockQueue[pos] == "J") nB = new blockJ(); 
        else if (blockQueue[pos] == "L") nB = new blockL(); 
        else if (blockQueue[pos] == "Z") nB = new blockZ(); 
        else if (blockQueue[pos] == "O") nB = new blockO(); 
        else if (blockQueue[pos] == "T") nB = new blockT();
    }
    else{
        int v1 = rand() % 9 + 1;
        if (v1 == 1 || v1 == 2) nB = new blockS(); 
        else if (v1 == 3) nB = new blockI(); 
        else if (v1 == 4) nB = new blockJ(); 
        else if (v1 == 5) nB = new blockL(); 
        else if (v1 == 6) nB = new blockO(); 
        else if (v1 == 7) nB = new blockT(); 
        else if (v1 == 8 || v1 == 9) nB = new blockZ();
    }
    return nB;
}

size_t Level4::getLevel(){
    return 4;
}

