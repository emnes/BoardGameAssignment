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

ostream& operator<<(ostream& os, const Player& player)
{
	return os 	<< "Food\tGold\tSpice\tFabric\tJewel\tRuby\tCart Capacity\tCart Size" << endl
					<< player.getFood() << "\t"
						<< player.getGold() << "\t"
							<< player.getSpice() << "\t"
								<< player.getFabric() << "\t"
									<< player.getJewel() << "\t"
										<< player.getRuby() << "\t"
											<< player.getCartCapacity() << "\t\t"
												<< player.getCartSize() << endl;
}
