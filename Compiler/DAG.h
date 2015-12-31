#ifndef DAG_H
#define DAG_H

#include "CodeTable.h"
#include <vector>
#include <map>

#define DAGOptimize

extern CodeTable* codetable;

class TreeNode
{
public:
	int nodeid;
	int child1, child2;
	bool is_operator;
	union
	{
		Temp* temp;
		SymbolTK op;
	};
	TreeNode(int id, Temp* temp);
	TreeNode(int id, int child1, int child2, SymbolTK token);
};

struct TempCmp
{
	bool operator () (const Temp* a, const Temp* b) const
	{
		if (a->temp_type != b->temp_type)
			return a->temp_type < b->temp_type;
		else if (a->temp_type == TEMPCHARTP || a->temp_type == TEMPINTTP)
			return a->id < b->id;
		else if (a->temp_type == VALUETP)
			return a->value < b->value;
		else if (a->temp_type == CONSTTP)
			return dynamic_cast<Constance*>(a->ident)->value < dynamic_cast<Constance*>(b->ident)->value;
		else if (a->temp_type == VARTP)
			return strcmp(a->ident->name, b->ident->name) < 0 ? true : false;
		else if (a->temp_type == REALPARA)
			return strcmp(a->ident->name, b->ident->name) < 0 ? true : false;
		else if (a->temp_type == FORMPARA)
			return strcmp(a->ident->name, b->ident->name) < 0 ? true : false;
	}

};

class DAG
{
public:
	std::vector<AssignCode*> assign_codes;
	std::vector<AssignCode*> result;
	std::vector<TreeNode> nodes;
	std::map<Temp*, int, TempCmp> temp2nodeid;
	void insert(AssignCode* code);
	void optimize();
};

#endif