/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CTextureManager.h"
using namespace std;

Texture CTextureManager::loadText(SDL_Surface *surface)
{
	return loadTexture(surface);
}

void CTextureManager::bindTexture(GLuint texture) 
{
	if (isTextureAlreadyBound(texture)) 
	{
		return;
	}
	glBindTexture(GL_TEXTURE_2D, texture);
	currentlyBoundTexture = texture;
}

void CTextureManager::bindTexture(Texture tex)
{
	if (isTextureAlreadyBound(tex))
	{
		return;
	}
	glBindTexture(GL_TEXTURE_2D, tex.textureId);
	currentlyBoundTexture = tex.textureId;
}

Texture CTextureManager::loadTexture(SDL_Surface *surface)
{
	Texture tex;
	GLuint texture;
	
	SDL_SetColorKey(surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 255, 0, 255));
	
	SDL_Surface *finalSurface = SDL_DisplayFormatAlpha(surface);
	
	glGenTextures(1, &texture);
	bindTexture(texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, finalSurface->w, finalSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, finalSurface->pixels);
	
	tex.textureId = texture;
	tex.width = finalSurface->w;
	tex.height = finalSurface->h;
    
    SDL_FreeSurface(surface);
	
	return tex;
}

Texture CTextureManager::loadTexture(const char *filename) 
{
	for (int i = 0; i < images.size(); i++)
		if (images[i].filename == filename)
			return images[i].tex;
	
	Texture tex;

	if (strstr(filename, ".png") != NULL) {
		SDL_Surface *surface;
		if ( (surface = IMG_Load(filename)) ) { 	
            GLuint texture;
            
            SDL_SetColorKey(surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGBA(surface->format, 0, 0, 0, 0));
            
            SDL_Surface *finalSurface = SDL_DisplayFormatAlpha(surface);
            
            glGenTextures(1, &texture);
            bindTexture(texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, finalSurface->w, finalSurface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, finalSurface->pixels);
            
            tex.textureId = texture;
            tex.width = finalSurface->w;
            tex.height = finalSurface->h;
            
            SDL_FreeSurface(surface);
		} 
		else {
			return tex;
		}    
		
        Image img;
        img.tex = tex;
        img.filename = (char *)filename;
        images.push_back(img);
        return tex;
    }
    
    if (strstr(filename, ".bmp") != NULL) {
		SDL_Surface *surface;
		if ( (surface = SDL_LoadBMP(filename)) ) { 
			tex = loadTexture(surface);
		} 
		else {
			return tex;
		}    
    
        Image img;
        img.tex = tex;
        img.filename = (char *)filename;
        images.push_back(img);
        return tex;
    }
    return tex;
}

bool CTextureManager::isTextureAlreadyBound(Texture tex)
{
	return isTextureAlreadyBound(tex.textureId);
}

bool CTextureManager::isTextureAlreadyBound(GLuint texture) {
	if (texture == currentlyBoundTexture) 
	{
		return true;
	}
	return false;
}