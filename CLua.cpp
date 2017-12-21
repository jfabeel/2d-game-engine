//
//  CLua.cpp
//  2DGame
//
//  Created by John Abeel on 5/6/11.
//  Copyright 2011 JGames. All rights reserved.
//

#include "CLua.h"

static int FadeEffect(lua_State *lua)
{
    CSfx::Instance()->fade(1.0f);
    return 0;
}

static int AddSound(lua_State *state)
{
    const char *sound_file = lua_tostring(state, 1);
    CSounds::Instance()->addSoundEffect(sound_file);
    return 0;
}

static int AddMusicTrack(lua_State *state)
{
    const char *music_file = lua_tostring(state, 1);
    CSounds::Instance()->addMusicTrack(music_file);
    return 0;
}

static int PlaySoundTrack(lua_State *state)
{
    int index = lua_tointeger(state, 1);
    CSounds::Instance()->playSoundEffect(index);
    return 0;
}

static int PlayMusicTrack(lua_State *state)
{
    int index = lua_tointeger(state, 1);
    CSounds::Instance()->playMusicTrack(index);
    return 0;
}

static int LoadTileMap(lua_State *state)
{
    const char *tile_map = lua_tostring(state, 1);
    const char *tilesheet = lua_tostring(state, 2);
    int tile_size = lua_tointeger(state, 3);
    CTileMap::Instance()->LoadTilesheet(tilesheet, tile_size);
    CTileMap::Instance()->LoadFile(tile_map);
    return 0;
}

static int InitalizePlayer(lua_State *state)
{
    const char *filename = lua_tostring(state, 1);
    int frame_count = lua_tointeger(state, 2);
    int row_count = lua_tointeger(state, 3);
    int frame_speed = lua_tointeger(state, 4);
    
    CPlayer::Instance()->Init(filename, frame_count, row_count, frame_speed);
    return 0;
}

static int isCollision(lua_State *state)
{
    int x1 = lua_tointeger(state, 1);
    int y1 = lua_tointeger(state, 2);
    int width1 = lua_tointeger(state, 3);
    int height1 = lua_tointeger(state, 4);
    
    int x2 = lua_tointeger(state, 5);
    int y2 = lua_tointeger(state, 6);
    int width2 = lua_tointeger(state, 7);
    int height2 = lua_tointeger(state, 8);
    
    lua_pushnumber(state, CCollision::Instance()->isCollision(x1, y1, width1, height1, x2, y2, width2, height2));
    return 1;
}

void CLua::Init()
{
    luaState = lua_open();
    luaL_openlibs(luaState);
    luaL_dofile(luaState, "main.lua");
    
    lua_register(luaState, "FadeEffect", FadeEffect);
    lua_register(luaState, "AddSound", AddSound);
    lua_register(luaState, "AddMusicTrack", AddMusicTrack);
    lua_register(luaState, "PlaySoundTrack", PlaySoundTrack);
    lua_register(luaState, "PlayMusicTrack", PlayMusicTrack);
    lua_register(luaState, "LoadTileMap", LoadTileMap);
    lua_register(luaState, "InitializePlayer", InitalizePlayer);
    lua_register(luaState, "isCollision", isCollision);
    
    lua_getglobal(luaState, "Init");
	lua_call(luaState, 0, 0);
}

void CLua::Update()
{
    lua_getglobal(luaState, "Update");
    lua_call(luaState, 0, 0);
}

void CLua::Cleanup()
{
    lua_close(luaState);
}
