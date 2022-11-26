#include "level0.h"
#include <string>

// init ctor
Level0::Level0(std::string seqOneSource): seqOneSource{seqOneSource}, seqOneLength{0} { }

void Level0::setBlockQueue(){
    seqOne.open("sequence1.txt");
    while(seqOne >> seqOneSource){
        // emplaceback the seqOneSource onto blockQueue
        blockQueue.emplace_back(seqOneSource);
        ++seqOneLength;
    }
}

// iterate through ifstream to get the block string
vector<vector<int>> Level0::getBlock(size_t i){
    // we want to iterate 
    size_t pos = i % seqOneLength;
    // now we get whatever string there is at that index
    if (blockQueue[pos] == "S"){
        vector<vector<int>> SBlock = {{1,1}, {1,2}, {2,0}, {2,1}};
        return SBlock;
        // return new IBlock{};
    }
}


size_t Level0::getLevel() {
    return 0;
}



