//
//  Player.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Player.h"

bool Player::pay(Player& player){
	if( this->getGold() > 0){
			++(player.gold);
			--(this->gold);
			return true;
	}else{
		return false;
	}
}
