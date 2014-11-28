//
//  Tile.cpp
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "Tile.h"

using namespace std;

template <typename J>
bool Desert<J>::action(Player& player){
	return false;
}

template <typename J>
TileType Desert<J>::getType() { return DESERT;}

template <typename J>
string Desert<J>::print() const {
	return "Desert : You cannot perform any action.";
}

template <typename J>
bool Restaurant<J>::action(Player& player){
	player.setFood(10);
	return true;
}

template <typename J>
TileType Restaurant<J>::getType(){return RESTAURANT;};

template <typename J>
string Restaurant<J>::print() const {
	return "Restaurant : Replenish food items to 10? (Y/N)";
}

template <typename J>
bool SpiceMerchant<J>::action(Player& player){
	
	if( player.getGold() > 1 &&
			player.getGold() > (1 + Tile<J>::numPlayersOnTile() - 1) &&
				!player.cartIsFull()){
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
TileType SpiceMerchant<J>::getType() { return SPICEMERCHANT;}

template <typename J>
string SpiceMerchant<J>::print() const {
	return "Spice Merchant : Purchase 3 sacks of spices for 2 pieces of gold? (Y/N)";
}

template <typename J>
bool FabricManufacturer<J>::action(Player& player){
	
	if( player.getGold() > 1 &&
			player.getGold() > (1 + Tile<J>::numPlayersOnTile() - 1) &&
				!player.cartIsFull()){
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
TileType FabricManufacturer<J>::getType() { return FABRICMANUFACTURER;}

template <typename J>
string FabricManufacturer<J>::print() const {
	return "Fabric Manufacturer :   Purchase 3 rolls of fabric tissues for 2 pieces of gold? (Y/N)";
}

template <typename J>
bool Jeweler<J>::action(Player& player){
	
	if( player.getGold() > 1 &&
			player.getGold() > (1 + Tile<J>::numPlayersOnTile() - 1) &&
				!player.cartIsFull()){
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
TileType Jeweler<J>::getType() { return JEWELER;}

template <typename J>
string Jeweler<J>::print() const {
	return "Fabric Manufacturer : Purchase 3 pieces of jewelry for 2 pieces of gold? (Y/N)";
}

template <typename J>
bool CartManufacturer<J>::action(Player& player){

	if( player.getGold() > 6 && 
			player.getGold() > (6 + Tile<J>::numPlayersOnTile() - 1)){
		player.setCartCapacity(player.getCartCapacity() + 3 );
		player.setGold(player.getGold() - 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType CartManufacturer<J>::getType() { return CARTMANUFACTURER;}

template <typename J>
string CartManufacturer<J>::print() const {
	return "Cart Manufacturer : Increase cart capacity by 3 for 7 pieces of gold? (Y/N)";
}

template <typename J>
bool SmallMarket<J>::action(Player& player){
	
	if( player.getFabric() > 0 &&
			player.getJewel() > 0 &&
				player.getSpice() > 0 &&
				 player.getGold() > (Tile<J>::numPlayersOnTile() - 2)){
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
TileType SmallMarket<J>::getType() { return SMALLMARKET;}

template <typename J>
string SmallMarket<J>::print() const {
	return "Small Market : Sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 pieces of gold? (Y/N)";
}

template <typename J>
bool SpiceMarket<J>::action(Player& player){
	
	if( player.getSpice() > 2 && player.getGold() > (Tile<J>::numPlayersOnTile() - 2)){
		player.setSpice(player.getSpice() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType SpiceMarket<J>::getType() { return SPICEMARKET;}

template <typename J>
string SpiceMarket<J>::print() const {
	return "Spice Market : Sell 3 sacks of spices for 6 pieces of gold? (Y/N)";
}

template <typename J>
bool JewelryMarket<J>::action(Player& player){
	
	if( player.getJewel() > 2 && player.getGold() > (Tile<J>::numPlayersOnTile() - 2)){
		player.setJewel(player.getJewel() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType JewelryMarket<J>::getType() { return JEWELRYMARKET;}

template <typename J>
string JewelryMarket<J>::print() const {
	return "Jewelry Market : Sell 3 pieces of jewelry for 6 pieces of gold? (Y/N)";
}

template <typename J>
bool FabricMarket<J>::action(Player& player){
	
	if( player.getFabric() > 2 && player.getGold() > (Tile<J>::numPlayersOnTile() - 2)){
		player.setFabric(player.getFabric() - 3);
		player.setCartSize(player.getCartSize() - 3);
		player.setGold(player.getGold() + 6);
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType FabricMarket<J>::getType() { return FABRICMARKET;}

template <typename J>
string FabricMarket<J>::print() const {
	return "Fabric Market : Sell 3 rolls of fabrics for 6 pieces of gold? (Y/N)";
}

template <typename J>
bool BlackMarket<J>::action(Player& player){
	
	if( player.getGold() > (Tile<J>::numPlayersOnTile() - 1) && !player.cartIsFull() && player.getGold() > 0){
		array<int, 4> goodsBought = {0,0,0,0}; // indexes goes like, 0:SPICE, 1:FABRIC, 2:JEWEL, 3:RUBY
		int numGoods = rand() % 6;
		for( int i = 0; i < numGoods; i++){
			if( player.incrementCartSize() ){
				int typeOfGood = rand() % 4;
				switch ( typeOfGood ){
					case SPICE :
						player.setSpice(player.getSpice() + 1);
						goodsBought[0]++;
						break;
					case FABRIC :
						player.setFabric(player.getFabric() + 1);
						goodsBought[1]++;
						break;
					case JEWEL :
						player.setJewel(player.getJewel() + 1);
						goodsBought[2]++;
						break;
					case RUBY :
						player.setRuby(player.getRuby() + 1);
						goodsBought[3]++;
						break;
				}
			}		
		}
		cout << "You just bought " << goodsBought[0] << " spice(s), " <<
										 goodsBought[1] << " fabric tissue(s), " <<
										 	goodsBought[2] << " jewel(s) and " <<
										 		goodsBought[3] << " ruby(ies)." << endl;
												 	
		player.setGold(player.getGold() - 1);
		return true;
	}else{
		return false;
	}
}

template <typename J>
string BlackMarket<J>::print() const {
	return "Black Market : Get between 0 and 5 goods at random for 1 piece of gold? (Y/N)";
}

template <typename J>
TileType BlackMarket<J>::getType() { return BLACKMARKET;}

template <typename J>
bool Casino<J>::action(Player& player){

// Using roulette selection algorithm to achieve weighted randomness
	
	if( player.getGold() > (Tile<J>::numPlayersOnTile() - 1) && player.getGold() > 0){
		
		enum Prizes{WIN10GOLD, WIN3GOLD, WIN2GOLD, LOOSE};
		
		// Initialize success rate for each type of winning, or loss
		array<int, 4> prizesWeights = {{10, 20, 30, 40}};
		
		// Calculate the sum of all weighted success rates
		int sumPrizesWeights = 0;
		for(int i=0; i<4; i++) {
		   sumPrizesWeights += prizesWeights.at(i);
		}
		
		// Take a pseudo-random number greater or equal to 0 
		// and less than sumOfSuccessRates
		int rnd = rand() % sumPrizesWeights;
		
		// Go through the te one at a time, subtracting their 
		// weight from your random number, until you get the item 
		// where the random number is less than that item's weight
		unsigned int prize;
		for(int i=0; i<4; i++) {
		  if(rnd < prizesWeights.at(i)){
		    prize = i;
		    break;
			}
		  rnd -= prizesWeights.at(i);
		}
		
		// Attribute prize that was won 
		switch ( prize ){
			case LOOSE :
				player.setGold(player.getGold() - 1);
				cout << "YOU LOST..." << endl;
				break;
			case WIN2GOLD:
				player.setGold(player.getGold() + 1);
				cout << "YOU WON 2 GOLD!" << endl;
				cout << '\a';
				break;
			case WIN3GOLD:
				player.setGold(player.getGold() + 2);
				cout << "YOU WON 3 GOLD!" << endl;
				cout << '\a'; 
				break;
			case WIN10GOLD:
				player.setGold(player.getGold() + 9);
				cout << "YOU WON 10 GOLD!!!" << endl;
				cout << '\a';
				break;
		}
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType Casino<J>::getType() { return CASINO;}

template <typename J>
string Casino<J>::print() const {
	return "Casino : Gamble for 1 piece of gold? (Y/N)";
}

template <typename J>
bool GemMerchant<J>::action(Player& player){
	unsigned int rubyPrice = 12 + player.getNumVisitsGemMerchant();
	if( (player.getGold() > (rubyPrice-1) ) && !player.cartIsFull()){
		player.setGold(player.getGold() - rubyPrice);
		player.setRuby(player.getRuby() + 1);
		player.incrementCartSize();
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType GemMerchant<J>::getType() { return GEMMERCHANT;}

template <typename J>
string GemMerchant<J>::print() const {
	return "GemMerchant : Buy a ruby for 12 pieces of gold + numbers of times you've bought here? (Y/N)";
}

template <typename J>
bool Palace<J>::action(Player& player){
	if( player.getFabric() > 4 &&
			player.getJewel() > 4 &&
				player.getSpice() > 4){
		player.setFabric(player.getFabric() - 5);
		player.setJewel(player.getJewel() - 5);
		player.setSpice(player.getSpice() - 5);
		player.setRuby(player.getRuby() + 1);
		player.setCartSize(player.getCartSize() - 14);
		return true;
	}else{
		return false;
	}
}

template <typename J>
TileType Palace<J>::getType() { return PALACE;}

template <typename J>
string Palace<J>::print() const {
	return "Palace : Exchange 5 rolls of fabrics, 5 pieces of jewelry and 5 sacks of spices for a ruby? (Y/N)";
}

template class Desert<Player>;
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
