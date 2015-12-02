#include <cstdio>
#include "CodeTable.h"
#include "Symbol.h"

CodeTable* code_table;
extern char token_name[][16];
extern SymbolTable* symbol_table;
Temp* zero;
Temp* one;

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
	this->type = VARTP;
	temp_cnt++;
}

Temp::Temp(int value)
{
	this->id = temp_cnt;
	this->type = VALUETP;
	this->value = value;
	temp_cnt++;
}

Temp::Temp(Identifier* ident, bool subscript, Temp* offset)
{
	if (zero == NULL)
		zero = new Temp();
	if (one == NULL)
		one = new Temp();
	this->type = IDENTTP;
	this->ident = ident;
	this->subscript = subscript;
	if (subscript)
		this->offset = new Temp(*offset);
}

void Temp::print()
{
	if (this->type == IDENTTP)
		printf("%s", this->ident->name);
	else if (this->type == VARTP)
		printf("Temp%d", this->id);
	else
		printf("Temp%d=%d", this->id, this->value);
}

Code::Code(KIND kind, char* type_name)
{
	this->kind = kind;
	strcpy_s(this->head, MAXLEN - 1, type_name);
}

ConditionCode::ConditionCode(SymbolTK token, const Temp* num1, const Temp* num2, const Label* label)
: Code(CONDITIONKD, "Condition")
{
	this->token = token;
	this->num1 = new Temp(*num1);
	this->num2 = new Temp(*num2);
	this->label = new Label(*label);
	code_table->insertCode(this);
}

void ConditionCode::print()
{
	printf("%s\t", this->head);
	printf("%s\t", token_name[this->token]);
	this->num1->print(); printf("\t");
	this->num2->print(); printf("\t");
	this->label->print(); printf("\n");
}

GotoCode::GotoCode(const Label *label)
: Code(GOTOKD, "Goto:")
{
	this->label = new Label(*label);
	code_table->insertCode(this);
}

void GotoCode::print()
{
	printf("%s\t", this->head);
	this->label->print();
}

LabelCode::LabelCode(const Label *label)
: Code(LABELKD, "Label:")
{
	this->label = new Label(*label);
	code_table->insertCode(this);
}

void LabelCode::print()
{
	printf("%s\t", this->head);
	this->label->print();
}

AssignCode::AssignCode(SymbolTK op, const Temp* dst, const Temp* src1, const Temp* src2)
: Code(ASSIGNKD, "Assign")
{
	this->op = op;
	this->target = new Temp(*dst);
	this->num1 = new Temp(*src1);
	this->num2 = new Temp(*src2);
	code_table->insertCode(this);
}

void AssignCode::print()
{
	printf("%s\t", this->head);
	printf("%s\t", token_name[this->op]);
	this->target->print(); printf("\t");
	this->num1->print(); printf("\t");
	this->num2->print(); printf("\n");
}

CallCode::CallCode(Identifier* ident, Identifier* target, std::vector<Temp*> args)
: Code(CALLKD, "Call")
{
	this->ident = ident;
	this->target = target;
	std::copy(args.begin(), args.end(), std::back_inserter(this->args));
	code_table->insertCode(this);
}

void CallCode::print()
{
	printf("%s\t", this->head);
	printf("%s\t", this->ident->name);
	printf("%d\t", this->target->name);
	printf("argv=%d\n", args.size());
}

NopCode::NopCode()
: Code(NOPKD, "Nop")
{
	code_table->insertCode(this);
};

void NopCode::print()
{
	printf("Nop\n");
}

WriteCode::WriteCode(char* content)
: Code(WRITEKD, "Write")
{
	this->is_string = true;
	strcpy_s(this->value.content, MAXLEN - 1, content);
	code_table->insertCode(this);
}

WriteCode::WriteCode(Temp* temp)
: Code(WRITEKD, "Write")
{
	this->is_string = false;
	this->value.temp = temp;
	code_table->insertCode(this);
}

void WriteCode::print()
{
	printf("%s\t", this->head);
	if (this->is_string)
		printf("%s", this->value.content);
	else
		this->value.temp->print();
	printf("\n");
}

ReadCode::ReadCode(Identifier* ident)
: Code(READKD, "Read")
{
	this->ident = ident;
	code_table->insertCode(this);
}

void ReadCode::print()
{
	printf("%s\t", this->head);
	printf("%s\n", this->ident->name);
}

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
		Code* other_code = new ConditionCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == GOTOKD)
	{
		GotoCode* other = dynamic_cast<GotoCode*>(code);
		Code* other_code = new GotoCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == LABELKD)
	{
		LabelCode* other = dynamic_cast<LabelCode*>(code);
		Code* other_code = new LabelCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == ASSIGNKD)
	{
		AssignCode* other = dynamic_cast<AssignCode*>(code);
		Code* other_code = new AssignCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == CALLKD)
	{
		CallCode* other = dynamic_cast<CallCode*>(code);
		Code* other_code = new CallCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == NOPKD)
	{
		NopCode* other = dynamic_cast<NopCode*>(code);
		Code* other_code = new NopCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == WRITEKD)
	{
		WriteCode* other = dynamic_cast<WriteCode*>(code);
		Code* other_code = new WriteCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else if (code->kind == READKD)
	{
		ReadCode* other = dynamic_cast<ReadCode*>(code);
		Code* other_code = new ReadCode(*other);
		nodes[index]->codes.push_back(other_code);
		nodes[index]->code_cnt += 1;
	}
	else
	{
		assert(0 == 1);
	}
	return true;
}

CodeTable* CodeTable::codetable = NULL;
