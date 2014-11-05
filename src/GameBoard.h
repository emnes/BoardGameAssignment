//
//  GameBoard.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__GameBoard__
#define __src__GameBoard__


#include <map>
#include <string>
#include <array>
#include "Tile.h"

using namespace std;
enum Move{TOP, DOWN, LEFT, RIGHT};

template<typename T, typename J, unsigned N, size_t ROW, size_t COL> class GameBoard {
	
	private:
		array<array<T, ROW>, COL> board;
		map<string, J*> players;
		
	public:
		GameBoard();
		void add(const T& tile, int row, int col);
		const T& getTile(int row, int col) const;
		//TODO: implement      void getCoordinate(const T &tile, int *row, int *col) const;
		//TODO: implement      void setPlayer(J player);
		J getPlayer(const std::string& playerName);
		//TODO: implement      const T& getTile(const std::string& playerName) const;
		std::vector<J> getPlayers(const T& tile) const;
		//TODO: implement      const T& move(Enum Move move, const std::string& playerName );
		void addPlayer(string playerName);
		
};

#endif /* defined(__BoardGame__GameBoard__) */
