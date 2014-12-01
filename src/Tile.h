//
//  Tile.cpp
//  BoardGame
//
//  Tile is part of the gameboard. When a player lands on a tile they can execute an action if its possible.
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

using std::vector;
using std::array;

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

template<typename J>  
class Tile
{
private:
	vector<string> players;
	array<int, 2> coordinates;
		
public:
	virtual bool action( Player& player) = 0;										// Action that a player can do on the tile
	virtual TileType getType() const = 0;											// Dynamic type of a tile, refer to the enum
    virtual Tile* clone() = 0;
	virtual void print() const= 0;													// Prints the action prompt for a tile of a certain type
	
	template <typename K>
	friend ostream& operator<<(ostream& os, const Tile<K>& tile);					// Print/Save tile information.

    bool operator==(const Tile &t){                                                 // Compare two tiles.
        if ((t != nullptr))
            if (&this == &t)
                return true;
        
        return false;
    }
	vector<string> getPlayers() const{return players;}								// Returns a vector of the player names
   
   	void addPlayer( const string& playerName){players.push_back(playerName);}		// Adds a player to the tile's current player list
   	void removePlayer(string playerName);											// Removes a player to the tile's current players list
    bool noPlayers(){return players.size() == 0;}
    
    /* Returns the number of other players on same tile 
     * than the current player.
     */
    int numOtherPlayers()
    {
        int numPlayersOnTile = players.size();
        int numOtherPlayersOnTile = 0;
        if( numPlayersOnTile > 1)
            numOtherPlayersOnTile = numPlayersOnTile - 1;
        return numOtherPlayersOnTile;
    }
    void getCoordinate(int *row, int *col){ *row = coordinates[0]; *col = coordinates[1]; }	// Returns the tile's coordinates.
    void setXCoordinate(int xCoord){coordinates[0] = xCoord;}						
    void setYCoordinate(int yCoord){coordinates[1] = yCoord;}
    
    typedef Tile<J>* (__stdcall *CreateTileFn)(void); 								// Create function pointer type definition.
};


template<typename J>
class Desert : public Tile<J>
{
public:
    virtual TileType getType() const override;
    virtual bool action( Player& player ) override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new Desert<J>(); }
    Tile<J>* clone(){return new Desert(*this); }
};

/* Replenishes food. */
template<typename J>
class Restaurant : public Tile<J>
{
public:
    virtual bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new Restaurant<J>(); }
    Tile<J>* clone(){return new Restaurant(*this); }
};

/* Cost: 1 gold.
 * 2/5 - 0 gold.
 * 3/10 - 2 gold.
 * 2/10 - 3 gold.
 * 1/10 - 10 gold.
 */
template<typename J>
class Casino : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new Casino<J>(); }
    Tile<J>* clone(){return new Casino(*this); }
};

/* Exchange 5 rolls of fabrics, 5 pieces of jewelry and 5 sacks of spices for ruby. */
template<typename J>
class Palace : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new Palace<J>(); }
    Tile<J>* clone(){return new Palace(*this); }
};

/* A player can sell 3 pieces of jewelry for 6 pieces of gold. */
template<typename J>
class Jeweler : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new Jeweler<J>(); }
    Tile<J>* clone(){return new Jeweler(*this); }
};

//--------- Manufacturers ---------//

/* For 2 pieces of gold, the player gets three rolls of fabric tissues. */
template<typename J>
class FabricManufacturer : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new FabricManufacturer<J>(); }
    Tile<J>* clone(){return new FabricManufacturer(*this); }
};

/* Increase capacity of cart by 3 for 7 gold. */
template<typename J>
class CartManufacturer : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new CartManufacturer<J>(); }
    Tile<J>* clone(){return new CartManufacturer(*this); }
};

//--------- Markets ---------//

/* Player can sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 gold. */
template<typename J>
class SmallMarket : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new SmallMarket<J>(); }
    Tile<J>* clone(){return new SmallMarket(*this); }
};

/* Sell 3 sacks of spices for 6 gold. */
template<typename J>
class SpiceMarket : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new SpiceMarket<J>(); }
    Tile<J>* clone(){return new SpiceMarket(*this); }
};

/* Sell 3 pieces of jewelry for 6 gold. */
template<typename J>
class JewelryMarket : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new JewelryMarket<J>(); }
    Tile<J>* clone(){return new JewelryMarket(*this); }
};

/* Sell 3 pieces of fabrics for 6 gold. */
template<typename J>
class FabricMarket : public Tile<J>
{
public:
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new FabricMarket<J>(); }
    Tile<J>* clone(){return new FabricMarket(*this); }
};

/* Get between 0 to 5 goods at random for 1 gold. */
template<typename J>
class BlackMarket : public Tile<J>
{
public:
    BlackMarket(){int numOfGoods = rand() % 6;}
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new BlackMarket<J>(); }
    Tile<J>* clone(){return new BlackMarket(*this); }
};

//--------- Merchants ---------//

/* For 2 pieces of gold, a player can purchase 3 sacks of spices. */
template<typename J>
class SpiceMerchant : public Tile<J>
{
public:
    bool action(Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new SpiceMerchant<J>(); }
    Tile<J>* clone(){return new SpiceMerchant(*this); }
};

/* Buy ruby. Cost increases each time ruby is bought here. */
template<typename J>
class GemMerchant : public Tile<J>
{
private:
	unsigned int rubyPrice = 12;
public:
	void increaseRubyPrice(){++rubyPrice;}
	void setRubyPrice(int _rubyPrice){rubyPrice = _rubyPrice;}
	int getRubyPrice() const {return rubyPrice;}
    bool action( Player& player) override;
    virtual TileType getType() const override;
    virtual void print() const;
    static Tile<J>* __stdcall Create() { return new GemMerchant<J>(); }
    Tile<J>* clone(){return new GemMerchant(*this); }
};

/*
 *  Remove player from tile.
 */
template <typename J>
void Tile<J>::removePlayer(string playerName)
{
	auto removeIt = std::remove(players.begin(), players.end(), playerName);
	players.erase(removeIt, players.end());
}

/*
 *  Prints/Saves tile's type, coordinates and any players.
 *  If the tile is a Gem Merchant it also saves its Ruby price.
 */
template <typename K>
ostream& operator<<(ostream& os, const Tile<K>& tile)
{
    os << tile.getType() << " " << tile.coordinates[0] << " " << tile.coordinates[1];
    for(auto p : tile.getPlayers())
    {
        os << " " << "Player" << " " << p;
    }
    if (tile.getType() == GEMMERCHANT) {
    	const GemMerchant<K>& gemMerchant = dynamic_cast<const GemMerchant<K>&>(tile);   	 	
    	os << " RubyPrice " << gemMerchant.getRubyPrice();
    }
    return os;
}
#endif /* defined(__BoardGame__Tile__) */
