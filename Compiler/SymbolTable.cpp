#include <iostream>
#include "SymbolTable.h"

SymbolTable symbol_table;

Label::Label()
{
	this->index = label_index++;
}

char* Label::toString(char* s)
{
	sprintf_s(s, 1023, "Label%d", this->index);
	return s;
}

Temp::Temp()
{
	this->index = tmp_index++;
	this->name[0] = '\0';
}

Temp::Temp(char* nname)
{
	strcpy_s(this->name, MAXLEN - 1, nname);
}

void Temp::fill(char* nname)
{
	strcpy_s(this->name, MAXLEN - 1, nname);
}

char* Temp::toString(char* s)
{
	sprintf_s(s, 1023, "T%d", this->index);
	return s;
}

SymbolTable::SymbolTable()
{
	memset(this->idents, 0, sizeof(this->idents));
}

int SymbolTable::insert(Identifier* ident)
{
	bool found = false;
	for (int i = symboltable_index - 1; i >= 1; --i)
	{
		if (!strcmp(idents[i]->name, ident->name))
		{
			found = true;
			break;
		}
		if (idents[i]->lastindex <= 0)
		{
			//assert(idents[i]->lastindex == -1);
			break;
		}
	}
	if (found)
		return NULL;
	if (ident->type == CONST)
	{
		Constance* cons = dynamic_cast<Constance*>(ident);
		Identifier* newcons = new Constance(*cons);
		this->idents[symboltable_index++] = newcons;
		return symboltable_index - 1;
	}
	else if (ident->type == INT || ident->type == CHAR)
	{
		Variable* var = dynamic_cast<Variable*>(ident);
		Identifier* newvar = new Variable(*var);
		this->idents[symboltable_index++] = newvar;
		return symboltable_index - 1;
	}
	else if (ident->type == INTARRAY || ident->type == CHARARRAY)
	{
		Array* arr = dynamic_cast<Array*>(ident);
		Identifier* newarr = new Array(*arr);
		this->idents[symboltable_index++] = newarr;
		return symboltable_index - 1;
	}
	else if (ident->type == PARA)
	{
		Parameter* pera = dynamic_cast<Parameter*>(ident);
		Identifier* newpara = new Parameter(*pera);
		this->idents[symboltable_index++] = newpara;
		return symboltable_index - 1;
	}
	else if (ident->type == PROC)
	{
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		Identifier* newproc = new Procedure(*proc);
		this->idents[symboltable_index++] = newproc;
		return symboltable_index - 1;
	}
	else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
	{
		Function* func = dynamic_cast<Function*>(ident);
		Identifier* newfunc = new Function(*func);
		this->idents[symboltable_index++] = newfunc;
		return symboltable_index - 1;
	}
	else
	{
		assert(0 == 1);
	}
}

Identifier* SymbolTable::find(int level, char* name)
{
	int display_level = display_table.size;
	while (display_level >= 1)
	{
		int sub_index = display_table.index[display_level];
		int index = sub_table.last[sub_index];
		while (index > sub_table.last[display_table.index[display_level - 1]])
		{
			/*
			if (symbol_table.idents[index]->lastindex < 1)
			{
				//assert(symbol_table.idents[index]->lastindex == -1);
				break;
			}
			*/
			if (!strcmp(symbol_table.idents[index]->name, name))
			{
				Identifier* ident = symbol_table.idents[index];
				return ident;
			}
			index--;
		}
		display_level--;
	}
	return NULL;
}

Identifier::Identifier(char* name, TYPE type, int level, int lastindex)
{
	this->index = ident_index++;
	strcpy_s(this->name, MAXLEN - 1, name);
	this->type = type;
	this->level = level;
	this->lastindex = lastindex - 1;
}

Constance::Constance(char* name, int level, int value, int lastindex) 
: Identifier(name, CONST, level, lastindex)
{
	this->addr = const_table.insert(value);
	symbol_table.insert(this);
}

Constance::Constance(const Constance& cons)
{
	this->index = cons.index;
	strcpy_s(this->name, MAXLEN - 1, cons.name);
	this->type = cons.type;
	this->level = cons.level;
	this->lastindex = cons.lastindex;
	this->addr = cons.addr;
}

Variable::Variable(char* name, TYPE type, int level, int lastindex)
: Identifier(name, type, level, lastindex)
{
	Memory* memory = NULL;
	memory = memory->getInstance();
	this->addr = memory->allocMem();
	symbol_table.insert(this);
}

Variable::Variable(const Variable& var)
{
	this->index = var.index;
	strcpy_s(this->name, MAXLEN - 1, var.name);
	this->type = var.type;
	this->level = var.level;
	this->lastindex = var.lastindex;
	this->addr = var.addr;
}

Array::Array(char* name, TYPE type, int level, int length, int lastindex)
: Identifier(name, type, level, lastindex)
{
	this->ref = array_table.insert(length);
	Memory* memory = NULL;
	memory = memory->getInstance();
	this->addr = memory->allocMem(length);
	symbol_table.insert(this);
}

Array::Array(const Array& arr)
{
	this->index = arr.index;
	strcpy_s(this->name, MAXLEN - 1, arr.name);
	this->type = arr.type;
	this->level = arr.level;
	this->lastindex = arr.lastindex;
	this->addr = arr.addr;
	this->ref = arr.ref;
}

Parameter::Parameter(char* name, int level, int lastindex, bool real, int addr)
: Identifier(name, PARA, level, lastindex)
{
	this->real = real;
	if (real)
		this->addr = addr;
	else
	{
		Memory* memory = NULL;
		memory = memory->getInstance();
		this->addr = memory->allocMem();
	}
	symbol_table.insert(this);
}

Parameter::Parameter(const Parameter& para)
{
	this->index = para.index;
	strcpy_s(this->name, MAXLEN - 1, para.name);
	this->type = para.type;
	this->level = para.level;
	this->real = para.real;
	this->lastindex = para.lastindex;
	this->addr = para.addr;
}

Procedure::Procedure(char* name, int level, int lastindex,
	int lastpar, int last, int psize, int vsize, int codeindex) :
	Identifier(name, PROC, level, lastindex)
{
	this->label = new Label();
	//this->ref = sub_table.insert(last, lastpar, psize, vsize);
	this->addr = codeindex;
	//this->lastindex = 0;
	symbol_table.insert(this);
}

Procedure::Procedure(const Procedure& proc)
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

void Procedure::setValue(int last, int lastpar, int psize, int vsize)
{
	sub_table.last[this->ref] = last;
	sub_table.lastpar[this->ref] = lastpar;
	sub_table.psize[this->ref] = psize;
	sub_table.vsize[this->ref] = vsize;
}

Function::Function(char* name, TYPE type, int level, int lastindex,
	int lastpar, int last, int psize, int vsize, int codeindex) :
	Identifier(name, type, level, lastindex)
{
	this->label = new Label();
	//this->ref = sub_table.insert(last, lastpar, psize, vsize);
	this->addr = codeindex;
	//this->lastindex = 0;
	symbol_table.insert(this);
}

Function::Function(const Function& func)
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

void Function::setValue(int last, int lastpar, int psize, int vsize)
{
	sub_table.last[this->ref] = last;
	sub_table.lastpar[this->ref] = lastpar;
	sub_table.psize[this->ref] = psize;
	sub_table.vsize[this->ref] = vsize;
}

int Identifier::ident_index = 1;
int SymbolTable::symboltable_index = 1;
int Label::label_index = 0;
int Temp::tmp_index = 0;
