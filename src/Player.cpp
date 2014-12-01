//
//  Player.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Player.h"

/*
 * Pay 1 gold to a player.
 * 	@param player
 * 		player to pay
 */
bool Player::pay(Player& player)
{
    if( this->getGold() > 0)
    {
        ++(player.gold);
        --(this->gold);
        return true;
    }
    else
        return false;
}

/* 
 * Increments the size of the 
 * cart, i.e. number of items
 * it actually holds.
 */
bool Player::incrementCartSize()
{
    if( currentCartSize < cart )
    {
        this->currentCartSize++;
        return true;
    }
    else
        return false;
}

/*
 * Player are qual if they have the same name
 * as one cannot create two player with the same
 * name inside a game.
 */
bool operator==(const Player& playerA, const Player& playerB)
{
    return playerA.getName()==playerB.getName();
}

/* 
 * Insertion operator. Is used to save the
 * game to file.
 */
ostream& operator<<(ostream& os, const Player& player)
{
    // You can add a print function for the UI here or in main
    return os << player.getName() << " " << player.getGold() << " "
    << player.getFood() << " " << player.getRuby() << " "
    << player.getSpice() << " " << player.getFabric() << " "
    << player.getJewel() << " " << player.getCartCapacity() << " "
    << player.getCartSize();
}

/* 
 * Prints the status of a player.
 * Used to print the status in gameplay ui.
 */
void Player::print() const
{
    cout << "Gold\tFood\tSpice\tFabric\tJewel\tRuby\tCart Capacity\tCart Size" << endl
    << getGold() << "\t"
    << getFood() << "\t"
    << getSpice() << "\t"
    << getFabric() << "\t"
    << getJewel() << "\t"
    << getRuby() << "\t"
    << getCartCapacity() << "\t\t"
    << getCartSize() << endl;
}

/*
 * Extraction opertor.  Used
 * in loading of a player from file.
 */
istream& operator>>(istream& is, Player& player)
{
    is >> player.gold;
    is >> player.food;
    is >> player.ruby;
    is >> player.spice;
    is >> player.fabric;
    is >> player.jewel;
    is >> player.cart;
    is >> player.currentCartSize;
    
    return is;
}
