#include "cDMAudio.h"

void cDMAudio::PlayFrontEndSound(unsigned short v1, unsigned int v2)
{
	((void (__thiscall *)(cDMAudio *, unsigned short, unsigned int))AddressByVersion(0x57CC20, 0x57CF70, 0x57CE70))(this, v1, v2);
}

void cDMAudio::PlayOneShot(int v1, unsigned short v2, float v3)
{
	((void (__thiscall *)(cDMAudio *, int, unsigned short, float))AddressByVersion(0x57C840, 0x57CB90, 0x57CA90))(this, v1, v2, v3);
}


cDMAudio &DMAudio = *(cDMAudio*)AddressByVersion(0x95CDBE, 0x95CF76, 0x96D0B6);