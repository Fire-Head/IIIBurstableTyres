#pragma once
#include "game\game.h"
#include "inc\String.h"
#include "inc\IniReader.h"
#include "inc\CPatch.h"


#define NAKED                            __declspec(naked)
#define NAK                              NAKED
#define EXPORT                           __declspec(dllexport)
#define EXP                              EXPORT

#define ARRLEN(a)                        (sizeof(a)/sizeof(a[0]))
#define _ARRAY_SIZE(array)               (sizeof(array) / sizeof(array[0]))
#define ARRAY_ELEMENT_SIZE(array)        (sizeof(array[0]))
#define ARRAY_SIZE                       _ARRAY_SIZE


#define EAXJMP(a)                        { _asm mov eax, a _asm jmp eax }
#define VARJMP(a)                        { _asm jmp a }

#define BIT(num) (1<<(num))


#ifdef _USELONGPIFORDEFS
#define PI ((float)3.1415926535f)
#else
#define PI ((float)3.1415)
#endif

#define _2PI (PI*2)

#define DEG2RAD(x) ((x) * PI / 180.0f)
#define RAD2DEG(x) ((x) * 180.0f / PI)

#define PERCENT(x, p) ( ( Float(x) * ( Float(p) / 100.0f ) ) )
#define LIMIT_ANGLE(v, min, max) ( ( v >= max ) ? ( v - max ) : ( ( v < min ) ? ( v + max ) : (v) ) )

#define clamp(v, a, b) (max(min(v, b), a))

#ifndef max
    #define max(a, b)                    (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
    #define min(a, b)                    (((a) > (b)) ? (b) : (a))
#endif


#define Log(x, ...) 