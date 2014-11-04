//
//  main.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Player.h"
#include "Tile.h"
#include <iostream>

using namespace std;

int main() {
	
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
    
	// Test Restaurant
	Player* tileTestPlayer1 = new Player("tileTestPlayer1");
	Player* tileTestPlayer2 = new Player("tileTestPlayer2");
	Player* tileTestPlayer3 = new Player("tileTestPlayer3");
	Restaurant<Player>* testRestaurant = new Restaurant<Player>();
		//TODO: implement tests
	delete testRestaurant, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;
	
	// Test SpiceMerchant
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    SpiceMerchant<Player>* testSpiceMerchant = new SpiceMerchant<Player>();
		//TODO: implement tests
    delete testSpiceMerchant;
    
    // Test FabricManufacturer
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    FabricManufacturer<Player>* testFabricManufacturer = new FabricManufacturer<Player>();
		//TODO: implement tests
    delete testFabricManufacturer, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test Jeweler
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    Jeweler<Player>* testJeweler = new Jeweler<Player>();
		//TODO: implement tests
    delete testJeweler, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test CartManufacturer
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    CartManufacturer<Player>* testCartManufacturer = new CartManufacturer<Player>();
		//TODO: implement tests
    delete testCartManufacturer, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test SmallMarket
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    SmallMarket<Player>* testSmallMarket = new SmallMarket<Player>();
		//TODO: implement tests
    delete testSmallMarket, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test SpiceMarket
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    SpiceMarket<Player>* testSpiceMarket = new SpiceMarket<Player>();
		//TODO: implement tests
    delete testSpiceMarket, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test JewelryMarket
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    JewelryMarket<Player>* testJewelryMarket = new JewelryMarket<Player>();
		//TODO: implement tests
    delete testJewelryMarket, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test FabricMarket
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    FabricMarket<Player>* testFabricMarket = new FabricMarket<Player>();
		//TODO: implement tests
    delete testFabricMarket, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test BlackMarket
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    BlackMarket<Player>* testBlackMarket = new BlackMarket<Player>();
		//TODO: implement tests
    delete testBlackMarket, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test Casino
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    Casino<Player>* testCasino = new Casino<Player>();
		//TODO: implement tests
    delete testCasino, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test GemMerchant
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    GemMerchant<Player>* testGemMerchant = new GemMerchant<Player>();
		//TODO: implement tests
    delete testGemMerchant, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
    
    // Test Palace
	tileTestPlayer1 = new Player("tileTestPlayer1");
	tileTestPlayer2 = new Player("tileTestPlayer2");
	tileTestPlayer3 = new Player("tileTestPlayer3");
    Palace<Player>* testPalace = new Palace<Player>();
		//TODO: implement tests
    delete testPalace, tileTestPlayer1, tileTestPlayer2, tileTestPlayer3;;
	
	cout<< "----------------------Tile tests ended---------------------------------" << endl << endl;
	
    return 0;
}
