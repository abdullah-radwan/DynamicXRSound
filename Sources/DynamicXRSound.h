#pragma once
#include <Orbitersdk.h>
#include <XRSound.h>

class DynamicXRS_DLL; // Internal DLL class

class DynamicXRSound
{
public:
	DynamicXRSound(VESSEL* vessel);

	bool IsPresent() const;

	float GetVersion() const;

	bool LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType);

	bool PlayWav(const int soundID, const bool bLoop = false, const float volume = 1.0);

	bool StopWav(const int soundID);

	bool IsWavPlaying(const int soundID) const;

	bool SetPaused(const int soundID, const bool bPause);

	bool IsPaused(const int soundID) const;

	bool SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled);

	bool GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const;

	bool SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath);

	const char* GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const;

	~DynamicXRSound();

private:
	DynamicXRS_DLL* xrSound;
	HINSTANCE xrsDLL;
};