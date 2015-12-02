#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <map>
#include <string>
#include <stack>
#include "Symbol.h"
#include "Memory.h"

#define MAXCNT 1024

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
	NONE
};

class Identifier
{
public:
	char name[MAXLEN];
	TYPE type;
	ADDR offset;
	Identifier() {};
	Identifier(char* name, TYPE type);
	virtual void print() = 0;
};
//int Identifier::ident_index = 1;

class SymbolTable
{
private:
	static SymbolTable* symboltable;
	SymbolTable() {}
public:
	SymbolTable* getInstance();
	static int nodecnt;
	int index;
	struct Node
	{
		bool is_proc;
		int father_index;
		int offset_cnt;
		int last_para, last_const, last_var, last_callable;
		std::vector<Identifier*> idents;
		Node()
		{
			//TODO: add display offset
			//memset(this, 0, sizeof(this));
			this->is_proc = false;
			this->father_index = 0;
			this->offset_cnt = 0;
			this->last_para = this->last_const = this->last_var = this->last_callable = 0;
		}
	};
	Node* nodes[MAXCNT];
	//create a new node
	int addNode(int father, bool is_proc);
	//go into nodes[id]
	void into(int id);
	//go back to now's father node
	void back();
	//push ident on current node, return true if succeed, false otherwise
	bool insertIdent(Identifier* ident);
	//return offset from its first memory block
	Identifier* findIdent(char* name);
};//symbol_table;
//int SymbolTable::symboltable_index = 1;

class Constance : public Identifier
{
	int value;
public:
	Constance(char* name, int value);
	Constance(const Constance& cons);
	void print() {}
};

class Variable : public Identifier
{
public:
	Variable(char* name, TYPE type);
	Variable(const Variable& var);
	void print() {}
};

class Array : public Identifier
{
public:
	int len;
	Array() : Identifier() {}
	Array(char* name, TYPE type, int length);
	Array(const Array& arr);
	void print() {}
};

class Parameter : public Identifier
{
public:
	bool real;//true if pass by value, false if pass by address
	Parameter(char* name, bool real);
	Parameter(const Parameter& para);
	void print() {}
};

class Procedure : public Identifier
{
public:
	int nodeid;
	ADDR addr;
	Procedure(char* name, int nodeid);
	Procedure(const Procedure& proc);
	void print() {}
};

class Function : public Identifier
{
public:
	int nodeid;
	ADDR addr; 
	Function(char* name, TYPE type, int nodeid);
	Function(const Function& func);
	void print() {}
};

extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;

#endif
