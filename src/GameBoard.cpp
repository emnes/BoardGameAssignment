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

template<typename T, typename J, unsigned int ROW, unsigned int COL>
GameBoard<T, J, ROW, COL>::GameBoard(string *playerNames, int playerNamesSize){
	
	array<float, 14> tileCreationRates = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0}};		// for testing purpose. -P
    tileFactory = TileFactory<J>::Get(ROW*COL);
	
	for (auto i = 0; i < playerNamesSize; i++){
	    addPlayer(*(playerNames + i));
	}
	
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
				tileCreationRates.at(i) = tileCreationRates.at(i)/36.0*100;
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
J GameBoard<T, J, ROW, COL>::getPlayer(const std::string& playerName)
{
	if(!players.at(playerName))
        throw std::out_of_range("Player does not exist.");
    return *(players.at(playerName));
}

template<typename T, typename J, unsigned int ROW, unsigned int COL>
const T& GameBoard<T, J, ROW, COL>::getTile(const std::string& playerName) const
{
    if(!players.at(playerName))
        throw std::out_of_range("Player does not exist.");
    
	//return playersCurrentTiles[playerName];
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
    if (tile->noPlayers())
        throw std::out_of_range("Tile has no players.");
    
	return tile->getPlayers();
}

/* Do we need this? <------------------* 
 * Adds player.
 * Parameters: name of player
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::addPlayer(string playerName){
    players.emplace(playerName, new Player(playerName));
    //initial position of each player to Restaurant is to be set here. -P
}

template class GameBoard<Tile<Player>*,Player, 6, 6>;
