#ifndef CODETABLE_H
#define CODETABLE_H

#include <vector>
#include "Symbol.h"
#include "SymbolTable.h"

#define MAXCNT 1024

extern char token_name[][16];
extern SymbolTable* symbol_table;

enum TEMPTYPE
{
	VALUETP,
	VARTP,
	IDENTTP
};

enum KIND
{
	CONDITIONKD,
	GOTOKD,
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
	void print();
};

class Temp
{
	static int temp_cnt;
public:
	int id;
	TEMPTYPE type;
	int value;
	Identifier* ident;
	bool subscript;
	Temp* offset;
	Temp();
	Temp(int value);
	Temp(Identifier* ident, bool subscript, Temp* offset = NULL);
	void print();
};

class Code
{
public:
	KIND kind;
	char head[MAXLEN];
	Code(KIND kind, char* type_name);
	virtual void print() = 0;
};

class ConditionCode : public Code
{
public:
	SymbolTK token;
	Temp *num1, *num2;
	Label *label;
	ConditionCode(SymbolTK token, const Temp* num1, const Temp* num2, const Label* label);
	void print();
};

class GotoCode : public Code
{
public:
	Label *label;
	GotoCode(const Label *label);
	void print();
};

class LabelCode : public Code
{
public:
	Label* label;
	LabelCode(const Label *label);
	void print();
};

class AssignCode : public Code
{
public:
	Temp *target;
	Temp *num1, *num2;
	SymbolTK op;
	AssignCode(SymbolTK op, const Temp* dst, const Temp* src1, const Temp* src2);
	void print();
};

class CallCode : public Code
{
public:
	Identifier* ident;
	Identifier* target;
	std::vector<Temp*> args;
	CallCode(Identifier* ident, Identifier* target, std::vector<Temp*> args);
	void print();
};

class NopCode : public Code
{
public:
	NopCode();
	void print();
};

class ReadCode : public Code
{
public:
	Identifier* ident;
	ReadCode(Identifier* ident);
	void print();
};

class WriteCode : public Code
{
public:
	bool is_string;
	union VALUE
	{
		char content[MAXLEN];
		Temp* temp;
	}value;
	WriteCode(char* content);
	WriteCode(Temp* temp);
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

extern CodeTable* code_table;
extern Temp* zero;
extern Temp* one;

#endif

