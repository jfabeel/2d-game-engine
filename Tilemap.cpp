/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "Tilemap.h"

Rectangle* CTileMap::CreateRect(int x, int y, int height, int width) 
{
	Rectangle* rect = new Rectangle(x, y, width, height);
	
	return rect;
}

int CTileMap::readInt(FILE *fp) 
{
	int i;
	fscanf(fp, "%d", &i);
	return i;
}

void CTileMap::LoadTilesheet(const char *filename, int tilesize)
{
    tilesheet = new CTilesheet();
	tilesheet->LoadTilesheet(filename, tilesize);
}

void CTileMap::Update() 
{
	drawOffset.x = (CMovement::Instance()->getX()*-1);
	drawOffset.y = (CMovement::Instance()->getY()*-1);
	if ((drawOffset.x*-2) < 0) 
	{
		drawOffset.x = 0;
	}
	if ((drawOffset.y*-2) < 0) 
	{
		drawOffset.y = 0;
	}
    
#ifdef SCREEN_COLLISION_BETA
    
	if ((drawOffset.x-CApp::Instance()->getWidth()) * -1 > (xTileCount*32))
	{
		drawOffset.x = -2*(xTileCount*32);
	}
	if ((drawOffset.y-CApp::Instance()->getHeight()) * -1 > (yTileCount*32))
	{
		drawOffset.y = -2*(yTileCount*32);
	}
    
#endif
    glPushMatrix();
	glTranslatef(drawOffset.x, drawOffset.y, 0);
	backgroundLayer->Update(tilesheet);
	firstLayer->Update(tilesheet);
	CPlayer::Instance()->Draw();
	secondLayer->Update(tilesheet);
	collisionLayer->Update(tilesheet);
    glPopMatrix();
	warpLayer->Update();
}

void CTileMap::LoadFile(const char *filename)
{
	FILE *f;
	f = fopen(filename, "rb");
    if (f == NULL)
    {
        std::cout << "File is not available of reconizable" << std::endl;
        return;
    }
	xTileCount = readInt(f);
	yTileCount = readInt(f);
		
	backgroundLayer = new CLayer(xTileCount, yTileCount);
	firstLayer = new CLayer(xTileCount, yTileCount);
	secondLayer = new CLayer(xTileCount, yTileCount);
	collisionLayer = new CCollisionLayer(xTileCount, yTileCount);
	warpLayer = new CWarp(warpCount);
    	
	backgroundLayer->LoadLayer(f, tilesheet);
	firstLayer->LoadLayer(f, tilesheet);
	secondLayer->LoadLayer(f, tilesheet);
	collisionLayer->LoadLayer(f);
	warpLayer->LoadWarps(f);
    
    for (int y = 0; y < yTileCount; y++) 
    {
		for (int x = 0; x < xTileCount; x++) 
        {
            int index = readInt(f);
            if (index != 0)
            {
                CMovement::Instance()->setPosition(new Vector2D((x*32)-CApp::Instance()->getWidth()/2, (y*32) - CApp::Instance()->getHeight()/2));
                break;
            }
        }
    }
		
	fclose(f);
}