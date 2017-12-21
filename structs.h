/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_STRUCTS
#define C_STRUCTS


typedef struct 
{
	GLfloat s1;
	GLfloat t1;
	GLfloat s2;
	GLfloat t2;
	
	void Print()
	{
		std::cout << "Texture Coordinate S1: " << s1 << " Texture Coordinate T1: " << t1 << " Texture Coordinate S2: " << s2 << " Texture Coordinate T2: " << t2 << std::endl;
	}
} TextureCoordinates;

typedef struct 
{
	GLfloat x;
	GLfloat y;
} Vertex;

typedef struct 
{
	float r;
	float g;
	float b;
	float alpha;
} Color;

typedef struct
{
   int x;
    int y;
    int width;
    int height;;
    int GID;
    
    bool canSend;
} Warp;

typedef struct 
{
	int x;
	int y;
	int width;
	int height;
	int GID;
} Tile;

typedef struct
{
	GLuint textureId;
	int width;
	int height;
} Texture;

typedef struct 
{
	Texture tex;
	char *filename;
} Image;

typedef enum 
{
	MOVING_RIGHT,
	MOVING_LEFT,
	ON_GROUND,
	MOVING,
	MOVING_DOWN,
	MOVING_UP
} State;

typedef enum {
	LEFT = 2,
	RIGHT = 3,
	UP = 4,
	DOWN = 1,
    UP_LEFT = 5,
    UP_RIGHT = 6,
    DOWN_LEFT = 7,
    DOWN_RIGHT = 8,
    NONE = 15
} Direction;


#endif