#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <map>
#include <string>
#include "Symbol.h"
#include "Memory.h"

#define MAXIDENT 1024

extern SubTable sub_table;
extern DisplayTable display_table;
extern ArrayTable array_table;
extern ConstTable const_table;
extern StringTable string_table;

enum TYPE
{
	CONST,
	INT,
	CHAR,
	INTARRAY,
	CHARARRAY,
	PARA,
	PROC,
	FUNCINT,
	FUNCCHAR,
};

class Identifier
{
public:
	static int ident_index;
	int index;
	char name[MAXLEN];
	int lastindex;
	TYPE type;
	int level;
	ADDR addr;
	Identifier() {};
	Identifier(char* name, TYPE type, int level, int lastindex);
	virtual void print() = 0;
};
//int Identifier::ident_index = 1;

class SymbolTable
{
public:
	SymbolTable();
	static int symboltable_index;
	Identifier* idents[MAXIDENT];
	int insert(Identifier* ident);
	Identifier* find(int level, char* name);
};//symbol_table;
//int SymbolTable::symboltable_index = 1;

class Label
{
public:
	static int label_index;
	Label();
	int index;
	int addr;
	char* Label::toString(char* s);
};
//int Label::label_index = 0;

class Temp
{
public:
	static int tmp_index;
	char name[MAXLEN];
	Temp();
	Temp(char* nname);
	void fill(char* nname);
	int index;
	char* toString(char* s);
};
//int Temp::tmp_index = 0;

class Constance : public Identifier
{
public:
	Constance(char* name, int level, int value, int lastindex);
	Constance(const Constance& cons);
	void print() {}
};

class Variable : public Identifier
{
public:
	Variable(char* name, TYPE type, int level, int lastindex);
	Variable(const Variable& var);
	void print() {}
};

class Array : public Identifier
{
public:
	int ref;
	Array() : Identifier() {}
	Array(char* name, TYPE type, int level, int length, int lastindex);
	Array(const Array& arr);
	void print() {}
};

class Parameter : public Identifier
{
public:
	bool real;
	Parameter(char* name, int level, int lastindex, bool real, int addr = NULL);
	Parameter(const Parameter& para);
	void print() {}
};

class Procedure : public Identifier
{
public:
	Label* label;
	int ref;
	Procedure(char* name, int level, int lastindex,
		int lastpar, int last, int psize, int vsize, int codeindex);
	Procedure(const Procedure& proc);
	~Procedure()
	{
		delete(this->label);
	}
	void print() {}
};

class Function : public Identifier
{
public:
	Label* label;
	int ref;
	Function(char* name, TYPE type, int level, int lastindex,
		int lastpar, int last, int psize, int vsize, int codeindex);
	Function(const Function& func);
	~Function()
	{
		delete(this->label);
	}
	void print() {}
};

extern SymbolTable symbol_table;

#endif
