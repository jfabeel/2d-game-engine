//
//  CEntityManager.h
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#ifndef C_ENTITY_MANAGER
#define C_ENTITY_MANAGER

#include "CBaseEntity.h"

#include <vector>

class CEntityManager
{
  private:
    std::vector <CBaseEntity *> entities;
  public:
    void Init();
    void Add(CBaseEntity *);
    void Update();
    void Cleanup();
    
    static CEntityManager *Instance()
    {
        static CEntityManager instance;
        return &instance;
    }
};

#endif