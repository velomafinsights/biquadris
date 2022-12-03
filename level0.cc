#include "level0.h"
#include <string>
#include "block.h"
#include "s.h"
#include "z.h"
#include "j.h"
#include "l.h"
#include "i.h"
#include "o.h"
#include "t.h"


using namespace std;

// init ctor
Level0::Level0(std::string seqOneSource): seqOneSource{seqOneSource}, seqOneLength{0} { 
    setBlockQueue();
}

void Level0::setBlockQueue(){
    // 
    seqOne.open(seqOneSource);
    string blockQItem;
    while(seqOne >> blockQItem){
        blockQueue.emplace_back(blockQItem);
        ++seqOneLength;
    }
}

Block* Level0::getBlock(size_t i){
    size_t pos = (i-1) % seqOneLength;
    Block* nB;
    if (blockQueue[pos] == "S"){
        nB = new blockS();
    }
    else if (blockQueue[pos] == "I"){
        nB = new blockI();
    }
    else if (blockQueue[pos] == "J"){
        nB = new blockJ();
    }
    else if (blockQueue[pos] == "L"){
        nB = new blockL();
    }
    else if (blockQueue[pos] == "Z"){
        nB = new blockZ();
    }
    else if (blockQueue[pos] == "O"){
        nB = new blockO();
    }
    else if (blockQueue[pos] == "T"){
        nB = new blockT();
    }
    else {
        nB = nullptr;
    }
    return nB;
}


size_t Level0::getLevel() {
    return 0;
}

