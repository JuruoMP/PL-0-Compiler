#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <map>
#include <string>
#include "Symbol.h"
#include "Memory.h"

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
	char name[MAXLEN];
	TYPE type;
	ADDR addr;
	int level;
	Identifier() {};
	Identifier(char* name, TYPE type, int level)
	{
		strcpy_s(this->name, MAXLEN - 1, name);
		this->type = type;
		this->level = level;
	}
	virtual void print() = 0;
};

class Constance : public Identifier
{
public:
	int value;
	Constance(char* name, int level, int value) 
		: Identifier(name, CONST, level)
	{
		this->value = value;
	}
	Constance(const Constance& cons) 
	{
		strcpy_s(this->name, MAXLEN - 1, cons.name);
		this->type = cons.type;
		this->level = cons.level;
		this->value = cons.value;
	}
	void print() {}
};

class Variable : public Identifier
{
public:
	int len;
	Variable() : Identifier() {}
	Variable(char* name, TYPE type, int level) 
		: Identifier(name, type, level) {}
	Variable(char* name, TYPE type, int level, int length) 
		: Identifier(name, type, level)
	{
		this->len = length;
	}
	Variable(Variable& var) 
	{
		strcpy_s(this->name, MAXLEN - 1, var.name);
		this->type = var.type;
		this->level = var.level;
		this->len = var.len;
	}
	void print() {}
};

class Parameter : public Identifier
{
public:
	bool real;
	Parameter(char* name, int level, bool real) 
		: Identifier(name, PARA, level)
	{
		this->real = real;
	}
	Parameter(const Parameter& para) 
	{
		strcpy_s(this->name, MAXLEN - 1, para.name);
		this->type = para.type;
		this->level = para.level;
		this->real = para.real;
	}
	void print() {}
};

class ParaTable
{
public:
	std::vector<Parameter> paras;
	ParaTable() {};
	ParaTable(const ParaTable& paratable)
	{
		for (int i = 0; i < paratable.paras.size(); ++i)
			this->paras.push_back(paratable.paras.at(i));
	}
	void add(const Parameter& para)
	{
		Parameter p(para);
		this->paras.push_back(p);
	}
};

class Procedure : public Identifier
{
public:
	ParaTable paraTable;
	Procedure(char* name, int level, ParaTable paras) :
		Identifier(name, PROC, level)
	{
		ParaTable p(paras);///////////////////////////////////////////////////////////////////////
		this->paraTable = p;
	}
	Procedure(const Procedure& proc)
	{
		strcpy_s(this->name, MAXLEN - 1, proc.name);
		this->type = proc.type;
		this->level = proc.level;
		ParaTable p(proc.paraTable);////////////////////////////////////////////////////////////////
		this->paraTable = p;
	}
	void print() {}
};

class Function : public Identifier
{
public:
	ParaTable paraTable;
	Function(char* name, TYPE type, int level, ParaTable paras) :
		Identifier(name, type, level)
	{
		ParaTable p(paras);//////////////////////////////////////////////////////////////////
		this->paraTable = p;
	}
	Function(Function& func) :
		Identifier(func.name, type, func.level)
	{
		strcpy_s(this->name, MAXLEN - 1, func.name);
		this->type = func.type;
		this->level = func.level;
		ParaTable p(func.paraTable);/////////////////////////////////////////////////////////////////
		this->paraTable = p;
	}
	void print() {}
};

class SymbolTable
{
public:
	class SubTable
	{
	public:
		int m_level;
		std::map<std::string, Identifier*> m_table;
		SubTable(int level) { this->m_level = level; }
	};
	std::vector<SubTable> tables;

	SymbolTable();
	bool pushLevel(int level);
	int popLevel();
	bool insert(int level, char* name, Identifier& ident);
	Identifier* find(int level, char* name);
};

#endif