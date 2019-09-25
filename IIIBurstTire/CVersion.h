#pragma once
#include <Windows.h>

extern int            nVersion;
extern bool           bAutoVersionCheck;


enum eGame
{
    Unknown_Game    = 0,
    GTA_3_1_0       = 1,
    GTA_3_1_1       = 2,
    GTA_3_Steam     = 3,
    GTA_3_Amazon    = 4,
    GTA_3_Australia = 5,
};

extern char *aGameVer [4];

DWORD getModuleEntryPointAddress(HANDLE hModule);
DWORD getGameVersion(HANDLE hModule = NULL);
eGame GetGameVersion();
int AddressByVersion(unsigned int _1_0, unsigned int _1_1, unsigned int _Steam);
bool IsGTAIII();
bool IsVersion_1_0();
bool IsVersion_1_1();
bool IsVersion_Steam();