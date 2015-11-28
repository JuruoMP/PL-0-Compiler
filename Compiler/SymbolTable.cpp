#include "SymbolTable.h"
#include "Memory.h"
#include <iostream>

Label::Label()
{
	this->index = label_index++;
}

char* Label::toString()
{
	char s[1024];
	sprintf_s(s, 1023, "Label%d", this->index);
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

char* Temp::toString()
{
	char s[1024];
	sprintf_s(s, 1023, "T%d", this->index);
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
		if (idents[i]->index == 0)
			break;
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
	else if (ident->type == INT || ident->type == CHAR ||
		ident->type == INTARRAY || ident->type == CHARARRAY ||
		ident->type == PARA)
	{
		Variable* var = dynamic_cast<Variable*>(ident);
		Identifier* newvar = new Variable(*var);
		this->idents[symboltable_index++] = newvar;
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
	return symboltable_index - 1;
}

Identifier* SymbolTable::find(int level, char* name)
{
	int level = display_table.size;
	while (level >= 1)
	{
		int sub_index = display_table.index[level];
		int index = sub_table.last[sub_index];
		while (!strcmp(symbol_table.idents[index]->name, name))
		{
			Identifier* ident = symbol_table.idents[index];
			return ident;
		}
	}
	return NULL;
}
