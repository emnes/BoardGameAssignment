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

Tile* TileFactory::next()
{
    
    return &t;
}