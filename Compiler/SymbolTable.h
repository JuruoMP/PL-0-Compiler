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

class Label
{
private:
	static int label_cnt;
public:
	Label();
	int index;
	ADDR addr;
	char* Label::toString();
};
int Label::label_cnt = 0;

class Temp
{
public:
	static int tmp_cnt;
	char name[MAXLEN];
public:
	Temp();
	Temp(char* nname);
	void fill(char* nname);
	int index;
	char* toString();
};
int Temp::tmp_cnt = 0;

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
	ParaTable* paraTable;
	Label* label;
	Procedure(char* name, int level, ParaTable paras) :
		Identifier(name, PROC, level)
	{
		this->label = new Label();
		this->paraTable = new ParaTable(paras);
	}
	Procedure(const Procedure& proc)
	{
		this->label = new Label();
		strcpy_s(this->name, MAXLEN - 1, proc.name);
		this->type = proc.type;
		this->level = proc.level;
		this->paraTable = new ParaTable(proc.paraTable);
	}
	~Procedure()
	{
		delete(this->label);
		delete(this->paraTable);
	}
	void print() {}
};

class Function : public Identifier
{
public:
	ParaTable* paraTable;
	Label* label;
	Function(char* name, TYPE type, int level, ParaTable paras) :
		Identifier(name, type, level)
	{
		this->label = new Label();
		this->paraTable = new ParaTable(paras);
	}
	Function(Function& func) :
		Identifier(func.name, type, func.level)
	{
		this->label = new Label();
		strcpy_s(this->name, MAXLEN - 1, func.name);
		this->type = func.type;
		this->level = func.level;
		this->paraTable = new ParaTable(func.paraTable);
	}
	~Function()
	{
		delete(this->label);
		delete(this->paraTable);
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
	ADDR insert(int level, char* name, Identifier& ident);
	Identifier* find(int level, char* name);
};

#endif