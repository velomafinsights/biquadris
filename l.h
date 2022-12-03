#ifndef _BLOCKL__
#define _BLOCKL__
#include "block.h"

class blockL: public Block {
    public: 
        blockL();
        std::vector<std::vector<std::vector<int>>> orientation;
        std::vector<int> blockWidth;
        std::vector<std::vector<std::vector<int>>> bottomMost;
        std::vector<std::vector<std::vector<int>>> leftMost;
        std::vector<std::vector<std::vector<int>>> rightMost;

        // movement of blocks not determined yet
        size_t x;
        size_t y;

        size_t currLevel;
        // character the block is made up of: I, J, L, O, S, Z, T
        char c;

        // current index in orientation vector
        size_t i;

};

#endif
