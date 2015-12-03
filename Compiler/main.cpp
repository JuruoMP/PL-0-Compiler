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

void Init()
{
	//symbol_table->nodes[symbol_table->index]->offset_cnt = 0;
	symbol_table = symbol_table->getInstance();
	new Procedure("main", 0);
	symbol_table->addNode("main", 0, true);
	symbol_table->into(1);
	code_table = code_table->getInstance();
	//code_table->into(0);
	code_table->addNode(0);
	code_table->into(1);
	zero = new Temp();
	one = new Temp();
	code_table = code_table->getInstance();
	node_stack.push(0);
	node_stack.push(1);
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
	system("pause");
	return 0;
}
