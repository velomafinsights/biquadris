#ifndef _BLOCKS_H_
#define _BLOCKS_H_
#include <iostream>
#include <vector>
#include <string>
#include "block.h"

class BlockS : public Block{
    /*//std::vector<std::vector<std::vector<int>>> sOrientation;
    
    // movement of blocks not determined yet
    size_t x;
    size_t y;
    size_t i;

    // current orientation (coordinates) of the 4 pieces of the block 
    std::vector<std::vector<int>> structure;*/


    public:
        BlockS();
        std::vector<std::vector<int>> getStructure() override;
        char getBlockType() override;
        void rotateClockWise() override;  // changes the 2D vector structure and size_t i equal to new index
        void rotateCounterClockWise() override;
        void moveBlockRight() override;
        void moveBlockLeft() override;
        void moveBlockDown() override;
        int getX() override;
        int getY() override;
};

#endif
