/*************************************************************************
 *
 * Credits: DK22Pac, ThirteenAG, Wesser, ...
 * Links:
 *    http://gtaforums.com/topic/117195-documenting-gta3vc-memory-adresses/page-38#entry1064528219
 *    http://gtaforums.com/topic/569153-creating-simple-dll-memory-hack/?p=1062866556
 *    http://ru-script.3dn.ru/forum/6-89-1
 *    https://github.com/thelink2012/plugin-sdk/blob/master/src/sdk/patch/CPatch.h
 *    https://github.com/ThirteenAG/Widescreen_Fixes_Pack/blob/master/includes/CPatch.h
 *    http://gtaforums.com/topic/508689-the-modders-lounge/?p=1065303732
 *
 ************************************************************************/

#pragma once

#include <Windows.h>

#define INJ_CALL 0
#define INJ_JUMP 1
#define INJ_VTBL 2
#define INJ_CB   3

#define CALLVOID(a) ((void (__cdecl *)())a)()
#define CALLVOIDRETCHAR(a) ((char (__cdecl *)())a)()
#define CALLVOIDPCHAR(a, c) ((void (__cdecl *)(char *))a)(c)
#define CALLVOIDUINT(a, c) ((void (__cdecl *)(unsigned int))a)(c)
#define READPVOID(a) (*(void **)a)
#define READCHAR(a) (*(char *)a)
#define READPCHAR(a) (*(char **)a)

#define GETMA(n, a) ((DWORD)GetModuleHandle (n) + a)

#define MAX_NOP_SIZE	9
#define NOP_TABLE_SIZE	(MAX_NOP_SIZE * MAX_NOP_SIZE)

typedef CONST BYTE OPCODE;
typedef VOID (WINAPI *MAKE_FUNC_T)(LPVOID lpAddress);
typedef VOID (WINAPI *MAKE_FUNCEX_T)(LPVOID lpAddress, LPVOID lpDestination);
	
namespace CPUOpcodes
{
	extern __declspec(selectany) OPCODE NOP		[ ][MAX_NOP_SIZE] =		// No-operation.
	{
		{ 0x90 },
		{ 0x66, 0x90 },
		{ 0x0F, 0x1F },
		{ 0x0F, 0x1F, 0x40 },
		{ 0x0F, 0x1F, 0x44 },
		{ 0x66, 0x0F, 0x1F, 0x44 },
		{ 0x0F, 0x1F, 0x80 },
		{ 0x0F, 0x1F, 0x84 },
		{ 0x66, 0x0F, 0x1F, 0x84 }
	};
	extern __declspec(selectany) OPCODE JO_OFF32	[6] = { 0x0F, 0x80 };	// Jump (near) if overflow.
	extern __declspec(selectany) OPCODE JNO_OFF32	[6] = { 0x0F, 0x81 };	// Jump (near) if not overflow.
	extern __declspec(selectany) OPCODE JB_OFF32	[6] = { 0x0F, 0x82 };	// Jump (near) if below.
	extern __declspec(selectany) OPCODE JNAE_OFF32[6] = { 0x0F, 0x82 };	// Jump (near) if not above or equal.
	extern __declspec(selectany) OPCODE JC_OFF32	[6] = { 0x0F, 0x82 };	// Jump (near) if carry.
	extern __declspec(selectany) OPCODE JNB_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if not below.
	extern __declspec(selectany) OPCODE JAE_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if above or equal.
	extern __declspec(selectany) OPCODE JNC_OFF32	[6] = { 0x0F, 0x83 };	// Jump (near) if not carry.
	extern __declspec(selectany) OPCODE JE_OFF32	[6] = { 0x0F, 0x84 };	// Jump (near) if equal.
	extern __declspec(selectany) OPCODE JZ_OFF32	[6] = { 0x0F, 0x84 };	// Jump (near) if zero.
	extern __declspec(selectany) OPCODE JNE_OFF32	[6] = { 0x0F, 0x85 };	// Jump (near) if not equal.
	extern __declspec(selectany) OPCODE JNZ_OFF32	[6] = { 0x0F, 0x85 };	// Jump (near) if not zero.
	extern __declspec(selectany) OPCODE JBE_OFF32	[6] = { 0x0F, 0x86 };	// Jump (near) if below or equal.
	extern __declspec(selectany) OPCODE JNA_OFF32	[6] = { 0x0F, 0x86 };	// Jump (near) if not above.
	extern __declspec(selectany) OPCODE JA_OFF32	[6] = { 0x0F, 0x87 };	// Jump (near) if above.
	extern __declspec(selectany) OPCODE JNBE_OFF32[6] = { 0x0F, 0x87 };	// Jump (near) if not below or equal.
	extern __declspec(selectany) OPCODE JS_OFF32	[6] = { 0x0F, 0x88 };	// Jump (near) if sign.
	extern __declspec(selectany) OPCODE JNS_OFF32	[6] = { 0x0F, 0x89 };	// Jump (near) if not sign.
	extern __declspec(selectany) OPCODE JP_OFF32	[6] = { 0x0F, 0x8A };	// Jump (near) if parity.
	extern __declspec(selectany) OPCODE JPE_OFF32	[6] = { 0x0F, 0x8A };	// Jump (near) if parity even.
	extern __declspec(selectany) OPCODE JNP_OFF32	[6] = { 0x0F, 0x8B };	// Jump (near) if not parity.
	extern __declspec(selectany) OPCODE JPO_OFF32	[6] = { 0x0F, 0x8B };	// Jump (near) if parity odd.
	extern __declspec(selectany) OPCODE JL_OFF32	[6] = { 0x0F, 0x8C };	// Jump (near) if less.
	extern __declspec(selectany) OPCODE JNGE_OFF32[6] = { 0x0F, 0x8C };	// Jump (near) if not greater or equal.
	extern __declspec(selectany) OPCODE JGE_OFF32	[6] = { 0x0F, 0x8D };	// Jump (near) if greater or equal.
	extern __declspec(selectany) OPCODE JNL_OFF32	[6] = { 0x0F, 0x8D };	// Jump (near) if not less.
	extern __declspec(selectany) OPCODE JLE_OFF32	[6] = { 0x0F, 0x8E };	// Jump (near) if less or equal.
	extern __declspec(selectany) OPCODE JNG_OFF32	[6] = { 0x0F, 0x8E };	// Jump (near) if not greater.
	extern __declspec(selectany) OPCODE JG_OFF32	[6] = { 0x0F, 0x8F };	// Jump (near) if greater.
	extern __declspec(selectany) OPCODE JNLE_OFF32[6] = { 0x0F, 0x8F };	// Jump (near) if not less or equal.
	extern __declspec(selectany) OPCODE JO_OFF8	[2] = { 0x70 };			// Jump (short) if overflow.
	extern __declspec(selectany) OPCODE JNO_OFF8	[2] = { 0x71 };			// Jump (short) if not overflow.
	extern __declspec(selectany) OPCODE JB_OFF8	[2] = { 0x72 };			// Jump (short) if below.
	extern __declspec(selectany) OPCODE JNAE_OFF8	[2] = { 0x72 };			// Jump (short) if not above or equal.
	extern __declspec(selectany) OPCODE JC_OFF8	[2] = { 0x72 };			// Jump (short) if carry.
	extern __declspec(selectany) OPCODE JNB_OFF8	[2] = { 0x73 };			// Jump (short) if not below.
	extern __declspec(selectany) OPCODE JAE_OFF8	[2] = { 0x73 };			// Jump (short) if above or equal.
	extern __declspec(selectany) OPCODE JNC_OFF8	[2] = { 0x73 };			// Jump (short) if not carry.
	extern __declspec(selectany) OPCODE JE_OFF8	[2] = { 0x74 };			// Jump (short) if equal.
	extern __declspec(selectany) OPCODE JZ_OFF8	[2] = { 0x74 };			// Jump (short) if zero.
	extern __declspec(selectany) OPCODE JNE_OFF8	[2] = { 0x75 };			// Jump (short) if not equal.
	extern __declspec(selectany) OPCODE JNZ_OFF8	[2] = { 0x75 };			// Jump (short) if not zero.
	extern __declspec(selectany) OPCODE JBE_OFF8	[2] = { 0x76 };			// Jump (short) if below or equal.
	extern __declspec(selectany) OPCODE JNA_OFF8	[2] = { 0x76 };			// Jump (short) if not above.
	extern __declspec(selectany) OPCODE JA_OFF8	[2] = { 0x77 };			// Jump (short) if above.
	extern __declspec(selectany) OPCODE JNBE_OFF8	[2] = { 0x77 };			// Jump (short) if not below or equal.
	extern __declspec(selectany) OPCODE JS_OFF8	[2] = { 0x78 };			// Jump (short) if sign.
	extern __declspec(selectany) OPCODE JNS_OFF8	[2] = { 0x79 };			// Jump (short) if not sign.
	extern __declspec(selectany) OPCODE JP_OFF8	[2] = { 0x7A };			// Jump (short) if parity.
	extern __declspec(selectany) OPCODE JPE_OFF8	[2] = { 0x7A };			// Jump (short) if parity even.
	extern __declspec(selectany) OPCODE JNP_OFF8	[2] = { 0x7B };			// Jump (short) if not parity.
	extern __declspec(selectany) OPCODE JPO_OFF8	[2] = { 0x7B };			// Jump (short) if parity odd.
	extern __declspec(selectany) OPCODE JL_OFF8	[2] = { 0x7C };			// Jump (short) if less.
	extern __declspec(selectany) OPCODE JNGE_OFF8	[2] = { 0x7C };			// Jump (short) if not greater or equal.
	extern __declspec(selectany) OPCODE JGE_OFF8	[2] = { 0x7D };			// Jump (short) if greater or equal.
	extern __declspec(selectany) OPCODE JNL_OFF8	[2] = { 0x7D };			// Jump (short) if not less.
	extern __declspec(selectany) OPCODE JLE_OFF8	[2] = { 0x7E };			// Jump (short) if less or equal.
	extern __declspec(selectany) OPCODE JNG_OFF8	[2] = { 0x7E };			// Jump (short) if not greater.
	extern __declspec(selectany) OPCODE JG_OFF8	[2] = { 0x7F };			// Jump (short) if greater.
	extern __declspec(selectany) OPCODE JNLE_OFF8	[2] = { 0x7F };			// Jump (short) if not less or equal.
	extern __declspec(selectany) OPCODE JCXZ_OFF8	[2] = { 0xE3 };			// Jump (short) if CX register is 0.
	extern __declspec(selectany) OPCODE JECXZ_OFF8[2] = { 0xE3 };			// Jump (short) if ECX register is 0.
	extern __declspec(selectany) OPCODE CALL_OFF32[5] = { 0xE8 };			// Call (near) subroutine.
	extern __declspec(selectany) OPCODE JMP_OFF32	[5] = { 0xE9 };			// Jump (near) unconditionally.
	extern __declspec(selectany) OPCODE JMP_OFF8	[2] = { 0xEB };			// Jump (short) unconditionally.
	extern __declspec(selectany) OPCODE JMP_PTR32	[6] = { 0xFF, 0x25 };	// Jump indirectly.
};

class CPatch
{
private:
	inline static void Patch(void* address, void* data, int size)
	{
		unsigned long protect[2];
		VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memcpy(address, data, size);
		VirtualProtect(address, size, protect[0], &protect[1]);
	}
	inline static void Patch2(int address, void* data, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memcpy((void *)address, data, size);
		VirtualProtect((void *)address, size, protect[0], &protect[1]);
	}
	template<typename value_t>
	inline static void Patch(int address, value_t data)
	{
		unsigned long vp = Unprotect(address, sizeof(value_t));
		*(value_t *)address = data;
		Protect(address, sizeof(value_t), vp);
	}
	static const unsigned char NopInstr[][MAX_NOP_SIZE];
public:
	template<typename T>
	inline static void CALL(int address, void *func, T &CB)
	{
		if ( *(int*)(address + 1) + (address + 5) != (int)func)
		{
			CB = reinterpret_cast <T>(*(int*)(address + 1) + (address + 5));
			RedirectCall(address, func);
		}
	}
	template<typename T>
	inline static void RAWPTR(void *address, void *func, T &CB)
	{
		if ( *(int*)address != (int)func)
		{
			CB = reinterpret_cast <T>(*(int*)((int)address));
			SetPointer((int)address, func);
		}
	}
	
	template<typename T>
	inline static void JA(int address, void *func, T &CB)
	{
		if ( *(int*)(address + 2) + (address + 6) != (int)func)
		{
			CB = ( (T)( (*(int*)(address + 2) + (address + 6)) ) );
			RedirectJA(address, func);
		}
	}
	
	inline static unsigned long Protect(int address, int size)
	{
		unsigned long vp;
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &vp);
		return vp;
	}
	inline static void Protect(int address, size_t size, unsigned long vp)
	{
		VirtualProtect((void *)address, size, vp, nullptr);
	}
	inline static unsigned long Unprotect(int address, size_t size)
	{
		unsigned long vp;
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &vp);

		return vp;
	}
	inline static void Unprotect(int address, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
	}
	inline static void Unprotect(int address, int size, unsigned long vp)
	{
		VirtualProtect((void *)address, size, vp, nullptr);
	}
	inline static DWORD WINAPI UnprotectMemory(LPVOID lpAddress, SIZE_T dwSize)
	{
		DWORD flOldProtect;
		VirtualProtect(lpAddress, dwSize, PAGE_EXECUTE_READWRITE, &flOldProtect);
		return flOldProtect;
	}
	inline static VOID WINAPI ProtectMemory(LPVOID lpAddress, SIZE_T dwSize, DWORD flOldProtect)
	{
		VirtualProtect(lpAddress, dwSize, flOldProtect, NULL);
	}
	inline static int GetOffset(int address, void *func)
	{
		return (int)func - (address + 4);
	}
	inline static int GetOffset(int address, int loc)
	{
		return loc - (address + 4);
	}
	template<typename OFFSET_T> inline static OFFSET_T WINAPI GetOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return (OFFSET_T)((DWORD)lpDestination - ((DWORD)lpAddress + sizeof(OFFSET_T)));
	}
	inline static char GetShortOffset(int address, int loc)
	{
		return loc - (address + 1);
	}
	template<typename addr_t>
	inline static char GetShortOffset(unsigned int address, addr_t loc)
	{
		return (int)loc - (address + 1);
	}
	inline static CHAR WINAPI GetShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return GetOffset<CHAR>(lpAddress, lpDestination);
	}
	template<typename addr_t>
	inline static int GetNearOffset(unsigned int address, addr_t loc)
	{
		return (int)loc - (address + 4);
	}
	inline static LONG WINAPI GetNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		return GetOffset<LONG>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeValue(LPVOID lpAddress, CONST BYTE aValue[], SIZE_T dwSize)
	{
		CopyMemory(lpAddress, aValue, dwSize);
	}
	template<typename VALUE_T> inline static VOID WINAPI MakeValue(LPVOID lpAddress, VALUE_T tValue)
	{
		*(VALUE_T *)lpAddress = tValue;
	}
	inline static VOID WINAPI MakeInstruction(LPVOID lpAddress, OPCODE aInstruction[], SIZE_T dwSize)
	{
		MakeValue(lpAddress, aInstruction, dwSize);
	}
	template<OPCODE aInstruction[], SIZE_T dwSize> inline static VOID WINAPI MakeInstruction(LPVOID lpAddress)
	{
		MakeInstruction(lpAddress, aInstruction, dwSize);
	}
	inline static VOID WINAPI MakePointer(LPVOID lpAddress, LPVOID lpPointer)
	{
		MakeValue<LPVOID>(lpAddress, lpPointer);
	}
	template<typename OFFSET_T> inline static VOID WINAPI MakeOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeValue<OFFSET_T>(lpAddress, GetOffset<OFFSET_T>(lpAddress, lpDestination));
	}
	inline static VOID WINAPI MakeShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeOffset<CHAR>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeOffset<LONG>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeNOP(LPVOID lpAddress, SIZE_T dwSize)
	{
		while(dwSize > MAX_NOP_SIZE)
		{
			MakeInstruction(lpAddress, CPUOpcodes::NOP[MAX_NOP_SIZE - 1], MAX_NOP_SIZE);
			dwSize -= MAX_NOP_SIZE;
		}

		MakeInstruction(lpAddress, CPUOpcodes::NOP[dwSize - 1], dwSize);
	}
	template<OPCODE aInstruction[], SIZE_T dwSize, typename OFFSET_T> inline static VOID WINAPI MakeBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeInstruction<aInstruction, dwSize>(lpAddress);
		MakeOffset<OFFSET_T>((PBYTE)lpAddress + dwSize, lpDestination);
	}
	template<OPCODE aInstruction[]> inline static VOID WINAPI MakeShortUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeBranch<aInstruction, 1, CHAR>(lpAddress, lpDestination);
	}
	template<OPCODE aInstruction[]> inline static VOID WINAPI MakeNearUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeBranch<aInstruction, 1, LONG>(lpAddress, lpDestination);
	}
	template<OPCODE aInstruction[]> inline static VOID WINAPI MakeIndirectBranch(LPVOID lpAddress, LPVOID lpVariable)
	{
		MakeBranch<aInstruction, 2, LPVOID>(lpAddress, lpVariable);
	}
	inline static VOID WINAPI MakeNearCall(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeNearUnconditionalBranch<CPUOpcodes::CALL_OFF32>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeShortJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeShortUnconditionalBranch<CPUOpcodes::JMP_OFF8>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeShortJnz(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeShortUnconditionalBranch<CPUOpcodes::JNZ_OFF8>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeNearJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		MakeNearUnconditionalBranch<CPUOpcodes::JMP_OFF32>(lpAddress, lpDestination);
	}
	inline static VOID WINAPI MakeIndirectJump(LPVOID lpAddress, LPVOID lpVariable)
	{
		MakeIndirectBranch<CPUOpcodes::JMP_PTR32>(lpAddress, lpVariable);
	}
	template<MAKE_FUNC_T tCallback, SIZE_T dwSize> static VOID WINAPI InstallHook(LPVOID lpAddress)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		tCallback(lpAddress);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}
	template<MAKE_FUNCEX_T tCallback, SIZE_T dwSize> static VOID WINAPI InstallHook(LPVOID lpAddress, LPVOID lpDestination)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		tCallback(lpAddress, lpDestination);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}
	static VOID WINAPI InstallHookPointer(LPVOID lpAddress, LPVOID lpPointer)
	{
		InstallHook<MakePointer, 4>(lpAddress, lpPointer);
	}
	static VOID WINAPI InstallHookShortOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<MakeShortOffset, 1>(lpAddress, lpDestination);
	}
	static VOID WINAPI InstallHookNearOffset(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<MakeNearOffset, 4>(lpAddress, lpDestination);
	}
	template<MAKE_FUNCEX_T tCallback> inline static VOID WINAPI InstallHookShortUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<tCallback, 2>(lpAddress, lpDestination);
	}
	template<MAKE_FUNCEX_T tCallback> inline static VOID WINAPI InstallHookNearUnconditionalBranch(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHook<tCallback, 5>(lpAddress, lpDestination);
	}
	template<MAKE_FUNCEX_T tCallback> inline static VOID WINAPI InstallHookIndirectBranch(LPVOID lpAddress, LPVOID lpVariable)
	{
		InstallHook<tCallback, 6>(lpAddress, lpVariable);
	}
	static VOID WINAPI InstallHookNearCall(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookNearUnconditionalBranch<MakeNearCall>(lpAddress, lpDestination);
	}
	static VOID WINAPI InstallHookShortJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookShortUnconditionalBranch<MakeShortJump>(lpAddress, lpDestination);
	}
	static VOID WINAPI InstallHookNearJump(LPVOID lpAddress, LPVOID lpDestination)
	{
		InstallHookNearUnconditionalBranch<MakeNearJump>(lpAddress, lpDestination);
	}
	static VOID WINAPI InstallHookIndirectJump(LPVOID lpAddress, LPVOID lpVariable)
	{
		InstallHookIndirectBranch<MakeIndirectJump>(lpAddress, lpVariable);
	}
	static VOID WINAPI WriteProtectedMemory(LPVOID lpAddress, CONST BYTE aValue[], SIZE_T dwSize)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeValue(lpAddress, aValue, dwSize);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}
	template<typename VALUE_T> static VOID WINAPI WriteProtectedMemory(LPVOID lpAddress, VALUE_T tValue)
	{
		CONST SIZE_T dwSize = sizeof(VALUE_T);
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeValue<VALUE_T>(lpAddress, tValue);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}
	static VOID WINAPI NopProtectedMemory(LPVOID lpAddress, SIZE_T dwSize)
	{
		DWORD flOldProtect = UnprotectMemory(lpAddress, dwSize);
		MakeNOP(lpAddress, dwSize);
		ProtectMemory(lpAddress, dwSize, flOldProtect);
	}
	static VOID WINAPI SkipProtectedMemory(LPVOID lpAddress, LPVOID lpDestination)
	{
		SSIZE_T lSize = (DWORD)lpDestination - (DWORD)lpAddress;

		if(lSize > 0)
		{
			if(lSize < 10)
				return NopProtectedMemory(lpAddress, lSize);
			if(lSize < 128)
				return InstallHookShortJump(lpAddress, lpDestination);
		}
		else if(lSize >= -128)
			return InstallHookShortJump(lpAddress, lpDestination);

		InstallHookNearJump(lpAddress, lpDestination);
	}
	inline static void Nop(int address, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memset((void *)address, 0x90, size);
		VirtualProtect((void *)address, size, protect[0], &protect[1]);
	}
	inline static void NopRange(int begin, int end)
	{
		Nop(begin, end - begin);
	}
	inline static void nop(int address, size_t size)
	{
		unsigned long vp = Unprotect(address, size);

		while(size > MAX_NOP_SIZE)
		{
			memcpy((void *)address, NopInstr[MAX_NOP_SIZE - 1], NOP_TABLE_SIZE);
			size -= NOP_TABLE_SIZE;
		}

		memcpy((void *)address, NopInstr[size - 1], size);
		Protect(address, size, vp);
	}
	inline static void FillWithZeroes(int address, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memset((void *)address, 0x00, size);
		VirtualProtect((void *)address, size, protect[0], &protect[1]);
	}
	inline static void RedirectCall(int address, void *func)
	{
		int temp = 0xE8;
		Patch((void *)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void *)((int)address + 1), &temp, 4);
	}
	inline static void RedirectMethodCall(int address, ...)
	{
		va_list v;
		va_start(v, address);
		void* func = va_arg(v, void*);
		va_end(v);

		int temp = 0xE8;
		Patch((void *)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void *)((int)address + 1), &temp, 4);
	}
	template<typename T>static void RedirectMethod(DWORD dwAddress, T method)
	{
		auto _ptr = method;
		void*& ptr = (void*&)_ptr;
		RedirectCall(dwAddress, ptr);
	}
	inline static void RedirectPush(int address, void *func)
	{
		int temp = 0x68;
		Patch((void *)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void *)((int)address + 1), &temp, 4);
	}
	inline static void RedirectJump(int address, void *func)
	{
		int temp = 0xE9;
		Patch((void *)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void *)((int)address + 1), &temp, 4);
	}
	inline static void RedirectJA(int address, void *func)
	{
		int temp = 0x870F;
		Patch((void *)address, &temp, 2);
		temp = (int)func - ((int)address + 6);
		Patch((void *)((int)address + 2), &temp, 4);
	}
	inline static void RedirectJZ(int address, void *func)
	{
		int temp = 0x840F;
		Patch((void *)address, &temp, 2);
		temp = (int)func - ((int)address + 6);
		Patch((void *)((int)address + 2), &temp, 4);
	}
	inline static void RedirectJNZ(int address, void *func)
	{
		int temp = 0x850F;
		Patch((void *)address, &temp, 2);
		temp = (int)func - ((int)address + 6);
		Patch((void *)((int)address + 2), &temp, 4);
	}
	
	inline static void RedirectJGE(int address, void *func)
	{
		int temp = 0x8D0F;
		Patch((void *)address, &temp, 2);
		temp = (int)func - ((int)address + 6);
		Patch((void *)((int)address + 2), &temp, 4);
	}
	inline static void RedirectMethodJump(int address, ...)
	{
		va_list v;
		va_start(v, address);
		void* func = va_arg(v, void*);
		va_end(v);

		int temp = 0xE9;
		Patch((void *)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void *)((int)address + 1), &temp, 4);
	}
	static bool Get(int address, void *out, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memcpy(out, (void *)address, size);
		VirtualProtect((void *)address, size, protect[0], &protect[1]);
		return true;
	}
	static bool Set(int address, void *out, int size)
	{
		unsigned long protect[2];
		VirtualProtect((void *)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memcpy((void *)address, out, size);
		VirtualProtect((void *)address, size, protect[0], &protect[1]);
		return true;
	}
	inline static void RedirectOffset(int address, void *func)
	{
		int temp = GetOffset(address, func);
		Patch2(address, &temp, 4);
	}
	inline static void RedirectOffset(int address, int loc)
	{
		int temp = GetOffset(address, loc);
		Patch2(address, &temp, 4);
	}
	inline static void RedirectShortOffset(int address, int loc)
	{
		unsigned char temp = GetShortOffset(address, loc);
		Patch2(address, &temp, 1);
	}
	template<typename addr_t>
	inline static void RedirectShortOffset(unsigned int address, addr_t loc)
	{
		Patch<char>(address, GetShortOffset<addr_t>(address, loc));
	}
	template<typename addr_t>
	inline void RedirectNearOffset(unsigned int address, addr_t loc)
	{
		Patch<int>(address, GetNearOffset<addr_t>(address, loc));
	}
	inline static void RedirectJump(int address, int loc)
	{
		unsigned char temp = 0xE9;
		Patch2(address++, &temp, 1);
		RedirectOffset(address, loc);
	}
	inline static void RedirectShortJump(int address, int loc)
	{
		unsigned char temp = 0xEB;
		Patch2(address++, &temp, 1);
		RedirectShortOffset(address, loc);
	}
	template<typename addr_t>
	inline static void RedirectShortJump(int address, addr_t loc)
	{
		const size_t size = sizeof(unsigned char) + sizeof(char);

		unsigned long vp = Unprotect(address, size);
		*(unsigned char *)address = 0xEB;
		*(char *)(++address) = GetShortOffset<addr_t>(address, loc);
		Protect(address, size, vp);
	}
	template<typename addr_t>
	inline void RedirectNearJump(int address, addr_t loc)
	{
		const size_t size = sizeof(unsigned char) + sizeof(int);

		unsigned long vp = Unprotect(address, size);
		*(unsigned char *)address = 0xE9;
		*(int *)(++address) = GetNearOffset<addr_t>(address, loc);
		Protect(address, size, vp);
	}
	inline static void RedirectCall(int address, int loc)
	{
		unsigned char temp = 0xE8;
		Patch2(address++, &temp, 1);
		RedirectOffset(address, loc);
	}
	inline static bool CheckChar(int address, unsigned char value)
    {
        unsigned long protect[2];
        unsigned char dummy = value;
        VirtualProtect((void *)address, 1, PAGE_EXECUTE_READ, &protect[0]);
        memcpy(&dummy, (void *)address, 1);
        VirtualProtect((void *)address, 1, protect[0], &protect[1]);
        return (dummy == value);
    }
	inline static void SetChar(int address, char value)
	{
		Patch((void *)address, &value, 1);
	}
	inline static void SetUChar(int address, unsigned char value)
	{
		Patch((void *)address, &value, 1);
	}
	inline static void SetShort(int address, short value)
	{
		Patch((void *)address, &value, 2);
	}
	inline static void SetUShort(int address, unsigned short value)
	{
		Patch((void *)address, &value, 2);
	}
	inline static void SetInt(int address, int value)
	{
		Patch((void *)address, &value, 4);
	}
	inline static void SetUInt(int address, unsigned int value)
	{
		Patch((void *)address, &value, 4);
	}
	inline static void SetUIntWithCheck(int address, unsigned int value, unsigned int expectedValue)
	{
		if (*(unsigned int *)address == expectedValue)
		Patch((void *)address, &value, 4);
	}
	inline static void SetFloat(int address, float value)
	{
		Patch((void *)address, &value, 4);
	}
	inline static void SetDouble(int address, double value)
	{
		Patch((void *)address, &value, 8);
	}
	inline static void SetPointer(int address, void *value)
	{
		Patch((void *)address, &value, 4);
	}
	inline static unsigned int TranslateCallAddr(unsigned int addr)
	{
		unsigned int offset = *(unsigned int *)(addr + 1);
		offset += (addr + 5);
		return offset;
	}
	inline static unsigned int MakeCallAddr(unsigned int calladdr, unsigned int funcaddr)
	{
		if(*(unsigned char *)calladdr == 0xE8)
			return TranslateCallAddr(calladdr);
		return funcaddr;
	}
	inline static unsigned int MakeJumpAddr(unsigned int jumpaddr, unsigned int funcaddr)
	{
		if (*(unsigned char *)jumpaddr == 0xE9)
			return TranslateCallAddr(jumpaddr);
		return funcaddr;
	}
	template<typename T>
	static T SafeRedirectCall(unsigned int calladdr, unsigned int defaultaddr, T func)
	{
		T retaddr = reinterpret_cast<T>(MakeCallAddr(calladdr, defaultaddr));
		RedirectCall(calladdr, func);
		return retaddr;
	}
	template<typename T>
	static void SafeRedirectCall(unsigned int calladdr, unsigned int defaultaddr, T func, T& retaddr)
	{
		retaddr = reinterpret_cast<T>(MakeCallAddr(calladdr, defaultaddr));
		RedirectCall(calladdr, func);
	}
	template<typename T>
	static T SafeRedirectJump(unsigned int jumpaddr, unsigned int defaultaddr, T func)
	{
		T retaddr = reinterpret_cast<T>(MakeJumpAddr(jumpaddr, defaultaddr));
		RedirectJump(jumpaddr, func);
		return retaddr;
	}
	template<typename T>
	static void SafeRedirectJump(unsigned int jumpaddr, unsigned int defaultaddr, T func, T& retaddr)
	{
		retaddr = reinterpret_cast<T>(MakeJumpAddr(jumpaddr, defaultaddr));
		RedirectJump(jumpaddr, func);
	}
	template<typename T>
	static T SafeRedirect_NoOffset(unsigned int addr, T func)
	{
		T retaddr = reinterpret_cast<T>(*reinterpret_cast<unsigned int *>(addr));
		SetPointer(addr, func);
		return retaddr;
	}
	template<typename T>
	static void SafeRedirect_NoOffset(unsigned int addr, T func, T& retaddr)
	{
		retaddr = reinterpret_cast<T>(*reinterpret_cast<unsigned int *>(addr));
		SetPointer(addr, func);
	}
	template<typename T>
	static void MakeInject(unsigned int type, unsigned int addr, T func, T& retaddr)
	{
		switch (type)
		{
		case INJ_CALL:
			SafeRedirectCall(addr, 0, func, retaddr);
			break;
		case INJ_JUMP:
			SafeRedirectJump(addr, 0, func, retaddr);
			break;
		case INJ_CB:
		case INJ_VTBL:
			SafeRedirect_NoOffset(addr, func, retaddr);
			break;
		}
	}	
	inline static void GetChar(int address, char *value)
	{
		Patch(value, (void *)address, 1);
	}
	inline static void GetShort(int address, short *value)
	{
		Patch(value, (void *)address, 2);
	}
	inline static void GetInt(int address, int *value)
	{
		Patch(value, (void *)address, 4);
	}
	inline static void GetFloat(int address, float *value)
	{
		Patch(value, (void *)address, 4);
	}
	inline static char GetChar(int address)
	{
		char value;
		Patch(&value, (void *)address, 1);
		return value;
	}
	inline static short GetShort(int address)
	{
		short value;
		Patch(&value, (void *)address, 2);
		return value;
	}
	inline static int GetInt(int address)
	{
		int value;
		Patch(&value, (void *)address, 4);
		return value;
	}
	inline static float GetFloat(int address)
	{
		float value;
		Patch(&value, (void *)address, 4);
		return value;
	}
	inline static void AdjustPointer(int address, void *value, int offset)
	{
		int result;
		if (((char)*(DWORD*)(address-0x3) == (char)0x8B)  || 
			((char)*(DWORD*)(address-0x3) == (char)0x83)  || 
			((char)*(DWORD*)(address-0x3) == (char)0x39)  || 
			((char)*(DWORD*)(address-0x3) == (char)0xC7)  ||
			((char)*(DWORD*)(address-0x1) == (char)0xA1)  ||
			((char)*(DWORD*)(address-0x2) == (char)0x8B)  ||
			((char)*(DWORD*)(address-0x3) == (char)0x89)  ||
			((char)*(DWORD*)(address-0x2) == (char)0x89)  
			) {

				if (
			((char)*(DWORD*)(address-0x2) != (char)0xE9)  &&
			((char)*(DWORD*)(address-0x1) != (char)0x00)  
			) {
		result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
		Patch((void *)address, &result, 4);
				}
		}
	}
	inline static void AdjustPointer2(int address, void *value, DWORD offset, DWORD end)
	{
		int result;
		if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
		result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
		Patch((void *)address, &result, 4);
		} else {
		address = address + 1;
			if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
			result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
			Patch((void *)address, &result, 4);
			} else {
				address = address + 1;
				if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
				result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
				Patch((void *)address, &result, 4);
				} else {
					address = address + 1;
					if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
				result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
				Patch((void *)address, &result, 4);
				} else {
					address = address + 1;
					if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
						result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
						Patch((void *)address, &result, 4);
					} else {
						address = address + 1;
						if((DWORD)*(DWORD*)address >= offset && (DWORD)*(DWORD*)address <= end) {
							result = (DWORD)value + (DWORD)*(DWORD*)address - (DWORD)offset;
							Patch((void *)address, &result, 4);
						}
					}
					}
				}
			}
		} 
	}
	inline static void AdjustPointer(int address, void *value, int offset, int end)
	{
		int lastaddr = address + 8, content, result;
		do {
			content = *(int *)address;
			if(content >= offset && content <= end) {
				result = (int)value + (content - offset);
				Patch2(address, &result, 4);
				break;
			}
		} while(++address < lastaddr);
	}
	inline static void AdjustPointer(int address, void *value, int start, int end, int offset)
	{
		int lastaddr = address + 12, content, result;
		do
		{
			content = *(int *)address;
			if(content >= start && content < end)
			{
				result = (int)value + (content - start) + offset;
				Patch2(address, &result, 4);
				break;
			}
		}
		while(++address < lastaddr);
	}
	inline static void AdjustPointer(int address, void *value, int start, int end, int oldsize, int newsize)
	{
		int lastaddr = address + 12, content, result;
		do
		{
			content = *(int *)address;
			if(content >= start && content < end)
			{
				result = (int)value + (content - start) + (newsize - oldsize);
				Patch2(address, &result, 4);
				break;
			}
		}
		while(++address < lastaddr);
	}
	inline static bool FileExists(const TCHAR *fileName)
	{
		DWORD       fileAttr;
		fileAttr = GetFileAttributes(fileName);
		if (0xFFFFFFFF == fileAttr && GetLastError()==ERROR_FILE_NOT_FOUND)
			return false;
		return true;
	}
};


const __declspec(selectany) unsigned char CPatch::NopInstr[][MAX_NOP_SIZE] =	// No-operation.
{
	{ 0x90 },
	{ 0x66, 0x90 },
	{ 0x0F, 0x1F, 0x00 },
	{ 0x0F, 0x1F, 0x40, 0x00 },
	{ 0x0F, 0x1F, 0x44, 0x00, 0x00 },
	{ 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00 },
	{ 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00 },
	{ 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 }
};
