#pragma warning(disable:4996)

#include <iostream>
#include <stack>
#include "Symbol.h"
#include "Memory.h"
#include "Grammar.h"
#include "CodeTable.h"

using namespace std;

extern std::vector<WORD> word_list;
extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;
extern CodeTable* code_table;
extern StringTable* string_table;
extern Temp* zero;
extern Temp* one;
extern Memory* memory;

void Init()
{
	printf("#pragma warning(disable:4996)\n");
	printf("#include <stdio.h>\n");
	printf("char _string[] = \"%%s\";\n");
	printf("char _value[] = \"%%d\";\n");
	printf("char _charac[] = \"%%c\";\n");
	symbol_table = symbol_table->getInstance();
	Procedure* main_proc = new Procedure("main", 0);
	symbol_table->addNode("main", 0, true);
	symbol_table->into(1);
	code_table = code_table->getInstance();
	code_table->addNode(0);
	code_table->into(0);
	std::vector<Temp*> args;
	new CallCode(main_proc, NULL, args);
	code_table->into(1);
	new FPCode(1, "fp_main");
	//zero = new Temp();
	//one = new Temp();
	string_table = string_table->getInstance();
	node_stack.push(0);
	node_stack.push(1);
	memory = memory->getInstance();
}

void End()
{
	printf("}\n");
	printf("return 0;\n");
	printf("}\n");
}

int main()
{
	freopen("code.asm", "w", stdout);
	Init();
	Symbol symbol("test.txt");
	symbol_table = symbol_table->getInstance();
	symbol.mgetsym();
	Grammar grammar;
	End();
	//system("pause");
	return 0;
}
