#include <iostream>
#include <stack>
#include "SymbolTable.h"

SymbolTable* SymbolTable::symboltable;
SymbolTable* symbol_table;
std::stack<int> node_stack;

int SymbolTable::nodecnt = 0;

SymbolTable* SymbolTable::getInstance()
{
	if (symboltable == NULL)
		symboltable = new SymbolTable();
	return symboltable;
}

int SymbolTable::addNode(int father, bool is_proc)
{
	nodecnt++;
	if (nodecnt >= MAXCNT)
		return -1;
	nodes[nodecnt] = new Node();
	nodes[nodecnt]->father_index = father;
	nodes[nodecnt]->is_proc = is_proc;
	return nodecnt;
}

void SymbolTable::into(int id)
{
	this->index = id;
}

void SymbolTable::back()
{
	//this->index = this->nodes[this->index]->father_index;
	//node_stack.pop();
	this->index = node_stack.top();
}

bool SymbolTable::insertIdent(Identifier* ident)
{
	std::vector<Identifier*>::iterator it = nodes[index]->idents.begin();
	for (it ; it != nodes[index]->idents.end(); ++it)
	{
		if (*it == ident)
			break;
	}
	if (it != nodes[index]->idents.end())
		return false;
	if (ident->type == CONST)
	{
		Constance* cons = dynamic_cast<Constance*>(ident);
		Identifier* newcons = new Constance(*cons);
		nodes[index]->idents.push_back(newcons);
		nodes[index]->last_const = nodes[index]->offset_cnt;
		nodes[index]->offset_cnt += 1;
	}
	else if (ident->type == INT || ident->type == CHAR)
	{
		Variable* var = dynamic_cast<Variable*>(ident);
		Identifier* newvar = new Variable(*var);
		nodes[index]->idents.push_back(newvar);
		nodes[index]->last_var = nodes[index]->offset_cnt;
		nodes[index]->offset_cnt += 1;
	}
	else if (ident->type == INTARRAY || ident->type == CHARARRAY)
	{
		Array* arr = dynamic_cast<Array*>(ident);
		Identifier* newarr = new Array(*arr);
		nodes[index]->idents.push_back(newarr);
		nodes[index]->last_var = nodes[index]->offset_cnt;
		nodes[index]->offset_cnt += arr->len;
	}
	else if (ident->type == PARA)
	{
		Parameter* para = dynamic_cast<Parameter*>(ident);
		Identifier* newpara = new Parameter(*para);
		nodes[index]->idents.push_back(newpara);
		nodes[index]->last_para = nodes[index]->offset_cnt;
		if (para->real)
			nodes[index]->offset_cnt += 1;
	}
	else if (ident->type == PROC)
	{
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		Identifier* newproc = new Procedure(*proc);
		nodes[index]->idents.push_back(newproc);
		nodes[index]->last_callable = nodes[index]->offset_cnt;
	}
	else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
	{
		Function* func = dynamic_cast<Function*>(ident);
		Identifier* newfunc = new Function(*func);
		nodes[index]->idents.push_back(newfunc);
		nodes[index]->last_callable = nodes[index]->offset_cnt;
	}
	else
	{
		assert(0 == 1);
	}
	return true;
}

Identifier* SymbolTable::findIdent(char* name)
{
	int tindex = this->index;
	std::vector<Identifier*>::iterator it;
	while (tindex != 0)
	{
		for (it = nodes[tindex]->idents.begin(); it != nodes[tindex]->idents.end(); ++it)
		{
			Identifier* ident = *it;
			if (!strcmp(ident->name, name))
				return ident;
		}
		tindex = nodes[tindex]->father_index;
	}
	assert(0 == 1);
	return NULL;
}

Identifier::Identifier(char* name, TYPE type)
{
	strcpy_s(this->name, MAXLEN - 1, name);
	this->offset = symbol_table->nodes[symbol_table->index]->offset_cnt;
	this->type = type;
}

Constance::Constance(char* name, int value) 
: Identifier(name, CONST)
{
	this->value = value;
	bool status = symbol_table->insertIdent(this);
}

Constance::Constance(const Constance& cons)
{
	strcpy_s(this->name, MAXLEN - 1, cons.name);
	this->type = cons.type;
	this->offset = cons.offset;
	this->value = cons.value;
}

Variable::Variable(char* name, TYPE type)
: Identifier(name, type)
{
	bool status = symbol_table->insertIdent(this);
}

Variable::Variable(const Variable& var)
{
	strcpy_s(this->name, MAXLEN - 1, var.name);
	this->type = var.type;
	this->offset = var.offset;
}

Array::Array(char* name, TYPE type, int length)
: Identifier(name, type)
{
	symbol_table->insertIdent(this);
}

Array::Array(const Array& arr)
{
	strcpy_s(this->name, MAXLEN - 1, arr.name);
	this->type = arr.type;
	this->offset = arr.offset;
	this->len = arr.len;
}

Parameter::Parameter(char* name, bool real)
: Identifier(name, PARA)
{
	this->real = real;
	symbol_table->insertIdent(this);
}

Parameter::Parameter(const Parameter& para)
{
	strcpy_s(this->name, MAXLEN - 1, para.name);
	this->type = para.type;
	this->real = para.real;
	this->offset = para.offset;
}

Procedure::Procedure(char* name, int nodeid) :
	Identifier(name, PROC)
{
	this->nodeid = nodeid;
	symbol_table->insertIdent(this);
}

Procedure::Procedure(const Procedure& proc)
{
	strcpy_s(this->name, MAXLEN - 1, proc.name);
	this->type = proc.type;
	this->addr = proc.addr;
	this->nodeid = proc.nodeid;
}

Function::Function(char* name, TYPE type, int nodeid) :
	Identifier(name, type)
{
	this->nodeid = nodeid;
	symbol_table->insertIdent(this);
}

Function::Function(const Function& func)
{
	strcpy_s(this->name, MAXLEN - 1, func.name);
	this->type = func.type;
	this->addr = func.addr;
	this->nodeid = func.nodeid;
}

