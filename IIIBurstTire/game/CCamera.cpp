#include "CCamera.h"

CCamera& TheCamera = *(CCamera*)AddressByVersion(0x6FACF8, 0x6FACF8, 0x70AE38);
char &CCamera::m_bUseMouse3rdPerson = *(char *)AddressByVersion(0x5F03D8, 0x5F03D8, 0x5FD3D8);