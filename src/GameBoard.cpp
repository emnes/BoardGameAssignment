//
//  GameBoard.cpp
//  BoardGame
//
//  Parameterized class (template) for the game board which acts as a grid builder.
//  The tiles of the grid are of type T and hold one or more players of type J.
//  Game board has N players.
//
//  Tiles are indentified by row and col. Players identified by name.
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

/*
 * Adds referenced tile to board.
 * Parameters: reference to tile, row and column of where to place tile.
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
void GameBoard<T, J, N, ROW, COL>::add(const T& tile, int row, int col)
{
    if (!board[row][col])
        throw std::out_of_range("Tile not added. Board does not contain specified coordinates.");
    else
        board[row][col] = tile;
}

/*
 * Returns tile
 * Parameters: Row and column of where tile might be located
 * Return: Tile of type T
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
const T& GameBoard<T, J, N, ROW, COL>::getTile(int row, int col) const
{
    if (!board[row][col])
        throw std::out_of_range("Tile does not exist.");
    return board[row][col];
}

/*
 * Returns player specificed with name
 * Parameters: name of player
 * Return: Player of type J
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
J GameBoard<T, J, N, ROW, COL>::getPlayer(const std::string& playerName)
{
	if(!players.at(playerName))
        throw std::out_of_range("Player does not exist.");
    return *(players.at(playerName));
}

template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
const T& GameBoard<T, J, N, ROW, COL>::getTile(const std::string& playerName) const
{
    if(!players.at(playerName))
        throw std::out_of_range("Player does not exist.");
    for (T tile : board) {
        if (std::find(tile.getPlayers().begin(), tile.getPlayers().end(), playerName)) {
            return tile; // or should it be *tile?
        }
    }
}
/*
 * Returns all players on a specific tile
 * Parameters: tile
 * Return: vector of players
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
std::vector<J> GameBoard<T, J, N, ROW, COL>::getPlayers(const T& tile) const{
    if (tile.noPlayers())
        throw std::out_of_range("Tile has no players.");
    
	return tile.getPlayers();
}

/* Do we need this? <------------------*
 * Adds player.
 * Parameters: name of player
 *
 */
template<typename T, typename J, unsigned N, size_t ROW, size_t COL>
void GameBoard<T, J, N, ROW, COL>::addPlayer(string playerName){
    players.emplace(playerName, new Player(playerName));
}