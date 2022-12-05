#include "s.h"

blockS::blockS(){
    vector<vector<int>> s0 = {{2,1}, {2,2}, {3,0}, {3,1}};
    vector<vector<int>> s1 = {{1,0}, {2,0}, {2,1}, {3,1}};
    orientation = {s0, s1, s0, s1};
    std::cout << "created s block" << std::endl;
    
    blockWidth = {2, 2};

    vector<vector<int>> b0 = {{2,2}, {3,0}, {3,1}};
    vector<vector<int>> b1 = {{2,0}, {3,1}};
    bottomMost = {b0, b1, b0, b1};

    c = 's';
    x = 0;
    y = 0;
    i = 0;       

}
