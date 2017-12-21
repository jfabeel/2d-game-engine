//
//  CBaseEntity.h
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#ifndef C_BASE_ENTITY
#define C_BASE_ENTITY

#include <math.h>

class CBaseEntity
{
  protected:
    int ID;
  public: 
    CBaseEntity()
    {
        ID = rand() % 999999;
    }
    virtual void Update() = 0;
    virtual void Init()=0;
    virtual void Cleanup() = 0;
    
    int getID()
    {
        return ID;
    }
};

#endif