#include "DynamicXRS_DLL.h"

DynamicXRS::DynamicXRS(VESSEL* vessel)  { xrSound = XRSound::CreateInstance(vessel); }

DynamicXRS::~DynamicXRS() { delete xrSound; }

bool DynamicXRS::IsPresent() const { return xrSound->IsPresent(); }

float DynamicXRS::GetVersion() const { return xrSound->GetVersion(); }

bool DynamicXRS::LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType)
{
	return xrSound->LoadWav(soundID, pSoundFilename, playbackType);
}

bool DynamicXRS::PlayWav(const int soundID, const bool bLoop, const float volume) { return xrSound->PlayWav(soundID, bLoop, volume); }

bool DynamicXRS::StopWav(const int soundID) { return xrSound->StopWav(soundID); }

bool DynamicXRS::IsWavPlaying(const int soundID) const { return xrSound->IsWavPlaying(soundID); }

bool DynamicXRS::SetPaused(const int soundID, const bool bPause) { return xrSound->SetPaused(soundID, bPause); }

bool DynamicXRS::IsPaused(const int soundID) const { return xrSound->IsPaused(soundID); }

bool DynamicXRS::SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled)
{
	return xrSound->SetDefaultSoundEnabled(soundID, bEnabled);
}

bool DynamicXRS::GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const
{
	return xrSound->GetDefaultSoundEnabled(soundID);
}

bool DynamicXRS::SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath)
{
	return xrSound->SetDefaultSoundGroupFolder(defaultSoundID, pSubfolderPath);
}

const char* DynamicXRS::GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const
{
	return xrSound->GetDefaultSoundGroupFolder(defaultSoundID);
}
