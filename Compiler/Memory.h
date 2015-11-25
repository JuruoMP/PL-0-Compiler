#ifndef MEMORY_H
#define MEMORY_H

#include "Symbol.h"
#include "SymbolTable.h"

typedef int ADDR;

//Singleton class Memory
class Memory
{
private:
	const static ADDR USTACKTOP = 0xffff0000;
	static ADDR ptr;
	static Memory* memory;
	Memory() { this->ptr = 0; }
public:
	Memory* getInstance()
	{
		return this->memory;
	}
	ADDR allocMem(int length = 1);
	void freeMem(int length);
};

#endif