#include "DynamicXRSound.h"
#include "DLL\DynamicXRS_Interface.h"

#ifdef _DEBUG
#define DLL_PATH "Modules\\DynamicXRSoundD.dll"
#else
#define DLL_PATH "Modules\\DynamicXRSound.dll"
#endif

DynamicXRSound::DynamicXRSound(VESSEL* vessel)
{
	xrSound = nullptr;

	xrsDLL = LoadLibraryA(DLL_PATH);

	if (xrsDLL)
	{
		typedef DynamicXRS_DLL* (*CreateInstance)(VESSEL*);
		CreateInstance createInstance = reinterpret_cast<CreateInstance>(GetProcAddress(xrsDLL, "CreateInstance"));

		if (createInstance) xrSound = createInstance(vessel);
	}
}

DynamicXRSound::~DynamicXRSound()
{
	if (xrsDLL)
	{
		typedef void (*DestroyInstance)(DynamicXRS_DLL*);
		DestroyInstance destroyInstance = reinterpret_cast<DestroyInstance>(GetProcAddress(xrsDLL, "DestroyInstance"));

		if (destroyInstance) destroyInstance(xrSound);

		FreeLibrary(xrsDLL);
	}
}

bool DynamicXRSound::IsPresent() const 
{ 
	if (!xrSound) return false;

	return xrSound->IsPresent();
}

float DynamicXRSound::GetVersion() const 
{ 
	if (!xrSound) return 0; 

	return xrSound->GetVersion();
}

bool DynamicXRSound::LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType)
{
	if (!xrSound) return false;

	return xrSound->LoadWav(soundID, pSoundFilename, playbackType);
}

bool DynamicXRSound::PlayWav(const int soundID, const bool bLoop, const float volume) 
{ 
	if (!xrSound) return false;

	return xrSound->PlayWav(soundID, bLoop, volume); 
}

bool DynamicXRSound::StopWav(const int soundID) 
{
	if (!xrSound) return false; 

	return xrSound->StopWav(soundID);
}

bool DynamicXRSound::IsWavPlaying(const int soundID) const
{
	if (!xrSound) return false;

	return xrSound->IsWavPlaying(soundID);
}

bool DynamicXRSound::SetPaused(const int soundID, const bool bPause)
{
	if (!xrSound) return false;

	return xrSound->SetPaused(soundID, bPause);
}

bool DynamicXRSound::IsPaused(const int soundID) const
{
	if (!xrSound) return false;

	return xrSound->IsPaused(soundID);
}

bool DynamicXRSound::SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled)
{
	if (!xrSound) return false;

	return xrSound->SetDefaultSoundEnabled(soundID, bEnabled);
}

bool DynamicXRSound::GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const
{
	if (!xrSound) return false;

	return xrSound->GetDefaultSoundEnabled(soundID);
}

bool DynamicXRSound::SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath)
{
	if (!xrSound) return false;

	return xrSound->SetDefaultSoundGroupFolder(defaultSoundID, pSubfolderPath);
}

const char* DynamicXRSound::GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const
{
	if (!xrSound) return nullptr;

	return xrSound->GetDefaultSoundGroupFolder(defaultSoundID);
}
