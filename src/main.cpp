//
//  main.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <array>
#include <time.h>
#include <limits> 
//#include "Player.h"
//#include "Tile.h" --- included through GameBoard.
#include "GameBoard.h"

using std::cin;

/*
	bool takeTurn( 
		GameBoard<Tile<Player>*,Player*,6,6>& gameBoard, const std::string& playerName ) { 
		
		try { 
			int m; 
	 		cin.exceptions(std::istream::failbit); 
	 		cin>> m; 
	 		const Tile<Player>* tilePtr = gameBoard.move( static_cast<Move>(m), playerName ); 
	 		Player* currentPlayer = gameBoard.getPlayer( playerName ); 
	 		if (currentPlayer->canAct()) { 
		 		bool makeAction; 
		 		cin>>makeAction; 
		 		if ( makeAction ) 
					std::vector<Player> opL = gameBoard.getPlayers( tilePtr ); 
				if (currentPlayer->getGold()>= opL.size()) { 
					currentPlayer.eat(); 
				for ( auto op : opL ) { 
		 			currentPlayer.pay( op, 1 ); 
					gameBoard.setPlayer( op ); // What is this supposed to do? -P
		 		} 
		 		tilePtr->action( p ); 
		 		gameBoard.setPlayer( p ); 
				} 
	 		} 
		} 
	 return true; 
	} catch ( std::istream::failure e ) { 
		cout<< "Incorrect key pressed"; cin.clear(); } 
	} catch ( std::out_of_range e ) { 
	 	cout<< e.what(); 
		return false; 
	} 
	*/

int main() {
	
	//srand(time(NULL));// fix
	
	/*
	
	******************************PLAYER TEST SUITE***********************************
    Player* testPlayer = new Player("testPlayer");
    
    cout<< "----------------------Player tests started------------------------------" << endl;
    
    cout<< endl << "Initialization tests..." << endl << endl;
    cout<< "gold" << "\t\t\t\t\t\t\t" << ((testPlayer->getGold()==5) ?"Succeded":"Failed") << endl;
    cout<< "ruby" << "\t\t\t\t\t\t\t" << ((testPlayer->getRuby()==0) ?"Succeded":"Failed") << endl;
    cout<< "spice" << "\t\t\t\t\t\t\t" << ((testPlayer->getSpice()==1) ?"Succeded":"Failed") << endl;
    cout<< "fabric" << "\t\t\t\t\t\t\t" << ((testPlayer->getFabric()==1) ?"Succeded":"Failed") << endl;
    cout<< "jewel" << "\t\t\t\t\t\t\t" << ((testPlayer->getJewel()==1) ?"Succeded":"Failed") << endl;
    cout<< "food" << "\t\t\t\t\t\t\t" << ((testPlayer->getFood()==10) ?"Succeded":"Failed") << endl;
    cout<< "cart" << "\t\t\t\t\t\t\t" << ((testPlayer->getCartCapacity()==9) ?"Succeded":"Failed") << endl;
    
	cout<< endl << "Functions tests..." << endl << endl;
	
    // Eats 5 food
    for( int i = 0; i < 5; i++){
    	testPlayer->eat();
    }
	cout<< "eat() " << "\t\t\t\t\t\t\t" << ((testPlayer->getFood()==5) ?"Succeded":"Failed") << endl;
	cout<< "canAct() with food > 0 " << "\t\t\t\t\t" << (testPlayer->canAct()?"Succeded":"Failed") << endl;
	// Eats food until it goes below 0
     for( int i = 0; i < 6; i++){
    	testPlayer->eat();
    }
    
    cout<< "eat() after food = 0  " << "\t\t\t\t\t" << ((testPlayer->getFood()==0) ?"Succeded":"Failed") << endl;
    cout<< "canAct() with food = 0 " << "\t\t\t\t\t" << ((!testPlayer->canAct())?"Succeded":"Failed") << endl;
    
    // Test paying a player
    Player* testPlayerToPay = new Player("testPlayerToPay");
    
    cout<< "pay(...) with gold > 0  " << "\t\t\t\t" << 
		((testPlayer->pay(*testPlayerToPay)
			&& testPlayer->getGold() == 4
				&& testPlayerToPay->getGold() == 6)?"Succeded":"Failed") << endl;
				
	// testPlayer pays testPlayerToPay until his gold == 0
	for( int i = 0; i < 4; i++){
		testPlayer->pay(*testPlayerToPay);
	}
	cout<< "pay(...) with gold == 0  " << "\t\t\t\t" << 
		(!(testPlayer->pay(*testPlayerToPay))?"Succeded":"Failed") << endl;
	
	//test incrementCartSize() when cart is not full
	cout<< "incrementCartSize() when cart is not full" << "\t\t" << 
		((testPlayer->incrementCartSize() && 
			(testPlayer->getCartSize()) == 4)?"Succeded":"Failed") << endl;
	
	//test incrementCartSize() when cart is full
	testPlayer->setCartSize(testPlayer->getCartSize() + 5);  
	cout<< "incrementCartSize() when cart is full" << "\t\t\t" << 
		((!(testPlayer->incrementCartSize()) && 
			(testPlayer->getCartSize()) == 9)?"Succeded":"Failed") << endl;
	
	delete testPlayer;
	delete testPlayerToPay;
				
	cout<< "----------------------Player tests ended---------------------------------" << endl << endl;
	cout<< "----------------------Tile tests started------------------------------" << endl;
	
	******************************TILE TEST SUITE***********************************
    
	Player* tileTestPlayer; 
    
	// Test Restaurant
	tileTestPlayer = new Player("tileTestPlayer");
	Restaurant<Player>* testRestaurant = new Restaurant<Player>();
	
	tileTestPlayer->setFood(1);
	cout<< "Restaurant action(...)" << "\t\t\t\t\t" << 
		(((testRestaurant->action(*tileTestPlayer)) && 
			tileTestPlayer->getFood() == 10)?"Succeded":"Failed") << endl;
	
	delete testRestaurant, tileTestPlayer;
	
	// Test SpiceMerchant
    SpiceMerchant<Player>* testSpiceMerchant = new SpiceMerchant<Player>();
	
	// Case 1 : player has plenty of capcity in cart and gold
	tileTestPlayer = new Player("tileTestPlayer");
	
	cout<< "SpiceMerchant action(...) [size<capacity]" << "\t\t" << 
		(((testSpiceMerchant->action(*tileTestPlayer)) && 
			tileTestPlayer->getSpice() == 4 &&
				tileTestPlayer->getGold() == 3)?"Succeded":"Failed") << endl;
	delete tileTestPlayer;
	
	// Case 2 : player has not enough gold
	tileTestPlayer = new Player("tileTestPlayer");
	tileTestPlayer->setGold(1);
	
	cout<< "SpiceMerchant action(...) [gold<2]" << "\t\t\t" << 
		((!((testSpiceMerchant->action(*tileTestPlayer))) &&
			tileTestPlayer->getGold() == 1)?"Succeded":"Failed") << endl;
	delete tileTestPlayer;	
	
	// Case 3 : player has enough gold but less capacity available
	tileTestPlayer = new Player("tileTestPlayer");
	tileTestPlayer->setCartSize(8);
	cout<< "SpiceMerchant action(...) [capacity avail < 3]" << "\t\t" << 
		(((testSpiceMerchant->action(*tileTestPlayer)) &&
			tileTestPlayer->getCartCapacity() == 9 &&
				tileTestPlayer->getSpice() == 2 &&
					tileTestPlayer->getGold() == 3)?"Succeded":"Failed") << endl;
    delete testSpiceMerchant, tileTestPlayer;
    
    // Test FabricManufacturer
	tileTestPlayer = new Player("tileTestPlayer");
    FabricManufacturer<Player>* testFabricManufacturer = new FabricManufacturer<Player>();
	
	// Case 1 : player has plenty of capcity in cart and gold
	cout<< "FabricManufacturer action(...) [size<capacity]" << "\t\t" << 
		(((testFabricManufacturer->action(*tileTestPlayer)) && 
			tileTestPlayer->getFabric()== 4)?"Succeded":"Failed") << endl;
	
	// Case 2 : player has not enough gold
	tileTestPlayer->setGold(1);
	cout<< "FabricManufacturer action(...) [gold<2]" << "\t\t\t" << 
		(((testFabricManufacturer->action(*tileTestPlayer)))?"Failed":"Succeded") << endl;
		
	// Case 3 : player has enough gold but less capacity available
	tileTestPlayer->setGold(2);
	tileTestPlayer->setCartSize(8);
	cout<< "FabricManufacturer action(...) [capacity avail < 3]" << "\t" << 
		(((testFabricManufacturer->action(*tileTestPlayer)) &&
			tileTestPlayer->getCartCapacity() == 9 &&
				tileTestPlayer->getFabric()== 5)?"Succeded":"Failed") << endl;
				
    delete testFabricManufacturer, tileTestPlayer;
    
    // Test Jeweler
	tileTestPlayer = new Player("tileTestPlayer");
    Jeweler<Player>* testJeweler = new Jeweler<Player>();
	
	// Case 1 : player has plenty of capcity in cart and gold
	cout<< "Jeweler action(...) [size<capacity]" << "\t\t\t" << 
		(((testJeweler->action(*tileTestPlayer)) && 
			tileTestPlayer->getJewel()== 4)?"Succeded":"Failed") << endl;
	
	// Case 2 : player has not enough gold
	tileTestPlayer->setGold(1);
	cout<< "Jeweler action(...) [gold<2]" << "\t\t\t\t" << 
		(((testJeweler->action(*tileTestPlayer)))?"Failed":"Succeded") << endl;
		
	// Case 3 : player has enough gold but less capacity available
	tileTestPlayer->setGold(2);
	tileTestPlayer->setCartSize(8);
	cout<< "Jeweler action(...) [capacity avail < 3]" << "\t\t" << 
		(((testJeweler->action(*tileTestPlayer)) &&
			tileTestPlayer->getCartCapacity() == 9 &&
				tileTestPlayer->getJewel()== 5)?"Succeded":"Failed") << endl;
				
    delete testJeweler, tileTestPlayer;
    
    // Test CartManufacturer
	tileTestPlayer = new Player("tileTestPlayer");
    CartManufacturer<Player>* testCartManufacturer = new CartManufacturer<Player>();
	
	tileTestPlayer->setGold(7);
	cout<< "CartManufacturer action(...) " << "\t\t\t\t" << 
		( (testCartManufacturer->action(*tileTestPlayer) &&
			tileTestPlayer->getCartCapacity()== 12)?"Succeded":"Failed") << endl;
    delete testCartManufacturer, tileTestPlayer;
    
    // Test SmallMarket
	tileTestPlayer = new Player("tileTestPlayer");
    SmallMarket<Player>* testSmallMarket = new SmallMarket<Player>();
	
	cout<< "SmallMarket action(...) " << "\t\t\t\t" << 
		( (testSmallMarket->action(*tileTestPlayer) &&
			tileTestPlayer->getGold() == 13 &&
				tileTestPlayer->getSpice() == 0 &&
						tileTestPlayer->getFabric() == 0 &&
								tileTestPlayer->getJewel() == 0 &&
									tileTestPlayer->getCartSize() == 0)
									?"Succeded":"Failed") << endl;
    delete testSmallMarket, tileTestPlayer;
    
    // Test SpiceMarket
	tileTestPlayer = new Player("tileTestPlayer");
    SpiceMarket<Player>* testSpiceMarket = new SpiceMarket<Player>();
	
	tileTestPlayer->setSpice(3);
	tileTestPlayer->setCartSize(5);
	cout<< "SpiceMarket action(...) " << "\t\t\t\t" << 
		( (testSpiceMarket->action(*tileTestPlayer) &&
				tileTestPlayer->getSpice() == 0 &&
					tileTestPlayer->getCartSize() == 2)
									?"Succeded":"Failed") << endl;
    delete testSpiceMarket, tileTestPlayer;
    
    // Test JewelryMarket
	tileTestPlayer = new Player("tileTestPlayer");
    JewelryMarket<Player>* testJewelryMarket = new JewelryMarket<Player>();
	
	tileTestPlayer->setJewel(3);
	tileTestPlayer->setCartSize(5);
	cout<< "JewelryMarket action(...) " << "\t\t\t\t" << 
		( (testJewelryMarket->action(*tileTestPlayer) &&
				tileTestPlayer->getJewel() == 0 &&
					tileTestPlayer->getCartSize() == 2)
									?"Succeded":"Failed") << endl;
    delete testJewelryMarket, tileTestPlayer;
    
    // Test FabricMarket
	tileTestPlayer = new Player("tileTestPlayer");
    FabricMarket<Player>* testFabricMarket = new FabricMarket<Player>();
	
	tileTestPlayer->setFabric(3);
	tileTestPlayer->setCartSize(5);
	cout<< "FabricMarket action(...) " << "\t\t\t\t" << 
		( (testFabricMarket->action(*tileTestPlayer) &&
				tileTestPlayer->getFabric() == 0 &&
					tileTestPlayer->getCartSize() == 2)
									?"Succeded":"Failed") << endl;
    delete testFabricMarket, tileTestPlayer;
    
    // Test BlackMarket
    cout<< endl << "Testing BlackMarket action(...)..." << endl;
	tileTestPlayer = new Player("tileTestPlayer");
    BlackMarket<Player>* testBlackMarket = new BlackMarket<Player>();
    cout<< "Before visiting the black market : " << endl;
	cout<< *tileTestPlayer;
	cout<< "After 1rst visit @ the black market : " << endl;
	testBlackMarket->action(*tileTestPlayer);
	cout<< *tileTestPlayer;
	cout<< "After 2nd visit @ the black market : " << endl;
	testBlackMarket->action(*tileTestPlayer);
	cout<< *tileTestPlayer;
	cout<< "After 3rd visit @ the black market : " << endl;
	testBlackMarket->action(*tileTestPlayer);
	cout<< *tileTestPlayer;
	cout<< "Each time the function is called, numGoods\nfollows a sequence different from the last call \tSuccess" << endl;
	cout<< "When the cart is full, no more gold is taken \t\tSuccess" << endl;
	cout<< "Testing BlackMarket action(...) ended" << endl << endl;
    delete testBlackMarket, tileTestPlayer;
    
    // Test Casino
	tileTestPlayer = new Player("tileTestPlayer");
    Casino<Player>* testCasino = new Casino<Player>();
    cout<< "Testing Casino action(...)..." << endl << endl;
    
    // Rate analysis variables
	enum Prizes {LOOSE, WIN2GOLD, WIN3GOLD, WIN10GOLD};
    array<float, 4> prizeRate = {{.0, .0, .0, .0}};
    
    // Perform occurence rate analysis
	tileTestPlayer->setGold(10000);
	for (int i = 0; i< 10000; i++){
		int goldBeforeCasino = tileTestPlayer->getGold();
		testCasino->action(*tileTestPlayer);
		int goldAfterCasino = tileTestPlayer->getGold();
		
		switch ( goldAfterCasino - goldBeforeCasino ){
			case -1:
				prizeRate.at(LOOSE)++;
				break;
			case 1:
				prizeRate.at(WIN2GOLD)++;
				break;
			case 2:
				prizeRate.at(WIN3GOLD)++;
				break;
			case 9:
				prizeRate.at(WIN10GOLD)++;
				break;
		}
	}
	for (int i = 0; i<4; i++){
		prizeRate.at(i) = prizeRate.at(i)/10000.0*100;
	}
	
	// Analysis of occurence rate results
	cout<< "Prize\t\tOccurence Rate" << endl << endl;
	cout<< "Loose\t\t" << prizeRate.at(LOOSE) << "%" << endl;
	cout<< "Win 2 gold\t" << prizeRate.at(WIN2GOLD) << "%" << endl;
	cout<< "Win 3 gold\t" << prizeRate.at(WIN3GOLD) << "%" << endl;
	cout<< "Win 10 gold\t" << prizeRate.at(WIN10GOLD) << "%" << endl <<endl;
	cout<< "Prizes occurence rates match expected rates \t\tSuccess" << endl;
	cout<< "Testing Casino action(...) ended" << endl << endl;
	
    delete testCasino, tileTestPlayer;
    
    // Test GemMerchant
	tileTestPlayer = new Player("tileTestPlayer");
    GemMerchant<Player>* testGemMerchant = new GemMerchant<Player>();
		//TODO: implement tests
    delete testGemMerchant, tileTestPlayer;
    
    // Test Palace
	tileTestPlayer = new Player("tileTestPlayer");
    Palace<Player>* testPalace = new Palace<Player>();
		//TODO: implement tests
    delete testPalace, tileTestPlayer;
	
	cout<< "----------------------Tile tests ended---------------------------------" << endl << endl;
	
	cout<< "Testing the creation of a 6x6 board with 4 players" << endl << endl;
	
	*/
    
	cout << "CSI2372 Final Project" << endl;
	cout << "by Patrice Boulet & Mazhar Shar" << endl << endl;
	cout << "************************************************************************" << endl;
	cout << "***********************************AGAME********************************" << endl;
	cout << "************************************************************************" << endl << endl;

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
	vector<string> playerNames;
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
	GameBoard<Tile<Player>*, Player, 6 ,6>* gameBoard = 
		new typename GameBoard<Tile<Player>*, Player, 6, 6>::GameBoard(playerNames.data(), playerNames.size());

	bool hasWon = false;
	while (!hasWon)
    {
        // Check for pause
		for( string currentPlayerName : playerNames)
        {
			Player currentPlayer = gameBoard->getPlayer(currentPlayerName);
			cout << "Current player:" << currentPlayerName << endl;
			cout<< currentPlayer << endl;
			gameBoard->printCurrentLocation(currentPlayerName);
	
			Tile<Player>* currentPlayerTile = gameBoard->getTile(currentPlayer.getName());
			int i, j;
			int* iPtr = &i;
			int* jPtr = &j;
			currentPlayerTile->getCoordinate(iPtr, jPtr);
			array<bool, 4> validMoves = {true,true,true,true};
			gameBoard->getValidMoves(validMoves.data(), i, j);
			int moveInt; // delete because not used? - M
			cout << "Where do you want to move next ? Enter your command number and press ENTER " << endl;
			
			if(validMoves[UP])
				cout << "0-UP\t";
            
			if(validMoves[RIGHT])
				cout << "1-RIGHT\t";
            
			if(validMoves[DOWN])
				cout << "2-DOWN\t";
            
			if(validMoves[LEFT])
				cout << "3-LEFT\t";
			
			// Current player inputting its next tile direction
			bool invalidInput = true;
			int input;
            string actionInput;
			while(invalidInput)
			{
				cin >> input;
                //cin >> actionInput; - Testing save -M
				if ( cin.fail() )
                {
					cout<<"Anything that is not an integer is not a valid choice, input your direction again:" << endl;
					cin.clear(); 
			  		cin.ignore(100, '\n'); 
				}else
                {
                    //if(actionInput == "p")
                        //cout << gameBoard; - Testing save - M
					Move direction = static_cast<Move>(input);
					if( (direction == UP && validMoves[UP])	||
							(direction == RIGHT && validMoves[RIGHT]) ||
								(direction == DOWN && validMoves[DOWN]) ||
									(direction == LEFT && validMoves[LEFT]) )
                    {
						invalidInput = false;
						gameBoard->move(direction, currentPlayer.getName());
						cout << string( 100, '\n' );
						cout << "Current player:" << endl;
						cout << currentPlayer << endl;
						gameBoard->printCurrentLocation(currentPlayer.getName());
						currentPlayerTile = gameBoard->getTile(currentPlayer.getName());
						if( (currentPlayerTile->getPlayers()).size() > 1)
                        {
							cout << endl << "Other player(s) on this tile : ";
							for( string sameTilePlayerName : currentPlayerTile->getPlayers())
                            {
								if (sameTilePlayerName != currentPlayer.getName())
									cout << sameTilePlayerName << " ";
							}	
							cout << endl;
							cout << "(It will cost you 1 more gold per other player on this tile to do an action.)" << endl << endl;
						}
						cout << *currentPlayerTile;
					}else
                    {
						cout<< "Sorry, not a valid direction." << endl;  
						cout<< "Please enter again in which direction you want to go:" << endl;
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
								}else{
									if( currentPlayer.getRuby() == 5)
                                    {
										cout<< "\t\t\t" << currentPlayerName << " HAS WON." << endl;
										cout<< endl << endl << "\t\t\tThank you for playing." << endl << endl; 
										hasWon = true;
										break;
									}
									if( currentPlayerTile->getType() != RESTAURANT)
										currentPlayer.eat();
									for(string recipientPlayerName : currentPlayerTile->getPlayers())
                                    {
										if( recipientPlayerName.compare(currentPlayerName))
                                        {
											Player recipientPlayer = gameBoard->getPlayer(recipientPlayerName);
											currentPlayer.pay(recipientPlayer);
											gameBoard->setPlayer(recipientPlayer);				
										}
									}
									gameBoard->setPlayer(currentPlayer);
									cout << endl << "Your status after performing this action is: " << endl;
									cout << currentPlayer << endl;	
								}
								invalidInput = false;
							}else if( !actionInput.compare("n") || !actionInput.compare("N") )
                            {
								invalidInput = false;
							}else
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
	}
}
	
    return 0;
}


