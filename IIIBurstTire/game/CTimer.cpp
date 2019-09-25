#include "CTimer.h"


bool& CTimer::m_CodePause = *(bool *)AddressByVersion(0x95CDB1, 0x95CF69, 0x96D0A9);
bool& CTimer::m_UserPause = *(bool *)AddressByVersion(0x95CD7C, 0x95CF34, 0x96D074);
unsigned int& CTimer::m_FrameCounter = *(unsigned int *)AddressByVersion(0x9412EC, 0x9414A4, 0x9515E4);
float& CTimer::ms_fTimeStep = *(float *)AddressByVersion(0x8E2C4C, 0x8E2D00, 0x8F2E40);
unsigned int& CTimer::m_snTimeInMilliseconds = *(unsigned int *)AddressByVersion(0x885B48, 0x885AF8, 0x895C38);