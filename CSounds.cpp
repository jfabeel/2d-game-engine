/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/

#include "CSounds.h"

int CSounds::addMusicTrack(const char *filename)
{
	Mix_Music *tempMusic;
	if ((tempMusic = Mix_LoadMUS(filename)) == NULL) return -1;
	music.push_back(tempMusic);
	return (music.size()-1);
}
int CSounds::addSoundEffect(const char *filename)
{
	Mix_Chunk *tempSfx;
	if ((tempSfx = Mix_LoadWAV(filename)) == NULL) return -1;
	sfx.push_back(tempSfx);
	return (sfx.size()-1);
}
void CSounds::playMusicTrack(int ID)
{
	if (ID < 0 || ID > music.size()-1) return;
	if (music[ID] == NULL) return;
	Mix_PlayMusic(music[ID], -1);
}
void CSounds::pauseMusicTrack()
{
	Mix_PauseMusic();
}
void CSounds::playSoundEffect(int ID)
{
	if (ID < 0 || ID > sfx.size()-1) return;
	if (sfx[ID] == NULL) return;
	Mix_PlayChannel(-1, sfx[ID], 0);
}
void CSounds::cleanUp()
{
	for(int i = 0;i < sfx.size();i++) {
        Mix_FreeChunk(sfx[i]);
    }
	
    sfx.clear();
	
	for(int i = 0;i < music.size();i++) {
        Mix_FreeMusic(music[i]);
    }
	
    music.clear();
}