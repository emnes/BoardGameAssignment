//
//  TileFactory.h
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

#ifndef __src__TileFactory__
#define __src__TileFactory__

#include "Tile.h"
#include <map>

using std::map;

template < class J >
class TileFactory
{
    
public:
    typedef Tile<J>* (*CreateTileFn)(void);
    typedef map<TileType, CreateTileFn>  FactoryMap;
    
    static TileFactory* Get(int _nTiles)					    		// Gets a singleton instance of a TileFactory
    {
        static TileFactory instance(_nTiles);
        return &instance;
    }
    ~TileFactory()														// d-tor
    {
        m_FactoryMap.clear();
    }
    Tile<J>* next();													// Returns new tile pointer of a random tileType.
    
    void Register(const TileType &tileType, CreateTileFn pfnCreate);	// Register the create function of each tile type.
    Tile<J>* CreateTile(const TileType &tileType);						// Broker for more specific tile Create functinos
    
private:
    vector<TileType> randomTiles;		     							// Holds the remaining types of tile to be created randomly
    TileFactory<J> (int _nTiles);
    TileFactory<J> &operator=(const TileFactory<J> &) { return *this; }	// Singleton pattern, cannot created a new instance while one exists
    
    FactoryMap m_FactoryMap;											// Holds function pointers associated with each tile type Create function
};

#endif /* defined(__BoardGame__TileFactory__) */
