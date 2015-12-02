#include <cstdio>
#include "CodeTable.h"

int Label::label_cnt = 0;
Label::Label()
{
	this->id = label_cnt;
	label_cnt++;
}

void Label::print()
{
	printf("Label%d", this->id);
}

int Temp::temp_cnt = 0;
Temp::Temp()
{
	this->id = temp_cnt;
	temp_cnt++;
}

void Temp::print()
{
	printf("Temp%d", this->id);
}

Code::Code(KIND kind, char* type_name)
{
	this->kind = kind;
	strcpy_s(this->head, MAXLEN - 1, type_name);
}

ConditionCode::ConditionCode(SymbolTK token, const Temp& num1, const Temp& num2, 
	const Label& true_label, const Label& false_label)
: Code(CONDITIONKD, "Condition")
{
	this->token = token;
	this->num1 = new Temp(num1);
	this->num2 = new Temp(num2);
	this->true_label = new Label(true_label);
	this->false_label = new Label(false_label);
}

GotoCode::GotoCode(const Label& label)
: Code(GOTOKD, "Goto:")
{
	this->label = new Label(label);
}

LabelCode::LabelCode(const Label& label)
: Code(LABELKD, "Label:")
{
	this->label = new Label(label);
}

AssignCode::AssignCode(SymbolTK op, const Temp& dst, const Temp& src1, const Temp& src2)
: Code(ASSIGNKD, "Assign")
{
	this->op = op;
	this->target = new Temp(dst);
	this->num1 = new Temp(src1);
	this->num2 = new Temp(src2);
}

CallCode::CallCode(char* name, ADDR retstore, const std::vector<Parameter> args) 
: Code(CALLKD, "Call")
{
	strcpy_s(this->fn, MAXLEN - 1, name);
	this->retstore = retstore;
	std::copy(args.begin(), args.end(), std::back_inserter(this->args));
}

NopCode::NopCode()
: Code(NOPKD, "Nop") {};

SymbolTable* SymbolTable::symboltable;
SymbolTable* symbol_table;

int CodeTable::nodecnt = 0;

CodeTable* CodeTable::getInstance()
{
	if (codetable == NULL)
		codetable = new CodeTable();
	return codetable;
}

int CodeTable::addNode(int father)
{
	nodecnt++;
	if (nodecnt >= MAXCNT)
		return -1;
	nodes[nodecnt] = new Node();
	nodes[nodecnt]->father_index = father;
	return nodecnt;
}

void CodeTable::into(int id)
{
	this->index = id;
}

void CodeTable::back()
{
	//this->index = this->nodes[this->index]->father_index;
	//node_stack.pop();
	this->index = node_stack.top();
}

bool CodeTable::insertCode(Code* code)
{
	if (code->kind == CONDITIONKD)
	{
		ConditionCode* other = dynamic_cast<ConditionCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == GOTOKD)
	{
		GotoCode* other = dynamic_cast<GotoCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == LABELKD)
	{
		LabelCode* other = dynamic_cast<LabelCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == ASSIGNKD)
	{
		AssignCode* other = dynamic_cast<AssignCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == CALLKD)
	{
		CallCode* other = dynamic_cast<CallCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == NOPKD)
	{
		NopCode* other = dynamic_cast<NopCode*>(code);
		Code* other_code = new Code(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else
	{
		assert(0 == 1);
	}
	return true;
}


