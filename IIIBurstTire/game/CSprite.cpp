#include "CSprite.h"

bool CSprite::CalcScreenCoors(RwV3d const &posn, RwV3d *out, float *w, float *h, bool Unk)
{
	return ((bool (__cdecl *)(RwV3d const &, RwV3d *, float *, float *, bool))AddressByVersion(0x51C3A0, 0x51C5D0, 0x51C560))(posn, out, w, h, Unk);
}

// Converted from static void __cdecl CSprite::InitSpriteBuffer2D() 0x51C5B0
void CSprite::InitSpriteBuffer2D()
{
	((void (__cdecl *)())AddressByVersion(0x51C5B0, 0x51C7E0, 0x51C770))();
}

// Converted from static void __cdecl CSprite::FlushSpriteBuffer() 0x51C520
void CSprite::FlushSpriteBuffer()
{
	((void (__cdecl *)())AddressByVersion(0x51C520, 0x51C750, 0x51C6E0))();
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite2D(float x, float y, float halfWidth, float halfHeight, RwRGBA const &color, short alpha, unsigned char intensity) 0x51E3C0 
void CSprite::RenderBufferedOneXLUSprite2D(float x, float y, float halfWidth, float halfHeight, RwRGBA const& color, short alpha, unsigned char intensity)
{
	((void (__cdecl *)(float, float, float, float, RwRGBA const&, short, unsigned char))AddressByVersion(0x51E3C0, 0x51E5F0, 0x51E580))(x, y, halfWidth, halfHeight, color, alpha, intensity);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite2D_Rotate_Dimension(float x, float y, float halfWidth, float halfHeight, RwRGBA const &color, short alpha, float rhw, unsigned char intensity) 0x51E490
void CSprite::RenderBufferedOneXLUSprite2D_Rotate_Dimension(float x, float y, float halfWidth, float halfHeight, RwRGBA const& color, short alpha, float rhw, unsigned char intensity)
{
	((void (__cdecl *)(float, float, float, float, RwRGBA const&, short, float, unsigned char))AddressByVersion(0x51E490, 0x51E6C0, 0x51E650))(x, y, halfWidth, halfHeight, color, alpha, rhw, intensity);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, float rotate, unsigned char aspect) 0x51D5B0
void CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, float rotate, unsigned char aspect)
{
	((void (__cdecl *)(float, float, float, float, float, unsigned char, unsigned char, unsigned char, short, float, float, unsigned char))AddressByVersion(0x51D5B0, 0x51D7E0, 0x51D770))(x, y, z, halfWidth, halfHeight, red, green, blue, alpha, rhw, rotate, aspect);
}

// Converted from static void __cdecl CSprite::RenderBufferedOneXLUSprite(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, unsigned char aspect) 0x51C5D0
void CSprite::RenderBufferedOneXLUSprite(float x, float y, float z, float halfWidth, float halfHeight, unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, unsigned char aspect)
{
	((void (__cdecl *)(float, float, float, float, float, unsigned char, unsigned char, unsigned char, short, float, unsigned char))AddressByVersion(0x51C5D0, 0x51C800, 0x51C790))(x, y, z, halfWidth, halfHeight, red, green, blue, alpha, rhw, aspect);
}



