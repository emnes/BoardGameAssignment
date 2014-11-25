//
//  GameBoard.h
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

#ifndef __src__GameBoard__
#define __src__GameBoard__


#include <map>
#include <string>
#include <array>
#include "Tile.h"
#include "TileFactory.h"

using namespace std;
enum Move{TOP, DOWN, LEFT, RIGHT}; // Only four possible neighbours: up, down, left, right


template<typename T, typename J, unsigned int ROW, unsigned int COL>class GameBoard {
	
private:
	array<array<T, ROW>, COL> board;								// Hold all the tiles for the current game
	map<string, J*> players;										// Key : Player's Name, Element : Pointer to Player object
	map<string, Tile<Player>*> playersCurrentTile;					// Keeps a reference of a player's current tile.
	TileFactory<J>* tileFactory;		 							// Singleton instance of TileFactory.

public:
	GameBoard(string *playerNames, int playerNamesSize);			// ctor
	void add(const T& tile, int row, int col);						// Adds a tile to position row,col to the board
	const T& getTile(int row, int col) const;						// Returns the tile located at position row,col of the board
	void getCoordinate(const T &tile, int *row, int *col) const;   	// Returns the coordinates of a tile
    void addPlayer(string playerName); 								// Adds a player to the game   
	//TODO: implement      void setPlayer(J player);


	J getPlayer(const std::string& playerName);						// Get a Player object by player name
	const T& getTile(const std::string& playerName) const;			// Get the current tile of a Player by player name
	std::vector<J> getPlayers(const T& tile) const;					// Get all the players located at a tile
	
	//TODO: implement      const T& move(Enum Move move, const std::string& playerName );
    // getTile of player. remove that player from that tile.
    // get coordinates of tile. if move up then increment column
    // move down decrement  column
    // move right increment row, move left decrement row
};

#endif /* defined(__BoardGame__GameBoard__) */
