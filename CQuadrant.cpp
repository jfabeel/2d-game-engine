//
//  CQuadrant.cpp
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#include "CQuadrant.h"

bool CQuadrant::IncludesID(int ID)
{
    for (int index = 0; index < IDs.size(); index++)
    {
        if (IDs.at(index) == ID)
        {
            return true;
        }
    }
    
    return false;
}

void CQuadrant::setBounds(int x, int y, int width, int height)
{
    Rectangle *rectangle = new Rectangle(x, y, width, height);
    this->setBounds(rectangle);
}