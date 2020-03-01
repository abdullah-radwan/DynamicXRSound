#pragma once
#include <XRSound.h>

class DynamicXRS_DLL
{
public:
	virtual bool IsPresent() const = 0;

	virtual float GetVersion() const = 0;

	virtual bool LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType) = 0;

	virtual bool PlayWav(const int soundID, const bool bLoop, const float volume) = 0;

	virtual bool StopWav(const int soundID) = 0;

	virtual bool IsWavPlaying(const int soundID) const = 0;

	virtual bool SetPaused(const int soundID, const bool bPause) = 0;

	virtual bool IsPaused(const int soundID) const = 0;

	virtual bool SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled) = 0;

	virtual bool GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const = 0;

	virtual bool SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath) = 0;

	virtual const char* GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const = 0;

	virtual ~DynamicXRS_DLL() { }
};