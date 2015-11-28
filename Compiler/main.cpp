#include <iostream>
#include "Symbol.h"
#include "Memory.h"
#include "Grammar.h"

using namespace std;

int main()
{
	extern std::vector<WORD> word_list;
	Symbol symbol("test.txt");
	extern Memory* memory;
	symbol.mgetsym();
	for (int i = 0; i < word_list.size(); ++i)
	{
		word_list[i].print();
	}
	Grammar grammar;
	system("pause");
	return 0;
}
