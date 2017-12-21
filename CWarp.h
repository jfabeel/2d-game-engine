/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_WARP
#define C_WARP

#include "CSfx.h"
#include "Tilemap.h"
#include "structs.h"

class CWarp {
private:
	std::vector <Warp> warps;
	int warpCount;
    bool isCollision;
public:
	CWarp(int count);
	void LoadWarps(FILE *fp);
	void Update();
    void Empty() { 
        warps.empty();
        warpCount = 0;
    }
};

#endif