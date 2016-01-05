#ifndef CODETABLE_H
#define CODETABLE_H

#include <vector>
#include "Symbol.h"
#include "SymbolTable.h"
#include "Memory.h"
#include "Asm.h"

#define MAXCNT 1024
#define MAXSTRLEN 2048

extern char token_name[][16];
extern SymbolTable* symbol_table;
extern Memory* memory;
extern std::stack<int> node_stack;

enum KIND
{
	CONDITIONKD,
	GOTOKD,
	FPKD,
	LABELKD,
	ASSIGNKD,
	CALLKD,
	NOPKD,
	READKD,
	WRITEKD
};

class Label
{
	static int label_cnt;
public:
	int id;
	Label();
	std::string print();
};

class Code
{
public:
	KIND kind;
	char head[MAXLEN];
	Code(KIND kind, char* type_name);
	virtual std::string print() = 0;
};

class ConditionCode : public Code
{
public:
	SymbolTK token;
	Temp *num1, *num2;
	Label *label;
	ConditionCode(SymbolTK token, const Temp* num1, const Temp* num2, const Label* label);
	std::string print();
};

class GotoCode : public Code
{
public:
	Label *label;
	GotoCode(const Label *label);
	std::string print();
};

class FPCode : public Code
{
public:
	int nodeid;
	char name[MAXLEN]; //name
	char str[MAXLEN]; //"fp_%s_%d", this->name, this->nodeid
	FPCode(int nodeid, char* name);
	std::string print();
};

class LabelCode : public Code
{
public:
	Label* label;
	LabelCode(const Label *label);
	std::string print();
};

class AssignCode : public Code
{
public:
	Temp *target;
	Temp *num1, *num2;
	SymbolTK op;
	AssignCode(SymbolTK op, const Temp* dst, const Temp* src1, const Temp* src2, bool insert2code = true);
	std::string print();
};

class CallCode : public Code
{
public:
	Callable* cal;
	char str[MAXLEN]; //"fp_%s_%d", this->name, this->nodeid
	Temp* target;
	std::vector<Temp*> args;
	CallCode(Callable* cal, Temp* target, std::vector<Temp*> args);
	std::string print();
};

class NopCode : public Code
{
public:
	std::string msg;
	NopCode(char* message);
	std::string print();
};

class ReadCode : public Code
{
public:
	Temp* temp;
	ReadCode(Temp* temp);
	std::string print();
};

class WriteCode : public Code
{
public:
	bool is_string;
	union VALUE
	{
		int str_id;
		Temp* temp;
	}value;
	WriteCode(char* content);
	WriteCode(Temp* temp);
	std::string print();
};

class CodeTable
{
private:
	static CodeTable* codetable;
	CodeTable();
public:
	CodeTable* getInstance();
	static int nodecnt;
	int index;
	struct Node
	{
		int index;
		int father_index;
		int code_cnt;
		std::vector<Code*> codes;
		std::vector<Asm*> asms;
		Node();
		void compile();
		//save value of a temp to $edx
		void getTempValue(Temp* temp);
		//save addr of a temp to $esi
		void getTempAddr(Temp* temp);
		void push(std::string str);
		void pop(std::string str);
		void printasm();
		void quadOptimize();
		void asmOptimize();
	};
	Node* nodes[MAXCNT];
	//create a new node
	int addNode(int father);
	//go into nodes[id]
	void CodeTable::into(int id);
	//go back to now's father node
	void back();
	//push code on current node, return true if succeed, false otherwise
	bool insertCode(Code* code);
	void Init();
	void End();
	void error(char* err_info);
};

class StringTable
{
private:
	static StringTable* stringtable;
	StringTable() {}
public:
	std::vector<std::string> strs;
	StringTable* getInstance();
	int index;
	//return index of str, starting from 0
	int add(char* str);
};

extern CodeTable* code_table;
extern StringTable* string_table;
extern Temp* zero;
extern Temp* one;

#endif

