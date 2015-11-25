#include "Memory.h"


Memory::Memory()
{
}

ADDR Memory::allocMem(int length)
{
	ptr += 4 * length;
	ADDR addr = USTACKTOP - ptr;
	return addr;
}

void Memory::freeMem(int length)
{
	ptr -= 4 * length;
}
