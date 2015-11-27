#include "Memory.h"

Memory* memory;

Memory::Memory()
{
	this->ptr = 0;
}

Memory* Memory::getInstance()
{
	if (this->memory == NULL)
		this->memory = new Memory();
	return this->memory;
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

