#include "DAG.h"

void DAG::insert(AssignCode* code)
{
	this->assign_codes.push_back(code);
}

void DAG::optimize()
{
	for (int i = 0; i < assign_codes.size(); ++i)
	{
		if (assign_codes.at(i)->op == SETTK)
		{
			int srcid;
			Temp* dst = assign_codes.at(i)->target;
			Temp* src = assign_codes.at(i)->num1;
			std::map<Temp*, int>::iterator it;
			it = temp2nodeid.find(src);
			if (src->temp_type == VALUETP || 
				src->temp_type == VARTP || src->temp_type == CONSTTP ||
				src->temp_type == REALPARA || src->temp_type == FORMPARA)
			{
				if (it == temp2nodeid.end())
				{
					srcid = this->nodes.size();
					TreeNode node(srcid, src);
					node.represent = src;
					this->nodes.push_back(node);
					temp2nodeid[src] = srcid;
				}
				else
					srcid = it->second;
			}
			else
			{
				assert(it != temp2nodeid.end());
				srcid = it->second;
			}
			it = temp2nodeid.find(dst);
			if (it != temp2nodeid.end())
				temp2nodeid.erase(dst);
			temp2nodeid[dst] = srcid;
			if (dst->temp_type == VARTP || dst->temp_type == REALPARA || dst->temp_type == FORMPARA)
			{
				AssignCode* code = new AssignCode(SETTK, dst, findRepresent(src), findRepresent(src), false);
				this->result.push_back(code);
				this->setRepresent(srcid, dst);
			}
		}
		else
		{
			//this->result.push_back(assign_codes.at(i));
			int dstid, src1id, src2id;
			Temp* dst = assign_codes.at(i)->target;
			Temp* src1 = assign_codes.at(i)->num1;
			Temp* src2 = assign_codes.at(i)->num2;
			std::map<Temp*, int>::iterator it;
			//Find operate numbers
			it = temp2nodeid.find(src1);
			if (it == temp2nodeid.end())
			{
				src1id = this->nodes.size();
				TreeNode node(src1id, src1);
				node.represent = src1;
				this->nodes.push_back(node);
				temp2nodeid[src1] = src1id;
			}
			else
				src1id = it->second;
			it = temp2nodeid.find(src2);
			if (it == temp2nodeid.end())
			{
				src2id = this->nodes.size();
				TreeNode node(src2id, src2);
				node.represent = src2;
				this->nodes.push_back(node);
				temp2nodeid[src2] = src2id;
			}
			else
				src2id = it->second;
			//Find if result already calculated
			bool found = false;
			int resultid = -1;
			for (int j = 0; j < nodes.size(); ++j)
			{
				if (nodes.at(j).op == assign_codes.at(i)->op &&
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
				if (dst->temp_type == VARTP || dst->temp_type == REALPARA || dst->temp_type == FORMPARA)
				{
					this->setRepresent(resultid, dst);
					AssignCode* code = new AssignCode(assign_codes.at(i)->op, dst, findRepresent(src1), findRepresent(src2), false);
					this->result.push_back(code);
				}
			}
			else
			{
				it = temp2nodeid.find(dst);
				if (it != temp2nodeid.end())
					temp2nodeid.erase(temp2nodeid.find(dst));
				dstid = this->nodes.size();
				TreeNode node(dstid, src1id, src2id, assign_codes.at(i)->op);
				node.represent = dst;
				this->nodes.push_back(node);
				temp2nodeid[dst] = dstid;
				AssignCode* code = new AssignCode(assign_codes.at(i)->op, dst, findRepresent(src1), findRepresent(src2), false);
				this->result.push_back(code);
			}
		}
	}
}

void DAG::setRepresent(int id, Temp* temp)
{
	for (int i = 0; i < this->nodes.size(); ++i)
	{
		if (nodes.at(i).nodeid == id)
		{
			nodes.at(i).represent = temp;
			break;
		}
	}
}

Temp* DAG::findRepresent(Temp* temp)
{
	int id = this->temp2nodeid[temp];
	return nodes.at(id).represent;
}

TreeNode::TreeNode(int id, Temp* temp)
{
	this->nodeid = id;
	this->child1 = -1;
	this->child2 = -1;
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
