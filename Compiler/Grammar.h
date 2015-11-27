#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include "Symbol.h"
#include "SymbolTable.h"

#define MAXCNT 32

extern WORD word;
extern std::vector<WORD> word_list;
extern int errcnt;

class Operation
{
public:
	char s1[MAXLEN], s2[MAXLEN], t[MAXLEN];
	char op[16];
	Operation(char* oop, char* tt, char* ss1 = "", char* ss2 = "")
	{
		strcpy_s(s1, MAXLEN - 1, ss1);
		strcpy_s(s2, MAXLEN - 1, ss2);
		strcpy_s(t, MAXLEN - 1, tt);
		strcpy_s(op, 15, oop);
	}
};
std::vector<Operation> operations;

class Grammar
{
public:
	Grammar();
	~Grammar() {};
	bool getSym();
	void program();
	void semiProgram();
	void constIllu();
	void constDec();
	int constVal();
	//void charVal();
	//void stringVal();
	//void intVal();
	//void ident();
	void varIllu();
	void varDec();
	enum TYPE type(int& length);
	//void basicType();
	void procIllu();
	void funcIllu();
	void procHead();
	void funcHead();
	int paraTable(ParaTable& para_table);
	int paraSegement(ParaTable& para_table);
	void sentence();
	void setSentence();
	//void funcIdent();
	void expression(Temp &temp);
	void term(Temp &temp);
	void factor(Temp &temp);
	void funcSentence(Temp &temp);
	void realParaTable();
	void realPara();
	//void addOp();
	//void multOp();
	void condition();
	void cmpOp();
	void conditionSentence();
	void whileSentence();
	void forSentence();
	void procSentence();
	void complexSentence();
	void readSentence();
	void writeSentence();
	//void letter();
	//void number();
	void error(int no);
};

enum ERROR
{
	GRAMMARERR,
	EXPECTDOT,
	EXPECTTYPE,
	EXPECTBASICTYPE,
	EXPECTPROC,
	EXPECTIDENT,
	EXPECTRSQRBRAC,
	EXPECTNUM,
	EXPECTSEMICOLON,
	EXPECTCONST,
	EXPECTEQU,
	EXPECTSET,
	EXPECTVAR,
	EXPECTCOLON,
	EXPECTLPARENT,
	EXPECTRPARENT,
	EXPECTI,
	EXPECTCMPOP,
	EXPECTLSQRBRAC,
	EXPECTIF,
	EXPECTTHEN,
	EXPECTDO,
	EXPECTFOR,
	EXPECTBEGIN,
	EXPECTEND,
	EXPECTWRITE,
	EXPECTREAD,
	EXPECTEMPTY,
	REDEFINATION,
	NOTAFUNCTION,
	IDENTNOTDEFINED,

};

#endif
