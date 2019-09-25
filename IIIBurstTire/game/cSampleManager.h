#pragma once
#include "..\address.h"
#include "types.h"

#pragma pack(push, 1)
struct tSample
{
  UInt32 nOffset;
  UInt32 nLength;
  UInt32 nBaseFrequency;
  Int32 nLoopStartOffset;
  Int32 nLoopEndOffset;
};
#pragma pack(pop)


class cSampleManager
{
public:
	UInt8 m_nEffectsVolume;
	UInt8 m_nMusicVolume;
	UInt8 m_nEffectsFadeVolume;
	UInt8 m_nMusicFadeVolume;
	char field_4;
	char _pad0;
	Char m_szCDRomRootPath[80];
	Bool m_bInitialised;
	Int8 m_nNumberOfProviders;
	Char *m_aAudioProviders[64];
	tSample m_aSamples[3032];
  
	static bool IsMP3RadioChannelAvailable();
	
	void SetStreamedVolumeAndPan(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
	void StartPreloadedStreamedFile(unsigned char v1);
	
	int GetSampleBaseFrequency(unsigned int a1);
	int GetSampleLoopStartOffset(unsigned int a1);
	int GetSampleLoopEndOffset(unsigned int a1);
};

extern cSampleManager &SampleManager;