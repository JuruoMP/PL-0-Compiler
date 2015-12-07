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
extern Temp* zero;
extern Temp* one;
extern Memory* memory;

void Init()
{
	symbol_table = symbol_table->getInstance();
	new Procedure("main", 0);
	symbol_table->addNode("main", 0, true);
	symbol_table->into(1);
	code_table = code_table->getInstance();
	code_table->addNode(0);
	code_table->into(1);
	//zero = new Temp();
	//one = new Temp();
	code_table = code_table->getInstance();
	node_stack.push(0);
	node_stack.push(1);
	memory = memory->getInstance();
}

int main()
{
	Init();
	Symbol symbol("test.txt");
	//extern Memory* memory;
	symbol_table = symbol_table->getInstance();
	symbol.mgetsym();
	for (int i = 0; i < word_list.size(); ++i)
	{
		word_list[i].print();
	}
	Grammar grammar;
	for (int i = 0; i < code_table->nodecnt; ++i)
	{
		for (int j = 0; j < code_table->nodes[i]->codes.size(); ++j)
		{
			code_table->nodes[i]->codes.at(j)->print();
		}
	}
	system("pause");
	return 0;
}
