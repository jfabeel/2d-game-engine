/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef RECTANGLE
#define RECTANGLE

#include "CRenderer.h"
#include "structs.h"

class Rectangle {
public:
	GLfloat x;
	GLfloat y;
	GLfloat w;
	GLfloat h;
	
	Vertex vertex1;
	Vertex vertex2;
	Vertex vertex3;
	Vertex vertex4;
	
	Rectangle();
	
	Rectangle(GLfloat xPos, GLfloat yPos, GLfloat width, GLfloat height)
	{
		x = xPos;
		y = yPos;
		w = width;
		h = height;
		
		vertex1.x = xPos;
		vertex1.y = yPos;

		vertex2.x = xPos+width;
		vertex2.y = yPos;
		
		vertex3.x = xPos;
		vertex3.y = yPos+height;
		
		vertex4.x = xPos+width;
		vertex4.y = yPos+height;
	}
	
	Vertex vertexAtIndex(int index)
	{
		switch (index)
		{
			case 0:
				return vertex1;
			break;
			case 1:
				return vertex2;
			break;
			case 2:
				return vertex3;
			break;
			case 3:
				return vertex4;
			break;
		}
		return vertex1;
	}
	
	void PrintAttributes() { std::cout << "X: " << x << " Y: " << y << " W: " << w << " H: " << h << std::endl; }
	void DebugDraw(Color color) { 
		CRenderer::Instance()->drawHollowRectangle(x, y, w, h, color.r, color.g, color.b, color.alpha);
	}
};

#endif