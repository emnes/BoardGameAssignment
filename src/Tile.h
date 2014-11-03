//
//  Tile.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.//

#ifndef __src__Tile__
#define __src__Tile__

#include "Player.h">
#include <vector>

using namespace std;

template<typename T> 
class Tile{
	
	private:
		vector<J> players;
	public:
		bool operation==(const Tile &t);
		virtual bool action( Player& player);
		virtual Tile* clone();
		ostream& operation<<;
};

template<typename T>
class Restaurant : public Tile<T>{
};

template<typename T>
class SpiceMerchant : public Tile<T>{
};

template<typename T>
class FabricManufactures : public Tile<T>{
};

template<typename T>
class Jeweler : public Tile<T>{
};

template<typename T>
class CartManufacturer : public Tile<T>{
};

template<typename T>
class SmallMarket : public Tile<T>{
};

template<typename T>
class SpiceMarket : public Tile<T>{
};

template<typename T>
class JewelryMarket : public Tile<T>{
};

template<typename T>
class BlackMarket : public Tile<T>{
};

template<typename T>
class Restaurant : public Tile<T>{
};

template<typename T>
class Restaurant : public Tile<T>{
};

#endif /* defined(__BoardGame__Tile__) */
