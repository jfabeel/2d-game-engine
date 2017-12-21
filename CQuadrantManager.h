//
//  CQuadrantManager.h
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#ifndef C_QUADRANT_MANAGER
#define C_QUADRANT_MANAGER

#include "CQuadrant.h"
#include "Tilemap.h"

class CTileMap;

class CQuadrantManager
{
  private:
    std::vector<CQuadrant *> quadrants;
  public:  
    static CQuadrantManager* Instance()
    {
        static CQuadrantManager instance;
        return &instance;
    }
    
    
    void addQuadrant(CQuadrant *quad)
    {
        quadrants.push_back(quad);
    }
    
    void addIDForQuadrantAtIndex(int ID, int index)
    {
        
    }

    void addQuadrant(Rectangle *bounds)
    {
        CQuadrant *quad = new CQuadrant();
        quad->setBounds(bounds);
        quadrants.push_back(quad);
    }
    
    CQuadrant *getQuadrantAtIndex(int index)
    {
        return quadrants.at(index);
    }
    
    void CreateWorld(int x, int y, int width, int height)
    {
        for (int xIndex = x; xIndex < width; xIndex+=(width/10))
        {
            for (int yIndex = y; yIndex < height; yIndex+=(height/10))
            {
                CQuadrant *quad = new CQuadrant;
                quad->setBounds(xIndex, yIndex, width/10, height/10);
                this->addQuadrant(quad);
            }
        }
    }
    
    CQuadrant *getQuadrantAtPosition(int x, int y);
};

#endif