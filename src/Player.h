//
//  Player.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__Player__
#define __src__Player__

#include <string>
#include <iostream>

using std::ostream;
using std::istream;
using std::string;
using std::endl;
using std::cout;

class Player
{
private:
    //Class variables
    string name;
    unsigned int gold = 5;
    unsigned int food = 10;
    
    // Goods for trading
    unsigned int ruby = 0;
    unsigned int spice = 1;
    unsigned int fabric = 1;
    unsigned int jewel = 1;
    
    //Tile& currentTile;
    
    // Cart
    unsigned int cart = 9;
    unsigned int currentCartSize = 3; 	// Keeps track of the current number of goods in the cart. -P
    
    // Functions
    friend ostream& operator<<(ostream& os, const Player& player);
    friend istream& operator>>(istream& is, Player& player);
    
    friend bool operator==(const Player& playerA, const Player& playerB);
    
public:
    Player(string _name) : name(_name){}
    
    // Getters
    string getName() const {return name;}
    unsigned int getFood() const {return food;}
    unsigned int getGold() const {return gold;}
    unsigned int getRuby() const {return ruby;}
    unsigned int getSpice() const {return spice;}
    unsigned int getFabric() const {return fabric;}
    unsigned int getJewel() const {return jewel;}
    unsigned int getCartCapacity() const {return cart;}
    unsigned int getCartSize() const {return currentCartSize;}
    
    // Setters
    void setFood(unsigned int _food){food = _food;}
    void setGold(unsigned int _gold){gold = _gold;}
    void setRuby(unsigned int _ruby){ruby = _ruby;}
    void setSpice(unsigned int _spice){spice = _spice;}
    void setFabric(unsigned int _fabric){fabric = _fabric;}
    void setJewel(unsigned int _jewel){jewel = _jewel;}
    void setCartCapacity(unsigned int _cart){cart = _cart;}
    void setCartSize(unsigned int _cartSize){currentCartSize = _cartSize;}
    
	void print() const;
	
    // Functions
    bool canAct() const{return food>0;}
    void eat() {if(canAct())--food;}
    bool pay(Player& player);
    bool incrementCartSize();
    bool cartIsFull(){return currentCartSize == cart;}
};

#endif /* defined(__BoardGame__Player__) */
