#include "Memory.h"

SubTable sub_table;
DisplayTable display_table;
ArrayTable array_table;
ConstTable const_table;
StringTable string_table;
Code code;

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
	ptr += length;
	return ptr;
}

void Memory::freeMem(int length)
{
	ptr -= length;
}

int SubTable::subtable_index = 1;
int DisplayTable::size = 1;
int ArrayTable::arraytable_index = 1;
int ConstTable::consttable_index = 1;
int StringTable::stringtable_index = 1;
int Code::code_index = 1;
int Memory::ptr = 1;
Memory* Memory::memory = NULL;
