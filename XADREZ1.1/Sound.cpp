#include "Sound.h"
 
using namespace std;
 

 Sound::Sound()
	{
	}

// Buffers to hold sound data.
ALuint Buffer;
 
// Sources are points of emitting sound.
ALuint Source;
 
/*
 * These are 3D cartesian vector coordinates. A structure or class would be
 * a more flexible of handling these, but for the sake of simplicity we will
 * just leave it as is.
 */
 
// Position of the source sound.
ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
 
// Velocity of the source sound.
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };
 
// Position of the Listener.
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
 
// Velocity of the Listener.
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
 
// Orientation of the Listener. (first 3 elements are "at", second 3 are "up")
// Also note that these should be units of '1'.
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };
 
/*
 * ALboolean LoadALData()
 *
 *         This function will load our sample data from the disk using the Alut
 *         utility and send the data into OpenAL as a buffer. A source is then
 *         also created to play that buffer.
 */
ALboolean Sound::LoadALData1()
{
            // Variables to load into.
            ALenum format;
            ALsizei size;
            ALvoid* data;
            ALsizei freq;
            ALboolean loop;
 
            // Load wav data into a buffer.
            alGenBuffers(1, &Buffer);
 
            if(alGetError() != AL_NO_ERROR)
                        return AL_FALSE;
 
			// Load any of your favourite wav song here
            alutLoadWAVFile((ALbyte *)"wavdata/file1.wav", &format, &data, &size, &freq, &loop);
            alBufferData(Buffer, format, data, size, freq);
            alutUnloadWAV(format, data, size, freq);
 

            // Bind the buffer with the source.
            alGenSources(1, &Source);
 
            if(alGetError() != AL_NO_ERROR)
                        return AL_FALSE;
 
            alSourcei (Source, AL_BUFFER,   Buffer   );
            alSourcef (Source, AL_PITCH,    1.0      );
            alSourcef (Source, AL_GAIN,     1.0      );
            alSourcefv(Source, AL_POSITION, SourcePos);
            alSourcefv(Source, AL_VELOCITY, SourceVel);
            alSourcei (Source, AL_LOOPING,  loop     );
 
            // Do another error check and return.
            if(alGetError() == AL_NO_ERROR)
                        return AL_TRUE;
 
            return AL_FALSE;
}
 
ALboolean Sound::LoadALData2()
{
            // Variables to load into.
            ALenum format;
            ALsizei size;
            ALvoid* data;
            ALsizei freq;
            ALboolean loop;
 
            // Load wav data into a buffer.
            alGenBuffers(1, &Buffer);
 
            if(alGetError() != AL_NO_ERROR)
                        return AL_FALSE;

			// Load any of your favourite wav song here
            alutLoadWAVFile((ALbyte *)"wavdata/file2.wav", &format, &data, &size, &freq, &loop);
            alBufferData(Buffer, format, data, size, freq);
            alutUnloadWAV(format, data, size, freq);
 
            // Bind the buffer with the source.
            alGenSources(1, &Source);
 
            if(alGetError() != AL_NO_ERROR)
                        return AL_FALSE;
 
            alSourcei (Source, AL_BUFFER,   Buffer   );
            alSourcef (Source, AL_PITCH,    1.0      );
            alSourcef (Source, AL_GAIN,     1.0      );
            alSourcefv(Source, AL_POSITION, SourcePos);
            alSourcefv(Source, AL_VELOCITY, SourceVel);
            alSourcei (Source, AL_LOOPING,  loop     );
 
            // Do another error check and return.
            if(alGetError() == AL_NO_ERROR)
                        return AL_TRUE;
 
            return AL_FALSE;
}
 
/*
 * void SetListenerValues()
 *
 *         We already defined certain values for the Listener, but we need
 *         to tell OpenAL to use that data. This function does just that.
 */
void Sound::SetListenerValues()
{
            alListenerfv(AL_POSITION,    ListenerPos);
            alListenerfv(AL_VELOCITY,    ListenerVel);
            alListenerfv(AL_ORIENTATION, ListenerOri);
}
 
/*
 * void KillALData()
 *
 *         We have allocated memory for our buffers and sources which needs
 *         to be returned to the system. This function frees that memory.
 */
void Sound::KillALData()
{
            alDeleteBuffers(1, &Buffer);
            alDeleteSources(1, &Source);
            alutExit();
}

void Sound::SomMovimento1()
{
	            // Initialize OpenAL and clear the error bit. 
            alutInit(NULL, 0);
            alGetError();
 
            // Load the wav data. 
            if(LoadALData1() == AL_FALSE) //method 1: LoadALData()
            {
                printf("Error loading data.");     
            }
 
            SetListenerValues(); //method 2: void SetListenerValues()
 
            // Setup an exit procedure. 
           // atexit(KillALData); //method 3: void KillALData()
 
			alSourcePlay(Source);
}

void Sound::SomMovimento2()
{
	            // Initialize OpenAL and clear the error bit. 
            alutInit(NULL, 0);
            alGetError();
 
            // Load the wav data. 
            if(LoadALData2() == AL_FALSE) //method 1: LoadALData()
            {
                printf("Error loading data.");     
            }
 
            SetListenerValues(); //method 2: void SetListenerValues()
 
            // Setup an exit procedure. 
           // atexit(KillALData); //method 3: void KillALData()
 
			alSourcePlay(Source);
}
 
 
