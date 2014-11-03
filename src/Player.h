//
//  Player.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__Player__
#define __src__Player__

class Player{
	
	private:
		unsigned int gold = 5;
		unsigned int food = 10;
		
		// Goods for trading
		unsigned int ruby = 0;
		unsigned int spice = 1;
		unsigned int fabric = 1;
		unsigned int jewel = 1;
		
		// Cart 
		unsigned int cart = 9;
		unsigned int currentCartLength = 3;
		
	public:
		
		// Getters
		unsigned int getFood(){return food;}
		unsigned int getGold(){return gold;}
		unsigned int getRuby(){return ruby;}
		unsigned int getSpice(){return spice;}
		unsigned int getFabric(){return fabric;}
		unsigned int getJewel(){return jewel;}
		unsigned int getCartCapacity(){return cart;}
		
		// Functions
		bool canAct() const{return food>0;}
		void eat() {if(canAct())--food;}
		bool pay(Player& player);
};

#endif /* defined(__BoardGame__Player__) */
