//
//  CSprite.cpp
//  2DGame
//
//  Created by John Abeel on 5/6/11.
//  Copyright 2011 Wakefield School. All rights reserved.
//

#include "CSprite.h"

void CSprite::SetImage(const char *filename, int frame_count, int row_count, int frame_speed)
{
    texture = CTextureManager::Instance()->loadTexture(filename);
	animation = new CAnimation(getTextureWidth(), getTextureHeight(), frame_count, row_count, frame_speed, 0, 0);
    animation->toggleAnimation(false);
}

void CSprite::Update()
{
    animation->Update();
}

void CSprite::Render(int x, int y, int width, int height)
{
    CRenderer::Instance()->drawRectangle(x, y, width, height, texture.textureId, animation->getTextureCoordinates().s1, animation->getTextureCoordinates().t1, animation->getTextureCoordinates().s2, animation->getTextureCoordinates().t2);
}

int CSprite::getTextureWidth()
{
    return texture.width;
}

int CSprite::getTextureHeight()
{
    return texture.height;
}

GLuint CSprite::getTextureID()
{
    return texture.textureId;
}

void CSprite::PauseAnimation(bool flag)
{
    animation->toggleAnimation(flag);
}

void CSprite::SetRow(int row)
{
    animation->setRow(row);
}