//
//  GameBoard.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "GameBoard.h"

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
const T& GameBoard<T, J, N, ROW, COL>::getTile(int row, int col) const{
	return (board.at(row)).at(col);
}
