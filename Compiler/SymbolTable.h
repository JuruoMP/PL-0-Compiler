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

class Label
{
private:
	static int label_index;
public:
	Label();
	int index;
	ADDR addr;
	char* Label::toString();
};
int Label::label_index = 0;

class Temp
{
public:
	static int tmp_index;
	char name[MAXLEN];
public:
	Temp();
	Temp(char* nname);
	void fill(char* nname);
	int index;
	char* toString();
};
int Temp::tmp_index = 0;


class Identifier
{
	static int ident_index;
public:
	int index;
	char name[MAXLEN];
	int lastindex;
	TYPE type;
	int level;
	ADDR addr;
	Identifier() {};
	Identifier(char* name, TYPE type, int level, int lastindex)
	{
		this->index = ident_index++;
		strcpy_s(this->name, MAXLEN - 1, name);
		this->type = type;
		this->level = level;
		this->lastindex = lastindex;
	}
	virtual void print() = 0;
};
int Identifier::ident_index = 1;

class Constance : public Identifier
{
public:
	Constance(char* name, int level, int value, int lastindex) 
		: Identifier(name, CONST, level, lastindex)
	{
		this->addr = const_table.insert(value);
	}
	Constance(const Constance& cons) 
	{
		this->index = cons.index;
		strcpy_s(this->name, MAXLEN - 1, cons.name);
		this->type = cons.type;
		this->level = cons.level;
		this->lastindex = cons.lastindex;
		this->addr = cons.addr;
	}
	void print() {}
};

class Variable : public Identifier
{
public:
	Variable() : Identifier()
	{
		Memory* memory = memory->getInstance();
		this->addr = memory->allocMem();
	}
	Variable(char* name, TYPE type, int level, int lastindex) 
		: Identifier(name, type, level, lastindex) {}
	Variable(const Variable& var) 
	{
		this->index = var.index;
		strcpy_s(this->name, MAXLEN - 1, var.name);
		this->type = var.type;
		this->level = var.level;
		this->lastindex = var.lastindex;
		this->addr = var.addr;
	}
	void print() {}
};

class Array : public Identifier
{
public:
	int ref;
	Array() : Identifier() {}
	Array(char* name, TYPE type, int level, int length, int lastindex)
		: Identifier(name, type, level, lastindex)
	{
		this->ref = array_table.insert(length);
		Memory* memory = memory->getInstance();
		this->addr = memory->allocMem(length);
	}
	Array(const Array& arr)
	{
		this->index = arr.index;
		strcpy_s(this->name, MAXLEN - 1, arr.name);
		this->type = arr.type;
		this->level = arr.level;
		this->lastindex = arr.lastindex;
		this->addr = arr.addr;
		this->ref = arr.ref;
	}
	void print() {}
};

class Parameter : public Identifier
{
public:
	bool real;
	Parameter(char* name, int level, int lastindex, bool real, int addr = NULL) 
		: Identifier(name, PARA, level, lastindex)
	{
		this->real = real;
		if (real)
			this->addr = addr;
		else
			this->addr = 
	}
	Parameter(const Parameter& para) 
	{
		this->index = para.index;
		strcpy_s(this->name, MAXLEN - 1, para.name);
		this->type = para.type;
		this->level = para.level;
		this->real = para.real;
		this->lastindex = para.lastindex;
		this->addr = para.addr;
	}
	void print() {}
};

class Procedure : public Identifier
{
public:
	Label* label;
	int ref;
	Procedure(char* name, int level, int lastindex, 
		int lastpar, int last, int psize, int vsize, int codeindex) :
		Identifier(name, PROC, level, lastindex)
	{
		this->label = new Label();
		this->ref = sub_table.insert(lastpar, last, psize, vsize);
		this->addr = codeindex;
	}
	Procedure(const Procedure& proc)
	{
		this->index = proc.index;
		this->label = new Label();
		strcpy_s(this->name, MAXLEN - 1, proc.name);
		this->type = proc.type;
		this->level = proc.level;
		this->lastindex = proc.lastindex;
		this->addr = proc.addr;
		this->ref = proc.ref;
	}
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
		int lastpar, int last, int psize, int vsize, int codeindex) :
		Identifier(name, type, level, lastindex)
	{
		this->label = new Label();
		this->ref = sub_table.insert(lastpar, last, psize, vsize);
		this->addr = codeindex;
	}
	Function(const Function& func)
	{
		this->index = func.index;
		this->label = new Label();
		strcpy_s(this->name, MAXLEN - 1, func.name);
		this->type = func.type;
		this->level = func.level;
		this->lastindex = func.lastindex;
		this->addr = func.addr;
		this->ref = func.ref;
	}
	~Function()
	{
		delete(this->label);
	}
	void print() {}
};

class SymbolTable
{
private:
	SymbolTable();
public:
	static int symboltable_index;
	Identifier* idents[MAXIDENT];
	int insert(Identifier& ident);
	Identifier* find(int level, char* name);
}symbol_table;
int SymbolTable::symboltable_index = 1;

#endif