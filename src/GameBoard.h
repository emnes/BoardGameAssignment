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
enum Move{UP, DOWN, LEFT, RIGHT}; // Only four possible neighbours: up, down, left, right


template<typename T, typename J, unsigned int ROW, unsigned int COL>class GameBoard {
	
private:
	array<array<T, ROW>, COL> board;								// Hold all the tiles for the current game
	map<string, J> players;											// Key : Player's Name, Element : Pointer to Player object
	map<string, T> playersCurrentTile;								// Keeps a reference of a player's current tile.
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
	
	void printCurrentLocation(const string& playerName);
	const T& move(Move move, const std::string& playerName );
};

template<typename T, typename J, unsigned int ROW, unsigned int COL>
GameBoard<T, J, ROW, COL>::GameBoard(string *playerNames, int playerNamesSize){
	
	array<float, 14> tileCreationRates = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0}};		// for testing purpose. -P
    tileFactory = TileFactory<J>::Get(ROW*COL);
	
	bool playersAreSetToStartTile = false;
	
    for(int i = 0; i < ROW; i++){
    	for( int j = 0; j < COL; j++){
    		Tile<J>* tileToInsert = tileFactory->next();
    		tileToInsert->setXCoordinate(i);
    		tileToInsert->setYCoordinate(j);
    		
    		// for testing purpose -P
			switch (tileToInsert->getType()){
    			case DESERT:
    				cout << "DESERT tile created" << endl;
    				tileCreationRates.at(DESERT)++;
    				break;
    			case RESTAURANT:
    				cout << "RESTAURANT tile created" << endl;
    				if( !playersAreSetToStartTile ){// NOT FOR TESTING PURPOSE DON'T REMOVE THIS PART*************
    					for (auto i = 0; i < playerNamesSize; i++){
						    addPlayer(*(playerNames + i));							// Add players 
						    playersCurrentTile[*(playerNames + i)] = tileToInsert;	// Set the player to start a Restaurant
						    tileToInsert->addPlayer(*(playerNames + i));			// Adds the player to this Restaurant tile
						}
						playersAreSetToStartTile = true;
					}
    				tileCreationRates.at(RESTAURANT)++;
    				break;
				case SPICEMERCHANT:
    				cout << "SPICEMERCHANT tile created" << endl;
    				tileCreationRates.at(SPICEMERCHANT)++;
    				break;
				case FABRICMANUFACTURER:
    				cout << "FABRICMANUFACTURER tile created" << endl;
    				tileCreationRates.at(FABRICMANUFACTURER)++;
    				break;
				case JEWELER:
    				cout << "JEWELER tile created" << endl;
    				tileCreationRates.at(JEWELER)++;
    				break;
				case CARTMANUFACTURER:
    				cout << "CARTMANUFACTURER tile created" << endl;
    				tileCreationRates.at(CARTMANUFACTURER)++;
    				break;
				case SMALLMARKET: 
    				cout << "SMALLMARKET tile created" << endl;
    				tileCreationRates.at(SMALLMARKET)++;
    				break;
				case SPICEMARKET:
    				cout << "SPICEMARKET tile created" << endl;
    				tileCreationRates.at(SPICEMARKET)++;
    				break;
				case JEWELRYMARKET: 
    				cout << "JEWELRYMARKET tile created" << endl;
    				tileCreationRates.at(JEWELRYMARKET)++;
    				break;
				case FABRICMARKET:
    				cout << "FABRICMARKET tile created" << endl;
    				tileCreationRates.at(FABRICMARKET)++;
    				break;
				case BLACKMARKET:
    				cout << "BLACKMARKET tile created" << endl;
    				tileCreationRates.at(BLACKMARKET)++;
    				break;
				case CASINO:
    				cout << "CASINO tile created" << endl;
    				tileCreationRates.at(CASINO)++;
    				break;
				case GEMMERCHANT:
    				cout << "GEMMERCHANT tile created" << endl;
    				tileCreationRates.at(GEMMERCHANT)++;
    				break;
				case PALACE: 
    				cout << "PALACE tile created" << endl;
    				tileCreationRates.at(PALACE)++;
    				break;
			}
    						
    		add(tileToInsert, i, j); // Add tile to board
    	}
    }	
    		for (int i = 0; i<14; i++){
				tileCreationRates.at(i) = tileCreationRates.at(i)/(static_cast<double>(ROW*COL))*100;
			}
			
			cout<< endl;
			cout<< "Tile Type\t\tOccurence Rate" << endl << endl;
			
			cout<< "Desert\t\t\t"<< tileCreationRates.at(DESERT) << "%" << endl;
			cout<< "Restaurant\t\t" << tileCreationRates.at(RESTAURANT) << "%" << endl;
			cout<< "SpiceMerchant\t\t" << tileCreationRates.at(SPICEMERCHANT) << "%" << endl;
			cout<< "FabricManufacturer\t" << tileCreationRates.at(FABRICMANUFACTURER) << "%" << endl;
			cout<< "Jeweler\t\t\t" << tileCreationRates.at(JEWELER) << "%" << endl;
			cout<< "CartManufacturer\t" << tileCreationRates.at(CARTMANUFACTURER) << "%" << endl;
			cout<< "SmallMarket\t\t" << tileCreationRates.at(SMALLMARKET) << "%" << endl;
			cout<< "SpiceMarket\t\t" << tileCreationRates.at(SPICEMARKET) << "%" << endl;
			cout<< "JewelryMarket\t\t" << tileCreationRates.at(JEWELRYMARKET) << "%" << endl;
			cout<< "FabricMarket\t\t" << tileCreationRates.at(FABRICMARKET) << "%" << endl;
			cout<< "BlackMarket\t\t" << tileCreationRates.at(BLACKMARKET) << "%" << endl;
			cout<< "Casino\t\t\t" << tileCreationRates.at(CASINO) << "%" << endl;
			cout<< "GemMerchant\t\t" << tileCreationRates.at(GEMMERCHANT) << "%" << endl;
			cout<< "Palace\t\t\t" << tileCreationRates.at(PALACE) << "%" << endl;  
			
			cout<< "Tile Creation is a success :)" << endl;
}

/*
 * Adds referenced tile to board.
 * Parameters: reference to tile, row and column of where to place tile.
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::add(const T& tile, int row, int col)
{
    if (row > ROW || row < 0
			|| col > COL || col < 0)
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
template<typename T, typename J, unsigned int ROW, unsigned int COL>
const T& GameBoard<T, J, ROW, COL>::getTile(int row, int col) const
{
    if (row > ROW-1 || row < 0
		|| col > COL-1 || col < 0)
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
template<typename T, typename J, unsigned int ROW, unsigned int COL>
J GameBoard<T, J, ROW, COL>::getPlayer(const string& playerName)
{
	//if( players[playerName] ))			// should be a search here and if pointer to end is returned then throw. -P
        //throw std::out_of_range("Player does not exist.");
    return players[playerName];
}

template<typename T, typename J, unsigned int ROW, unsigned int COL>
const T& GameBoard<T, J, ROW, COL>::getTile(const std::string& playerName) const
{
	//auto it = playersCurrentTile.find(playerName);
    //if( it == playersCurrentTile.end())			// should be a search here and if pointer to end is returned then throw. -P
      //throw std::out_of_range("Player does not exist.");
    
	//return it->second;
}
/*
 * Returns all players on a specific tile
 * Parameters: tile
 * Return: vector of players
 * Exception: std::out_of_range
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
std::vector<J> GameBoard<T, J, ROW, COL>::getPlayers(const T& tile) const{
    //if (tile->noPlayers())
      ///  throw std::out_of_range("Tile has no players.");
    
	//return tile->getPlayers();
}

/*
 * Adds player.
 * Parameters: name of player
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::addPlayer(string playerName){
    players.emplace(playerName, new Player(playerName));
    //initial position of each player to Restaurant is to be set here. -P
}

template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::getCoordinate(const T &tile, int *row, int *col) const{   	// Returns the coordinates of a tile
	tile->getCoordinate(row, col);
}
/*
 * Moves a player to a different tile.
 * 
 * @param move
 *		type of Move
 * @param playerName
 *		name of the player to move	
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
const T& GameBoard<T, J, ROW, COL>::move(Move move, const string& playerName ){
	
	const T& currentTile = getTile(playerName);
	currentTile->removePlayer(playerName);
	int row, col;
	int* rowPtr = &row;
	int* colPtr = &col;
	getCoordinate(currentTile, rowPtr, colPtr);
	
	const T& nextTile;
	switch ( move ){							// we MUST handle illegal moves in UI. -P
		case UP:
			nextTile = getTile(row, col +1);
			break;
		case RIGHT:
			nextTile = getTile(row +1, col);
			break;
		case DOWN:
			nextTile = getTile(row, col -1);
			break;
		case LEFT:
			nextTile = getTile(row -1, col);
			break;
	}
	
	nextTile->addPlayer(playerName);
	playersCurrentTile[playerName] = nextTile;	
}

template<typename T, typename J, unsigned int ROW, unsigned int COL> 
void GameBoard<T, J, ROW, COL>::printCurrentLocation(const string& playerName){
	const T playerTile = getTile(playerName);
	int playerRow, playerCol;
	int* rowPtr = &playerRow;
	int* colPtr = &playerCol;
	getCoordinate(playerTile, rowPtr, colPtr); // This statement makes the game crash, have to work on it!
	cout<< endl;
	cout<< "YOU ARE HERE : X" << endl;
	//prints the top of the board
	for ( int j=0; j<2; j++){
		for ( int i = 0; i < COL; i++){
			cout<< "******";
		}
		cout << endl;
	}
	for (int j = COL-1; j > -1; j--){
		cout<< "** ";
		for (int i = 0; i < ROW; i++){
		//if( playerRow == i && playerCol == j){			// This works but the players
		//		cout<< "  X  ";								// are not currenlty correctly initialized 
		//	}else{											// a restaurant tile, their position is (0,0). -P
				const T& aTile = getTile(i, j);
				switch (aTile->getType()){
	    			case DESERT:
	    				cout << " DES ";
	    				break;
	    			case RESTAURANT:
	    				cout << " RES ";
	    				break;
					case SPICEMERCHANT:
	    				cout << " SPI ";
	    				break;
					case FABRICMANUFACTURER:
	    				cout << " FAB ";
	    				break;
					case JEWELER:
	    				cout << " JEW ";
	    				break;
					case CARTMANUFACTURER:
	    				cout << " CAR ";
	    				break;
					case SMALLMARKET: 
	    				cout << " SMM ";
	    				break;
					case SPICEMARKET:
	    				cout << " SPM ";
	    				break;
					case JEWELRYMARKET: 
	    				cout << " JEM ";
	    				break;
					case FABRICMARKET:
	    				cout << " FAM ";
	    				break;
					case BLACKMARKET:
	    				cout << " BLM ";
	    				break;
					case CASINO:
	    				cout << " CAS ";
	    				break;
					case GEMMERCHANT:
	    				cout << " GEM ";
	    				break;
					case PALACE: 
	    				cout << " PAL ";
	    				break;
				}
			//} 
			if (i == ROW-1){
				cout << " **";
			}		
		}
		cout<< endl;
		cout<< endl;
	}
	
	//prints the bottom of the board
	for ( int j=0; j<2; j++){
		for ( int i = 0; i < COL; i++){
			cout<< "******";
		}
		cout << endl;
	}
}

#endif /* defined(__BoardGame__GameBoard__) */
