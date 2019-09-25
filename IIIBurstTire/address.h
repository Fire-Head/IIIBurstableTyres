#pragma once
#include "CVersion.h"
#include ".\game\types.h"

//#if 1
#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
#define VALIDATE_OFFSET(struc, member, offset) \
	static_assert(offsetof(struc, member) == offset, "The offset of " #member " in " #struc " is not " #offset "...")
//#endif

struct tDummy { };
static const tDummy dummy_func;

#define FUNCVMT(index) (*(void ***)this)[index]

//#define DUMMY(c) c(tDummy vmt)
#define DUMMY(c) c(tDummy) {}
#define DUMMYB(c, b) c(tDummy vmt) : b(vmt) {}
#define DUMMYCTOR(b) b(dummy_func)


#define ADDR_RSGLOBAL                                            AddressByVersion(0x8F4360, 0x8F4414, 0x904554)
///#define ADDR_PSGLOBAL                                            0x72CF60
//#define ADDR_ID3D8DEVICE                                         AddressByVersion(0x662EF0, 0x662EF0, 0x673440) //pD3DDevice
#define ADDR_ID3D8DEVICE                                         AddressByVersion(0x662EF0, 0x662EF0, 0x67342C) //pD3DDevice
#define ADDR_RWENGINEINSTANCE                                    AddressByVersion(0x661228, 0x661228, 0x671248)
//#define ADDR_ID3D8                                               0x662EFC //Test
#define ADDR_PPARAMS                                             AddressByVersion(0x943010, 0x9431C8, 0x953308)
