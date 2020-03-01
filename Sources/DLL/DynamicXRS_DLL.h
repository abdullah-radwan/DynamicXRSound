#pragma once
#include <Orbitersdk.h>
#include "DynamicXRS_Interface.h"

class DynamicXRS : public DynamicXRS_DLL
{
public:
	DynamicXRS(VESSEL* vessel);
	~DynamicXRS();

	bool IsPresent() const override;

	float GetVersion() const override;

	bool LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType) override;

	bool PlayWav(const int soundID, const bool bLoop, const float volume) override;

	bool StopWav(const int soundID) override;

	bool IsWavPlaying(const int soundID) const override;

	bool SetPaused(const int soundID, const bool bPause) override;

	bool IsPaused(const int soundID) const override;

	bool SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled) override;

	bool GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const override;

	bool SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath) override;

	const char* GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const override;

private:
	XRSound* xrSound;
};

DLLCLBK DynamicXRS_DLL* CreateInstance(VESSEL* vessel) { return new DynamicXRS(vessel); }

DLLCLBK void DestroyInstance(DynamicXRS_DLL* instance) { delete instance; }