//
//  TileFactory.h
//  BoardGame
//
//  TileFactory is a singleton class, only one instance may be created.
//
//  Created by Mazhar Shar & Patrice Boulet on 28/10/2014.
//  Copyright (c) 2014 Mazhar Shar & Patrice Boulet. All rights reserved.
//

#ifndef __src__TileFactory__
#define __src__TileFactory__

#import "Tile.h"

class TileFactory
{
public:
        static TileFactory* get(int _nTiles)
        {
            static TileFactory tf(_nTiles);
            return &tf;
        }
        Tile* next();
private:
    TileFactory(int _nTiles){};
    TileFactory(TileFactory const&); // Unimplemented copy ctor prevents singleton being copied
    void operator=(TileFactory const&); // Unimplemented assignment operator prevents assignment
};

#endif /* defined(__BoardGame__TileFactory__) */
