#ifndef MEMORY_H
#define MEMORY_H

#include "Symbol.h"
#include "SymbolTable.h"

#define FPMAX 128
#define ARRAYMAX 1024
#define CONSTMAX 1024
#define LEVELMAX 128
#define STRINGMAX 256

typedef int ADDR;

class SubTable
{
private:
	SubTable();
public:
	static int subtable_index;
	int last[FPMAX], lastpar[FPMAX], psize[FPMAX], vsize[FPMAX];
	int insert(int last, int lastpar, int psize, int vsize)
	{
		this->last[subtable_index] = last;
		this->lastpar[subtable_index] = lastpar;
		this->psize[subtable_index] = psize;
		this->vsize[subtable_index] = vsize;
		subtable_index++;
		return subtable_index - 1;
	}
}sub_table;
int SubTable::subtable_index = 1;

class DisplayTable
{
private:
	DisplayTable() { this->size = 1; };
public:
	static int size;
	int index[LEVELMAX];
	void insert(int id)
	{
		this->index[size++] = id;
	}
}display_table;
int DisplayTable::size = 1;

class ArrayTable
{
private:
	ArrayTable();
public:
	static int arraytable_index;
	int len[ARRAYMAX];
	int insert(int len)
	{
		this->len[arraytable_index++] = len;
		return arraytable_index - 1;
	}
}array_table;
int ArrayTable::arraytable_index = 1;

class ConstTable
{
private:
	ConstTable();
public:
	static int consttable_index;
	int value[CONSTMAX];
	int insert(int value)
	{
		for (int i = 1; i < consttable_index; ++i)
		{
			if (this->value[i] == value)
				return i;
		}
		this->value[consttable_index++] = value;
		return consttable_index - 1;
	}
}const_table;
int ConstTable::consttable_index = 1;

class StringTable
{
private:
	StringTable();
public:
	static int stringtable_index;
	std::string strs[STRINGMAX];
	int insert(std::string str)
	{
		strs[stringtable_index++] = str;
		return stringtable_index - 1;
	}
}string_table;
int StringTable::stringtable_index = 1;


//Singleton class Memory
class Memory
{
private:
	const static ADDR USTACKTOP = 0xffff0000;
	static ADDR ptr;
	static Memory* memory;
	Memory();
public:
	Memory* getInstance();
	ADDR allocMem(int length = 1);
	void freeMem(int length);
};

class Code
{
#define OPLEN 16
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
}code;
int Code::code_index = 1;

#endif