#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include <vector>
#include <string>


// Block implements 

class Block {
    
    char orientation; // (1, 2, 3, 4) tells the degree of rotation (0, 90, 180, 270)

    // since rotation happens about the top left corner of block, x and y represent bottom left?
    size_t x;
    size_t y;

    vector<vector<string>> structure;

 public:
};
#endif
