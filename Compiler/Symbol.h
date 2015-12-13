#ifndef SYMBOL_H
#define SYMBOL_H

#include <vector>
#include "common.h"
/*
#ifdef _DEBUG
#define SymbolDEBUG
#define SYMBOLCHECK
#endif
*/
#ifndef _MSC_VER
#define strcpy_s(a, len, b) strcpy(a, b)
#endif

#define MAXLEN 256

extern char token_name[][16];

typedef struct Position
{
	int mlineno;
	int mcolno;
	Position()
	{
		this->mlineno = -1;
		this->mcolno = -1;
	}
	Position(const Position& pos)
	{
		this->mlineno = pos.mlineno;
		this->mcolno = pos.mcolno;
	}
	void setPosition(int lineno, int colno)
	{
		this->mlineno = lineno;
		this->mcolno = colno;
	}
}POSITION;

enum SymbolTK
{
	ARRAYTK = 0,
	INTTK = 1,
	CHARTK = 2,
	CONSTTK = 3,
	VARTK = 4,
	IFTK = 5,
	THENTK = 6,
	ELSETK = 7,
	DOTK = 8,
	WHILETK = 9,
	FORTK = 10,
	TOTK = 11,
	DOWNTOTK = 12,
	BEGINTK = 13,
	ENDTK = 14,
	READTK = 15,
	WRITETK = 16,
	PROCTK = 17,
	FUNCTK = 18,
	COMMATK = 19,
	SEMICOLONTK = 20,
	LPARENTTK = 21,
	RPARENTTK = 22,
	LSQRBRACTK = 23,
	RSQRBRACTK = 24,
	COLONTK = 25,
	SETTK = 26,
	ADDTK = 27,
	SUBTK = 28,
	MULTK = 29,
	DIVTK = 30,
	SQUOTETK = 31,
	DQUOTETK = 32,
	SMALLTK = 33,
	SMALLEQUTK = 34,
	LARGETK = 35,
	LARGEEQUTK = 36,
	EQUTK = 37,
	NEQUTK = 38,
	ITK = 39,
	IDENTTK = 40,
	DOTTK = 41,
	OFTK = 42,
	ERRTK = 43,
	EMPTYTK = 44
};

typedef union
{
	int num;
	char content[256];
}VALUE;

struct WORD
{
	POSITION position;
	SymbolTK token;
	VALUE value;
	WORD()
	{
		POSITION position;
		this->position = position;
		this->token = ERRTK;
	}
	WORD(const WORD& word)
	{
		this->position = word.position;
		this->token = word.token;
		this->value = word.value;
	}
	WORD(const POSITION& pos, const SymbolTK& tk, const int v)
	{
		this->position.mlineno = pos.mlineno;
		this->position.mcolno = pos.mcolno;
		this->token = tk;
		this->value.num = v;
	}
	WORD(const POSITION& pos, const SymbolTK& tk, const char* str)
	{
		this->position.mlineno = pos.mlineno;
		this->position.mcolno = pos.mcolno;
		this->token = tk;
		strcpy_s(this->value.content, MAXLEN - 1, str);
	}
	void print();
};

class Symbol
{
	char mfilename[MAXLEN];
	char mgetchar();
	void error(const POSITION& pos, char& c, char stopc = 0);
public:
	Symbol(const char* filename);
	void mgetsym();
};

extern std::vector<WORD> word_list;

#endif