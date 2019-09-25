#include "CTxdStore.h"

int CTxdStore::AddTxdSlot(char  const* name)
{
	return ((int (__cdecl *)(char  const*))AddressByVersion(0x5274E0, 0x527720, 0x5276B0))(name);
}

void CTxdStore::RemoveTxdSlot(int index)
{
	((void (__cdecl *)(int))AddressByVersion(0x527520, 0x527760, 0x5276F0))(index);
}


int CTxdStore::FindTxdSlot(char  const* name)
{
	return ((int (__cdecl *)(char  const*))AddressByVersion(0x5275D0, 0x527810, 0x5277A0))(name);
}

bool CTxdStore::LoadTxd(int index, char  const* filename)
{
	return ((bool (__cdecl *)(int, char  const*))AddressByVersion(0x5276B0, 0x5278F0, 0x527880))(index, filename);
}

void CTxdStore::SetCurrentTxd(int index)
{
	((void (__cdecl *)(int))AddressByVersion(0x5278C0, 0x527B00, 0x527A90))(index);
}

void CTxdStore::PushCurrentTxd()
{
	((void (__cdecl *)())AddressByVersion(0x527900, 0x527B40, 0x527AD0))();
}

void CTxdStore::PopCurrentTxd()
{
	((void (__cdecl *)())AddressByVersion(0x527910, 0x527B50, 0x527AE0))();
}

CTexDictionary *CTxdStore::AddRef(int index)
{
	return ((CTexDictionary *(__cdecl *)(int))AddressByVersion(0x527930, 0x527B70, 0x527B00))(index);
}
