#pragma once

struct tPoolObjectFlags
{
	union
	{
		struct
		{
			unsigned char nID : 7;
			unsigned char bIsFreeSlot : 1;
		};
		unsigned char IntValue; 
	};
	
};

template<class A, class B> class CPool
{
public:
	B* m_Objects;
	tPoolObjectFlags* m_ByteMap;
	int m_Size;
	int m_Top;

	
	CPool()
	{
		
	}
	
	A *GetAt(int item)
	{
		if ( (item & 0xFF) == m_ByteMap[item >> 8].IntValue )
			return (A *)&m_Objects[item >> 8];
		else
			return NULL;
	}
	
	bool GetIsFree(int i) const
	{
		return !!(m_ByteMap[i].bIsFreeSlot);
	}
	
	int GetSize(void) const { return m_Size; }
	
	A *GetSlot(int i){
		return GetIsFree(i) ? NULL : (A*)&m_Objects[i];
	}
	
	int GetJustIndex(A *item)
	{
		return ( ((B *)(item)) - m_Objects);
	}
}; 