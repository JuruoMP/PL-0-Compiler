#include "Grammar.h"
#include <iostream>
#include <stack>

int errcnt = 0;
static WORD word, preread;

extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;
extern CodeTable* code_table;
extern StringTable* string_table;
extern Temp* zero;
extern Temp* one;

#define CODEINDEXNULL 0

//#ifdef _DEBUG
//#define GrammarDebug 
//#endif

Grammar::Grammar()
{
	getSym();
	program();
	/*
	for (int i = 0; i <= code_table->nodecnt; ++i)
	{
		printf("\nNODE : %d\n", i);
		for (int j = 0; j < code_table->nodes[i]->codes.size(); ++j)
			std::cout << code_table->nodes[i]->codes.at(j)->print() << std::endl;
	}
	*/
	//printf("\n\nASM CODE : \n");
	//code_table->Init();
	for (int i = 1; i <= code_table->nodecnt; ++i)
	{
		symbol_table->into(i);
		code_table->into(i);
		code_table->nodes[i]->compile();
	}
	code_table->End();

	for (int i = 0; i < string_table->strs.size(); ++i)
	{
		//char string%d[] = ...
		std::cout << "char in_string" << i << "[] = \""
			<< string_table->strs.at(i) << "\";" << std::endl;
	}
	printf("int main()\n");
	printf("{\n");
	printf("_asm{\n");
	for (int i = 1; i <= code_table->nodecnt; ++i)
	{
		printf("\n");
		printf("\n;NODE : %d\n", i);
		//"fp_%s_%d", this->name, this->nodeid
		code_table->nodes[i]->printasm();
		printf("\n");
	}
	printf("ENDPOINT :\n");
	
}

static unsigned int position = 0;
unsigned int sym_position = 0;
bool Grammar::getSym()
{
	if (position < word_list.size())
	{
		word = word_list.at(position);
		//word.print();
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
		if (word_list.at(sym_position).token == COLONTK)
		{
			sym_position--;
			break;
		}
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
		error(word, EXPECTDOT);
	}
	else
	{
		getSym();
	}
	if (word.token != EMPTYTK)
	{
		error(word, EXPECTEMPTY);
	}
	return;
}

void Grammar::semiProgram()
{
#ifdef GrammarDebug
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
	code_table->back();
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
		error(word, EXPECTCONST);
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
		error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTIDENT);
	}
	int value;
	TYPE type;
	if (word.token == EQUTK)
	{
		getSym();
		value = constVal(&type);
	}
	else
	{
		valid = false;
		error(word, EXPECTEQU);
	}
	Constance cons(name, value, type);
}

int Grammar::constVal(TYPE *type)
{
#ifdef GrammarDebug
	std::cout << "In ConstVal" << std::endl;
#endif
	int value = 1;
	if (word.token == ADDTK || word.token == SUBTK || word.token == ITK)
	{
		*type = CONSTINT;
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
			error(word, GRAMMARERR);
		}
	}
	else if (word.token == SQUOTETK)
	{
		*type = CONSTCHAR;
		value *= word.value.num;
		getSym();
	}
	else
	{
		error(word, GRAMMARERR);
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
		error(word, EXPECTVAR);
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
			error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTIDENT);
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
			error(word, EXPECTIDENT);
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
		error(word, EXPECTCOLON);
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
							error(word, EXPECTBASICTYPE);
						}
					}
				}
				else
				{
					error(word, EXPECTRSQRBRAC);
				}
			}
			else
			{
				error(word, EXPECTNUM);
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
		error(word, EXPECTTYPE);
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
		error(word, EXPECTSEMICOLON);
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
			error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTSEMICOLON);
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
			error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTPROC);
	}
	if (word.token == IDENTTK)
	{
		char name[MAXLEN];
		strcpy_s(name, MAXLEN - 1, word.value.content);
		int nodeid1 = symbol_table->addNode(name, node_stack.top(), true);
		new Procedure(name, nodeid1);
		int nodeid2 = code_table->addNode(node_stack.top());
		assert(nodeid1 == nodeid2);
		node_stack.push(nodeid1);
		symbol_table->into(nodeid1);
		code_table->into(nodeid2);
		FPCode fpcode(nodeid1, name);
		getSym();
	}
	else
	{
		error(word, EXPECTIDENT);
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
		error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTPROC);
	}
	TYPE type = readType();
	if (word.token == IDENTTK)
	{
		char name[MAXLEN];
		strcpy_s(name, MAXLEN - 1, word.value.content);
		int nodeid1 = symbol_table->addNode(name, node_stack.top() , false);
		new Function(name, type, nodeid1);
		int nodeid2 = code_table->addNode(node_stack.top());
		assert(nodeid1 == nodeid2);
		node_stack.push(nodeid1);
		symbol_table->into(nodeid1);
		code_table->into(nodeid2);
		FPCode fpcode(nodeid1, name);
		if (type == FUNCINT)
			new Variable(name, RETINT);
		else
			new Variable(name, RETCHAR);
		getSym();
	}
	else
	{
		error(word, EXPECTIDENT);
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
		error(word, EXPECTCOLON);
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
		error(word, EXPECTBASICTYPE);
	}
	if (word.token == SEMICOLONTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTSEMICOLON);
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
		error(word, EXPECTLPARENT);
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
		error(word, EXPECTRPARENT);
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
		error(word, EXPECTIDENT);
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
			error(word, EXPECTIDENT);
		}
	}
	if (word.token == COLONTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTCOLON);
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
		error(word, EXPECTBASICTYPE);
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
			error(word, IDENTNOTDEFINED);
		}
		else if (ident->type == INT || ident->type == CHAR || 
			ident->type == INTARRAY || ident->type == CHARARRAY ||
			ident->type == RETINT || ident->type == RETCHAR ||
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
			error(word, GRAMMARERR);
		}
	}
	/*
	else
	{
		error(word, GRAMMARERR);
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
	Temp *subscript = NULL, *left = NULL, *right = NULL;
	if (word.token == IDENTTK)
	{
		getSym();
		if (word.token == LSQRBRACTK)
		{
			is_array = true;
			getSym();
			expression(&subscript);
			if (word.token == RSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(word, EXPECTRSQRBRAC);
			}
			left = new Temp(ident, true, subscript);
		}
		else
			left = new Temp(ident, false, NULL);
	}
	else
	{
		error(word, EXPECTIDENT);
	}
	if (word.token == SETTK)
	{
		getSym();
	}
	else
	{
		error(word, GRAMMARERR);
	}
	expression(&right);
	AssignCode code(SETTK, left, right, right);
}

void Grammar::expression(Temp **result)
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
	Temp* temp_left = NULL;
	term(&temp_left);
	Temp * new_temp;
	if (value == -1)
	{
		if (temp_left->temp_type == TEMPTP)
			new_temp = temp_left;
		else
			new_temp = new Temp();
		AssignCode code(SUBTK, new_temp, zero, temp_left);
	}
	else
		new_temp = temp_left;
	temp_left = new_temp;
	while (word.token == ADDTK || word.token == SUBTK)
	{
		bool is_add;
		if (word.token == ADDTK)
			is_add = true;
		else
			is_add = false;
		getSym();
		Temp* temp_right = NULL;
		term(&temp_right);
		if (temp_left->temp_type == TEMPTP)
			new_temp = temp_left;
		else if (temp_right->temp_type == TEMPTP)
			new_temp = temp_right;
		else
			new_temp = new Temp();
		if (is_add)
			AssignCode code(ADDTK, new_temp, temp_left, temp_right);
		else
			AssignCode code(SUBTK, new_temp, temp_left, temp_right);
		temp_left = new_temp;
	}
	*result = temp_left;
	//AssignCode code(SETTK, *result, temp_left, temp_left);
}

void Grammar::term(Temp **result)
{
#ifdef GrammarDebug
	std::cout << "In Term" << std::endl;
#endif
	//*result = new Temp();
	Temp *temp_left = NULL;
	factor(&temp_left);
	while (word.token == MULTK || word.token == DIVTK)
	{
		bool is_mul;
		if (word.token == MULTK)
			is_mul = true;
		else
			is_mul = false;
		getSym();
		Temp* temp_right = NULL;
		factor(&temp_right);
		Temp* new_temp;
		if (temp_left->temp_type == TEMPTP)
			new_temp = temp_left;
		else if (temp_right->temp_type == TEMPTP)
			new_temp = temp_right;
		else
			new_temp = new Temp();
		if (is_mul)
			AssignCode code(MULTK, new_temp, temp_left, temp_right);
		else
			AssignCode code(DIVTK, new_temp, temp_left, temp_right);
		temp_left = new_temp;
	}
	*result = temp_left;
	//AssignCode code(SETTK, *result, temp_left, temp_left);
}

void Grammar::factor(Temp **result)
{
#ifdef GrammarDebug
	std::cout << "In Factor" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table->findIdent(word.value.content);
		if (ident == NULL)
		{
			error(word, IDENTNOTDEFINED);
		}
		else if (ident->type == CONSTINT || ident->type == CONSTCHAR
			|| ident->type == INT || ident->type == CHAR)
		{
			*result = new Temp(ident, false, NULL);
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
				error(word, EXPECTLSQRBRAC);
			}
			Temp* offset = NULL;
			expression(&offset);
			if (word.token == RSQRBRACTK)
			{
				getSym();
			}
			else
			{
				error(word, EXPECTRSQRBRAC);
			}
			*result = new Temp(ident, true, offset);
		}
		else if (ident->type == RETINT || ident->type == RETCHAR ||
			ident->type == FUNCINT || ident->type == RETCHAR)
		{
			funcSentence(result);
		}
		else if (ident->type == PARA)
		{
			*result = new Temp(ident, false, NULL);
			getSym();
		}
		else
		{
			error(word, GRAMMARERR);
		}
	}
	else if (word.token == ITK)
	{
		*result = new Temp(word.value.num);
		getSym();
	}
	else if (word.token == LPARENTTK)
	{
		getSym();
		expression(result);
		if (word.token == RPARENTTK)
		{
			getSym();
		}
		else
		{
			error(word, EXPECTRPARENT);
		}
	}
	else
	{
		error(word, EXPECTIDENT);
	}
}

void Grammar::funcSentence(Temp **temp)
{
#ifdef GrammarDebug
	std::cout << "In FuncSentence" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table->findIdent(word.value.content);
		if (ident->type != FUNCINT && ident->type != FUNCCHAR)
			ident = symbol_table->ret2head(ident);
		Function* func = dynamic_cast<Function*>(ident);
		if (func == NULL)
		{
			error(word, NOTAFUNC);
		}
		getSym();
		std::vector<Temp*> args;
		if (word.token == LPARENTTK)
		{
			/*func->paraTable.paras.size() != 0*/
			realParaTable(args);
		}
		*temp = new Temp();
		CallCode code(func, *temp, args);
	}
	else
	{
		error(word, EXPECTIDENT);
	}
}

void Grammar::realParaTable(std::vector<Temp*> &args)
{
#ifdef GrammarDebug
	std::cout << "In RealParaTable" << std::endl;
#endif
	if (word.token == LPARENTTK)
	{
		Temp* para = NULL;
		getSym();
		realPara(&para);
		args.push_back(para);
		while (word.token == COMMATK)
		{
			getSym();
			realPara(&para);
			args.push_back(para);
		}
	}
	else
	{
		error(word, EXPECTLPARENT);
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTRPARENT);
	}
}

void Grammar::realPara(Temp **temp)
{
#ifdef GrammarDebug
	std::cout << "In RealPara" << std::endl;
#endif
	expression(temp);
}

void Grammar::condition(Label *label, bool condition)
{
#ifdef GrammarDebug
	std::cout << "In Condition" << std::endl;
#endif
	Temp *left = NULL, *right = NULL;
	expression(&left);
	SymbolTK cmptoken = word.token;
	if (word.token == SMALLTK || word.token == SMALLEQUTK ||
		word.token == LARGETK || word.token == LARGEEQUTK ||
		word.token == EQUTK || word.token == NEQUTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTCMPOP);
	}
	expression(&right);
	if (condition == false)
	{
		switch (cmptoken)
		{
		case SMALLTK:
			cmptoken = LARGEEQUTK;
			break;
		case SMALLEQUTK:
			cmptoken = LARGETK;
			break;
		case LARGETK:
			cmptoken = SMALLEQUTK;
			break;
		case LARGEEQUTK:
			cmptoken = SMALLTK;
			break;
		case EQUTK:
			cmptoken = NEQUTK;
			break;
		case NEQUTK:
			cmptoken = EQUTK;
			break;
		default:
			assert(0 == 1);
		}
	}
	ConditionCode code(cmptoken, left, right, label);
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
		error(word, EXPECTIF);
	}
	Label *false_label = new Label();
	Label *out_label = new Label();
	condition(false_label, false);
	if (word.token == THENTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTTHEN);
	}
	sentence();
	GotoCode goto_code(out_label);
	LabelCode false_label_code(false_label);
	if (word.token == ELSETK)
	{
		getSym();
		sentence();
	}
	LabelCode true_label_code(out_label);
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
		error(word, EXPECTDO);
	}
	Label *label = new Label();
	LabelCode label_code(label);
	sentence();//A
	if (word.token == WHILETK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTTHEN);
	}
	condition(label, true);
}

void Grammar::forSentence()
{
#ifdef GrammarDebug
	std::cout << "In ForSentence" << std::endl;
#endif
	Label *label1 = new Label();
	Label *label2 = new Label();
	if (word.token == FORTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTFOR);
	}
	Identifier* ident = NULL;
	if (word.token == IDENTTK)
	{
		ident = symbol_table->findIdent(word.value.content);
		getSym();
	}
	else
	{
		error(word, EXPECTIDENT);
	}
	Temp* temp_ident = new Temp(ident, false, NULL);
	if (word.token == SETTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTSET);
	}
	Temp *init_value = NULL;
	expression(&init_value);
	AssignCode(SETTK, temp_ident, init_value, init_value);
	LabelCode label_code1(label1);
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
		error(word, GRAMMARERR);
	}
	Temp *end_value = NULL;
	expression(&end_value);//B
	if (is_to)
		ConditionCode condition_code(LARGETK, temp_ident, end_value, label2);
	else
		ConditionCode condition_code(SMALLTK, temp_ident, end_value, label2);
	if (word.token == DOTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTDO);
	}
	sentence();
	if (is_to)
	{
		AssignCode assign_code(ADDTK, temp_ident, temp_ident, one);
		GotoCode goto_code(label1);
	}
	else
	{
		AssignCode assign_code(SUBTK, temp_ident, temp_ident, one);
		GotoCode goto_code(label1);
	}
	LabelCode label_code2(label2);
}

void Grammar::procSentence()
{
#ifdef GrammarDebug
	std::cout << "In ProcSentence" << std::endl;
#endif
	if (word.token == IDENTTK)
	{
		Identifier* ident = symbol_table->findIdent(word.value.content);
		Procedure* proc = dynamic_cast<Procedure*>(ident);
		if (proc == NULL)
		{
			error(word, NOTAPROC);
		}
		getSym();
		std::vector<Temp*> args;
		if (word.token == LPARENTTK)
		{
			/*proc->paraTable.paras.size() = 0*/
			realParaTable(args);
		}
		CallCode code(proc, NULL, args);
	}
	else
	{
		error(word, EXPECTIDENT);
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
		error(word, EXPECTBEGIN);
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
		error(word, EXPECTEND);
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
		error(word, EXPECTREAD);
	}
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTLPARENT);
	}
	Identifier* ident;
	if (word.token == IDENTTK)
	{
		ident = symbol_table->findIdent(word.value.content);
		Temp* temp = new Temp(ident, false, NULL);
		ReadCode read_code(temp);
		getSym();
	}
	else
	{
		error(word, EXPECTIDENT);
	}
	while (word.token == COMMATK)
	{
		getSym();
		if (word.token == IDENTTK)
		{
			ident = symbol_table->findIdent(word.value.content);
			Temp* temp = new Temp(ident, false, NULL);
			ReadCode read_code(temp);
			getSym();
		}
		else
		{
			error(word, EXPECTIDENT);
		}
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTRPARENT);
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
		error(word, EXPECTWRITE);
	}
	if (word.token == LPARENTTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTLPARENT);
	}
	if (word.token == DQUOTETK)
	{
		WriteCode write_code1(word.value.content);
		getSym();
		if (word.token == COMMATK)
		{
			getSym();
			Temp *temp = NULL;
			expression(&temp);
			if (temp->temp_type == VALUETP)
				WriteCode write_code2(temp);
			else
				WriteCode write_code2(temp);
		}
	}
	else
	{
		Temp *temp = NULL;
		expression(&temp);
		if (temp->temp_type == VALUETP)
			WriteCode write_code2(temp);
		else
			WriteCode write_code2(temp);
	}
	if (word.token == RPARENTTK)
	{
		getSym();
	}
	else
	{
		error(word, EXPECTRPARENT);
	}
}

char grammar_error[][MAXLEN] = {
	"Grammar error", "Expect dot token", "Expect type token", "Expect basic type token", 
	"Expect Procedure token", "Expect Identifier token", "Expect Square bracket token", 
	"Expect a number", "Expect semicolon token", "Expect const token", "Expect equal token", 
	"Expect set token", "Expect var token", "Expect colon token", "Expect left parent", "Expect right parent", 
	"Expect a integer", "Expect compare operation token", "Expect left square bracket", "Expect if token", "Expect then token", 
	"Expect do token", "Expect for token", "Expect begin token", "Expect end token", "Expect write token", "Expect read token", 
	"Expect empty", "Redifination", "Not a procedure", "Not a function", "Identifier not definied"
};

void Grammar::error(WORD word, GRAMMAR_ERROR no)
{
	errcnt++;
	std::cerr << "ERROR " << errcnt << " : " << grammar_error[no] << 
		"@" << word.position.mlineno << std::endl;
	std::vector<SymbolTK> stopword;
	stopword.push_back(SEMICOLONTK);
	this->readpass(stopword);
}

void Grammar::readpass(std::vector<SymbolTK> stopword)
{
	bool stop_flag = false;
	while (stop_flag == false)
	{
		this->getSym();
		for (int i = 0; i < stopword.size(); ++i)
		{
			if (word.token == stopword.at(i))
			{
				stop_flag = true;
				break;
			}
		}
	}
}
