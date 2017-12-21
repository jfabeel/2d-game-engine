/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifdef BETA
#include "CMinimap.h"

void CMiniMap::Update()
{	
	CCRenderer::Instance()::Instance()->SetColor(red, green, blue, alpha);
	for (int index = 0; index < (CApp::Instance()->GetWidth()/32) + (CApp::Instance()->GetHeight()/32); index++)
	{
		if (CTileMap::Instance()->isSolid(index))
		{
			CRenderer::Instance()->drawPixel(index%(CApp::Instance()->GetWidth()/32), index/(CApp::Instance()->GetHeight()/32));
		}
	}
}

#endif