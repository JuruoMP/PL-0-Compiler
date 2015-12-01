#include <iostream>
#include <stack>
#include "Symbol.h"
#include "Memory.h"
#include "Grammar.h"

using namespace std;

extern std::vector<WORD> word_list;
extern SymbolTable* symbol_table;
extern std::stack<int> node_stack;

void Init()
{
	symbol_table = symbol_table->getInstance();
	symbol_table->into(1);
	node_stack.push(1);
}

int main()
{
	Init();
	Symbol symbol("test.txt");
	//extern Memory* memory;
	symbol_table->addNode(0, true);
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
