#include "Memory.h"

Memory* memory;

ADDR Memory::ptr;
Memory* Memory::m_memory;

Memory::Memory()
{
	ptr = 0;
}

Memory* Memory::getInstance()
{
	if (m_memory == NULL)
		m_memory = new Memory();
	return m_memory;
}

ADDR Memory::allocMem(int length)
{
	ptr += length;
	return ptr;
}

void Memory::freeMem(int length)
{
	ptr -= length;
}

