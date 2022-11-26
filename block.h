#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Block implements 

class Block {
    // orientation determined by a 3D vector
    vector<vector<vector<int>>> orientation;
    
    // movement of blocks not determined yet
    size_t x;
    size_t y;

    // character the block is made up of: I, J, L, O, S, Z, T
    char c;

    // current index in orientation vector
    size_t i;

    // current orientation (coordinates) of the 4 pieces of the block 
    vector<vector<int>> structure;

 public:
        
};
#endif
