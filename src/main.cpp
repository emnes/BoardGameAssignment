//
//  main.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Player.h"
#include <iostream>

using namespace std;

int main() {
    
    // Player test suite
    Player* testPlayer = new Player();
    
    cout<< "----------------------Player tests started------------------------------" << endl;
    
    cout<< "Initialization tests started..." << endl;
    cout<< "gold" << "\t\t\t\t\t" << ((testPlayer->getGold()==5) ?"Succeded":"Failed") << endl;
    cout<< "ruby" << "\t\t\t\t\t" << ((testPlayer->getRuby()==0) ?"Succeded":"Failed") << endl;
    cout<< "spice" << "\t\t\t\t\t" << ((testPlayer->getSpice()==1) ?"Succeded":"Failed") << endl;
    cout<< "fabric" << "\t\t\t\t\t" << ((testPlayer->getFabric()==1) ?"Succeded":"Failed") << endl;
    cout<< "jewel" << "\t\t\t\t\t" << ((testPlayer->getJewel()==1) ?"Succeded":"Failed") << endl;
    cout<< "food" << "\t\t\t\t\t" << ((testPlayer->getFood()==10) ?"Succeded":"Failed") << endl;
    cout<< "cart" << "\t\t\t\t\t" << ((testPlayer->getCartCapacity()==9) ?"Succeded":"Failed") << endl;
    cout<< "Initialization tests ended..." << endl;
    
    // Eats 5 food
    for( int i = 0; i < 5; i++){
    	testPlayer->eat();
    }
	cout<< "eat() " << "\t\t\t\t\t" << ((testPlayer->getFood()==5) ?"Succeded":"Failed") << endl;
	cout<< "canAct() with food > 0 " << "\t\t\t" << (testPlayer->canAct()?"Succeded":"Failed") << endl;
	// Eats food until it goes below 0
     for( int i = 0; i < 6; i++){
    	testPlayer->eat();
    }
    
    cout<< "eat() after food = 0  " << "\t\t\t" << ((testPlayer->getFood()==0) ?"Succeded":"Failed") << endl;
    cout<< "canAct() with food = 0 " << "\t\t\t" << ((!testPlayer->canAct())?"Succeded":"Failed") << endl;
    
    // Test paying a player
    Player* testPlayerToPay = new Player();
    
    cout<< "pay(...) with gold > 0  " << "\t\t" << 
		((testPlayer->pay(*testPlayerToPay)
			&& testPlayer->getGold() == 4
				&& testPlayerToPay->getGold() == 6)?"Succeded":"Failed") << endl;
				
	// testPlayer pays testPlayerToPay until his gold == 0
	for( int i = 0; i < 4; i++){
		testPlayer->pay(*testPlayerToPay);
	}
	cout<< "pay(...) with gold == 0  " << "\t\t" << 
		(!(testPlayer->pay(*testPlayerToPay))?"Succeded":"Failed") << endl;
				
	cout<< "----------------------Player tests ended---------------------------------" << endl;
    return 0;
}
