#ifndef BASICBLOCK_H
#define BASICBLOCK_H

#include <set>
#include <vector>
#include "CodeTable.h"

class set
{
public:
	std::set<Temp*> temps;
	set() { this->temps.clear(); }
	static set* Union(set* set1, set* set2);
	static set* Minus(set* set1, set* set2);
	bool In(Temp* temp);
	void Insert(Temp* temp);
	static bool Equ(set* set1, set* set2);
};

class BasicBlock
{
private:
	int st, ed;
public:
	int index;
	int size;
	CodeTable::Node* node;
	set* inset;
	set* outset;
	set* defset;
	set* useset;
	std::vector<int> after;
	BasicBlock(int index, CodeTable::Node* parent, int st, int ed);
	Code* get_code(int pos);
	void init_analyse();
};

#endif

