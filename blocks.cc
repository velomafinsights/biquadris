#include "blocks.h"

BlockS::BlockS(){
    vector<vector<int>> s0 = {{2,1}, {2,2}, {3,0}, {3,1}};
    vector<vector<int>> s1 = {{1,0}, {2,0}, {2,1}, {3,1}};
    orientation = {s0, s1, s0, s1};
    // create 2D vectors
    // add to 3D vec orientation
   //
    x = 0;
    y = 0;
    c = 's';
    i = 0;
}

char BlockS::getBlockType(){
    return c;
}

void BlockS::rotateClockWise(){
    if (i == 3) i = 0;
    else{
        ++i;
    }
}

void BlockS::rotateCounterClockWise(){
    if (i == 0) i = 3;
    else{
        --i;
    }
}

void BlockS::moveBlockRight(){
    // create a check for out of range
    // create a check for current orientation and max width
    if (i == 0 || i == 2){
        if (x < 8){
            ++x;
        }
    }
    else{
        if (x < 9){
            ++x;
        }
    }
}

void BlockS::moveBlockLeft(){
    if (x > 0){
        --x;
    }
}

void BlockS::moveBlockDown(){
    ++y;
}

std::vector<std::vector<int>> BlockS::getStructure(){
    return orientation[i];
}

int BlockS::getX() {
    return x;
}

int BlockS::getY() {
    return y;
}

