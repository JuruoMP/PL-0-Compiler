#include "Grammar.h"
#include <iostream>
#include <stack>

int errcnt = 0;
static WORD word, preread;

extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;

#define CODEINDEXNULL 0

//#ifdef _DEBUG
#define GrammarDebug 
//#endif

Grammar::Grammar()
{
	getSym();
	program();
}

static int position = 0;
int sym_position = 0;
bool Grammar::getSym()
{
	if (position < word_list.size())
	{
		word = word_list.at(position);
		word.print();
		position++;
		sym_position = position;
		return true;
	}
	else
	{
		return false;
	}
}

TYPE Grammar::readType()
{
	sym_position = position;
	while (sym_position < word_list.size())
	{
		sym_position++;
		if (word_list.at(sym_position).token == RPARENTTK)
			break;
	}
	if (word_list.at(sym_position + 2).token == INTTK)
		return FUNCINT;
	else
		return FUNCCHAR;
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
#ifdef GrammarDebugsub_table.insert
	std::cout << "In SemiProgram" << std::endl;
#endif
	if (word.token == CONSTTK)
		constIllu();
	if (word.token == VARTK)
		varIllu();
	int display_cnt = 0;
	while (word.token == PROCTK || word.token == FUNCTK)
	{
		display_cnt++;
		if (word.token == PROCTK)
			procIllu();
		else
			funcIllu();
	}
	complexSentence();
	node_stack.pop();
	symbol_table->back();
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
	Constance cons(name, value);
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
					 Variable var(name[i], type);
					 break;
		}
		case INTARRAY:
		case CHARARRAY:
		{
						  Array arr(name[i], type, len);
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
	char name[MAXLEN];
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
	char name[MAXLEN];
	TYPE type;
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
		//memory.pushInfo();
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
	if (word.token == IDENTTK)
	{
		char name[MAXLEN];
		strcpy_s(name, MAXLEN - 1, word.value.content);
		int nodeid = symbol_table->addNode(node_stack.top(), true);
		new Procedure(name, nodeid);
		node_stack.push(nodeid);
		symbol_table->into(nodeid);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	if (word.token == LPARENTTK)
	{
		paraTable();
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
	TYPE type = readType();
	if (word.token == IDENTTK)
	{
		char name[MAXLEN];
		strcpy_s(name, MAXLEN - 1, word.value.content);
		int nodeid = symbol_table->addNode(node_stack.top() , true);
		new Function(name, type, nodeid);
		node_stack.push(nodeid);
		symbol_table->into(nodeid);
		getSym();
	}
	else
	{
		error(EXPECTIDENT);
	}
	int cntvar = 0;
	if (word.token == LPARENTTK)
	{
		paraTable();
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
}

void Grammar::paraTable()
{
#ifdef GrammarDebug
	std::cout << "In ParaTable" << std::endl;
#endif
	if (word.token == LPARENTTK)
	{
		getSym();
		paraSegement();
	}
	else
	{
		error(EXPECTLPARENT);
	}
	while (word.token == SEMICOLONTK)
	{
		getSym();
		paraSegement();
		if (word.token == RPARENTTK)
		{
			break;
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

void Grammar::paraSegement()
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
		strcpy_s(name[cnt], MAXLEN - 1, word.value.content);
		cnt++;
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
		Parameter para(name[i], real);
	}
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
		Identifier* ident = symbol_table->findIdent(word.value.content);
		if (ident == NULL)
		{
			error(IDENTNOTDEFINED);
		}
		else if (ident->type == INT || ident->type == CHAR || 
			ident->type == INTARRAY || ident->type == CHARARRAY ||
			ident->type == FUNCINT || ident->type == FUNCCHAR ||
			ident->type == PARA)
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
	bool is_array = false;
	Identifier* ident = symbol_table->findIdent(word.value.content);
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
		Identifier* ident = symbol_table->findIdent(word.value.content);
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
		else if (ident->type == PARA)
		{
			temp.fill(ident->name);
			getSym();
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
		Identifier* ident = symbol_table->findIdent(word.value.content);
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
		//code.insert("FCAL", str1, str2, str3);
		//code.insert("SETLABEL", str3);
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

void Grammar::condition()
{
#ifdef GrammarDebug
	std::cout << "In Condition" << std::endl;
#endif
	Temp temp1, temp2;
	expression(temp1);
	SymbolTK cmptoken = word.token;
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
	switch (cmptoken)
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
	condition();//A
	//code.insert("JEQ", str1, "FLAG", "0");
	if (word.token == THENTK)
	{
		getSym();
	}
	else
	{
		error(EXPECTTHEN);
	}
	sentence();//B
	if (word.token == ELSETK)
	{
		//code.insert("J", str2);
	}
	//code.insert("SETLABEL", str1);
	if (word.token == ELSETK)
	{
		getSym();
		sentence();
		//code.insert("SETLABEL", str2);
	}
}

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
	//label.toString(str);
	//code.insert("SETLABEL", str);
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
	//code.insert("JEQ", str, "FLAG", "1");
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
	//code.insert("SET", name, temp1.toString(str1));
	//code.insert("SETLABEL", label1.toString(str2));
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
		//code.insert("LARGE", "FLAG", name, temp2.toString(str2));
		//code.insert("JEQ", label2.toString(str2), "FLAG", "1");
		//code.insert("INC", name);

	}
	else
	{
		//code.insert("LARGEEQU", "FLAG", name, temp2.toString(str2));
		//code.insert("JEQ", label2.toString(str2), "FLAG", "1");
		//code.insert("DEC", name);
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
	//code.insert("SETLABEL", label2.toString(str2));
}

void Grammar::procSentence()
{
#ifdef GrammarDebug
	std::cout << "In ProcSentence" << std::endl;
#endif
	char str1[1024], str2[1024];
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table->findIdent(word.value.content);
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
		//code.insert("PCAL", proc->label->toString(str1), label.toString(str2));
		//code.insert("SETLABEL", label.toString(str1));
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
	char str[1024];
	if (word.token == DQUOTETK)
	{
		//code.insert("WRITE", word.value.content);
		getSym();
		if (word.token == COMMATK)
		{
			getSym();
			Temp temp;
			expression(temp);
			//code.insert("WRITE", temp.toString(str));
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
