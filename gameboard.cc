#include "gameboard.h"

GameBoard::GameBoard(size_t level, size_t currPlayer):
    level{level}, currPlayer{currPlayer} {
        // initialize the 2d Pieces array
        // iterate rows first
        for (int i = 0; i < 18; ++i){
            // create a row of Pieces
            // vector<Piece> singleRow;
            // canvas.emplace_back(singleRow);
            for (int j = 0; j < 11; ++j){
                // for every column j, initialize values to something
                // canvas[i].emplace_back(Piece(i, j));
            }
        }
    }



