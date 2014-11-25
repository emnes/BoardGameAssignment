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
#include "Player.h"
#include "Tile.h"
#include "GameBoard.h"

using namespace std;

int main() {
	
	srand(time(NULL));// fix
	/*******************************PLAYER TEST SUITE************************************/
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
	
	/*******************************TILE TEST SUITE************************************/
    
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
	
	
	
	cout << "CSI2372 Final Project" << endl;
	cout << "by Patrice Boulet & Mazhar Shar" << endl << endl;
	cout << "**********************************************************************" << endl;
	cout << "*********************************AGAME********************************" << endl;
	cout << "**********************************************************************" << endl << endl;

	int numOfPlayers;
	cout<< "Enter the number of players:";
	cin >> numOfPlayers;
	
	vector<string> playerNames;
	for( int i = 0; i < numOfPlayers; i++){
		cout<< "Enter the name of player " << i+1 << " : ";
		string playerName;
		cin >> playerName;
		playerNames.push_back(playerName);
	}
	
	// Initialize a a 6x6 board with 4 players of type Player and their respective names.
	GameBoard<Tile<Player>*, Player, 6 ,6>* gameBoard = 
		new typename GameBoard<Tile<Player>*, Player, 6, 6>::GameBoard(
			playerNames.data(), playerNames.size());
	
    return 0;
}
