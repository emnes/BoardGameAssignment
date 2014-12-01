//
//  main.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//
//  Here is implemented the main loop of the game.  One can
//  choose to load the latest saved game or to start a new game.
//  The first player that gets 5 rubies wins.  Each action costs
//  1 food item and when other players are on the same tile a player
//  pay 1 gold to each of the other players to perform an action.  When
//  player has no more food he an move but cannot do any action.
//

#include <iostream>
#include <unistd.h>
#include <array>
#include <time.h>
#include <limits>
#include <limits>
#include "GameBoard.h"
#include <stdio.h>

#ifdef WINDOWS 										// Conditionnal inclusions dependent on operating system type
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

using std::cin;

GameBoard<Tile<Player>*, Player, 6 ,6>* gameBoard;	// Object that holds the state of the game
vector<string> playerNames;							// Simply hold all the names of the players
string workingDirectoryPath;						// Current working directory path

/*
 * Saves the game state and data
 * to file.
 */
void saveGame()
{
    ofstream outfile;
    outfile.open(workingDirectoryPath + "/gameData.txt");
    if (outfile.is_open())
    {
        outfile << *(gameBoard);
        cout << "Game saved." << endl;
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    outfile.clear();
    outfile.close();
}

/* 
 * Loads a saved game state and
 * data from file.
 */
bool loadGame()
{
    ifstream infile;
    infile.open(workingDirectoryPath + "/gameData.txt");
    if (infile.is_open())
    {
        gameBoard = new typename GameBoard<Tile<Player>*, Player, 6, 6>::GameBoard();
        infile >> *gameBoard;
        cout << "Game loaded." << endl;
        infile.clear();
        infile.close();
        return true;
    }
    else
    {
        cout << "Error opening file" << endl;
        infile.clear();
        infile.close();
        return false;
    }
}

/*
 * Creates a new game.
 */
void createGame()
{
    // UI prompts for the number of players and stores it
    int numOfPlayers = 0;
    bool invalidNumberOfPlayers = true;
    cout<< "\t\t\tEnter the number of players:";
    while(invalidNumberOfPlayers){
        cin >> numOfPlayers;
        if ( cin.fail() ){
            cout<<"The number of players needs to be an integer greater than 1." << endl;
            cout<<"\t\tPlease enter a correct number of players:" << endl;
            cin.clear(); // Clears the input stream fail flag
            cin.ignore(100, '\n'); // Ignores any characters left in the stream
        }else{
            if( numOfPlayers > 1)
                invalidNumberOfPlayers = false;
            else {
                cout << "At least 2 players are required to play this game." << endl;
                cout << "Please enter a correct number of players:" << endl;
            }
        }
    }
    
    // UI prompts for all the names of the players and stores them
    //vector<string> playerNames; moved to the top
    for( int i = 0; i < numOfPlayers; i++)
    {
        cout<< "\t\t\tEnter the name of player " << i+1 << " : ";
        bool invalidPlayerName = true;
        while( invalidPlayerName){
            string playerName;
            cin >> playerName;
            if ( find(playerNames.begin(), playerNames.end(), playerName) == playerNames.end()){
                playerNames.push_back(playerName);
                invalidPlayerName = false;
            }else{
                cout << "Cannot have two players with the same name." << endl;
                cout << "Please enter another name:" << endl;
            }
        }
        
    }
    
    // Initialize a a 6x6 board with 4 players of type Player and their respective names.
    gameBoard =
    new typename GameBoard<Tile<Player>*, Player, 6, 6>::GameBoard(playerNames.data(), playerNames.size());
}

void playerWon(const string& playerName)
{
    cout<< "\t\t\t" << playerName << " HAS WON." << endl;
    cout<< endl << endl << "\t\t\tThank you for playing." << endl << endl;
    delete gameBoard;
    exit(0);
}
    
int main()
{
	// Fetch the current working directory path
	char cCurrentPath[FILENAME_MAX];
	
	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
     return errno;
    }
    
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; 
	workingDirectoryPath = cCurrentPath;
	std::replace(workingDirectoryPath.begin(), workingDirectoryPath.end(), '\\', '/');
	
	
	cout << "CSI2372 Final Project" << endl;
	cout << "by Patrice Boulet & Mazhar Shar" << endl << endl;
	cout << "************************************************************************" << endl;
	cout << "***********************************AGAME********************************" << endl;
	cout << "************************************************************************" << endl << endl;
    
    bool startedGame = false;
    while(!startedGame)
    {
        cout << "Would you like to start a new game or load previous game?" << endl;
        cout << "0-NEW\t" << "1-LOAD\t" << endl;
        cout << "Enter: ";
        int gameChoice;
        cin >> gameChoice;
        if (gameChoice == 0)
        {
            startedGame = true;
            createGame();
        }
        else
        {
            if(loadGame()){
                for( Player p : gameBoard->players){
                    playerNames.push_back(p.getName());
                }
                startedGame = true;
            }
        }
    }
    bool hasWon = false;
    while (!hasWon)
    {
        // currentPlayerIndex holds whose turn it is (useful for a saving & loading)
        for (int i = gameBoard->getCurrentPlayerIndex(); i < playerNames.size(); ++i)
        {
            string currentPlayerName = playerNames[i];
            
            // print the UI
            Player currentPlayer = gameBoard->getPlayer(currentPlayerName);
            cout << "Current player:" << currentPlayerName << endl;
            currentPlayer.print();
            gameBoard->printCurrentLocation(currentPlayerName);
            
            // prompt for move
            Tile<Player>* currentPlayerTile = gameBoard->getTile(currentPlayer.getName());
            int xCoord, yCoord;
            currentPlayerTile->getCoordinate(&xCoord, &yCoord);
            array<bool, 4> validMoves = {true,true,true,true};
            gameBoard->getValidMoves(validMoves.data(), xCoord, yCoord);
            cout << "Where do you want to move next ? Enter your command number and press ENTER " << endl;
            
            if(validMoves[UP])
                cout << "0-UP\t";
            
            if(validMoves[RIGHT])
                cout << "1-RIGHT\t";
            
            if(validMoves[DOWN])
                cout << "2-DOWN\t";
            
            if(validMoves[LEFT])
                cout << "3-LEFT\t";
            cout << "4-SAVE AND EXIT\t";
            
            // Current player inputting its next tile direction
            bool invalidInput = true;
            int input;
            while(invalidInput)
            {
                cin >> input;
                if ( cin.fail() )
                {
                    cout<<"Only integer is a valid choice, input your choice again:" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }else
                {
                    Move direction = static_cast<Move>(input);
                    if( (direction == UP && validMoves[UP])	||
                       (direction == RIGHT && validMoves[RIGHT]) ||
                       (direction == DOWN && validMoves[DOWN]) ||
                       (direction == LEFT && validMoves[LEFT]))
                    {
                        invalidInput = false;
                        gameBoard->move(direction, currentPlayer.getName());
                        cout << string( 100, '\n' );
                        cout << "Current player:" << currentPlayer.getName() << endl;
                        currentPlayer.print();
                        gameBoard->printCurrentLocation(currentPlayer.getName());
                        currentPlayerTile = gameBoard->getTile(currentPlayer.getName());
                        currentPlayerTile->print();
                    }
                    else if(input == 4)
                    {
                        invalidInput = false;
                        saveGame();
                        delete gameBoard;
                        exit(0);
                    }
                    else
                    {
                        cout<< "Sorry, not a valid input" << endl;
                        cout<< "Please enter again:" << endl;
                    }
                }
            }
            
            // Current player doing action on the new tile if, applicable
            if( currentPlayer.canAct())
            {
                if( currentPlayerTile->getType() != DESERT)
                {
                    invalidInput = true;
                    string actionInput;
                    while(invalidInput)
                    {
                        cin >> actionInput;
                        if ( cin.fail() )
                        {
                            cout<<"Wrong input, choose Y or N" << endl;
                            cin.clear(); // Clears the input stream fail flag
                            cin.ignore(100, '\n'); // Ignores any characters left in the stream
                        }else
                        {
                            if( !actionInput.compare("y") || !actionInput.compare("Y") )
                            {
                                if( !currentPlayerTile->action(currentPlayer))
                                {
                                    cout<< "Sorry, you do not have enough ressources to perform this action." << endl;
                                }
                                else
                                {
                                    if( currentPlayer.getRuby() >= 5)
                                    {
                                        playerWon(currentPlayerName);
                                    }
                                    if( currentPlayerTile->getType() != RESTAURANT)
                                        currentPlayer.eat();
                                    
									// paying other players on tile, if applicable
									for(string recipientPlayerName : currentPlayerTile->getPlayers())
                                    {
                                        if( recipientPlayerName.compare(currentPlayerName))
                                        {
                                            Player recipientPlayer = gameBoard->getPlayer(recipientPlayerName);
                                            currentPlayer.pay(recipientPlayer);
                                            gameBoard->setPlayer(recipientPlayer);				
                                        }
                                    }
                                    //print the status of the player after performing the action
                                    gameBoard->setPlayer(currentPlayer);
                                    cout << endl << "Your status after performing this action is: " << endl;
                                    currentPlayer.print();	
                                }
                                invalidInput = false;
                            }
                            else if( !actionInput.compare("n") || !actionInput.compare("N") )
                            {
                                invalidInput = false;
                            }
                            else
                            {
                                cout<<"Sorry, your input is not valid, please choose Y or N" << endl;		
                            }
                        }
                    }
                }
                cout << "Press enter to continue . . . ";
                cin.sync();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << string( 100, '\n' );
            }
            // update currentPlayerIndex here is crucial for loading and saving
            gameBoard->setCurrentPlayerIndex(gameBoard->getCurrentPlayerIndex() + 1);
            if( gameBoard->getCurrentPlayerIndex() == playerNames.size() )
                gameBoard->setCurrentPlayerIndex(0); // Resets currentPlayerIndex after loop completes to ensure next turn starts from first player.
        }
    }
    
    return 0;
}


