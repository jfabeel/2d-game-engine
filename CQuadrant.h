//
//  CQuadrant.h
//  2DGame
//
//  Created by John Abeel on 5/2/11.
//  Copyright 2011 JGames. All rights reserved.
//

#ifndef C_QUADRANT
#define C_QUADRANT

#include "Rectangle.h"
#include <vector>

class CQuadrant {
  private:
    Rectangle *bounds;
    std::vector<int> IDs;
  public:
    bool IncludesID(int ID);
    Rectangle *getBounds(){ return bounds;}
    void setBounds(int x, int y, int width, int height);
    void setBounds(Rectangle *rect) { bounds = rect; }
    void addID(int ID) { 
        IDs.push_back(ID);
    }
};

#endif