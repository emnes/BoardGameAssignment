//
//  Tile.h
//  BoardGame
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.//

#ifndef __src__Tile__
#define __src__Tile__

#include "Player.h"
#include <stdlib.h>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

enum Goods
{
    SPICE,
    FABRIC,
    JEWEL,
    RUBY
};

enum TileType{DESERT, RESTAURANT, SPICEMERCHANT, FABRICMANUFACTURER, JEWELER,
				CARTMANUFACTURER, SMALLMARKET, SPICEMARKET, JEWELRYMARKET, 
					FABRICMARKET, BLACKMARKET, CASINO, GEMMERCHANT, PALACE }; 

// Tile is a template class because in the feature there could be more than one type of Player, for code reuse. -P
template<typename J>  
class Tile
{
private:
	vector<string> players;
	array<int, 2> coordinates;
		
public:
	//bool operator==(const Tile &t);
	virtual bool action( Player& player) = 0;
	virtual TileType getType() = 0;
	//virtual Tile* clone();
	
	template <typename K>
	friend ostream& operator<<(ostream& os, const Tile<J>& tile);
	
	vector<string> getPlayers(){return players;}										// I think we won't be using this anymore. -P
   
   	void addPlayer( const string& playerName){players.push_back(playerName);}	// Adds a player to the tile's current player list
   	void removePlayer(string playerName);								// Removes a player to the tile's current players list
    bool noPlayers(){return players.size() == 0;}
    
    int numPlayersOnTile(){return players.size();}
    void getCoordinate(int *row, int *col){ *row = coordinates[0]; *col = coordinates[1]; }
    void setXCoordinate(int xCoord){coordinates[0] = xCoord;}
    void setYCoordinate(int yCoord){coordinates[1] = yCoord;}
    
    virtual string print() const= 0;
    
    typedef Tile<J>* (__stdcall *CreateTileFn)(void); 
};


template<typename J>
class Desert : public Tile<J>
{
	public:		
		virtual TileType getType() override;
		virtual bool action( Player& player ) override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new Desert<J>(); }
};

template<typename J>
class Restaurant : public Tile<J>
{
	public:
		virtual bool action( Player& player) override;
		virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new Restaurant<J>(); }
};

template<typename J>
class Casino : public Tile<J>
{
    public:
        bool action( Player& player) override;
		virtual TileType getType() override;
		virtual string print() const;       
        static Tile<J>* __stdcall Create() { return new Casino<J>(); }
};

template<typename J>
class Palace : public Tile<J>
{
    public:
        bool action( Player& player) override;
        virtual TileType getType() override;
    	virtual string print() const;
        static Tile<J>* __stdcall Create() { return new Palace<J>(); }
};

template<typename J>
class Jeweler : public Tile<J>
{
    public:
        bool action( Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new Jeweler<J>(); }
};

// Speak to TA about using inheritance for Manufacturers, Merchants and Markets.
//--------- Manufacturers ---------//

template<typename J>
class FabricManufacturer : public Tile<J>
{
	public:	
		bool action( Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;		
		static Tile<J>* __stdcall Create() { return new FabricManufacturer<J>(); }
};

template<typename J>
class CartManufacturer : public Tile<J>
{
    public:
        bool action( Player& player) override;
        virtual TileType getType() override;
        virtual string print() const;
		static Tile<J>* __stdcall Create() { return new CartManufacturer<J>(); }
};

//--------- Markets ---------//

template<typename J>
class SmallMarket : public Tile<J>
{
	public:	
		bool action( Player& player) override;
        virtual TileType getType() override;
        virtual string print() const;
		static Tile<J>* __stdcall Create() { return new SmallMarket<J>(); }
};

template<typename J>
class SpiceMarket : public Tile<J>
{
	public:
		bool action( Player& player) override;
		virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new SpiceMarket<J>(); }
};

template<typename J>
class JewelryMarket : public Tile<J>
{
    public:
		bool action( Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new JewelryMarket<J>(); }
};

template<typename J>
class FabricMarket : public Tile<J>
{
	public:
		bool action( Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new FabricMarket<J>(); }
};

template<typename J>
class BlackMarket : public Tile<J>
{
    public:
        BlackMarket(){int numOfGoods = rand() % 6;} // fix
        bool action( Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new BlackMarket<J>(); }
};

//--------- Merchants ---------//

template<typename J>
class SpiceMerchant : public Tile<J>
{
    public:
        bool action(Player& player) override;
        virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new SpiceMerchant<J>(); }
};

template<typename J>
class GemMerchant : public Tile<J>
{
	public:
		bool action( Player& player) override;
	    virtual TileType getType() override;
		virtual string print() const;
		static Tile<J>* __stdcall Create() { return new GemMerchant<J>(); }
};

template <typename J>
void Tile<J>::removePlayer(string playerName){
	auto removeIt = std::remove(players.begin(), players.end(), playerName);
	players.erase(removeIt, players.end());
}

template <typename K>
ostream& operator<<(ostream& os, const Tile<K>& tile){ 
		os << tile.print() << endl;
	return os;
}

#endif /* defined(__BoardGame__Tile__) */
