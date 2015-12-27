#ifndef DAG_H
#define DAG_H

#include "CodeTable.h"
#include <vector>
#include <map>
/*
extern CodeTable* codetable;

class DAG
{
public:
	std::vector<AssignCode> assign_codes;
	std::vector<AssignCode> result;
	std::vector<TreeNode> nodes;
	std::map<Temp*, int> temp2nodeid;
	void insert(AssignCode code);
	void optimize();
};

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
	TreeNode(int id, int child1, int child2, Temp* temp);
	TreeNode(int id, int child1, int child2, SymbolTK token);
};
*/
#endif