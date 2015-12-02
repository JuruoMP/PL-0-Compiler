#ifndef MEMORY_H
#define MEMORY_H

#include <cassert>
#include "Symbol.h"

#define FPMAX 128
#define ARRAYMAX 1024
#define CONSTMAX 1024
#define LEVELMAX 128
#define STRINGMAX 256

typedef int ADDR;

class StringTable
{
public:
	StringTable() {};
	static int stringtable_index;
	std::string strs[STRINGMAX];
	int insert(std::string str)
	{
		strs[stringtable_index++] = str;
		return stringtable_index - 1;
	}
};// string_table;
//int StringTable::stringtable_index = 1;


//Singleton class Memory
class Memory
{
private:
	const static int USTACKTOP = 0xffff0000;
	static int ptr;
	static Memory* memory;
	Memory();
public:
	Memory* getInstance();
	int allocMem(int length = 1);
	void freeMem(int length);
};

extern StringTable string_table;

#endif