//
//  TileFactory.cpp
//  BoardGame
//
//  TileFactory is a singleton class, only one instance may be created.
//  TileFactory creates all types of tiles in random order. The board is filled with these tiles.
//  _nTiles - inputted number of tiles.
//  floor(1/14) of _nTiles for each type. Rest are desert.
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#include "TileFactory.h"

template< class J>
Tile <J>* TileFactory<J>::next()
{		
	// Initialize success rate for each type of tile
	array<int, 2> tileTypeWeights = {{10, 140}}; // should be dependent of nTiles ? -P
	
	// Calculate the sum of all weighted success rates
	int sumTileTypeWeights = 0;
	for(int i=0; i<2; i++) {
	   sumTileTypeWeights += tileTypeWeights.at(i);
	}
	
	// Take a pseudo-random number greater or equal to 0 
	// and less than sumOfSuccessRates
	int rnd = rand() % sumTileTypeWeights;
	
	// Go through the tile types one at a time, subtracting their 
	// weight from your random number, until you get the item 
	// where the random number is less than that item's weight
	TileType tileType;
	for(int i=0; i<4; i++) {
	  if(rnd < tileTypeWeights.at(i)){
	    tileType = i;
	    break;
		}
	  rnd -= tileTypeWeights.at(i);
	}
	
	// Generate tile type 
	if( tileType == DESERT ){
		return CreateTile(DESERT);
	}else{
		rnd = rand() % 14 + 1;  // Randomly chooses between 13 specialized tile types.
		return CreateTile(rnd);
	}
}

/* 
 * Tile factory constructor.  Register the types of tiles here.
 */
template < class J >
TileFactory<J>::TileFactory(int _nTiles)
{
	srand(time(NULL));// fix
	nTiles = _nTiles;
	Register(DESERT, &Desert<J>::Create());
	Register(RESTAURANT, &Restaurant<J>::Create());
	Register(SPICEMERCHANT, &SpiceMerchant<J>::Create());
	Register(FABRICMANUFACTURER, &FabricManufacturer<J>::Create());
	Register(JEWELER, &Jeweler<J>::Create());
	Register(CARTMANUFACTURER, &CartManufacturer<J>::Create());
	Register(SMALLMARKET, &SmallMarket<J>::Create());
	Register(SPICEMARKET, &SpiceMarket<J>::Create());
	Register(JEWELRYMARKET, &JewelryMarket<J>::Create());
	Register(FABRICMARKET, &FabricMarket<J>::Create());
	Register(BLACKMARKET, &BlackMarket<J>::Create());
	Register(CASINO, &Casino<J>::Create());
	Register(GEMMERCHANT, &GemMerchant<J>::Create());
	Register(PALACE, &Palace<J>::Create());
}

/*
 * Creates a mapping between tile types and their create functions.
 */
template <class J>
void TileFactory<J>::Register(const TileType &tileType, CreateTileFn pfnCreate)
{
   m_FactoryMap[tileType] = pfnCreate;
}

/*
 * Returns a new instance of the given tile type.
 */
template <class J>
Tile<J> *TileFactory<J>::CreateTile(const TileType &tileType)
{
    typename FactoryMap::iterator it = m_FactoryMap.find(tileType);
    if( it != m_FactoryMap.end() )
    	return it->second();
    return NULL;
}

template class TileFactory<Player>;
