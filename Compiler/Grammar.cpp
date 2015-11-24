#include "Grammar.h"
#include <iostream>

int errcnt = 0;
static WORD word, preread;
int level = 0;
SymbolTable symbol_table;

//#ifdef _DEBUG
#define GrammarDebug
//#endif

Grammar::Grammar()
{
	getSym();
	program();
}

bool Grammar::getSym()
{
	static int position = 0;
	if (position < word_list.size())
	{
		word = word_list.at(position);
		if (position < word_list.size() - 1)
			preread = word_list.at(position + 1);
		position++;
		return true;
	}
	else
	{
		return false;
	}
}

void Grammar::program()
{
#ifdef GrammarDebug
	std::cout << "In Program" << std::endl;
#endif
	semiProgram();
	if (word.token != DOTTK)
	{
		error(EXPECTDOT);
	}
	else
	{
		getSym();
	}
	if (word.token != EMPTYTK)
	{
		error(EXPECTEMPTY);
	}
	return;
}

void Grammar::semiProgram()
{
#ifdef GrammarDebug
	std::cout << "In SemiProgram" << std::endl;
#endif
	level++;
	symbol_table.pushLevel(level);
	if (word.token == CONSTTK)
	{
		constIllu();
	}
	if (word.token == VARTK)
	{
		varIllu();
	}
	while (word.token == PROCTK || word.token == FUNCTK)
	{
		if (word.token == PROCTK)
		{
			procIllu();
		}
		else
		{
			funcIllu();
		}
	}
	complexSentence();
	level--;
	symbol_table.popLevel();
}

void Grammar::constIllu()
{
#ifdef GrammarDebug
	std::cout << "In ConstIllu" << std::endl;
#endif
	if (word.token == CONSTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTCONST);
	}
	do
	{
		if (word.token == COMMATK)
		{
			getSym();
		}
		constDec();
	} while (word.token == COMMATK);
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
}

void Grammar::constDec()
{
#ifdef GrammarDebug
	std::cout << "In ConstDec" << std::endl;
#endif
	bool valid = true;
	char name[MAXLEN];
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		valid = false;
		error(EXPECTIDENT);
	}
	int value;
	if (word.token == EQUTK)
	{
		getSym();
		value = constVal();
	}
	else
	{
		valid = false;
		error(EXPECTEQU);
	}
	Constance cons(name, level, value);
	bool ret = symbol_table.insert(level, name, cons);
	if (!ret)
	{
		error(REDEFINATION);
	}
}

int Grammar::constVal()
{
#ifdef GrammarDebug
	std::cout << "In ConstVal" << std::endl;
#endif
	int value = 1;
	if (word.token == ADDTK || word.token == SUBTK || word.token == ITK)
	{
		if (word.token == ADDTK)
		{
			getSym();
		}
		else if (word.token == SUBTK)
		{
			value = -1;
			getSym();
		}
		if (word.token == ITK)
		{
			value *= word.value.num;
			getSym();
		}
		else
		{
			error(GRAMMARERR);
		}
	}
	else if (word.token == SQUOTETK)
	{
		value *= word.value.num;
		getSym();
	}
	else
	{
		error(GRAMMARERR);
	}
	return value;
}

void Grammar::varIllu()
{
#ifdef GrammarDebug
	std::cout << "In VarIllu" << std::endl;
#endif
	if (word.token == VARTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTVAR);
	}
	do
	{
		varDec();
		if (word.token == SEMICOLONTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTSEMICOLON);
		}
	} while (word.token != PROCTK && word.token != FUNCTK && word.token != BEGINTK);
}

void Grammar::varDec()
{
#ifdef GrammarDebug
	std::cout << "In VarDec" << std::endl;
#endif
	char name[MAXCNT][MAXLEN];
	int cnt = 0;
	if (word.token == IDENTTK)
	{
		strcpy_s(name[cnt++], MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	while (word.token == COMMATK)
	{
		getSym();
		if (word.token == IDENTTK)
		{
			strcpy_s(name[cnt++], MAXLEN - 1, word.value.content);
			getSym();
		}
		else
		{
			error(EXPECTIDENT);
		}
	}
	TYPE type;
	int len;
	if (word.token == COLONTK)
	{
		getSym();
		type = this->type(len);
	}
	else
	{
		error(EXPECTCOLON);
	}
	for (int i = 0; i < cnt; ++i)
	{
		switch (type)
		{
		case INT:
		case CHAR:
		{
					 Variable var(name[i], type, level);
					 symbol_table.insert(level, name[i], var);
					 break;
		}
		case INTARRAY:
		case CHARARRAY:
		{
						  Variable var(name[i], type, level, len);
						  symbol_table.insert(level, name[i], var);
						  break;
		}
			
		}
	}
}

enum TYPE Grammar::type(int& length)
{
#ifdef GrammarDebug
	std::cout << "In Type" << std::endl;
#endif
	TYPE type;
	if (word.token == ARRAYTK)
	{
		getSym();
		if (word.token == LSQRBRACTK)
		{
			getSym();
			if (word.token == ITK)
			{
				length = word.value.num;
				getSym();
				if (word.token == RSQRBRACTK)
				{
					getSym();
					if (word.token == OFTK)
					{
						getSym();
						if (word.token == INTTK)
						{
							type = INTARRAY;
							getSym();
						}
						else if (word.token == CHARTK)
						{
							type = CHARARRAY;
							getSym();
						}
						else
						{
							error(EXPECTBASICTYPE);
						}
					}
				}
				else
				{
					error(EXPECTRSQRBRAC);
				}
			}
			else
			{
				error(EXPECTNUM);
			}
		}
	}
	else if (word.token == INTTK)
	{
		type = INT;
		length = 1;
		getSym();
	}
	else if (word.token == CHARTK)
	{
		type = CHAR;
		length = 1;
		getSym();
	}
	else
	{
		error(EXPECTTYPE);
	}
	return type;
}

void Grammar::procIllu()
{
#ifdef GrammarDebug
	std::cout << "In ProcIllu" << std::endl;
#endif
	procHead();
	semiProgram();
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
	while (word.token == PROCTK)
	{
		procHead();
		semiProgram();
		if (word.token == SEMICOLONTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTSEMICOLON);
		}
	}
}

void Grammar::funcIllu()
{
#ifdef GrammarDebug
	std::cout << "In FuncIllu" << std::endl;
#endif
	funcHead();
	semiProgram();
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
	while (word.token == FUNCTK)
	{
		funcHead();
		semiProgram();
		if (word.token == SEMICOLONTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTSEMICOLON);
		}
	}
}

void Grammar::procHead()
{
#ifdef GrammarDebug
	std::cout << "In ProcHead" << std::endl;
#endif
	if (word.token == PROCTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTPROC);
	}
	char name[MAXLEN];
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	ParaTable para_table;
	int cntvar;
	if (word.token == LPARENTTK)
	{
		cntvar = paraTable(para_table);
	}
	Procedure proc(name, level, para_table);
	symbol_table.insert(level, name, proc);
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
}

void Grammar::funcHead()
{
#ifdef GrammarDebug
	std::cout << "In FuncHead" << std::endl;
#endif
	if (word.token == FUNCTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTPROC);
	}
	char name[MAXLEN];
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	ParaTable para_table;
	int cntvar = 0;
	if (word.token == LPARENTTK)
	{
		cntvar += paraTable(para_table);
	}
	if (word.token == COLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTCOLON);
	}
	if (word.token == INTTK)
	{
		Function func(name, FUNCINT, level, para_table);
		symbol_table.insert(level, name, func);
		getSym();
	}
	else if (word.token == CHARTK)
	{
		Function func(name, FUNCCHAR, level, para_table);
		symbol_table.insert(level, name, func);
		getSym();
	}
	else
	{
		error(EXPECTBASICTYPE);
	}
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
}

int Grammar::paraTable(ParaTable& para_table)
{
#ifdef GrammarDebug
	std::cout << "In ParaTable" << std::endl;
#endif
	int cnt = 0;
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTLPARENT);
	}
	cnt += paraSegement(para_table);
	while (word.token == SEMICOLONTK)
	{
		getSym();
		if (word.token == RPARENTTK)
		{
			break;
		}
		cnt += paraSegement(para_table);
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTRPARENT);
	}
	return cnt;
}

int Grammar::paraSegement(ParaTable& para_table)
{
#ifdef GrammarDebug
	std::cout << "In ParaSegement" << std::endl;
#endif
	bool real = false;
	if (word.token == VARTK)
	{
		real = true;
		getSym();
	}
	int cnt = 0;
	char name[MAXCNT][MAXLEN];
	strcpy_s(name[cnt++], MAXLEN - 1, word.value.content);
	getSym();
	while (word.token == COMMATK)
	{
		getSym();
		if (word.token == IDENTTK)
		{
			strcpy_s(name[cnt++], MAXLEN - 1, word.value.content);
			getSym();
		}
		else
		{
			error(EXPECTIDENT);
		}
	}
	if (word.token == COLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTCOLON);
	}
	TYPE type;
	if (word.token == INTTK)
	{
		type = INT;
		getSym();
	}
	else if (word.token == CHARTK)
	{
		type = CHAR;
		getSym();
	}
	else
	{
		error(EXPECTBASICTYPE);
	}
	for (int i = 0; i < cnt; ++i)
	{
		Parameter para(name[i], level + 1, real);
		para_table.add(para);
	}
	return cnt;
}

void Grammar::sentence()
{
#ifdef GrammarDebug
	std::cout << "In Sentence" << std::endl;
#endif
	if (word.token == IFTK)
	{
		conditionSentence();
	}
	else if (word.token == WHILETK)
	{
		whileSentence();
	}
	else if (word.token == FORTK)
	{
		forSentence();
	}
	else if (word.token == DOTK)
	{
		whileSentence();
	}
	else if (word.token == BEGINTK)
	{
		complexSentence();
	}
	else if (word.token == READTK)
	{
		readSentence();
	}
	else if (word.token == WRITETK)
	{
		writeSentence();
	}
	else if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table.find(level, word.value.content);
		if (ident == NULL)
		{
			error(IDENTNOTDEFINED);
		}
		else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
		{
			if (preread.token == SETTK)
			{
				setSentence();
			}
			else
			{
				funcSentence();
			}
		}
		else if (ident->type == INT || ident->type == CHAR || 
			ident->type == INTARRAY || ident->type == CHARARRAY)
		{
			setSentence();
		}
		else if (ident->type == PROC)
		{
			procSentence();
		}
		else
		{
			error(GRAMMARERR);
		}
	}
	/*
	else
	{
		error(GRAMMARERR);
	}
	*/
}

void Grammar::setSentence()
{
#ifdef GrammarDebug
	std::cout << "In SetSentence" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		getSym();
		if (word.token == LSQRBRACTK)
		{
			getSym();
			expression();
			if (word.token == RSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(EXPECTRSQRBRAC);
			}
		}
	}
	else
	{
		error(EXPECTIDENT);
	}
	if (word.token == SETTK)
	{
		getSym();
	}
	else
	{
		error(GRAMMARERR);
	}
	expression();
}

void Grammar::expression()
{
#ifdef GrammarDebug
	std::cout << "In Expression" << std::endl;
#endif
	int value = 1;
	if (word.token == ADDTK || word.token == SUBTK)
	{
		if (word.token == SUBTK)
			value = -1;
		getSym();
	}
	term();
	while (word.token == ADDTK || word.token == SUBTK)
	{
		getSym();
		term();
	}
}

void Grammar::term()
{
#ifdef GrammarDebug
	std::cout << "In Term" << std::endl;
#endif
	factor();
	while (word.token == MULTK || word.token == DIVTK)
	{
		getSym();
		factor();
	}
}

void Grammar::factor()
{
#ifdef GrammarDebug
	std::cout << "In Factor" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table.find(level, word.value.content);
		if (ident == NULL)
		{
			error(IDENTNOTDEFINED);
		}
		if (ident->type == CONST)
		{
			getSym();
		}
		else if (ident->type == INT || ident->type == CHAR)
		{
			getSym();
		}
		else if (ident->type == INTARRAY || ident->type == CHARARRAY)
		{
			getSym();
			if (word.token == LSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(EXPECTLSQRBRAC);
			}
			expression();
			if (word.token == RSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(EXPECTRSQRBRAC);
			}
		}
		else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
		{
			funcSentence();
		}
		else
		{
			error(GRAMMARERR);
		}
	}
	else if (word.token == ITK)
	{
		getSym();
	}
	else if (word.token == LPARENTTK)
	{
		getSym();
		expression();
		if (word.token == RPARENTTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTRPARENT);
		}
	}
	else
	{
		error(EXPECTIDENT);
	}
}

void Grammar::funcSentence()
{
#ifdef GrammarDebug
	std::cout << "In FuncSentence" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table.find(level, word.value.content);
		Function* func = dynamic_cast<Function*>(ident);
		if (func == NULL)
		{
			error(NOTAFUNCTION);
		}
		getSym();
		if (word.token == LPARENTTK)
		{
			/*func->paraTable.paras.size() != 0*/
			realParaTable();
		}
		//getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
}

void Grammar::realParaTable()
{
#ifdef GrammarDebug
	std::cout << "In RealParaTable" << std::endl;
#endif
	if (word.token == LPARENTTK)
	{
		getSym();
		realPara();
		while (word.token == COMMATK)
		{
			getSym();
			realPara();
		}
	}
	else
	{
		error(EXPECTLPARENT);
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTRPARENT);
	}
}

void Grammar::realPara()
{
#ifdef GrammarDebug
	std::cout << "In RealPara" << std::endl;
#endif
	expression();
}

void Grammar::condition()
{
#ifdef GrammarDebug
	std::cout << "In Condition" << std::endl;
#endif
	expression();
	if (word.token == SMALLTK || word.token == SMALLEQUTK ||
		word.token == LARGETK || word.token == LARGEEQUTK ||
		word.token == EQUTK || word.token == NEQUTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTCMPOP);
	}
	expression();
}

void Grammar::conditionSentence()
{
#ifdef GrammarDebug
	std::cout << "In ConditionSentence" << std::endl;
#endif
	if (word.token == IFTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTIF);
	}
	condition();
	if (word.token == THENTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTTHEN);
	}
	sentence();
	if (word.token == ELSETK)
	{
		getSym();
		sentence();
	}
}

void Grammar::whileSentence()
{
#ifdef GrammarDebug
	std::cout << "In WhileSentence" << std::endl;
#endif
	if (word.token == DOTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTDO);
	}
	sentence();
	if (word.token == WHILETK)
	{
		getSym();
	}
	else
	{
		error(EXPECTTHEN);
	}
	condition();
}

void Grammar::forSentence()
{
#ifdef GrammarDebug
	std::cout << "In ForSentence" << std::endl;
#endif
	if (word.token == FORTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTFOR);
	}
	if (word.token == IDENTTK)
	{
		getSym();
	}
	else
	{
		ERROR(EXPECTIDENT);
	}
	if (word.token == SETTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSET);
	}
	expression();
	if (word.token == TOTK || word.token == DOWNTOTK)
	{
		getSym();
	}
	else
	{
		error(GRAMMARERR);
	}
	expression();
	if (word.token == DOTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTDO);
	}
	sentence();
}

void Grammar::procSentence()
{
#ifdef GrammarDebug
	std::cout << "In ProcSentence" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table.find(level, word.value.content);
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		if (proc == NULL)
		{
			error(NOTAFUNCTION);
		}
		getSym();
		if (word.token == LPARENTTK)
		{
			/*proc->paraTable.paras.size() != 0*/
			realParaTable();
		}
	}
	else
	{
		error(EXPECTIDENT);
	}
}

void Grammar::complexSentence()
{
#ifdef GrammarDebug
	std::cout << "In ComplexSentence" << std::endl;
#endif
	if (word.token == BEGINTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTBEGIN);
	}
	sentence();
	while (word.token == SEMICOLONTK)
	{
		getSym();
		sentence();
	}
	if (word.token == ENDTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTEND);
	}
}

void Grammar::readSentence()
{
#ifdef GrammarDebug
	std::cout << "In ReadSentence" << std::endl;
#endif
	if (word.token == READTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTREAD);
	}
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTLPARENT);
	}
	if (word.token == IDENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	while (word.token == COMMATK)
	{
		getSym();
		if (word.token == IDENTTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTIDENT);
		}
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTRPARENT);
	}
}

void Grammar::writeSentence()
{
#ifdef GrammarDebug
	std::cout << "In WriteSentence" << std::endl;
#endif
	if (word.token == WRITETK)
	{
		getSym();
	}
	else
	{
		error(EXPECTWRITE);
	}
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTLPARENT);
	}
	if (word.token == DQUOTETK)
	{
		getSym();
		if (word.token == COMMATK)
		{
			getSym();
			expression();
		}
	}
	else
	{
		//getSym();
		expression();
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTRPARENT);
	}
}

void Grammar::error(int no)
{
	errcnt++;
	std::cout << "ERROR " << errcnt << " : " << no << std::endl;
}
