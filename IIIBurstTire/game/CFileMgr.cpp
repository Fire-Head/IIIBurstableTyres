#include "CFileMgr.h"

int CFileMgr::LoadFile(const char *path, unsigned char *buf, int size, const char *mode)
{
	return ((int (__cdecl *)(const char *, unsigned char *, int, const char *))AddressByVersion(0x479090, 0x479090, 0x479090))(path, buf, size, mode);
}
