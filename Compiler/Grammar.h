#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include "Symbol.h"
#include "SymbolTable.h"

#define MAXCNT 32

extern WORD word;
extern std::vector<WORD> word_list;
extern int errcnt;

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
	void expression();
	void term();
	void factor();
	void funcSentence();
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
