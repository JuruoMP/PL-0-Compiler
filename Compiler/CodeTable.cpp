#include <cstdio>
#include "CodeTable.h"
#include "Symbol.h"

CodeTable* code_table;
extern char token_name[][16];
extern SymbolTable* symbol_table;
extern Memory* memory;
extern std::stack<int> node_stack;
extern Temp* zero;
extern Temp* one;

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
	this->label->print(); printf("\n");
}

FPCode::FPCode(int nodeid, char* name)
: Code(FPKD, "FP:")
{
	this->nodeid = nodeid;
	strcpy_s(this->name, MAXLEN - 1, name);
	sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d", this->name, this->nodeid);
	code_table->insertCode(this);
}

void FPCode::print()
{
	printf("%s\t", this->head);
	printf("%d\t", this->nodeid);
	printf("%s\n", this->str);
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
	this->label->print(); printf("\n");
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

CallCode::CallCode(Identifier* ident, Temp* target, std::vector<Temp*> args)
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
	this->target->print(); printf("\t");
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
CodeTable::CodeTable()
{
	this->index = 0;
	this->nodes[this->index] = new Node();
}

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
	nodes[nodecnt]->index = nodecnt;
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

CodeTable::Node::Node()
{
	this->father_index = 0;
	this->code_cnt = 0;
}

void CodeTable::Node::compile()
{
	ADDR esp_offset = 0;
	//推入display地址，计算display区数
	Asm* asmcode;
	std::vector<std::string> args;
	//push	ebp
	args.clear();
	args.push_back("ebp");
	asmcode = new Asm(ASMPUSH, args);
	this->asms.push_back(asmcode);
	//mov	ebp, esp
	args.clear();
	args.push_back("ebp"); args.push_back("esp");
	asmcode = new Asm(ASMMOV, args);
	this->asms.push_back(asmcode);
	//push	ebx
	args.clear();
	args.push_back("ebx");
	asmcode = new Asm(ASMPUSH, args);
	//push	esi
	args.clear();
	args.push_back("esi");
	asmcode = new Asm(ASMPUSH, args);
	//push	edi
	args.clear();
	args.push_back("edi");
	asmcode = new Asm(ASMPUSH, args);
	//lea	edi, [ebp-??h]
	for (int i = 0; i < this->codes.size(); ++i)
	{
		Code* basecode = this->codes.at(i);
		if (basecode->kind == CONDITIONKD)
		{
			//
			ConditionCode* code = dynamic_cast<ConditionCode*>(basecode);
			Asm* asmcode;
			

			asmcode = new Asm(ASMCMP, args);
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == GOTOKD)
		{
			GotoCode* code = dynamic_cast<GotoCode*>(basecode);
			args.clear();
			char name[MAXLEN];
			sprintf_s(name, MAXLEN - 1, "Label%d", code->label->id);
			args.push_back(name);
			asmcode = new Asm(ASMJMP, args);
		}
		else if (basecode->kind == FPKD)
		{
			FPCode* code = dynamic_cast<FPCode*>(basecode);
			Asm* asmcode = new Asm(code->str);
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == LABELKD)
		{
			LabelCode* code = dynamic_cast<LabelCode*>(basecode);
			char name[MAXLEN];
			sprintf_s(name, MAXLEN - 1, "Label%d", code->label->id);
			Asm* asmcode = new Asm(name);
		}
		else if (basecode->kind == ASSIGNKD)
		{
			AssignCode* code = dynamic_cast<AssignCode*>(basecode);
			//find the variable/temp on stack, get its address = display[i]{esi+4*display_id} + offset
			if (code->num1->type == VALUETP)
			{
				args.clear();
				char value[MAXLEN];
				sprintf_s(value, MAXLEN - 1, "%d", code->num1->value);
				args.push_back(value);
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
			}
			else if (code->num1->type == IDENTTP || code->num1->type == TEMPTP)
			{
				Identifier* ident;
				if (code->num1->type == IDENTTP)
					ident = code->num1->ident;
				else
					ident = symbol_table->findTemp(code->num1->id);
				int display_id = 0, node_id = this->index;
				while (node_id != ident->this_node)
				{
					node_id = code_table->nodes[node_id]->father_index;
					display_id++;
				}
				if (display_id == 0)
				{
					int ident_offset = ident->getOffset();
					args.clear();
				}
				else
				{
					int display_offset = 4 * display_id;
					int ident_offset = ident->getOffset();
					//display_ebp = [esi + display_offset]
					//real_addr = display_ebp - ident_offset
					if (code->num1->has_subscript)//only IDENTTP
					{
						//
					}
				}
				//char value[MAXLEN];
				//sprintf_s(value, MAXLEN - 1, "[%d]", code->num1->value);
				//args.push_back(value);
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
			}
			if (code->target->type == VALUETP)
			{
				//error();
			}
			else if (code->target->type == IDENTTP)
			{
				Identifier* ident = code->target->ident;
			}
			else if (code->target->type == TEMPTP)
			{
			}
		}
		else if (basecode->kind == CALLKD)
		{
			//
			//A->B 推入A的display区给B
			//如果A比B等级高，再推入A作为B的display区
			CallCode* code = dynamic_cast<CallCode*>(basecode);
			std::vector<std::string> args;
			//逆向push参数
			//call函数
			//push ebp
			//局部变量申请空间
			//释放局部空间
			//pop ebp
			//ret n <- 参数占用的空间
			//code->
			Asm* callcode = new Asm(ASMCALL, args);
		}
		else if (basecode->kind == READKD)
		{
			//TODO : ADD CODE TO READ
			ReadCode* code = dynamic_cast<ReadCode*>(basecode);
		}
		else if (basecode->kind == WRITEKD)
		{
			//TODO : ADD CODE TO WRITE
			WriteCode* code = dynamic_cast<WriteCode*>(basecode);
		}
		else
		{
			assert(basecode->kind == NOPKD);
		}
	}
	//pop	edi  
	args.clear();
	args.push_back("edi");
	asmcode = new Asm(ASMPOP, args);
	this->asms.push_back(asmcode);
	//pop	esi
	args.clear();
	args.push_back("esi");
	asmcode = new Asm(ASMPOP, args);
	this->asms.push_back(asmcode);
	//pop	ebx
	args.clear();
	args.push_back("ebx");
	asmcode = new Asm(ASMPOP, args);
	this->asms.push_back(asmcode);
	//mov	esp, ebp
	args.clear();
	args.push_back("ebp"); args.push_back("ebp");
	asmcode = new Asm(ASMMOV, args);
	this->asms.push_back(asmcode);
	//pop	ebp
	args.clear();
	args.push_back("ebp");
	asmcode = new Asm(ASMPOP, args);
	this->asms.push_back(asmcode);
	//ret
	asmcode = new Asm(ASMRET, args);
	this->asms.push_back(asmcode);
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
	else if (code->kind == FPKD)
	{
		FPCode* other = dynamic_cast<FPCode*>(code);
		Code* other_code = new FPCode(*other);
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
