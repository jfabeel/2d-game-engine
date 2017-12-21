/***********************************************************************
 ** Rockridge Apps
 ** John Abeel
 ** Copyright (c) 2011. All rights reserved.
 **********************************************************************/
#ifndef C_SOUNDS
#define C_SOUNDS

#include <vector>
#include <SDL_mixer/SDL_mixer.h>

class CSounds {
private:
	std::vector <Mix_Chunk *> sfx;
	std::vector <Mix_Music *> music;
	
public:
	int addMusicTrack(const char *filename);
	int addSoundEffect(const char *filename);
	void playMusicTrack(int ID);
	void playSoundEffect(int ID);
	void pauseMusicTrack();
	void cleanUp();
	
	static CSounds *Instance() 
	{
		static CSounds inst;
		return &inst;
	}
};

#endif