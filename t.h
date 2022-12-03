#ifndef _BLOCKT__
#define _BLOCKT__
#include "block.h"

class blockT: public Block {
    public: 
        blockT();
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
        char c = 't';

        // current index in orientation vector
        size_t i;

};

#endif