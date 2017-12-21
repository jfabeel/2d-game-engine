//
//  CQuadrantManager.cpp
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#include "CQuadrantManager.h"

CQuadrant *CQuadrantManager::getQuadrantAtPosition(int x, int y)
{
    return getQuadrantAtIndex(x + y * (CTileMap::Instance()->getXCount()));// * CTileMap::Instance()->getTileSize()));
}