#include "level0.h"
#include <string>
#include "block.h"
#include "blocks.h"

using namespace std;

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
Block* Level0::getBlock(size_t i){
    // we want to iterate 
    size_t pos = i % seqOneLength;
    // now we get whatever string there is at that index
    //if (blockQueue[pos] == "S"){
        Block* SBlock = new BlockS();
        return SBlock;
        // return new IBlock{};
    //}

    // else if (blockQueue[pos] == "J"){
    //     vector<vector<int>> JBlock = {{0,0}, {1, 0}, {1,1}, {1,2}};
    //     return IBlock;

    // } else if(blockQueue[pos] == "O") {
    //     vector<vector<int>> OBlock = {{1,1}, {1,2}, {2,1}, {2,2}};
    //     return OBlock;

    // } else if(blockQueue[pos] == "T"){
    //     vector<vector<int>> TBlock = {{1,0}, {1,1}, {1,2}, {2,1}};
    //     return TBlock;

    // } else if(blockQueue[pos] == "L"){
    //     vector<vector<int>> LBlock = {{0,2}, {1, 0}, {1,1}, {1,2}};
    //     return LBlock;

    // } else if(blockQueue[pos] == "I"){
    //     vector<vector<int>> IBlock = {{1,0}, {1,1}, {1,2}, {1,3}};
    //     return IBlock;

    // } else{
    //     vector<vector<int>> ZBlock = {{1,0}, {1,1}, {2,1}, {2,2}};
    //     return ZBlock;
    // }
}


size_t Level0::getLevel() {
    return 0;
}




