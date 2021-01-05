#pragma once
#include <Orbitersdk.h>
#include <XRSound.h>

#include "DLL\DynamicXRS_Interface.h"

class DynamicXRSound : public XRSound
{
public:
	DynamicXRSound(VESSEL* vessel);
	DynamicXRSound(const char* pUniqueModuleName);
	~DynamicXRSound();

	bool IsPresent() const override;

	float GetVersion() const override;

	bool LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType) override;

	bool PlayWav(const int soundID, const bool bLoop = false, const float volume = 1.0) override;

	bool StopWav(const int soundID) override;

	bool IsWavPlaying(const int soundID) const override;

	bool SetPaused(const int soundID, const bool bPause) override;

	bool IsPaused(const int soundID) const override;

	bool SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled) override;

	bool GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const override;

	bool SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath) override;

	const char* GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const override;

private:
	DynamicXRS_DLL* xrSound;
	HINSTANCE xrsDLL;
};