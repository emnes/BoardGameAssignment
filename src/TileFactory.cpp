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
    //return &t;
}

/* 
 * Tile factory constructor.  Register the types of tiles here.
 */
template < class J >
TileFactory<J>::TileFactory(int _nTiles)
{
	nTiles = _nTiles;
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
