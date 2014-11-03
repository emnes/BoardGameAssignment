//
//  GameBoard.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__GameBoard__
#define __src__GameBoard__

#include <array>
#include "Tile.h"

using namespace std;


template<typename T, typename J, unsigned N, size_t, ROW, size_t COL> class GameBoard {
	
	private:
		array<array<T, ROW>, COL> board;
		
};

#endif /* defined(__BoardGame__GameBoard__) */
