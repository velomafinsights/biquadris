#include "level0.h"
#include <string>
#include "block.h"

using namespace std;

// init ctor
Level0::Level0(std::string seqOneSource): seqOneSource{seqOneSource}, seqOneLength{0} { 
    setBlockQueue();
}

void Level0::setBlockQueue(){
    // 
    seqOne.open(seqOneSource);
    // seqOneSource change to blockQItem
    while(seqOne >> blockQItem){
        // emplaceback the seqOneSource onto blockQueue
        blockQueue.emplace_back(blockQItem);
        ++seqOneLength;
    }
}

/*
void Level0::printBlockQueue(){
    for (int i = 0; i < seqOneLength; ++i){
        cout<< blockQueue[i] << endl;
    }
}*/

// iterate through ifstream to get the block string
Block* Level0::getBlock(size_t i){
    // we want to iterate 
    size_t pos = (i-1) % seqOneLength;
    Block* nB;
    if (blockQueue[pos] == "S"){
        nB = new Block('s');
    }

    else if (blockQueue[pos] == "I"){
        nB = new Block('i');
    }

    else if (blockQueue[pos] == "J"){
        nB = new Block('j');
    }

    else if (blockQueue[pos] == "L"){
        nB = new Block('l');
    }

    else if (blockQueue[pos] == "Z"){
        nB = new Block('z');
    }

    else if (blockQueue[pos] == "O"){
        nB = new Block('o');
    }

    else if (blockQueue[pos] == "T"){
        nB = new Block('t');
    }
    else {
        nB = nullptr;
    }
    return nB;
}


size_t Level0::getLevel() {
    return 0;
}




