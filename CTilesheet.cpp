/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CTilesheet.h"

void CTilesheet::LoadTilesheet(const char *filename, int tileSize)
{
	this->currentTexture = CTextureManager::Instance()->loadTexture(filename);
	this->textureWidth = currentTexture.width;
	this->textureHeight = currentTexture.height;
	this->tileSize = tileSize;
}
TextureCoordinates CTilesheet::getTilesheetCoordinates(int desiredTileIndexX, int desiredTileIndexY)
{
	GLfloat textureCoordinateS1;
	GLfloat textureCoordinateT1;
	GLfloat textureCoordinateS2;
	GLfloat textureCoordinateT2;
	
	textureCoordinateS1 = (desiredTileIndexX) * (this->tileSize / this->textureWidth);
	textureCoordinateT1 = (desiredTileIndexY) * (this->tileSize / this->textureHeight);
	
	textureCoordinateS2 = (desiredTileIndexX + 1) * (this->tileSize / this->textureWidth);
	textureCoordinateT2 = (desiredTileIndexY + 1) * (this->tileSize / this->textureHeight);
	
	TextureCoordinates textureCoordinates;
	textureCoordinates.s1 = textureCoordinateS1;
	textureCoordinates.t1 = textureCoordinateT1;
	textureCoordinates.s2 = textureCoordinateS2;
	textureCoordinates.t2 = textureCoordinateT2;
			
	return textureCoordinates;
}
TextureCoordinates CTilesheet::getTilesheetCoordinates(int desiredTile)
{	
	int amountOfTilesPerRow = (this->textureWidth/this->tileSize);
	int amountOfRows = (this->textureHeight/this->tileSize);
	
	desiredTile = desiredTile-1;
		
	return getTilesheetCoordinates((desiredTile)%amountOfRows, (desiredTile)/amountOfTilesPerRow);
}