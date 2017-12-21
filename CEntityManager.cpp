//
//  CEntityManager.cpp
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#include "CEntityManager.h"

void CEntityManager::Init()
{}

void CEntityManager::Add(CBaseEntity *entity)
{
    //Add to certain Quadrant
    entities.push_back(entity);
}

void CEntityManager::Update()
{
    //Implement a quadrant system
}

void CEntityManager::Cleanup()
{
    
}