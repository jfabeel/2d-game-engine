/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_TILESHEET
#define C_TILESHEET

#include "CTextureManager.h"
#include "structs.h"

class CTilesheet {
private:
	Texture currentTexture;
	GLfloat textureHeight;
	GLfloat textureWidth;
	GLfloat tileSize;
public:
	void LoadTilesheet(const char *filename, int tileSize);
	GLfloat getTileSize() { return tileSize; }
    int getXTileCount() { return currentTexture.width/tileSize; }
    int getYTileCount() { return currentTexture.height/tileSize; }
	TextureCoordinates getTilesheetCoordinates(int desiredTileIndexX, int desiredTileIndexY);
	TextureCoordinates getTilesheetCoordinates(int desiredTile);
	GLuint getTilesheetID() { return currentTexture.textureId; }
};

#endif