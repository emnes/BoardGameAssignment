//
//  Player.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__Player__
#define __src__Player__

//#include "Tile.h"
#include <string>
#include <iostream>

using namespace std;

class Player{
	
	private:
		//Class variables
		const string name;
		unsigned int gold = 5;
		unsigned int food = 10;
		
		// Goods for trading
		unsigned int ruby = 0;
		unsigned int spice = 1;
		unsigned int fabric = 1;
		unsigned int jewel = 1;
		
		// Function related variables
		unsigned int numVisitsGemMerchant = 0;
		//Tile& currentTile;
		
		// Cart 
		unsigned int cart = 9;
		unsigned int cartSize = 3;
		
		// Functions
		friend ostream& operator<<(ostream& os, const Player& player);
		
	public:
		Player(string _name) : name(_name){}
				
		// Getters & Setters
		string getName() const {return name;}
		unsigned int getFood() const {return food;}
		unsigned int getGold() const {return gold;}
		unsigned int getRuby() const {return ruby;}
		unsigned int getSpice() const {return spice;}
		unsigned int getFabric() const {return fabric;}
		unsigned int getJewel() const {return jewel;}
		unsigned int getCartCapacity() const {return cart;}
		unsigned int getCartSize() const {return cartSize;}
		unsigned int getNumVisitsGemMerchant() {return numVisitsGemMerchant;}
		//Tile& getCurrentTile(){return currentTile;}
		void setFood(unsigned int _food){food = _food;}
		void setGold(unsigned int _gold){gold = _gold;}
		void setRuby(unsigned int _ruby){ruby = _ruby;}
		void setSpice(unsigned int _spice){spice = _spice;}
		void setFabric(unsigned int _fabric){fabric = _fabric;}
		void setJewel(unsigned int _jewel){jewel = _jewel;}
		void setCartCapacity(unsigned int _cart){cart = _cart;}
		void setCartSize(unsigned int _cartSize){cartSize = _cartSize;}
		//void setCurrentTile(const T& _currentTile){currentTile = _currentTile};
		
		void incrementVisitsGemMerchant(){numVisitsGemMerchant++;}
		
		// Functions
		bool canAct() const{return food>0;}
		void eat() {if(canAct())--food;}
		bool pay(Player& player);
		bool incrementCartSize();
		bool cartIsFull(){return cartSize == cart;}

};

#endif /* defined(__BoardGame__Player__) */
