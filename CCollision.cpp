/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CCollision.h"


bool CCollision::isCollision(int x1, int y1, int width1, int height1, int x, int y, int width, int height)
{
    
    //if (y1+height1 <= y || y1 <= y+height || x1+width1 <= x || x1 >= x+width)
        //return false;
	
	if( y1+height1 <= y )
    {
        return 0;
    }
    
    if( y1 >= y+height )
    {
        return 0;
    }
    
    if( x1+width1 <= x )
    {
        return 0;
    }
    
    if( x1 >= x+width )
    {
        return 0;
    }
    
    return true;
}


bool CCollision::isCollision(Rectangle *A, int x, int y, int width, int height)
{	
	return isCollision(A->x, A->y, A->w, A->h, x, y, width, height);
}

bool CCollision::isCollision(Rectangle *A, Rectangle *B)
{	
	return isCollision(A, B->x, B->y, B->w, B->h);
}	
