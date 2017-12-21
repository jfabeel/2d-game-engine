/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CRenderer.h"

CRenderer::CRenderer()
{
	current_color = new Color;
	
	current_color->r = 1.0f;
	current_color->g = 1.0f;
	current_color->b = 1.0f;
	current_color->alpha = 1.0f;
}

void CRenderer::drawRectangle(int x, int y, int width, int height) 
{
    glDisable(GL_TEXTURE_2D);
	glColor4f(current_color->r, current_color->g, current_color->b, current_color->alpha);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x, y);
	glVertex2f(x+width, y);
	glVertex2f(x, y+height);
	glVertex2f(x+width, y+height);
	glEnd();
	glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawRectangle(int x, int y, int width, int height, Color *colors[4]) 
{
    glDisable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLE_STRIP);
	glColor4f(colors[0]->r, colors[0]->g, colors[0]->b, colors[0]->alpha);
	glVertex2f(x, y);
	glColor4f(colors[1]->r, colors[1]->g, colors[1]->b, colors[1]->alpha);
	glVertex2f(x+width, y);
	glColor4f(colors[2]->r, colors[2]->g, colors[2]->b, colors[2]->alpha);
	glVertex2f(x, y+height);
	glColor4f(colors[3]->r, colors[3]->g, colors[3]->b, colors[3]->alpha);
	glVertex2f(x+width, y+height);
	glEnd();
	glEnable(GL_TEXTURE_2D);
}

void CRenderer::setAlpha(float alpha)
{
	current_color->alpha = alpha;
}
void CRenderer::setColor(float r, float g, float b, float alpha)
{
	current_color->r = r;
	current_color->g = g;
	current_color->b = b;
	current_color->alpha = alpha;
}

void CRenderer::drawPixel(int x, int y)
{
    glDisable(GL_TEXTURE_2D);
	glColor4f(current_color->r, current_color->g, current_color->b, current_color->alpha);
	glBegin(GL_POINT);
	glVertex2f(x, y);
	glEnd();
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawHollowRectangle(int x, int y, int width, int height) 
{
    glDisable(GL_TEXTURE_2D);
	glColor4f(current_color->r, current_color->g, current_color->b, current_color->alpha);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x+width, y);
	glVertex2f(x, y);
	glVertex2f(x, y+height);
	glVertex2f(x+width, y+height);
	glEnd();
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawHollowRectangle(int x, int y, int width, int height, float red, float blue, float green, float alpha)
{
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINE_LOOP);
    glColor4f(red, green, blue, alpha);
    glVertex2f(x+width, y);
	glVertex2f(x, y);
	glVertex2f(x, y+height);
	glVertex2f(x+width, y+height);
	glEnd();
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawText(int x, int y, const char *text)
{
	if(!text||!strlen(text)) return; 
	bool blending;
	if(glIsEnabled(GL_BLEND)) blending = true; 
	glEnable(GL_BLEND); 
    glDisable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glColor4f(current_color->r, current_color->g, current_color->b, current_color->alpha); 
	glRasterPos2f(x,y); 
	while (*text){ 
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text); 
		text++; 
	} 
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawRectangle(int x, int y, int width, int height, GLuint textureID, float texCoordX, float texCoordY, float texCoordX2, float texCoordY2)
{
	CTextureManager::Instance()->bindTexture(textureID);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(texCoordX, texCoordY); glVertex2f(x, y);
	glTexCoord2f(texCoordX2, texCoordY); glVertex2f(x+width, y);
	glTexCoord2f(texCoordX, texCoordY2); glVertex2f(x, y+height);
	glTexCoord2f(texCoordX2, texCoordY2); glVertex2f(x+width, y+height);
	glEnd();
}

void CRenderer::drawRectangle(int x, int y, int width, int height, float red, float blue, float green, float alpha)
{
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(red, green, blue, alpha);
    glVertex2f(x+width, y);
	glVertex2f(x, y);
	glVertex2f(x, y+height);
	glVertex2f(x+width, y+height);
	glEnd();
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::drawRectangle(int x, int y, int width, int height, GLuint textureID) 
{
	
	CTextureManager::Instance()->bindTexture(textureID);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(x+width, y);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y+height);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(x+width, y+height);
	glEnd();
	
}
void CRenderer::drawCircle(int x, int y, int radius) 
{
    glDisable(GL_TEXTURE_2D);
	glColor4f(current_color->r, current_color->g, current_color->b, current_color->alpha);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (int angle = 0; angle <= 360; angle++) 
	{
		glVertex2f(x + sinf(angle) * radius, y + cosf(angle) * radius);
	}
	glEnd();
    glEnable(GL_TEXTURE_2D);
}

void CRenderer::setColor(float r, float g, float b) 
{
	current_color->r = r;
	current_color->g = g;
	current_color->b = b;
}