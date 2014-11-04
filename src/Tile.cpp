//
//  Tile.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Tile.h"
#include <stdlib.h>

template <typename J>
bool Restaurant<J>::action(Player& player){
	player.setFood(10);
	return true;
}

template <typename J>
bool SpiceMerchant<J>::action(Player& player){
	
	if( player.getGold() > 1 && !player.cartIsFull()){
		player.setGold(player.getGold()-2);
		for( int i = 0; i < 3; i++){
			if( player.incrementCartSize() ){
				player.setSpice(player.getSpice()+1);
			}
		}
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool FabricManufacturer<J>::action(Player& player){
	
	if( player.getGold() > 1 && !player.cartIsFull()){
		player.setGold(player.getGold()-2);
		for( int i = 0; i < 3; i++){
			if( player.incrementCartSize() ){
				player.setFabric(player.getFabric()+1);
			}
		}
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool Jeweler<J>::action(Player& player){
	
	if( player.getGold() > 1 && !player.cartIsFull()){
		player.setGold(player.getGold()-2);
		for( int i = 0; i < 3; i++){
			if( player.incrementCartSize() ){
				player.setJewel(player.getJewel()+1);
			}
		}
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool CartManufacturer<J>::action(Player& player){

	if( player.getGold() > 6){
		player.setCartCapacity(player.getCartCapacity() + 3 );
		player.setGold(player.getGold() - 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool SmallMarket<J>::action(Player& player){
	
	if( player.getFabric() > 0 &&
			player.getJewel() > 0 &&
				player.getSpice() > 0){
		player.setFabric(player.getFabric() - 1);
		player.setJewel(player.getJewel() - 1);
		player.setSpice(player.getSpice() - 1);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 8);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool SpiceMarket<J>::action(Player& player){
	
	if( player.getSpice() > 2 ){
		player.setSpice(player.getSpice() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool JewelryMarket<J>::action(Player& player){
	
	if( player.getJewel() > 2 ){
		player.setJewel(player.getJewel() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool FabricMarket<J>::action(Player& player){
	
	if( player.getFabric() > 2 ){
		player.setFabric(player.getFabric() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool BlackMarket<J>::action(Player& player){
	
	if( player.getGold() > 0 && !player.cartIsFull()){
		
		int numGoods = rand() % 6;
		cout<< "numGoods = " << numGoods << endl;
		for( int i = 0; i < numGoods; i++){
			if( player.incrementCartSize() ){
				int typeOfGood = rand() % 4;
				switch ( typeOfGood ){
					case SPICE :
						player.setSpice(player.getSpice() + 1);
						break;
					case FABRIC :
						player.setFabric(player.getFabric() + 1);
						break;
					case JEWEL :
						player.setJewel(player.getJewel() + 1);
						break;
					case RUBY :
						player.setRuby(player.getRuby() + 1);
						break;
				}
			}		
		}
		player.setGold(player.getGold() - 1);
		return true;
	}else{
		return false;
	}
}

template <typename J>
bool Casino<J>::action(Player& player){
	//TODO: Implement this function
}

template <typename J>
bool GemMerchant<J>::action(Player& player){
	//TODO: Implement this function
}

template <typename J>
bool Palace<J>::action(Player& player){
	//TODO: Implement this function
}

template class Restaurant<Player>;
template class SpiceMerchant<Player>;
template class FabricManufacturer<Player>;
template class Jeweler<Player>;
template class CartManufacturer<Player>;
template class SmallMarket<Player>;
template class SpiceMarket<Player>;
template class JewelryMarket<Player>;
template class FabricMarket<Player>;
template class BlackMarket<Player>;
template class Casino<Player>;
template class GemMerchant<Player>;
template class Palace<Player>;

