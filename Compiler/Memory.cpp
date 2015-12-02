#include "Memory.h"

StringTable string_table;

Memory::Memory()
{
	this->ptr = 0;
}

Memory* Memory::getInstance()
{
	if (memory == NULL)
		memory = new Memory();
	return memory;
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

int StringTable::stringtable_index = 1;
int Memory::ptr = 1;
Memory* Memory::memory = NULL;
