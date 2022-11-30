#include "level3.h"

Level3::Level3(bool queueFromFile, std::string seqOneSource): 
    seqOneSource{seqOneSource}, queueFromFile{queueFromFile}, seqOneLength{0} {
        setBlockQueue();
    }


void Level3::setBlockQueue(){
    seqOne.open(seqOneSource);
    string blockQItem;
    while(seqOne >> blockQItem){
        blockQueue.emplace_back(blockQItem);
        ++seqOneLength;
    }
}

Block* Level3::getBlock(size_t i){
    Block* nB = nullptr;
    if (queueFromFile){
        size_t pos = (i-1) % seqOneLength;
        if (blockQueue[pos] == "S") nB = new Block('s');
        else if (blockQueue[pos] == "I") nB = new Block('i');
        else if (blockQueue[pos] == "J") nB = new Block('j'); 
        else if (blockQueue[pos] == "L") nB = new Block('l'); 
        else if (blockQueue[pos] == "Z") nB = new Block('z'); 
        else if (blockQueue[pos] == "O") nB = new Block('o'); 
        else if (blockQueue[pos] == "T") nB = new Block('t');
    }
    else{
        int v1 = rand() % 9 + 1;
        if (v1 == 1 || v1 == 2) nB = new Block('s'); 
        else if (v1 == 3) nB = new Block('i'); 
        else if (v1 == 4) nB = new Block('j'); 
        else if (v1 == 5) nB = new Block('l'); 
        else if (v1 == 6) nB = new Block('o'); 
        else if (v1 == 7) nB = new Block('t'); 
        else if (v1 == 8 || v1 == 9) nB = new Block('z');
    }
    return nB;
}

size_t Level3::getLevel(){
    return 3;
}

