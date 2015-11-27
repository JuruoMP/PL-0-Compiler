#include "SymbolTable.h"
#include "Memory.h"
#include <iostream>

extern Memory* memory;

Label::Label()
{
	this->index = label_cnt++;
}

char* Label::toString()
{
	char s[1024];
	sprintf_s(s, 1023, "Label%d", this->index);
}

Temp::Temp()
{
	this->index = tmp_cnt++;
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
	SubTable ltable(0);
	this->tables.push_back(ltable);
}

bool SymbolTable::pushLevel(int level)
{
	SubTable ltable(level);
	if (tables.back().m_level == level - 1)
	{
		tables.push_back(ltable);
		return true;
	}
	else
	{
		return false;
	}
}

int SymbolTable::popLevel()
{
	//TODO:free memory
	int level = tables.back().m_level;
	tables.pop_back();
	return level;
}

ADDR SymbolTable::insert(int level, char* name, Identifier& ident)
{
	std::string str = name;
	ADDR ptr = NULL;
	if (tables.at(level).m_table.find(str) == tables.at(level).m_table.end())
	{
		if (ident.type == CONST)
		{
			Constance* cons = dynamic_cast<Constance*>(&ident);
			Identifier* newcons = new Constance(*cons);
			tables.at(level).m_table.insert(std::pair<std::string, Identifier*>(name, newcons));
			ptr = memory->allocMem();
		}
		else if (ident.type == INT || ident.type == CHAR || 
			ident.type == INTARRAY || ident.type == CHARARRAY ||
			ident.type == PARA)
		{
			Variable* var = dynamic_cast<Variable*>(&ident);
			Identifier* newvar = new Variable(*var);
			tables.at(level).m_table.insert(std::pair<std::string, Identifier*>(name, newvar));
			ptr = memory->allocMem(var->len);
		}
		else if (ident.type == PROC)
		{
			Procedure* proc = dynamic_cast<Procedure*>(&ident);
			Identifier* newproc = new Procedure(*proc);
			tables.at(level).m_table.insert(std::pair<std::string, Identifier*>(name, newproc));
		}
		else if (ident.type == FUNCINT || ident.type == FUNCCHAR)
		{
			Function* func = dynamic_cast<Function*>(&ident);
			Identifier* newfunc = new Function(*func);
			tables.at(level).m_table.insert(std::pair<std::string, Identifier*>(name, newfunc));
			ptr = memory->allocMem();
		}
		return ptr;
	}
	else
	{
		return NULL;
	}
}

Identifier* SymbolTable::find(int level, char* name)
{
	//std::map<std::string, Identifier*>::iterator it;
	std::string str = name;
	while (level > 0)
	{
		//std::map<std::string, Identifier*> table = tables.at(level).m_table;
		//it = table.find(str);
		if (tables.at(level).m_table.find(str) != tables.at(level).m_table.end())
		{
			std::map<std::string, Identifier*>::iterator it;
			it = tables.at(level).m_table.find(str);
			return tables.at(level).m_table.find(str)->second;
		}
		level--;
	}
	return NULL;
}
