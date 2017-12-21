//
//  CSprite.h
//  2DGame
//
//  Created by John Abeel on 5/6/11.
//  Copyright 2011 Wakefield School. All rights reserved.
//


#ifndef CSPRITE
#define CSPRITE

#include "CTextureManager.h"
#include "CAnimation.h"
#include "CRenderer.h"
#include <OpenGL/OpenGL.h>

class CSprite
{
  private:
    CAnimation *animation;
    Texture texture;
  public:
    void SetImage(const char *filename, int frame_count, int row_count, int frame_speed);
    void Render(int x, int y, int width, int height);
    void Update();
    
    CSprite(){}
    
    int getTextureWidth();
    int getTextureHeight();
    GLuint getTextureID();
    
    void PauseAnimation(bool flag);
    void SetRow(int row);
};

#endif