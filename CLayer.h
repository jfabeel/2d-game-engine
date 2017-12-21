/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_LAYER
#define C_LAYER 

#include "defines.h"
#include "CRenderer.h"
#include "Tilemap.h"
#include "CTilesheet.h"
#include <vector>
#include "structs.h"

using namespace std;

class CLayer {
private:
	int xTileCount;
	int yTileCount;
	vector <Tile> tiles;
    vector <TextureCoordinates> cache;
public:
	CLayer(int tileCountX, int tileCountY);
	CLayer();
	void Update(CTilesheet *tilesheet);
	void AddTile(int gid);
	void LoadLayer(FILE *fp, CTilesheet *tilesheet);
	void print();
    TextureCoordinates getTextureCoordinatesForTile(int index) { return cache.at(index); }
    void Empty() {
        tiles.empty();
        cache.empty();
        xTileCount = 0;
        yTileCount = 0;
    }
};

#endif