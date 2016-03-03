#pragma once

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>

class Sound
{
private:
    struct WaveHeaderType
    {
        char chunkId[4];
        unsigned long chunkSize;
        char format[4];
        char subChunkId[4];
        unsigned long subChunkSize;
        unsigned short audioFormat;
        unsigned short numChannels;
        unsigned long sampleRate;
        unsigned long bytesPerSecond;
        unsigned short blockAlign;
        unsigned short bitsPerSample;
        char dataChunkId[4];
        unsigned long dataSize;
    };

public:
    Sound();
    Sound(const Sound&);
    ~Sound();
    bool Initialize(HWND);
    void Shutdown();

    bool PlayBGM(int);
	void StopBGM();
    void PlaySE(int);

private:
    bool InitializeDirectSound(HWND);
    void ShutdownDirectSound();

    bool LoadWaveFile(char*, IDirectSoundBuffer8**);
    void ShutdownWaveFile(IDirectSoundBuffer8**);


private:
    IDirectSound8* m_DirectSound;
    IDirectSoundBuffer* m_primaryBuffer;
    IDirectSoundBuffer8** m_bgmBuffers;
	int num_bgm;
	int current_bgm;

    IDirectSoundBuffer8** m_seBuffers;
    int num_se;
	int currentLaser;
	int currentHit;
};