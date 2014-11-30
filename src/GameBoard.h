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
#include <algorithm>
#include <fstream>
//#include "Tile.h" -- included through TileFactory
#include "TileFactory.h"

using std::ofstream;
using std::ifstream;

enum Move{UP, RIGHT, DOWN, LEFT}; // Only four possible neighbours: up, down, left, right


template<typename T, typename J, unsigned int ROW, unsigned int COL>class GameBoard {
	
public:
	array<array<T, ROW>, COL> board;								// Hold all the tiles for the current game.
	vector<J> players;												// Vector of all players.
	map<string, T> playersCurrentTile;								// Keeps a reference of a player's current tile.
	TileFactory<J>* tileFactory;		 							// Singleton instance of TileFactory.

public:
	GameBoard();													// GameBoard constructor for loading from file.
	GameBoard(string *playerNames, size_t playerNamesSize);			// GameBoard constructor.
	void add(const T& tile, int row, int col);						// Adds a tile to position row,col to the board.
	const T& getTile(int row, int col) const;						// Returns the tile located at position row,col of the board.
	void getCoordinate(const T &tile, int *row, int *col) const;   	// Returns the coordinates of a tile.
    void addPlayer(string playerName); 								// Adds a player to the game.
    void setPlayer(J player);                                       // Updates player -- maybe need for loading **

	J getPlayer(const std::string& playerName);						// Get a Player object by player name.
	const T& getTile(const std::string& playerName) const;			// Get the current tile of a Player by player name.
	std::vector<J> getPlayers(const T& tile) const;					// Get all the players located at a tile.
	void getValidMoves(bool* b, int i, int j);                      // Returns boolean array of moves a play can make. Dependant on placement of player's current tile.
	
	void printCurrentLocation(const string& playerName);            // Prints X where player is located.
	const T& move(Move move, const std::string& playerName );       // Moves player.
    template<typename U, typename L, unsigned int R, unsigned int C>
    friend ostream& operator<<(ostream& os, const GameBoard<U, L, R, C>& gameBoard);   // Save game.
    template<typename U, typename L, unsigned int R, unsigned int C>
    friend istream& operator>>(istream& os, GameBoard<U, L, R, C>& gameBoard);         // Load game.
};

template<typename T, typename J, unsigned int ROW, unsigned int COL>
GameBoard<T, J, ROW, COL>::GameBoard(){
	
	// I putted the aldorighms to laod fom file here, maube it should be done in the main loop, maybe not, we have to explore this.
	
	TileFactory<J>* tileFactory = TileFactory<J>::Get(ROW*COL);	// Tile factory singleton
	
	// Get the number of players from file
	int numOfPlayers; // init here
	
	if( true/* first token is "Player" */)
	{
		for( int i = 0; i < numOfPlayers; i++)
		{
			
			// Somehow start to read a player from file.
			string playerName;  // init from file
			addPlayer(playerName);
			
			// Create the actual Player object from file
			// Player player; -
            Player player(playerName);
			// init all its attributes from file
			
			setPlayer(player); // override the dummy player that was created before with the one created from file
		}
	}else if( true/* first token is Tile */)
	{
		// Read and init these from file
		TileType tileType;
		int xCoord;
		int yCoord;
		
		Tile<J>* tileToInsert = tileFactory->CreateTile(tileType);
		tileToInsert->setXCoordinate(xCoord);
    	tileToInsert->setYCoordinate(yCoord);
    	
    	if (true/* we read there are some players on that tile */)
		{    	
			// init this from file
			string tilePlayerName;
	    	playersCurrentTile[tilePlayerName] = tileToInsert;
	    	tileToInsert->addPlayer(tilePlayerName);
    	}
    	add(tileToInsert, xCoord, yCoord); // Add tile to board
	}		
}

template<typename T, typename J, unsigned int ROW, unsigned int COL>
GameBoard<T, J, ROW, COL>::GameBoard(string *playerNames, size_t playerNamesSize){

	array<float, 14> tileCreationRates = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0}};		// for testing purpose. -P
    tileFactory = TileFactory<J>::Get(ROW*COL);
	
	bool playersAreSetToStartTile = false;
	
    for(int i = 0; i < ROW; i++){
    	for( int j = 0; j < COL; j++){
    		Tile<J>* tileToInsert = tileFactory->next();
    		tileToInsert->setXCoordinate(i);
    		tileToInsert->setYCoordinate(j);
    		// for testing purpose -P
            /*if (tileToInsert->getType() == RESTAURANT) {
                if( !playersAreSetToStartTile ){// NOT FOR TESTING PURPOSE DON'T REMOVE THIS PART*************
                    for (auto i = 0; i < playerNamesSize; i++){
                        addPlayer(*(playerNames + i));							// Add players
                        playersCurrentTile[*(playerNames + i)] = tileToInsert;	// Set the player to start a Restaurant
                        int row, col;
                        int* rowPtr = &row;
                        int* colPtr = &col;
                        playersCurrentTile[*(playerNames + i)]->getCoordinate(rowPtr, colPtr);
                        //cout << endl << "Player " << *(playerNames + i) << " was set to (" << row << "," << col << ")" << endl;
                        tileToInsert->addPlayer(*(playerNames + i));			// Adds the player to this Restaurant tile
                    }
                    playersAreSetToStartTile = true;
                }
            }*/ // USE ABOVE FOR FINAL. Will not need switch case for one case.
            
			switch (tileToInsert->getType()){
    			/*case DESERT:
    				cout << "DESERT tile created" << endl;
    				tileCreationRates.at(DESERT)++;
    				break; */
    			case RESTAURANT:
    				//cout << "RESTAURANT tile created" << endl;
    				if( !playersAreSetToStartTile ){// NOT FOR TESTING PURPOSE DON'T REMOVE THIS PART*************
    					for (auto i = 0; i < playerNamesSize; i++){
						    addPlayer(*(playerNames + i));							// Add players 
						    playersCurrentTile[*(playerNames + i)] = tileToInsert;	// Set the player to start a Restaurant
						    int row, col;
						    int* rowPtr = &row;
						    int* colPtr = &col;					
							playersCurrentTile[*(playerNames + i)]->getCoordinate(rowPtr, colPtr);
							//cout << endl << "Player " << *(playerNames + i) << " was set to (" << row << "," << col << ")" << endl; 
							tileToInsert->addPlayer(*(playerNames + i));			// Adds the player to this Restaurant tile
						}
						playersAreSetToStartTile = true;
					}
    				//tileCreationRates.at(RESTAURANT)++;
    				break;
				/*case SPICEMERCHANT:
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
    				break; */
			}
    						
    		add(tileToInsert, i, j); // Add tile to board
    	}
    }		
    		/*
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
			
			cout<< "Tile Creation is a success" << endl;
			
			*/
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
    for( Player& player : players){
    	if (player.getName() == playerName)
    		return player;
	}
    throw std::out_of_range("Player does not exist.");
}

template<typename T, typename J, unsigned int ROW, unsigned int COL>
const T& GameBoard<T, J, ROW, COL>::getTile(const std::string& playerName) const
{
	auto it = playersCurrentTile.find(playerName);
    if( it == playersCurrentTile.end())		
      throw std::out_of_range("Player does not exist.");
    
	return it->second;
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
    vector<J> tilePlayers;
	if (tile->noPlayers()){
      	throw std::out_of_range("Tile has no players.");
    }else{
    	for ( string playerName : tile->getPlayers()){
    		tilePlayers.push_back(GameBoard<T, J, ROW, COL>::getPlayer(playerName));
		}	
	} 
    return tilePlayers;
}

/*
 * Adds player.
 * Parameters: name of player
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::addPlayer(string playerName){
    Player* newPlayer = new Player(playerName);
    players.push_back(*newPlayer);
}

/*
 * Updates a player status.
 * Parameters: name of player
 *
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::setPlayer(J player){
   for( int i; i < players.size(); i ++){
   		if( players.at(i) == player )
   			players.at(i) = player;
   }
}

/*
 * Returns a given tile's coordinate on the 
 * game board.
 */
template<typename T, typename J, unsigned int ROW, unsigned int COL>
void GameBoard<T, J, ROW, COL>::getCoordinate(const T &tile, int *row, int *col) const{   
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
	
	T nextTile;
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
	return nextTile;
}

template<typename T, typename J, unsigned int ROW, unsigned int COL> 
void GameBoard<T, J, ROW, COL>::printCurrentLocation(const string& playerName){
	cout<< endl;
	cout<< "\t\t\t     YOU ARE HERE : X" << endl;
	//prints the top of the board
	for ( int j=0; j<2; j++){
		cout<< "\t\t  ";
		for ( int i = 0; i < COL; i++){
			cout<< "******";
		}
		cout << endl;
	}
	
	bool showTileTypes = false; // True to show the tile types on the board GUI, otherwise they won't be shown.
	
	for (int j = COL-1; j > -1; j--){
		cout<< "\t\t  ** ";
		for (int i = 0; i < ROW; i++){
				bool isCurrentLocation = false;							// True if (i, j) is the current location of the player			
				const T& aTile = getTile(i, j);
				if( !aTile->noPlayers() ){
					for( string tilePlayerName : aTile->getPlayers()){
						if (tilePlayerName == playerName)
							isCurrentLocation = true;
					}
				}
				if( !isCurrentLocation ){
					if( showTileTypes ){
						switch (aTile->getType()){
			    			case DESERT:
			    				cout << "  +  ";
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
					}else{
						cout<< "  +  ";	
					}
				}else{
					cout<< "  X  ";
				}
			if (i == ROW-1){
				cout << " **";
			}		
		}
		cout<< endl;
		cout<< "\t\t  **";
		for ( int i = 0; i < COL; i++){
			cout<< "     ";
		}
		cout << "  **" << endl;
		
	}
	
	//prints the bottom of the board
	for ( int j=0; j<2; j++){
		cout<< "\t\t  ";
		for ( int i = 0; i < COL; i++){
			cout<< "******";
		}
		cout << endl;
	}
}

template<typename T, typename J, unsigned int ROW, unsigned int COL> 
void GameBoard<T, J, ROW, COL>::getValidMoves(bool* b, int i, int j){
	
	if ( j == COL - 1)
		*(b + static_cast<int>(UP)) = false;
	if ( i == ROW - 1)
		*(b + static_cast<int>(RIGHT)) = false;
	if( j == 0 )
		*(b + static_cast<int>(DOWN)) = false;
	if( i == 0 )
		*(b + static_cast<int>(LEFT)) = false;
}

// Need to change typename variables
// WORK ON THIS TOMORROW. Need gameBoard to save players into text file when 'p' is entered....
// Look into: template operators. Why was gameBoard's operator not being called?
template<typename U, typename L, unsigned int R, unsigned int C>
ostream& operator<<(ostream& os, const GameBoard<U, L, R, C>& gameBoard)
{
    os << gameBoard.players.size() << endl;
    os << "PlayerNames";
    for (Player p: gameBoard.players)
         os << " " << p.getName();
    os << endl;
    for (Player p: gameBoard.players)
        os << "Player" << " " << p << endl;

    for (auto column : gameBoard.board)
    {
        for (auto tile : column)
        {
            os << "Tile " << *(tile) << endl;
        }
    }
    return os;
}
template<typename U, typename L, unsigned int R, unsigned int C>
istream& operator>>(istream& is, GameBoard<U, L, R, C>& gameBoard)
{
    // is >> numOfPlayers
    // loop for numOfPlayers and then pass names and size into gameboard
    // set the properties of each player
    
    string _numOfPlayers;
    is >> _numOfPlayers;
    int numOfPlayers = std::stoi(_numOfPlayers);

    string* playerNames[numOfPlayers];
    
    // How will we change each property?
    
    gameBoard = new GameBoard<U, L, R, C>("", 0);
    //Update each player
    
    for (Player p: gameBoard.players)
    {
        is >> p;
        cout << p;
    }
    
    for (auto column : gameBoard.board)
    {
        for (auto tile : column)
        {
            is >> *(tile);
        }
    }
    return is;
}

#endif /* defined(__BoardGame__GameBoard__) */
