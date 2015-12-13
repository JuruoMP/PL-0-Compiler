#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <vector>
#include <string>
#include <stack>
#include "Symbol.h"
#include "Memory.h"

#define MAXCNT 1024
#define UNITSIZE 4

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
	RETINT,
	RETCHAR,
	TEMP,
	NONE
};

class Identifier
{
public:
	int this_node;
	char name[MAXLEN];
	TYPE type;
	ADDR offset;
	Identifier() {};
	Identifier(char* name, TYPE type);
	virtual std::string print() = 0;
	ADDR getOffset();
};
//int Identifier::ident_index = 1;

enum TEMPTYPE
{
	VALUETP,
	TEMPTP,
	VARTP,
	CONSTTP,
	REALPARA,
	FORMPARA
};

class Temp : public Identifier
{
	static int temp_cnt;
public:
	int id;//TEMPTP
	TEMPTYPE temp_type;
	int value;//VALUETP
	Identifier* ident;//IDENTTP
	bool has_subscript;//IDENTTP
	Temp* subscribe;//IDENTTP
	Temp();
	Temp(int value);
	Temp(Identifier* ident, bool has_subscript, Temp* subscribe);
	Temp::Temp(const Temp &temp);
	Temp::Temp(const Identifier &ident);
	std::string print();
};

class Constance : public Identifier
{
public:
	int value;
	Constance(char* name, int value);
	Constance(const Constance& cons);
	std::string print() { return NULL; }
};

class Variable : public Identifier
{
public:
	Variable(char* name, TYPE type);
	Variable(const Variable& var);
	std::string print() { return NULL; }
};

class Array : public Identifier
{
public:
	int len;
	Array() : Identifier() {}
	Array(char* name, TYPE type, int length);
	Array(const Array& arr);
	std::string print() { return NULL; }
};

class Parameter : public Identifier
{
public:
	bool real;//true if pass by value, false if pass by address
	Parameter(char* name, bool real);
	Parameter(const Parameter& para);
	std::string print() { return NULL; }
};

class Callable : public Identifier
{
public:
	int nodeid;
	ADDR addr;
	Callable() {}
	Callable(char* name, TYPE type);
	virtual std::string print() = 0;
	Parameter* getParaAt(int pos);
};

class Procedure : public Callable
{
public:
	//int nodeid;
	//ADDR addr;
	Procedure(char* name, int nodeid);
	Procedure(const Procedure& proc);
	std::string print() { return NULL; }
};

class Function : public Callable
{
public:
	//int nodeid;
	//ADDR addr;
	Function(char* name, TYPE type, int nodeid);
	Function(const Function& func);
	std::string print() { return NULL; }
};

class SymbolTable
{
private:
	static SymbolTable* symboltable;
	SymbolTable();
public:
	SymbolTable* getInstance();
	static int nodecnt;
	int index;
	struct Node
	{
		char name[MAXLEN];
		bool is_proc;
		int father_index;
		int display_size;
		int offset_cnt;
		int last_para, last_const, last_var, last_temp;
		std::vector<Identifier*> idents;
		Node(char* name, bool is_proc, int level);
	};
	Node* nodes[MAXCNT];
	//create a new node
	int addNode(char* name, int father, bool is_proc);
	//go into nodes[id]
	void into(int id);
	//go back to now's father node
	void back();
	//push ident on current node, return true if succeed, false otherwise
	bool insertIdent(Identifier* ident);
	//return offset from its first memory block
	Identifier *findIdent(char* name);
	Temp *findTemp(int id);
	//check if a and b are at same level
	bool sameLevel(Node &a, Node &b);
	Identifier* ret2head(Identifier* ret);
};//symbol_table;
//int SymbolTable::symboltable_index = 1;

extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;
extern Temp* zero;
extern Temp* one;

#endif
