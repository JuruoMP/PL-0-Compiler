#ifndef CODETABLE_H
#define CODETABLE_H

#include "Symbol.h"
#include "SymbolTable.h"
#include <vector>

#define MAXCNT 1024

enum KIND
{
	CONDITIONKD,
	GOTOKD,
	LABELKD,
	ASSIGNKD,
	CALLKD,
	NOPKD
};

class Label
{
	static int label_cnt;
public:
	int id;
	Label();
	void print();
};

class Temp
{
	static int temp_cnt;
public:
	int id;
	Temp();
	void print();
};

class Code
{
public:
	KIND kind;
	char head[MAXLEN];
	Code(KIND kind, char* type_name);
	virtual void print();
};

class ConditionCode : public Code
{
public:
	SymbolTK token;
	Temp *num1, *num2;
	Label *true_label, *false_label;
	ConditionCode(SymbolTK token, const Temp& num1, const Temp& num2,
		const Label& true_label, const Label& false_label);
	void print();
};

class GotoCode : public Code
{
public:
	Label *label;
	GotoCode(const Label& label);
	void print();
};

class LabelCode : public Code
{
public:
	Label* label;
	LabelCode(const Label& label);
	void print();
};

class AssignCode : public Code
{
public:
	Temp *target;
	Temp *num1, *num2;
	SymbolTK op;
	AssignCode(SymbolTK op, const Temp& dst, const Temp& src1, const Temp& src2);
	void print();
};

class CallCode : public Code
{
public:
	char fn[MAXLEN];
	ADDR retstore;
	std::vector<char > args;
	CallCode(char* name, ADDR retstore, const std::vector<Parameter> args);
	void print();
};

class NopCode : public Code
{
public:
	NopCode();
	void print();
};

class CodeTable
{
private:
	static CodeTable* codetable;
	CodeTable() {}
public:
	CodeTable* getInstance();
	static int nodecnt;
	int index;
	struct Node
	{
		int father_index;
		int code_cnt;
		std::vector<Code*> codes;
		Node()
		{
			this->father_index = 0;
			this->code_cnt = 0;
		}
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
};

#endif

