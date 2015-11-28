#include "Grammar.h"
#include <iostream>

int errcnt = 0;
static WORD word, preread;
int level = 0;
extern SymbolTable symbol_table;
int lastindex = 0;//???????

#define CODEINDEXNULL 0

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

int Grammar::semiProgram()
{
	bool defined = false;
	int tlastindex = lastindex;
#ifdef GrammarDebug
	std::cout << "In SemiProgram" << std::endl;
#endif
	level++;
	int cnt_const, cnt_var;
	if (word.token == CONSTTK)
	{
		cnt_const = constIllu();
		if (cnt_const)
			defined = true;
	}
	if (word.token == VARTK)
	{
		cnt_var = varIllu();
		if (cnt_var)
			defined = true;
	}
	while (word.token == PROCTK || word.token == FUNCTK)
	{
		defined = true;
		if (word.token == PROCTK)
		{
			procIllu();
		}
		else
		{
			funcIllu();
		}
	}
	if (defined)
		display_table.push(tlastindex + 1);
	int ret = lastindex;
	complexSentence();
	level--;
	display_table.pop();
	return ret;
}

int Grammar::constIllu()
{
#ifdef GrammarDebug
	std::cout << "In ConstIllu" << std::endl;
#endif
	int cnt = 0;
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
		cnt++;
	} while (word.token == COMMATK);
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
	return cnt;
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
	Constance cons(name, level, value, lastindex + 1);
	lastindex = cons.index;
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

int Grammar::varIllu()
{
#ifdef GrammarDebug
	std::cout << "In VarIllu" << std::endl;
#endif
	int cnt = 0;
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
		cnt += varDec();
		if (word.token == SEMICOLONTK)
		{
			getSym();
		}
		else
		{
			error(EXPECTSEMICOLON);
		}
	} while (word.token != PROCTK && word.token != FUNCTK && word.token != BEGINTK);
	return cnt;
}

int Grammar::varDec()
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
					 Variable var(name[i], type, level, lastindex + 1);
					 lastindex = var.index;
					 break;
		}
		case INTARRAY:
		case CHARARRAY:
		{
						  Array arr(name[i], type, level, len, lastindex + 1);
						  lastindex = arr.index;
						  break;
		}
			
		}
	}
	return cnt;
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
	int tlastindex = lastindex;
	lastindex = 0;
	int last, lastpar, psize, vsize;
	Memory* memory = NULL;
	memory = memory->getInstance();
	//memory.pushInfo();
	char name[MAXLEN];
	lastpar = procHead(name);
	last = semiProgram();
	psize = lastpar - tlastindex;
	vsize = lastindex - tlastindex;
	Procedure proc1(name, level, tlastindex,
		lastpar, last, psize, vsize, CODEINDEXNULL);
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
		tlastindex = lastindex;
		lastindex = 0;
		//memory->pushInfo();
		lastpar = procHead(name);
		last = semiProgram();
		psize = lastpar - tlastindex;
		vsize = lastindex - tlastindex;
		Procedure proc2(name, level, tlastindex,
			lastpar, last, psize, vsize, CODEINDEXNULL);
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
	int tlastindex = lastindex;
	lastindex = 0;
	int last, lastpar, psize, vsize;
	Memory* memory = NULL;
	memory = memory->getInstance();
	//memory.pushInfo();
	char name[MAXLEN];
	TYPE type;
	lastpar = funcHead(name, type);
	last = semiProgram();
	psize = lastpar - tlastindex;
	vsize = lastindex - tlastindex;
	Function fun1(name, type, level, tlastindex,
		lastpar, last, psize, vsize, CODEINDEXNULL);
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
		tlastindex = lastindex;
		lastindex = 0;
		//memory.pushInfo();
		lastpar = funcHead(name, type);
		last = semiProgram();
		psize = lastpar - tlastindex;
		vsize = lastindex - tlastindex;
		Function fun2(name, type, level, tlastindex,
			lastpar, last, psize, vsize, CODEINDEXNULL);
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

int Grammar::procHead(char* name)
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
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	int lastpar;
	if (word.token == LPARENTTK)
	{
		lastpar = paraTable();
	}
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTSEMICOLON);
	}
	return lastpar;
}

int Grammar::funcHead(char* name, TYPE &type)
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
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	int lastpar;
	int cntvar = 0;
	if (word.token == LPARENTTK)
	{
		lastpar = paraTable();
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
		type = FUNCINT;
		getSym();
	}
	else if (word.token == CHARTK)
	{
		type = FUNCCHAR;
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
	return lastpar;
}

int Grammar::paraTable()
{
#ifdef GrammarDebug
	std::cout << "In ParaTable" << std::endl;
#endif
	int lastpar = 0;
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTLPARENT);
	}
	lastpar = paraSegement();
	while (word.token == SEMICOLONTK)
	{
		getSym();
		if (word.token == RPARENTTK)
		{
			break;
		}
		lastpar = paraSegement();
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTRPARENT);
	}
	return lastpar;
}

int Grammar::paraSegement()
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
		Parameter para(name[i], level + 1, lastindex + 1, real);
		lastindex = para.index;
	}
	return lastindex;
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
		else if (ident->type == INT || ident->type == CHAR || 
			ident->type == INTARRAY || ident->type == CHARARRAY ||
			ident->type == FUNCINT || ident->type == FUNCCHAR)
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

/*Finish operation*/
void Grammar::setSentence()
{
#ifdef GrammarDebug
	std::cout << "In SetSentence" << std::endl;
#endif
	bool is_array = false;
	Identifier* ident = symbol_table.find(level, word.value.content);
	Temp temp1, temp2;
	char name[MAXLEN];
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
		getSym();
		if (word.token == LSQRBRACTK)
		{
			is_array = true;
			getSym();
			expression(temp1);
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
	expression(temp2);
	char str1[1024], str2[1024];
	temp1.toString(str1);
	temp2.toString(str2);
	if (is_array)
		code.insert("SET", name, str1, str2);
	else
		code.insert("SET", name, "0", str2);
}

/*Finish operation*/
void Grammar::expression(Temp &temp)
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
	term(temp);
	while (word.token == ADDTK || word.token == SUBTK)
	{
		bool is_add;
		if (word.token == ADDTK)
			is_add = true;
		else
			is_add = false;
		getSym();
		Temp ttemp;
		term(ttemp);
		char str1[1024], str2[1024];
		temp.toString(str1);
		ttemp.toString(str2);
		if (is_add)
			code.insert("ADD", str1, str1, str2);
		else
			code.insert("SUB", str1, str1, str2);
	}
}

void Grammar::term(Temp &temp)
{
#ifdef GrammarDebug
	std::cout << "In Term" << std::endl;
#endif
	factor(temp);
	while (word.token == MULTK || word.token == DIVTK)
	{
		bool is_mul;
		if (word.token == MULTK)
			is_mul = true;
		else
			is_mul = false;
		getSym();
		Temp ttemp;
		factor(ttemp);
		char str1[1024], str2[1024];
		temp.toString(str1);
		ttemp.toString(str2);
		if (is_mul)
			code.insert("MULT", str1, str1, str2);
		else
			code.insert("DIV", str1, str1, str2);
	}
}

void Grammar::factor(Temp &temp)
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
		else if (ident->type == CONST)
		{
			temp.fill(ident->name);
			getSym();
		}
		else if (ident->type == INT || ident->type == CHAR)
		{
			temp.fill(ident->name);
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
			Temp ttemp;
			expression(ttemp);
			if (word.token == RSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(EXPECTRSQRBRAC);
			}
			char str1[1024], str2[1024];
			temp.toString(str1);
			ttemp.toString(str2);
			code.insert("LOAD", str1, ident->name, str2);
		}
		else if (ident->type == FUNCINT || ident->type == FUNCCHAR)
		{
			funcSentence(temp);
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
		expression(temp);
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

void Grammar::funcSentence(Temp &temp)
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
			error(NOTAFUNC);
		}
		
		getSym();
		if (word.token == LPARENTTK)
		{
			/*func->paraTable.paras.size() != 0*/
			realParaTable();
		}
		Label label;
		char str1[1024], str2[1024], str3[1024];
		temp.toString(str1);
		func->label->toString(str2);
		label.toString(str3);
		code.insert("FCAL", str1, str2, str3);
		code.insert("SETLABEL", str3);
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
		Temp temp;
		getSym();
		realPara(temp);
		char str[1024];
		temp.toString(str);
		code.insert("PUSH", str);
		while (word.token == COMMATK)
		{
			getSym();
			realPara(temp);
			temp.toString(str);
			code.insert("PUSH", str);
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

void Grammar::realPara(Temp &temp)
{
#ifdef GrammarDebug
	std::cout << "In RealPara" << std::endl;
#endif
	expression(temp);
}

/*Finish operation*/
void Grammar::condition()
{
#ifdef GrammarDebug
	std::cout << "In Condition" << std::endl;
#endif
	Temp temp1, temp2;
	expression(temp1);
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
	expression(temp2);
	char str1[1024], str2[1024];
	temp1.toString(str1);
	temp2.toString(str2);
	switch (word.token)
	{
	case SMALLTK:
		code.insert("SMALL", "FLAG", str1, str2);
		break;
	case SMALLEQUTK:
		code.insert("SMALLSQU", "FLAG", str1, str2);
		break;
	case LARGETK:
		code.insert("LARGE", "FLAG", str1, str2);
		break;
	case LARGEEQUTK:
		code.insert("LARGEEQU", "FLAG", str1, str2);
		break;
	case EQUTK:
		code.insert("EQU", "FLAG", str1, str2);
		break;
	case NEQUTK:
		code.insert("NEQU", "FLAG", str1, str2);
		break;
	default:
		assert(0 == 1);
		break;
	}
}

/*Finish operation*/
void Grammar::conditionSentence()
{
#ifdef GrammarDebug
	std::cout << "In ConditionSentence" << std::endl;
#endif
	Label label1, label2;
	if (word.token == IFTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTIF);
	}
	condition();//A
	char str1[1024], str2[1024];
	label1.toString(str1);
	code.insert("JEQ", str1, "FLAG", "0");
	if (word.token == THENTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTTHEN);
	}
	if (word.token == ELSETK)
	{
		label2.toString(str2);
		code.insert("J", str2);
	}
	sentence();//B
	label1.toString(str1);
	code.insert("SETLABEL", str1);
	if (word.token == ELSETK)
	{
		getSym();
		sentence();
		label2.toString(str2);
		code.insert("SETLABEL", str2);
	}
}

/*Finish operation*/
void Grammar::whileSentence()
{
#ifdef GrammarDebug
	std::cout << "In WhileSentence" << std::endl;
#endif
	char str[1024];
	if (word.token == DOTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTDO);
	}
	Label label;
	label.toString(str);
	code.insert("SETLABEL", str);
	sentence();//A
	if (word.token == WHILETK)
	{
		getSym();
	}
	else
	{
		error(EXPECTTHEN);
	}
	condition();//B
	code.insert("JEQ", str, "FLAG", "1");
}

/*Finish operation*/
void Grammar::forSentence()
{
#ifdef GrammarDebug
	std::cout << "In ForSentence" << std::endl;
#endif
	Label label1, label2;
	if (word.token == FORTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTFOR);
	}
	char name[MAXLEN];
	if (word.token == IDENTTK)
	{
		strcpy_s(name, MAXLEN - 1, word.value.content);
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
	Temp temp1, temp2;
	expression(temp1);
	char str1[1024], str2[1024];
	code.insert("SET", name, temp1.toString(str1));
	code.insert("SETLABEL", label1.toString(str2));
	bool is_to = true;
	if (word.token == TOTK || word.token == DOWNTOTK)
	{
		if (word.token == DOWNTOTK)
			is_to = false;
		else
			is_to = true;
		getSym();
	}
	else
	{
		error(GRAMMARERR);
	}
	expression(temp2);//B
	if (is_to)
	{
		code.insert("LARGE", "FLAG", name, temp2.toString(str2));
		code.insert("JEQ", label2.toString(str2), "FLAG", "1");
		code.insert("INC", name);

	}
	else
	{
		code.insert("LARGEEQU", "FLAG", name, temp2.toString(str2));
		code.insert("JEQ", label2.toString(str2), "FLAG", "1");
		code.insert("DEC", name);
	}
	if (word.token == DOTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTDO);
	}
	sentence();
	code.insert("SETLABEL", label2.toString(str2));
}

/*Finish operation*/
void Grammar::procSentence()
{
#ifdef GrammarDebug
	std::cout << "In ProcSentence" << std::endl;
#endif
	char str1[1024], str2[1024];
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table.find(level, word.value.content);
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		if (proc == NULL)
		{
			error(NOTAPROC);
		}
		getSym();
		if (word.token == LPARENTTK)
		{
			/*proc->paraTable.paras.size() = 0*/
			realParaTable();
		}
		Label label;
		code.insert("PCAL", proc->label->toString(str1), label.toString(str2));
		code.insert("SETLABEL", label.toString(str1));
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

/*Finish operation*/
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
	char str[1024];
	if (word.token == DQUOTETK)
	{
		code.insert("WRITE", word.value.content);
		getSym();
		if (word.token == COMMATK)
		{
			getSym();
			Temp temp;
			expression(temp);
			code.insert("WRITE", temp.toString(str));
		}
	}
	else
	{
		Temp temp;
		expression(temp);
		code.insert("WRITE", temp.toString(str));
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
