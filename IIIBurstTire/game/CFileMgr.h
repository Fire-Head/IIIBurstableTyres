#pragma once
#include <windows.h>
#include "..\address.h"

class CFileMgr
{
public:
	static int LoadFile(char const *path, unsigned char *buf, int size, char  const* mode);
};