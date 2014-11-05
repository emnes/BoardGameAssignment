//
//  GameBoard.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "GameBoard.h"

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
GameBoard<T, J, N, ROW, COL>::GameBoard(){
	
	// Create the board
	board.resize(ROW);
  	for (int i = 0; i < ROW; ++i)
    	board[i].resize(COL);
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
const T& GameBoard<T, J, N, ROW, COL>::getTile(int row, int col) const{
	return board[row][col];
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
void GameBoard<T, J, N, ROW, COL>::addPlayer(string playerName){
	players.emplace(playerName, new Player(playerName));
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
J GameBoard<T, J, N, ROW, COL>::getPlayer(const std::string& playerName){
	return *(players.at(playerName));
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
std::vector<J> GameBoard<T, J, N, ROW, COL>::getPlayers(const T& tile) const{
	return tile.getPlayers();
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
void GameBoard<T, J, N, ROW, COL>::add(const T& tile, int row, int col){
	board[row][col] = tile;
}
