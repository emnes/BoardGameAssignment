//
//  Tile.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.//

#ifndef __src__Tile__
#define __src__Tile__

#include "Player.h"
#include <vector>

using namespace std;

template<typename T, typename J> 
class Tile{
	
	private:
		vector<J> players;
	public:
		//bool operation==(const Tile &t);
		virtual bool action( Player& player);
		virtual Tile* clone();
		//ostream& operation<<;
};

template<typename T, typename J>
class Restaurant : public Tile<T,J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class SpiceMerchant : public Tile<T,J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class FabricManufactures : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class Jeweler : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class CartManufacturer : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class SmallMarket : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class SpiceMarket : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class JewelryMarket : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class FabricMarket : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class BlackMarket : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class Casino : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class GemMerchant : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

template<typename T, typename J>
class Palace : public Tile<T, J>{
	
	public:
		
		bool action( Player& player) override;
};

#endif /* defined(__BoardGame__Tile__) */
