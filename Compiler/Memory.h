#ifndef MEMORY_H
#define MEMORY_H

#include <cassert>
#include "Symbol.h"

#define FPMAX 128
#define ARRAYMAX 1024
#define CONSTMAX 1024
#define LEVELMAX 128
#define STRINGMAX 256
#define STACKFRAMEMAX 128

typedef int ADDR;

//Singleton class Memory
class Memory
{
private:
	const static int USTACKTOP = 0xffff0000;
	static ADDR ptr;
	static Memory* m_memory;
	Memory();
public:
	Memory* getInstance();
	int allocMem(int length = 1);
	void freeMem(int length);
};

class StackFrame
{
public:
	ADDR esp;
	ADDR ebp;
	ADDR display[STACKFRAMEMAX];
	//ADDR constaddr, varaddr, procaddr, funcaddr;
};

extern Memory* memory;

#endif