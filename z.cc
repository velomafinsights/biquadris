#include "z.h"

blockZ::blockZ(){
    vector<vector<int>> s0 = {{2,0}, {2,1}, {3,1}, {3,2}};
    vector<vector<int>> s1 = {{1,1}, {2,0}, {2,1}, {3,0}};
    orientation = {s0, s1, s0, s1};

    blockWidth = {2, 2};

    vector<vector<int>> b0 = {{2,0}, {3,1}, {3,2}};
    vector<vector<int>> b1 = {{2,1}, {3,0}};
    bottomMost = {b0, b1, b0, b1};

    c = 'z';
    x = 0;
    y = 0;
    i = 0;       

}
