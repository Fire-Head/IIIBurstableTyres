#include "CVersion.h"
#include <stdio.h>
#include <stdarg.h>

char *aGameVer [4] = 
{
    "",                //0
    "GTA_3_1_0",       //1
    "GTA_3_1_1",       //2
    "GTA_3_Steam"      //3
};

int            nVersion            =    -1;
bool           bAutoVersionCheck   =    1;

DWORD getModuleEntryPointAddress(HANDLE hModule) 
{
	IMAGE_DOS_HEADER * pDOSHeader = (IMAGE_DOS_HEADER *)hModule;
	IMAGE_NT_HEADERS * pNTHeaders = (IMAGE_NT_HEADERS*)((BYTE*)pDOSHeader + pDOSHeader->e_lfanew);
	return pNTHeaders->OptionalHeader.AddressOfEntryPoint + (DWORD)pDOSHeader;
	//return pNTHeaders->OptionalHeader.AddressOfEntryPoint + 0x400000;
}

DWORD getGameVersion(HANDLE hModule) 
{
	enum
	{
		ENTRYPOINT_1_0                  = 0x5C1E70,
		ENTRYPOINT_1_0_CD               = 0x983056,
		ENTRYPOINT_1_1                  = 0x5C2130,
		ENTRYPOINT_1_1_BUKA_1C          = 0x985240,
		ENTRYPOINT_STEAM                = 0x9912ED,
		ENTRYPOINT_STEAM_CRACKED        = 0x5C6FD0,
		ENTRYPOINT_STEAM_MAC_OS_CRACKED = 0x5C7C60,
		ENTRYPOINT_AMAZON               = -1,
	};

	if (!hModule) 
		hModule = GetModuleHandle(NULL);
	
	DWORD dwEntryPoint = getModuleEntryPointAddress(hModule);
	switch (dwEntryPoint) 
	{
		case ENTRYPOINT_1_0:
		case ENTRYPOINT_1_0_CD:
			return GTA_3_1_0;
		case ENTRYPOINT_1_1:
		case ENTRYPOINT_1_1_BUKA_1C:
			return GTA_3_1_1;
		case ENTRYPOINT_STEAM:
		case ENTRYPOINT_STEAM_CRACKED:
			return GTA_3_Steam;
	}
	return Unknown_Game;
}

eGame GetGameVersion()
{
	nVersion = (eGame)getGameVersion();
	return (eGame)nVersion;
}

int AddressByVersion(unsigned int _1_0, unsigned int _1_1, unsigned int _Steam)
{
    if (bAutoVersionCheck && nVersion == -1)
    {
        GetGameVersion();
    }

    switch ( nVersion )
    {
        case GTA_3_1_0:
           return _1_0;
           break;
        case GTA_3_1_1:
           return _1_1;
           break;
        case GTA_3_Steam:
           return _Steam;
           break;
    }

	__asm int 3
	return -1;
}

bool IsGTAIII()
{
	eGame Ver = (eGame)getGameVersion();
	if ( Ver == Unknown_Game )
		return false;
	else
		return true;
}

bool IsVersion_1_0()
{
	return ((eGame)getGameVersion()) == GTA_3_1_0;
}

bool IsVersion_1_1()
{
	return ((eGame)getGameVersion()) == GTA_3_1_1;
}

bool IsVersion_Steam()
{
	return ((eGame)getGameVersion()) == GTA_3_Steam;
}