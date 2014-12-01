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
#include <ctime>
#include <algorithm> 	// std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


template< class J>
Tile <J>* TileFactory<J>::next()
{
    TileType tileType = randomTiles.back();
    randomTiles.pop_back();
    return CreateTile(tileType);
}

/*
 * Tile factory constructor.  Register the types of tiles here.
 */
template < class J >
TileFactory<J>::TileFactory(int _nTiles)
{
    int numTilesToCreate = _nTiles;
    int numSpecializedTilesOfEachType = (1.0/14.0)*_nTiles;						// Get the number of specialized tile do generate for each type
    for ( int i = 0; i < numSpecializedTilesOfEachType; i++){					// Put them into an array
        for ( int j = 1; j < 14; j++){
            randomTiles.push_back(static_cast<TileType>(j));
            numTilesToCreate--;
        }
    }
    while( numTilesToCreate > 0){												// The rest of the remaining tile are going to be of type DESERT
        randomTiles.push_back(DESERT);
        numTilesToCreate--;
    }
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();		
    shuffle(randomTiles.begin(), randomTiles.end(), std::default_random_engine(seed));	// Shuffles the array we just created
    
    // Registers all tile types Create function pointers
    Register(DESERT, &Desert<J>::Create);
    Register(RESTAURANT, &Restaurant<J>::Create);
    Register(SPICEMERCHANT, &SpiceMerchant<J>::Create);
    Register(FABRICMANUFACTURER, &FabricManufacturer<J>::Create);
    Register(JEWELER, &Jeweler<J>::Create);
    Register(CARTMANUFACTURER, CartManufacturer<J>::Create);
    Register(SMALLMARKET, &SmallMarket<J>::Create);
    Register(SPICEMARKET, &SpiceMarket<J>::Create);
    Register(JEWELRYMARKET, &JewelryMarket<J>::Create);
    Register(FABRICMARKET, &FabricMarket<J>::Create);
    Register(BLACKMARKET, &BlackMarket<J>::Create);
    Register(CASINO, &Casino<J>::Create);
    Register(GEMMERCHANT, &GemMerchant<J>::Create);
    Register(PALACE, &Palace<J>::Create);
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
    return m_FactoryMap[tileType]();
}

template class TileFactory<Player>;
