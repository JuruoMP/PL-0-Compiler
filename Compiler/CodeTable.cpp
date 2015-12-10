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

//#define ASMDEBUG
//#define LESSPUSHPOP

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
	printf("%s\t\t", this->head);
	printf("%s\t\t", token_name[this->token]);
	this->num1->print(); printf("\t\t");
	this->num2->print(); printf("\t\t");
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
	printf("%s\t\t", this->head);
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
	printf("%s", this->head);
	printf("(%d)\t\t", this->nodeid);
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
	printf("%s\t\t", this->head);
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
	printf("%s\t\t", this->head);
	printf("%s\t\t", token_name[this->op]);
	this->target->print(); printf("\t\t");
	this->num1->print(); printf("\t\t");
	if (this->op != SETTK)
		this->num2->print();
	printf("\n");
}

CallCode::CallCode(Identifier* ident, Temp* target, std::vector<Temp*> args)
: Code(CALLKD, "Call")
{
	this->ident = ident;
	if (this->ident->type == PROC)
	{
		Procedure* proc = dynamic_cast<Procedure*>(this->ident);
		//"fp_%s_%d", this->name, this->nodeid
		sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d\t\t", proc->name, proc->nodeid);
	}
	else
	{
		Function* func = dynamic_cast<Function*>(this->ident);
		//"fp_%s_%d", this->name, this->nodeid
		sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d\t\t", func->name, func->nodeid);
	}
	this->target = target;
	std::copy(args.begin(), args.end(), std::back_inserter(this->args));
	code_table->insertCode(this);
}

void CallCode::print()
{
	printf("%s\t\t", this->head);
	printf("%s", this->str);
	if (this->target != NULL)
	{
		printf("dst=");
		this->target->print();
		printf("\t\t");
	}
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
	printf("%s\t\t", this->head);
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
	printf("%s\t\t", this->head);
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

CodeTable::Node::Node()
{
	this->father_index = 0;
	this->code_cnt = 0;
}

void CodeTable::Node::compile()
{
	Asm* asmcode;
	std::vector<std::string> args;
	//push ebp
	push("ebp");
	//mov ebp, esp
	args.clear();
	args.push_back("ebp"); args.push_back("esp");
	asmcode = new Asm(ASMMOV, args);
	this->asms.push_back(asmcode);
#ifndef LESSPUSHPOP
	//push eax, ebx, ecx, edx, esi, edi
	push("eax"); push("ebx"); push("ecx"); push("edx");
	push("esi"); push("edi");
#endif
	//push consts, vars, temps
	int nodeid = this->index;
	SymbolTable::Node* node = symbol_table->nodes[nodeid];
	for (int i = 0; i < node->last_const; ++i)
	{
		Identifier* ident = node->idents.at(i);
		Constance* cons = dynamic_cast<Constance*>(ident);
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "%d", cons->value);
		push(value);
	}
	//esp -= (node->last_temp - node->last_const) * UNITSIZE;
	args.clear();
	args.push_back("esp");
	char value[MAXLEN];
	sprintf_s(value, MAXLEN - 1, "%d", (node->last_temp - node->last_const) * UNITSIZE);
	args.push_back(value);
	asmcode = new Asm(ASMSUB, args);
	this->asms.push_back(asmcode);
	for (int i = 0; i < this->codes.size(); ++i)
	{
		Code* basecode = this->codes.at(i);
		if (basecode->kind == CONDITIONKD)
		{
			ConditionCode* code = dynamic_cast<ConditionCode*>(basecode);
			/*
			1.Generate code to load value of code->num1 to edx
			2.MOV eax edx
			*/
			getTempValue(code->num1);
			args.clear();
			args.push_back("eax"); args.push_back("edx");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			/*
			1.Generate code to load value of code->num2 to edx
			2.MOV ebx edx
			*/
			getTempValue(code->num2);
			args.clear();
			args.push_back("ebx"); args.push_back("edx");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			/*
			Generate compare code of numbers in eax & ebx
			*/
			args.clear();
			args.push_back("eax"); args.push_back("ebx");
			asmcode = new Asm(ASMCMP, args);
			this->asms.push_back(asmcode);
			args.clear();
			char name[MAXLEN];
			sprintf_s(name, MAXLEN - 1, "Label%d", code->label->id);
			args.push_back(name);
			switch (code->token)
			{
			case SMALLTK:
				asmcode = new Asm(ASMJL, args);
				break;
			case SMALLEQUTK:
				asmcode = new Asm(ASMJNG, args);
				break;
			case LARGETK:
				asmcode = new Asm(ASMJG, args);
				break;
			case LARGEEQUTK:
				asmcode = new Asm(ASMJNL, args);
				break;
			case EQUTK:
				asmcode = new Asm(ASMJE, args);
				break;
			case NEQUTK:
				asmcode = new Asm(ASMJNE, args);
				break;
			default:
				assert(0 == 1);
			}
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
			Asm* asmcode = new Asm(code->str);//"fp_%s_%d", this->name, this->nodeid
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
			/*
			1.Generate code to load value of code->num1 to edx
			2.MOV eax edx
			*/
			getTempValue(code->num1);
			args.clear();
			args.push_back("eax"); args.push_back("edx");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			if (code->op != SETTK)
			{
				/*
				1.Generate code to load value of code->num2 to edx
				2.MOV ebx edx
				*/
				getTempValue(code->num2);
				args.clear();
				args.push_back("ebx"); args.push_back("edx");
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
				/*
				calculate value of assignment and save it to eax
				*/
				switch (code->op)
				{
				case ADDTK:
					//add eax, ebx
					args.clear();
					args.push_back("eax"); args.push_back("ebx");
					asmcode = new Asm(ASMADD, args);
					this->asms.push_back(asmcode);
					break;
				case SUBTK:
					//sub eax, ebx
					args.clear();
					args.push_back("eax"); args.push_back("ebx");
					asmcode = new Asm(ASMSUB, args);
					this->asms.push_back(asmcode);
					break;
				case MULTK:
					//imul ebx	<-edx.eax *= ebx
					args.clear();
					args.push_back("ebp");
					asmcode = new Asm(ASMMUL, args);
					this->asms.push_back(asmcode);
					break;
				case DIVTK:
					//sub edx, edx
					//idiv ebx	<-edx.eax/ebx, eaxÉÌ edxÓàÊý
					args.clear();
					args.push_back("edx"); args.push_back("edx");
					asmcode = new Asm(ASMSUB, args);
					this->asms.push_back(asmcode);
					args.clear();
					args.push_back("ebx");
					asmcode = new Asm(ASMDIV, args);
					this->asms.push_back(asmcode);
					break;
				}
			}
			if (code->target->temp_type == VALUETP)
			{
				printf("Left value can not be constance.\n");
				assert(0 == 1);
				//error();
			}
			else
			{
				/*
				1.Generate code to load address of code->target to esi
				2.MOV [esi], eax
				*/
				getTempAddr(code->target);
				args.clear();
				args.push_back("[esi]"); args.push_back("eax");
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
			}
		}
		else if (basecode->kind == CALLKD)
		{
			/*
			A -> B
			Push display address(prev ebps)
			Notice : 
			if A and B are the same level(A.father == B.father), 
			then B.display = A.display
			*/
			CallCode* code = dynamic_cast<CallCode*>(basecode);
			int caller_index = this->index;
			int callee_index = code->ident->this_node;
			//Calculate display_base of caller and count of displays should be copied
			ADDR display_offset = UNITSIZE * (2 + symbol_table->nodes[caller_index]->last_para);
			int display_cnt = 0, tmp = callee_index;
			while (tmp > 1)
			{
				display_cnt++;
				tmp = symbol_table->nodes[tmp]->father_index;
			}
			//push reversed displays to stack
			//display_base = $ebp + display_offset
			//$esi = $ebp + display_offset
			//mov esi, ebp
			//add esi, display_offset
			args.clear();
			args.push_back("esi"); args.push_back("ebp");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("esi");
			char value[MAXLEN];
			sprintf_s(value, MAXLEN - 1, "%d", display_offset);
			args.push_back(value);
			asmcode = new Asm(ASMADD, args);
			//push [display_base($esi) + i * UNITSIZE]
			for (int i = display_cnt - 1; i >= 0; --i)
			{
				args.clear();
				sprintf_s(value, MAXLEN - 1, "[esi + %d]", i * UNITSIZE);
				args.push_back(value);
				asmcode = new Asm(ASMPUSH, args);
				this->asms.push_back(asmcode);
			}
			//push reversed parameters to stack
			for (int i = code->args.size() - 1; i >= 0; --i)
			{
				args.clear();
				Temp* arg = code->args.at(i);
				if (arg->temp_type == VALUETP)
				{
					sprintf_s(value, MAXLEN - 1, "%d", arg->value);
					args.push_back(value);
				}
				else if (arg->temp_type == TEMPTP)
				{
					getTempValue(arg);
					args.push_back("edx");
				}
				else if (arg->temp_type == IDENTTP)
				{
					Parameter* para = code_table->nodes[callee_index]->getParaAt(i);
					if (para)
					{
						if (para->real)
						{
							getTempAddr(arg);
							args.push_back("esi");
						}
						else
						{
							getTempValue(arg);
							args.push_back("edx");
						}
					}
					else
					{
						//error();
						assert(0 == 1);
					}
				}
				else
				{
					assert(0 == 1);
				}
				asmcode = new Asm(ASMPUSH, args);
				this->asms.push_back(asmcode);
			}
			//callº¯Êý
			args.clear();
			args.push_back(code->str);
			asmcode = new Asm(ASMCALL, args);
			this->asms.push_back(asmcode);
			if (code->target)
			{
				getTempAddr(code->target);
				//mov [esi], eax
				args.clear();
				args.push_back("[esi]"); args.push_back("eax");
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
			}
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
	if(symbol_table->nodes[this->index]->is_proc == false)
	{
		//mov eax, [ebp + UNITSIZE]
		args.clear();
		args.push_back("eax");
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "[ebp - %d]", UNITSIZE);
		args.push_back(value);
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
	}
#ifndef LESSPUSHPOP
	//pop edi, esi, edx, ecx, ebx, eax
	pop("edi"); pop("esi");
	pop("edx"); pop("ecx"); pop("ebx"); pop("eax");
#endif
	//mov esp, ebp
	args.clear();
	args.push_back("esp"); args.push_back("ebp");
	asmcode = new Asm(ASMMOV, args);
	this->asms.push_back(asmcode);
	//pop ebp
	pop("ebp");
	//ret
	args.clear();
	asmcode = new Asm(ASMRET, args);
	this->asms.push_back(asmcode);
}

void CodeTable::Node::getTempValue(Temp *temp)
{
#ifdef ASMDEBUG
	printf("getTempValue Start\n");
#endif
#ifndef LESSPUSHPOP
	//push("eax");
	//push("ebx");
	//push("ecx");
	push("esi");
	//push("edi");
#endif
	Asm *asmcode;
	std::vector<std::string> args;
	if (temp->temp_type == VALUETP)
	{
		args.clear();
		//mov eax, value
		char value[MAXLEN];
		args.push_back("edx");
		sprintf_s(value, MAXLEN - 1, "%d", temp->value);
		args.push_back(value);
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
	}
	else
	{
		//get addr of a temp to $esi
		getTempAddr(temp);
		//mov edx, [esi]
		args.clear();
		args.push_back("edx"); args.push_back("[esi]");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
	}
#ifndef LESSPUSHPOP
	//pop("edi");
	pop("esi");
	//pop("ecx");
	//pop("ebx");
	//pop("eax");
#endif
#ifdef ASMDEBUG
	printf("getTempValue End\n");
#endif
}

void CodeTable::Node::getTempAddr(Temp *temp)
{
#ifdef ASMDEBUG
	printf("getTempAddr Start\n");
#endif
#ifndef LESSPUSHPOP
	//push("eax");
	//push("ebx");
	//push("ecx");
	push("edx");
	//push("edi");
#endif
	Asm *asmcode;
	std::vector<std::string> args;
	Identifier* ident;
	ADDR display_offset = 0, ident_base_offset = 0, subscribe_offset = 0;
	if (temp->temp_type == IDENTTP)
		ident = temp->ident;
	else
		ident = symbol_table->findTemp(temp->id);
	int display_id = 0, node_id = this->index;
	while (node_id != ident->this_node)
	{
		node_id = code_table->nodes[node_id]->father_index;
		display_id++;
	}
	if (display_id == 0)
	{
		display_offset = 0;////////////////
		ident_base_offset = ident->getOffset();
		//mov esi, ebp
		//add esi, ident_base_offset
		args.clear();
		args.push_back("esi"); args.push_back("ebp");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
		args.clear();
		args.push_back("esi");
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "%d", ident_base_offset);
		args.push_back(value);
		asmcode = new Asm(ASMADD, args);
		this->asms.push_back(asmcode);
	}
	else
	{
		display_offset = UNITSIZE * (2 + symbol_table->nodes[ident->this_node]->last_para + display_id);
		ident_base_offset = ident->getOffset();
		//mov esi, ebp
		//add esi, display_offset
		//mov esi, [esi]
		//add esi, ident_base_offset
		args.clear();
		args.push_back("esi"); args.push_back("ebp");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
		args.clear();
		args.push_back("esi");
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "%d", display_offset);
		args.push_back(value);
		asmcode = new Asm(ASMADD, args);
		this->asms.push_back(asmcode);
		args.clear();
		args.push_back("esi"); args.push_back("[esi]");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
		args.clear();
		args.push_back("esi");
		sprintf_s(value, MAXLEN - 1, "%d", ident_base_offset);
		args.push_back(value);
		asmcode = new Asm(ASMADD, args);
	}
	if (temp->has_subscript)//only IDENTTP
	{
		getTempValue(temp->subscribe);
		//add esi, edx
		args.clear();
		args.push_back("esi");
		args.push_back("edx");
		asmcode = new Asm(ASMADD, args);
		this->asms.push_back(asmcode);
	}
#ifndef LESSPUSHPOP
	//pop("edi");
	pop("edx");
	//pop("ecx");
	//pop("ebx");
	//pop("eax");
#endif
#ifdef ASMDEBUG
	printf("getTempAddr End\n");
#endif
}

void CodeTable::Node::push(std::string str)
{
	std::vector<std::string> args;
	args.push_back(str);
	Asm* asmcode = new Asm(ASMPUSH, args);
	this->asms.push_back(asmcode);
}

void CodeTable::Node::pop(std::string str)
{
	std::vector<std::string> args;
	args.push_back(str);
	Asm* asmcode = new Asm(ASMPOP, args);
	this->asms.push_back(asmcode);
}

void CodeTable::Node::printasm()
{
	for (int i = 0; i < this->asms.size(); ++i)
		this->asms.at(i)->print();
}

Parameter* CodeTable::Node::getParaAt(int pos)
{
	int nodeid = this->index;
	Identifier* ident = symbol_table->nodes[nodeid]->idents.at(pos);
	Parameter* para = dynamic_cast<Parameter*>(ident);
	return para;
}

CodeTable* CodeTable::codetable = NULL;
