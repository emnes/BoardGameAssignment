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

using namespace std;
enum TileType{DESERT, RESTAURANT, SPICEMERCHANT, FABRICMANUFACTURER, JEWELER,
				CARTMANUFACTURER, SMALLMARKET, SPICEMARKET, JEWELRYMARKET, 
					FABRICMARKET, BLACKMARKET, CASINO, GEMMERCHANT, PALACE }; 

template < class J >
class TileFactory
{

public:
		typedef Tile<J>* (__stdcall *CreateTileFn)(void); 
		
        static TileFactory* Get(int _nTiles)
        {
            static TileFactory instance(_nTiles);
            return &instance;
        }
        Tile<J>* next();
        
        typedef map<TileType, Tile<J>&>  FactoryMap;
    	void Register(const TileType &tileType, CreateTileFn pfnCreate);
    	Tile<J>* CreateTile(const TileType &tileType);
private:
	int nTiles;
    TileFactory<J> (int _nTiles);
    TileFactory<J> (const TileFactory<J> &); // Unimplemented copy ctor prevents singleton being copied
    TileFactory<J> &operator=(const TileFactory<J> &) { return *this; }
    
    FactoryMap m_FactoryMap;
};

#endif /* defined(__BoardGame__TileFactory__) */
