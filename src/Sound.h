#pragma once
#include <iostream>
 
#include <conio.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

class Sound
{
public:
	Sound(void);
	~Sound(void);

	ALboolean LoadALData1();
	ALboolean LoadALData2();
	void SetListenerValues();
	void Sound::KillALData();
	void SomMovimento1();
	void SomMovimento2();
};

