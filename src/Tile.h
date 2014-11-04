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

template<typename J> 
class Tile{
	
	private:
		vector<J> players;
		
	public:
		//bool operation==(const Tile &t);
		virtual bool action( Player& player){return false;}
		//virtual Tile* clone();
		//ostream& operation<<;
};

template<typename J>
class Restaurant : public Tile<J>{
	
	public:	
		virtual bool action( Player& player) override;
};

template<typename J>
class SpiceMerchant : public Tile<J>{
	
	public:	
		bool action( Player& player) override;
};

template<typename J>
class FabricManufacturer : public Tile<J>{
	
	public:	
		bool action( Player& player) override;
};

template<typename J>
class Jeweler : public Tile<J>{
	
	public:	
		bool action( Player& player) override;
};

template<typename J>
class CartManufacturer : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class SmallMarket : public Tile<J>{
	
	public:	
		bool action( Player& player) override;
};

template<typename J>
class SpiceMarket : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class JewelryMarket : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class FabricMarket : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class BlackMarket : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class Casino : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class GemMerchant : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

template<typename J>
class Palace : public Tile<J>{
	
	public:
		bool action( Player& player) override;
};

#endif /* defined(__BoardGame__Tile__) */
