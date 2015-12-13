#include <iostream>
#include <stack>
#include "SymbolTable.h"

SymbolTable* SymbolTable::symboltable;
SymbolTable* symbol_table;
std::stack<int> node_stack;

int SymbolTable::nodecnt = 0;

SymbolTable::Node::Node(char* name, bool is_proc, int level)
{
	strcpy_s(this->name, MAXLEN - 1, name);
	this->is_proc = is_proc;
	this->display_size = level;
	this->offset_cnt = 0;
	this->last_para = this->last_const 
		= this->last_var = this->last_temp = 0;
}

SymbolTable::SymbolTable()
{
	this->index = 0;
	char* str = "INIT";
	this->nodes[this->index] = new Node(str, true, 0);
	this->nodes[this->index]->offset_cnt = 0;
}

SymbolTable* SymbolTable::getInstance()
{
	if (symboltable == NULL)
		symboltable = new SymbolTable();
	return symboltable;
}

int SymbolTable::addNode(char* name, int father, bool is_proc)
{
	int level = 0, nownode = father;
	while (nownode != 0)
	{
		level++;
		nownode = nodes[nownode]->father_index;
	}
	nodecnt++;
	if (nodecnt >= MAXCNT)
		return -1;
	nodes[nodecnt] = new Node(name, is_proc, level);
	nodes[nodecnt]->father_index = father;
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
		nodes[index]->offset_cnt += 1;
		nodes[index]->last_const = nodes[index]->offset_cnt;
		nodes[index]->last_var = nodes[index]->last_temp = nodes[index]->last_const;
	}
	else if (ident->type == INT || ident->type == CHAR ||
		ident->type == RETINT || ident->type == RETCHAR)
	{
		Variable* var = dynamic_cast<Variable*>(ident);
		Identifier* newvar = new Variable(*var);
		nodes[index]->idents.push_back(newvar);
		nodes[index]->offset_cnt += 1;
		nodes[index]->last_var = nodes[index]->offset_cnt;
		nodes[index]->last_temp = nodes[index]->last_var;
	}
	else if (ident->type == INTARRAY || ident->type == CHARARRAY)
	{
		Array* arr = dynamic_cast<Array*>(ident);
		Identifier* newarr = new Array(*arr);
		nodes[index]->idents.push_back(newarr);
		nodes[index]->offset_cnt += arr->len;
		nodes[index]->last_var = nodes[index]->offset_cnt;
		nodes[index]->last_temp = nodes[index]->last_const;
	}
	else if (ident->type == PARA)
	{
		Parameter* para = dynamic_cast<Parameter*>(ident);
		Identifier* newpara = new Parameter(*para);
		nodes[index]->idents.push_back(newpara);
		//if (para->real)
			//nodes[index]->offset_cnt += 1;
		//nodes[index]->last_para = nodes[index]->offset_cnt;
	}
	else if (ident->type == PROC)
	{
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		Identifier* newproc = new Procedure(*proc);
		nodes[index]->idents.push_back(newproc);
		//nodes[index]->last_callable = nodes[index]->offset_cnt;
	}
	else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
	{
		Function* func = dynamic_cast<Function*>(ident);
		Identifier* newfunc = new Function(*func);
		nodes[index]->idents.push_back(newfunc);
		//nodes[index]->last_callable = nodes[index]->offset_cnt;
	}
	else if (ident->type == TEMP)
	{
		Temp* temp = dynamic_cast<Temp*>(ident);
		Identifier* newtemp = new Temp(*temp);
		nodes[index]->idents.push_back(newtemp);
		nodes[index]->offset_cnt += 1;
		nodes[index]->last_temp = nodes[index]->offset_cnt;
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
			//if (nodes[tindex]->is_proc == false && it == nodes[tindex]->idents.begin())
				//continue;
			if (!strcmp(ident->name, name))
				return ident;
		}
		tindex = nodes[tindex]->father_index;
	}
	assert(0 == 1);
	return NULL;
}

Identifier* SymbolTable::ret2head(Identifier* ret)
{
	int tindex = this->nodes[ret->this_node]->father_index;
	std::vector<Identifier*>::iterator it;
	for (it = nodes[tindex]->idents.begin(); it != nodes[tindex]->idents.end(); ++it)
	{
		Identifier* ident = *it;
		if (!strcmp(ident->name, ret->name))
			return ident;
	}
	assert(0 == 1);
	return NULL;
}

Temp* SymbolTable::findTemp(int id)
{
	int tindex = this->index;
	std::vector<Identifier*>::iterator it;
	while (tindex != 0)
	{
		for (it = nodes[tindex]->idents.begin(); it != nodes[tindex]->idents.end(); ++it)
		{
			Identifier* ident = *it;
			if (ident->type == TEMP)
			{
				Temp* temp = dynamic_cast<Temp*>(ident);
				if (temp->id == id)
					return temp;
			}
		}
		tindex = nodes[tindex]->father_index;
	}
	assert(0 == 1);
	return NULL;
}

bool SymbolTable::sameLevel(Node &a, Node &b)
{
	if (a.father_index == b.father_index)
		return true;
	else
		return false;
}

Identifier::Identifier(char* name, TYPE type)
{
	strcpy_s(this->name, MAXLEN - 1, name);
	this->type = type;
	this->this_node = symbol_table->index;
	if (this->type == PARA)
		this->offset = symbol_table->nodes[symbol_table->index]->last_para++;
	else
		this->offset = -symbol_table->nodes[symbol_table->index]->offset_cnt;
}

ADDR Identifier::getOffset()
{
	if (this->type == PARA)
		return UNITSIZE * (2 + this->offset);
	else
		return UNITSIZE * this->offset;
}

Constance::Constance(char* name, int value) 
: Identifier(name, CONST)
{
	this->value = value;
	this->offset -= 1;
	bool status = symbol_table->insertIdent(this);
}

Constance::Constance(const Constance& cons)
{
	this->this_node = cons.this_node;
	strcpy_s(this->name, MAXLEN - 1, cons.name);
	this->type = cons.type;
	this->offset = cons.offset;
	this->value = cons.value;
}

Variable::Variable(char* name, TYPE type)
: Identifier(name, type)
{
	this->offset -= 1;
	bool status = symbol_table->insertIdent(this);
}

Variable::Variable(const Variable& var)
{
	this->this_node = var.this_node;
	strcpy_s(this->name, MAXLEN - 1, var.name);
	this->type = var.type;
	this->offset = var.offset;
}

Array::Array(char* name, TYPE type, int length)
: Identifier(name, type)
{
	this->len = length;
	this->offset -= length;
	symbol_table->insertIdent(this);
}

Array::Array(const Array& arr)
{
	this->this_node = arr.this_node;
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
	this->this_node = para.this_node;
	strcpy_s(this->name, MAXLEN - 1, para.name);
	this->type = para.type;
	this->real = para.real;
	this->offset = para.offset;
}

Callable::Callable(char* name, TYPE type)
: Identifier(name, type) {}

Parameter* Callable::getParaAt(int pos)
{
	int nodeid = this->nodeid;
	if (this->type == FUNCINT || this->type == FUNCCHAR)
		pos++;
	if (symbol_table->nodes[nodeid]->idents.size() <= pos)
		return NULL;
	Identifier* ident = symbol_table->nodes[nodeid]->idents.at(pos);
	Parameter* para = dynamic_cast<Parameter*>(ident);
	return para;
}

Procedure::Procedure(char* name, int nodeid) 
: Callable(name, PROC)
{
	this->nodeid = nodeid;
	symbol_table->insertIdent(this);
}

Procedure::Procedure(const Procedure& proc)
{
	this->this_node = proc.this_node;
	strcpy_s(this->name, MAXLEN - 1, proc.name);
	this->type = proc.type;
	this->addr = proc.addr;
	this->nodeid = proc.nodeid;
}

Function::Function(char* name, TYPE type, int nodeid) 
: Callable(name, type)
{
	this->nodeid = nodeid;
	symbol_table->insertIdent(this);
}

Function::Function(const Function& func)
{
	this->this_node = func.this_node;
	strcpy_s(this->name, MAXLEN - 1, func.name);
	this->type = func.type;
	this->addr = func.addr;
	this->nodeid = func.nodeid;
}

int Temp::temp_cnt = 0;
Temp::Temp() 
{
	this->this_node = symbol_table->index;
	this->offset = -symbol_table->nodes[symbol_table->index]->offset_cnt - 1;
	this->id = temp_cnt;
	this->type = TEMP;
	this->temp_type = TEMPTP;
	this->has_subscript = false;
	temp_cnt++;
	symbol_table->insertIdent(this);
}

Temp::Temp(int value)
{
	this->this_node = symbol_table->index;
	this->id = temp_cnt;
	this->type = TEMP;
	this->temp_type = VALUETP;
	this->value = value;
	this->has_subscript = false;
	temp_cnt++;
	//symbol_table->insertIdent(this);
}

Temp::Temp(Identifier* ident, bool has_subscript, Temp* subscribe)
{
	this->this_node = symbol_table->index;
	if (zero == NULL)
		zero = new Temp(0);
	if (one == NULL)
		one = new Temp(1);
	this->type = TEMP;
	if (ident->type == INT || ident->type == CHAR ||
		ident->type == INTARRAY || ident->type == CHARARRAY)
		this->temp_type = VARTP;
	else if (ident->type == CONST)
		this->temp_type = CONSTTP;
	else if (ident->type == PARA)
	{
		Parameter* para = dynamic_cast<Parameter*>(ident);
		if (para->real)
			this->temp_type = REALPARA;
		else
			this->temp_type = FORMPARA;
	}
	else
		//TODO : change this to readable
		this->temp_type = VARTP;
	this->ident = ident;
	this->has_subscript = has_subscript;
	if (this->has_subscript)
		this->subscribe = new Temp(*subscribe);
	this->offset = 0;
}


Temp::Temp(const Temp &temp)
{
	this->this_node = temp.this_node;
	this->type = temp.type;
	this->offset = temp.offset;
	this->id = temp.id;
	this->temp_type = temp.temp_type;
	this->value = temp.value;
	this->ident = temp.ident;
	this->has_subscript = temp.has_subscript;
	if (this->has_subscript)
		this->subscribe = new Temp(*temp.subscribe);
	this->offset = temp.offset;
}

std::string Temp::print()
{
	std::string str;
	if (this == NULL)
		str = "NULL";
	else if (this->temp_type == CONSTTP || this->temp_type == VARTP)
	{
		str = this->ident->name;
		if (this->has_subscript)
		{
			str += "[";
			str += this->subscribe->print();
			str += "]";
		}
	}
	else if (this->temp_type == TEMPTP)
		str = "Temp" + int2string(this->id);
	else
		str = int2string(this->value);
	//printf("Temp%d=%d", this->id, this->value);
	return str;
}

Temp* zero;
Temp* one;
