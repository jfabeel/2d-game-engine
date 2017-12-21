/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#ifndef C_TEXTURE_MANAGER
#define C_TEXTURE_MANAGER
#include "SDL.h"
#include "SDL_opengl.h"
#include <iostream>
#include <SDL_image/SDL_image.h>
#include <vector>
#include "structs.h"

class CTextureManager {
private:
	GLuint currentlyBoundTexture;
	std::vector <Image> images;
public:
	void bindTexture(GLuint texture);
	void bindTexture(Texture tex);
	CTextureManager()
	{
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	}
	Texture loadTexture(SDL_Surface *surface);
	Texture loadText(SDL_Surface *surface);
	bool isTextureAlreadyBound(Texture tex);
	Texture loadTexture(const char *filename);
	bool isTextureAlreadyBound(GLuint texture);
	static CTextureManager *Instance() {
		static CTextureManager inst;
		return &inst;
	}
};

#endif