#include "BasicBlock.h"

set* set::Union(set* set1, set* set2)
{
	set* new_set = new set();
	for (std::set<Temp*>::iterator it = set1->temps.begin();
		it != set1->temps.end();)
	{
		new_set->temps.insert(*it);
		it++;
	}
	for (std::set<Temp*>::iterator it = set2->temps.begin();
		it != set2->temps.end();)
	{
		new_set->temps.insert(*it);
		it++;
	}
	return new_set;
}

set* set::Minus(set* set1, set* set2)
{
	set* new_set = new set();
	for (std::set<Temp*>::iterator it = set1->temps.begin();
		it != set1->temps.end();)
	{
		new_set->temps.insert(*it);
		it++;
	}
	for (std::set<Temp*>::iterator it = set2->temps.begin();
		it != set2->temps.end();)
	{
		new_set->temps.erase(*it);
		it++;
	}
	return new_set;
}

bool set::In(Temp* temp)
{
	if (this->temps.find(temp) != this->temps.end())
		return true;
	else
		return false;
}

void set::Insert(Temp* temp)
{
	this->temps.insert(temp);
}

bool set::Equ(set* set1, set* set2)
{
	for (std::set<Temp*>::iterator it = set1->temps.begin();
		it != set1->temps.end();)
	{
		if (set2->temps.find(*it) == set2->temps.end())
		{
			return false;
		}
		it++;
	}
	for (std::set<Temp*>::iterator it = set2->temps.begin();
		it != set2->temps.end();)
	{
		if (set1->temps.find(*it) == set1->temps.end())
		{
			return false;
		}
		it++;
	}
	return true;
}

BasicBlock::BasicBlock(int index, CodeTable::Node* parent, int st, int ed)
{
	this->index = index;
	this->node = parent;
	this->st = st;
	this->ed = ed;
	this->size = ed - st;
	this->inset = new set();
	this->outset = new set();
	this->defset = new set();
	this->useset = new set();
}

Code* BasicBlock::get_code(int pos)
{
	if (pos >= 0)
		return this->node->codes.at(this->st + pos);
	else
		return this->node->codes.at(this->ed + pos);
}

void BasicBlock::init_analyse()
{
	for (int i = 0; i < this->size; ++i)
	{
		Code* basecode = this->get_code(i);
		if (basecode->kind == CONDITIONKD)
		{
			ConditionCode* code = dynamic_cast<ConditionCode*>(basecode);
			Temp* src1 = code->num1;
			Temp* src2 = code->num2;
			if (!this->defset->In(src1))
				this->useset->Insert(src1);
			if (!this->defset->In(src2))
				this->useset->Insert(src2);
		}
		else if (basecode->kind == ASSIGNKD)
		{
			AssignCode* code = dynamic_cast<AssignCode*>(basecode);
			Temp* src1 = code->num1;
			Temp* src2 = code->num2;
			Temp* dst = code->target;
			if (!this->defset->In(src1))
				this->useset->Insert(src1);
			if (!this->defset->In(src2))
				this->useset->Insert(src2);
			if (!this->useset->In(dst))
				this->defset->Insert(dst);
		}
		else if (basecode->kind == CALLKD)
		{
			CallCode* code = dynamic_cast<CallCode*>(basecode);
			for (int j = 0; j < code->args.size(); ++j)
			{
				if (!this->defset->In(code->args.at(j)))
					this->useset->Insert(code->args.at(j));
			}
		}
	}
}

