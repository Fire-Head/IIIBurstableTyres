#include "CObject.h"


void *CObject::operator new(unsigned int size)
{
	return ((void *(__cdecl *)(unsigned int))AddressByVersion(0x4BAE70, 0x4BAF60, 0x4BAEF0))(size);
}

void *CObject::operator new(unsigned int size, int a2)
{
	return ((void *(__cdecl *)(unsigned int, int))AddressByVersion(0x4BAE80, 0x4BAF70, 0x4BAF00))(size, a2);
}

void CObject::operator delete(void *object)
{
	((void (__cdecl *)(void *))AddressByVersion(0x4BAEA0, 0x4BAF90, 0x4BAF20))(object);
}