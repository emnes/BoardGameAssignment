//
//  Player.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Player.h"

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

bool operator==(const Player& playerA, const Player& playerB)
{
	return playerA.getName()==playerB.getName();
}

void Player::print() const
{
    cout << "Food\tGold\tSpice\tFabric\tJewel\tRuby\tCart Capacity\tCart Size" << endl
    << getFood() << "\t"
    << getGold() << "\t"
    << getSpice() << "\t"
    << getFabric() << "\t"
    << getJewel() << "\t"
    << getRuby() << "\t"
    << getCartCapacity() << "\t\t"
    << getCartSize() << endl;
}

// Save friendly insertion operator.
ostream& operator<<(ostream& os, const Player& player)
{
    // You can add a print function for the UI here or in main
    return os << player.getName() << " " << player.getGold() << " " << player.getFood() << " " << player.getRuby() << " " << player.getSpice() << " " << player.getFabric() << " " << player.getJewel() << " " << player.getNumVisitsGemMerchant() << " " << player.getCartCapacity() << " " << player.getCartSize();
}

// Load friendly extraction operator. (Might not use in final).

istream& operator>>(istream& is, Player& player)
{
    is >> player.gold;
    is >> player.food;
    is >> player.ruby;
    is >> player.spice;
    is >> player.fabric;
    is >> player.jewel;
    is >> player.numVisitsGemMerchant;
    is >> player.cart;
    is >> player.currentCartSize;
    
    return is;
}
