//
//  CLua.h
//  2DGame
//
//  Created by John Abeel on 5/6/11.
//  Copyright 2011 JGames. All rights reserved.
//
#ifndef CLUA
#define CLUA

#include "CSfx.h"

extern "C" {
    #include "Lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

class CLua
{
   private:
    lua_State *luaState;
   public:
    void Init();
    void Cleanup();
    void Update();
    
    static CLua *Instance()
    {
        static CLua lua;
        return &lua;
    }
};

#endif