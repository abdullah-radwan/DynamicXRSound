#include "DynamicXRSound.h"

#ifdef _DEBUG
#define DLL_PATH "Modules\\DynamicXRSoundD.dll"
#else
#define DLL_PATH "Modules\\DynamicXRSound.dll"
#endif

XRSound* XRSound::CreateInstance(VESSEL* pVessel)
{
	return new DynamicXRSound(pVessel);
}

XRSound* XRSound::CreateInstance(const char* pUniqueModuleName)
{
	return new DynamicXRSound(pUniqueModuleName);
}

DynamicXRSound::DynamicXRSound(VESSEL* vessel)
{
	xrSound = nullptr;

	xrsDLL = LoadLibraryA(DLL_PATH);

	if (xrsDLL)
	{
		typedef DynamicXRS_DLL* (*CreateInstance)(VESSEL*);
		CreateInstance createInstance = reinterpret_cast<CreateInstance>(GetProcAddress(xrsDLL, "CreateInstanceVessel"));

		if (createInstance) xrSound = createInstance(vessel);
	}
}

DynamicXRSound::DynamicXRSound(const char* pUniqueModuleName)
{
	xrSound = nullptr;

	xrsDLL = LoadLibraryA(DLL_PATH);

	if (xrsDLL)
	{
		typedef DynamicXRS_DLL* (*CreateInstance)(const char*);
		CreateInstance createInstance = reinterpret_cast<CreateInstance>(GetProcAddress(xrsDLL, "CreateInstanceModule"));

		if (createInstance) xrSound = createInstance(pUniqueModuleName);
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
	return xrSound ? xrSound->IsPresent() : false;
}

float DynamicXRSound::GetVersion() const 
{ 
	return xrSound ? xrSound->GetVersion() : 0;
}

bool DynamicXRSound::LoadWav(const int soundID, const char* pSoundFilename, const XRSound::PlaybackType playbackType)
{
	return xrSound ? xrSound->LoadWav(soundID, pSoundFilename, playbackType) : false;
}

bool DynamicXRSound::PlayWav(const int soundID, const bool bLoop, const float volume) 
{ 
	return xrSound ? xrSound->PlayWav(soundID, bLoop, volume) : false;
}

bool DynamicXRSound::StopWav(const int soundID) 
{
	return xrSound ? xrSound->StopWav(soundID) : false;
}

bool DynamicXRSound::IsWavPlaying(const int soundID) const
{
	return xrSound ? xrSound->IsWavPlaying(soundID) : false;
}

bool DynamicXRSound::SetPaused(const int soundID, const bool bPause)
{
	return xrSound ? xrSound->SetPaused(soundID, bPause) : false;
}

bool DynamicXRSound::IsPaused(const int soundID) const
{
	return xrSound ? xrSound->IsPaused(soundID) : false;
}

bool DynamicXRSound::SetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID, const bool bEnabled)
{
	return xrSound ? xrSound->SetDefaultSoundEnabled(soundID, bEnabled) : false;
}

bool DynamicXRSound::GetDefaultSoundEnabled(const XRSound::DefaultSoundID soundID) const
{
	return xrSound ? xrSound->GetDefaultSoundEnabled(soundID) : false;
}

bool DynamicXRSound::SetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID, const char* pSubfolderPath)
{
	return xrSound ? xrSound->SetDefaultSoundGroupFolder(defaultSoundID, pSubfolderPath) : false;
}

const char* DynamicXRSound::GetDefaultSoundGroupFolder(const XRSound::DefaultSoundID defaultSoundID) const
{
	return xrSound ? xrSound->GetDefaultSoundGroupFolder(defaultSoundID) : false;
}
