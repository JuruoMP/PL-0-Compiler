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

class Code
{
#define OPLEN 256
public:
	class Op
	{
	public:
		char tar[OPLEN], src1[OPLEN], src2[OPLEN];
		char opcode[OPLEN];
	};
	static int code_index;
	int index;
	int addr;
	Op op;
	int insert(char* op, char* tar, char* src1 = "", char* src2 = "")
	{
		this->index = code_index++;
		strcpy_s(this->op.opcode, OPLEN - 1, op);
		strcpy_s(this->op.tar, OPLEN - 1, tar);
		strcpy_s(this->op.src1, OPLEN - 1, src1);
		strcpy_s(this->op.src2, OPLEN - 1, src2);
		return code_index - 1;
	}
};// code;
//int Code::code_index = 1;

extern StringTable string_table;
extern Code code;

#endif