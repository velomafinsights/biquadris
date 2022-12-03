#include "star.h"

blockStar::blockStar(){
    vector<vector<int>> s0 = {{0,5}};
    orientation = {s0, s0, s0, s0};
    blockWidth = {1, 1};
    bottomMost = {s0, s0, s0, s0};

    x = 0;
    y = 0;
    i = 0;       

}

void blockStar::moveBlockDown(){
    orientation[i][0][0] += 1;
}

int blockStar::blockRemoved(){
    return 4;
}

void blockStar::rowCleared(int row){
 if (blockCleared || orientation[i][0][0] == row) {
            orientation[i].clear();
        }
}
