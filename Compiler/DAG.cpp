#include "DAG.h"
/*
void DAG::insert(AssignCode code)
{
	this->assign_codes.push_back(code);
}

void DAG::optimize()
{
	for (int i = 0; i < assign_codes.size; ++i)
	{
		if (assign_codes.at(i).op == SETTK)
		{
			int srcid;
			Temp* dst = assign_codes.at(i).target;
			Temp* src = assign_codes.at(i).num1;
			std::map<Temp*, int>::iterator it;
			it = temp2nodeid.find(src);
			assert(it != temp2nodeid.end());
			srcid = it->second;
			it = temp2nodeid.find(dst);
			if (it != temp2nodeid.end())
				temp2nodeid.erase(dst);
			temp2nodeid[dst] = srcid;
		}
		else
		{
			//this->result.push_back(assign_codes.at(i));
			int dstid, src1id, src2id;
			Temp* dst = assign_codes.at(i).target;
			Temp* src1 = assign_codes.at(i).num1;
			Temp* src2 = assign_codes.at(i).num2;
			std::map<Temp*, int>::iterator it;
			//Find operate numbers
			it = temp2nodeid.find(src1);
			if (it == temp2nodeid.end())
			{
				assert(src1->temp_type != TEMPCHARTP && src1->temp_type != TEMPINTTP);
				src1id = this->nodes.size();
				TreeNode node(src1id, -1, -1, src1);
				this->nodes.push_back(node);
				temp2nodeid[src1] = src1id;
			}
			else
				src1id = it->second;
			it = temp2nodeid.find(src2);
			if (it == temp2nodeid.end())
			{
				assert(src2->temp_type != TEMPCHARTP && src2->temp_type != TEMPINTTP);
				src2id = this->nodes.size();
				TreeNode node(src2id, -1, -1, src2);
				this->nodes.push_back(node);
				temp2nodeid[src2] = src2id;
			}
			else
				src2id = it->second;
			//Find if result already calculated
			bool found = false;
			int resultid = -1;
			for (int j = 0; j < nodes.size; ++j)
			{
				if (nodes.at(j).op == assign_codes.at(i).op &&
					nodes.at(j).child1 == src1id &&
					nodes.at(j).child2 == src2id)
				{
					resultid = j;
					found = true;
					break;
				}
			}
			if (found)
			{
				//Find result
				it = temp2nodeid.find(dst);
				if (it != temp2nodeid.end())
					temp2nodeid.erase(temp2nodeid.find(dst));
				temp2nodeid[dst] = resultid;
			}
			else
			{
				it = temp2nodeid.find(dst);
				if (it != temp2nodeid.end())
					temp2nodeid.erase(temp2nodeid.find(dst));
				dstid = this->nodes.size();
				TreeNode node(dstid, src1id, src2id, assign_codes.at(i).op);
				this->nodes.push_back(node);
				temp2nodeid[dst] = dstid;
			}
		}
	}
}

TreeNode::TreeNode(int id, int child1, int child2, Temp* temp)
{
	this->nodeid = id;
	this->child1 = child1;
	this->child2 = child2;
	this->is_operator = false;
	this->temp = temp;
}

TreeNode::TreeNode(int id, int child1, int child2, SymbolTK token)
{
	this->nodeid = id;
	this->child1 = child1;
	this->child2 = child2;
	this->is_operator = true;
	this->op = token;
}
*/