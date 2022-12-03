#include "o.h"

blockO::blockO(){
    vector<vector<int>> s0 = {{2,0}, {2,1}, {3,0}, {3,1}};
    orientation = {s0, s0, s0, s0};
    blockWidth = {2, 2};
    vector<vector<int>> b0 = {{3,0}, {3,1}};
    bottomMost = {b0, b0, b0, b0};

    x = 0;
    y = 0;
    i = 0;       

}
