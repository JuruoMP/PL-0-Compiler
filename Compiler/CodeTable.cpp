#include <cstdio>
#include "CodeTable.h"
#include "Symbol.h"
#include "DAG.h"

CodeTable* code_table;
extern char token_name[][16];
extern SymbolTable* symbol_table;
extern Memory* memory;
extern std::stack<int> node_stack;
StringTable* string_table;
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

std::string Label::print()
{
	std::string str;
	str = "Label" + int2string(this->id);
	return str;
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

std::string ConditionCode::print()
{
	std::string str;
	str = this->token + "\t\t";
	str += token_name[this->token]; str += "\t\t";
	str += this->head; str += "\t\t";
	str +=  token_name[this->token]; str += "\t\t";
	str += this->num1->print() + "\t\t";
	str += this->num2->print() + "\t\t";
	str += this->label->print();
	return str;
}

GotoCode::GotoCode(const Label *label)
: Code(GOTOKD, "Goto:")
{
	this->label = new Label(*label);
	code_table->insertCode(this);
}

std::string GotoCode::print()
{
	std::string str;
	str += this->head; str += "\t\t";
	str += this->label->print();
	return str;
}

FPCode::FPCode(int nodeid, char* name)
: Code(FPKD, "FP:")
{
	this->nodeid = nodeid;
	strcpy_s(this->name, MAXLEN - 1, name);
	sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d", this->name, this->nodeid);
	code_table->insertCode(this);
}

std::string FPCode::print()
{
	std::string str;
	str += this->head;
	str += "("; str += int2string(this->nodeid); str += ")"; str += "\t\t";
	str += this->str;
	return str;
}

LabelCode::LabelCode(const Label *label)
: Code(LABELKD, "Label:")
{
	this->label = new Label(*label);
	code_table->insertCode(this);
}

std::string LabelCode::print()
{
	std::string str;
	str += this->head; str += "\t\t";
	str += this->label->print();
	return str;
}

AssignCode::AssignCode(SymbolTK op, const Temp* dst, const Temp* src1, const Temp* src2, bool insert2code)
: Code(ASSIGNKD, "Assign")
{
	this->op = op;
	this->target = new Temp(*dst);
	this->num1 = new Temp(*src1);
	this->num2 = new Temp(*src2);
	if (insert2code)
		code_table->insertCode(this);
}

std::string AssignCode::print()
{
	std::string str;
	str += this->head; str += "\t\t";
	str += token_name[this->op]; str += "\t\t";
	str += this->target->print(); str += "\t\t";
	str += this->num1->print(); str += "\t\t";
	if (this->op != SETTK)
		str += this->num2->print();
	return str;
}

CallCode::CallCode(Callable* cal, Temp* target, std::vector<Temp*> args)
: Code(CALLKD, "Call")
{
	this->cal = cal;
	if (this->cal->type == PROC)
	{
		Procedure* proc = dynamic_cast<Procedure*>(this->cal);
		//"fp_%s_%d", this->name, this->nodeid
		sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d\t\t", proc->name, proc->nodeid);
	}
	else if (this->cal->type == FUNCINT || this->cal->type == FUNCCHAR)
	{
		Function* func = dynamic_cast<Function*>(this->cal);
		//"fp_%s_%d", this->name, this->nodeid
		sprintf_s(this->str, MAXLEN - 1, "fp_%s_%d\t\t", func->name, func->nodeid);
		this->target = target;
	}
	else
	{
		code_table->error("Identifier not callable.");
		//assert(0 == 1);
	}
	this->target = target;
	for (int i = 0; i < args.size(); ++i)
	{
		Parameter* require = cal->getParaAt(i);
		Temp* passin = args.at(i);
		if (require == NULL)
		{
			code_table->error("Too many parameter(s).");
			//assert(0 == 1);
		}
		else if (require->real && 
			(passin->temp_type == VALUETP || passin->temp_type == CONSTTP ||
			passin->temp_type == TEMPINTTP || passin->temp_type == TEMPCHARTP))
		{
			code_table->error("'var' type parameter is not writable.");
			//assert(0 == 1);
		}
		else
			this->args.push_back(passin);
	}
	if (cal->getParaAt(args.size()) != NULL)
	{
		code_table->error("Too less parameter(s).");
		//assert(0 == 1);
	}
	code_table->insertCode(this);
}

std::string CallCode::print()
{
	std::string str;
	str += this->head; str += "\t\t";
	str += this->str;
	if (this->target != NULL)
	{
		str += "dst=";
		str += this->target->print();
		str += "\t\t";
	}
	else
		str += "(no ret)\t";
	str += "argc="; str += int2string(args.size());
	return str;
}

NopCode::NopCode(char* message)
: Code(NOPKD, "Nop")
{
	this->msg = message;
	code_table->insertCode(this);
};

std::string NopCode::print()
{
	std::string str = ";NOP\t" + this->msg;
	return str;
}

WriteCode::WriteCode(char* content)
: Code(WRITEKD, "Write")
{
	this->is_string = true;
	this->value.str_id = string_table->add(content);
	code_table->insertCode(this);
}

WriteCode::WriteCode(Temp* temp)
: Code(WRITEKD, "Write")
{
	this->is_string = false;
	this->value.temp = temp;
	code_table->insertCode(this);
}

std::string WriteCode::print()
{
	std::string str;
	str += this->head; str += "\t\t";
	if (this->is_string)
		str += "String" + int2string(this->value.str_id);
	else
		str += this->value.temp->print();
	return str;
}

ReadCode::ReadCode(Temp* temp)
: Code(READKD, "Read")
{
	this->temp = temp;
	code_table->insertCode(this);
}

std::string ReadCode::print()
{
	std::string str;
	str += this->head;
	str += "\t\t";
	str += this->temp->print();
	return str;
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
		code_table->error("Invalid code.");
		//assert(0 == 1);
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
	for (int i = 0; i < this->codes.size(); ++i)
	{
#ifdef _DEBUG
		this->asms.push_back(new Asm(";" + this->codes.at(i)->print()));
#endif
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
				code_table->error("Not a compare operation.");
				//assert(0 == 1);
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
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == FPKD)
		{
			FPCode* code = dynamic_cast<FPCode*>(basecode);
			Asm* asmcode = new Asm(code->str);//"fp_%s_%d", this->name, this->nodeid
			this->asms.push_back(asmcode);
			//push ebp
			push("ebp");
			//mov ebp, esp
			args.clear();
			args.push_back("ebp"); args.push_back("esp");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
#ifndef LESSPUSHPOP
			//push eax, ebx, ecx, edx, esi, edi
			if (symbol_table->nodes[this->index]->is_proc)
				push("eax");
			push("ebx"); push("ecx"); push("edx");
			push("esi"); push("edi");
#endif
			//push consts, vars, temps
			int nodeid = this->index;
			SymbolTable::Node* node = symbol_table->nodes[nodeid];
			for (int i = 0; i < node->idents.size(); ++i)
			{
				if (node->idents.at(i)->type == CONSTINT || node->idents.at(i)->type == CONSTCHAR)
				{
					Identifier* ident = node->idents.at(i);
					Constance* cons = dynamic_cast<Constance*>(ident);
					char value[MAXLEN];
					sprintf_s(value, MAXLEN - 1, "%d", cons->value);
					push(value);
				}
			}
			//esp -= (node->last_temp - node->last_const) * UNITSIZE;
			args.clear();
			args.push_back("esp");
			char value[MAXLEN];
			sprintf_s(value, MAXLEN - 1, "%d", (node->last_temp - node->last_const) * UNITSIZE);
			args.push_back(value);
			asmcode = new Asm(ASMSUB, args);
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == LABELKD)
		{
			LabelCode* code = dynamic_cast<LabelCode*>(basecode);
			char name[MAXLEN];
			sprintf_s(name, MAXLEN - 1, "Label%d", code->label->id);
			asmcode = new Asm(name);
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == ASSIGNKD)
		{
#ifdef DAGOptimize
			DAG* dag = new DAG();
			while (basecode->kind == ASSIGNKD)
			{
				AssignCode* code = dynamic_cast<AssignCode*>(basecode);
				dag->insert(code);
				i++;
				if (i >= this->codes.size())
					break;
				basecode = this->codes.at(i);
			}
			dag->optimize();
			for (int j = 0; j < dag->result.size(); ++j)
			{
				AssignCode* code = dag->result.at(j);
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
						args.push_back("eax");
						args.push_back("ebx");
						asmcode = new Asm(ASMMUL, args);
						this->asms.push_back(asmcode);
						break;
					case DIVTK:
						//cdq
						//idiv ebx	<-edx.eax/ebx, eax商 edx余数
						args.clear();
						asmcode = new Asm(ASMCDQ, args);
						this->asms.push_back(asmcode);
						args.clear();
						args.push_back("ebx");
						asmcode = new Asm(ASMDIV, args);
						this->asms.push_back(asmcode);
						break;
					}
				}
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
#else
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
					args.push_back("eax");
					args.push_back("ebx");
					asmcode = new Asm(ASMMUL, args);
					this->asms.push_back(asmcode);
					break;
				case DIVTK:
					//cdq
					//idiv ebx	<-edx.eax/ebx, eax商 edx余数
					args.clear();
					asmcode = new Asm(ASMCDQ, args);
					this->asms.push_back(asmcode);
					args.clear();
					args.push_back("ebx");
					asmcode = new Asm(ASMDIV, args);
					this->asms.push_back(asmcode);
					break;
				}
			}
			/*
			1.Generate code to load address of code->target to esi
			2.MOV [esi], eax
			*/
			getTempAddr(code->target);
			args.clear();
			args.push_back("[esi]"); args.push_back("eax");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
#endif
		}
		else if (basecode->kind == CALLKD)
		{
			CallCode* code = dynamic_cast<CallCode*>(basecode);
			int caller_index = this->index;
			int callee_index;
			if (code->cal->type == PROC)
				callee_index = dynamic_cast<Procedure*>(code->cal)->nodeid;
			else
				callee_index = dynamic_cast<Function*>(code->cal)->nodeid;
			//Calculate display_base of caller and count of displays should be copied
			int callee_display_cnt = 0, caller_display_cnt = 0;
			int tmp = callee_index;
			while (tmp > 1)
			{
				callee_display_cnt++;
				tmp = symbol_table->nodes[tmp]->father_index;
			}
			tmp = caller_index;
			while (tmp > 1)
			{
				caller_display_cnt++;
				tmp = symbol_table->nodes[tmp]->father_index;
			}
			//push reversed displays to stack
			//display_base = $ebp + display_offset
			//$esi = $ebp + display_offset
			//mov esi, ebp
			//add esi, display_offset
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";calculate display base addr"));
#endif
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";this->display base -> esi"));
#endif
			args.clear();
			args.push_back("esi"); args.push_back("ebp");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("esi");
			ADDR display_offset = UNITSIZE * (2 + symbol_table->nodes[caller_index]->last_para + caller_display_cnt);
			char value[MAXLEN];
			sprintf_s(value, MAXLEN - 1, "%d", display_offset);
			args.push_back(value);
			asmcode = new Asm(ASMADD, args);
			this->asms.push_back(asmcode);
			//push [display_base($esi) + i * UNITSIZE]
			/*
			|consts		|
			|ret value	|
			|registers	|
			|___________|
			|prev ebp	|
			|ret addr	|
			|paras		|
			|display2	|
			|display1	|/_____display_offset
			|...		|\
			*/
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";start pushing display"));
#endif
			if (caller_display_cnt < callee_display_cnt)
			{
				//case of calling sub function
				for (int i = 1; i <= caller_display_cnt; ++i)
				{
					args.clear();
					sprintf_s(value, MAXLEN - 1, "[esi - %d]", i * UNITSIZE);
					args.push_back(value);
					asmcode = new Asm(ASMPUSH, args);
					this->asms.push_back(asmcode);
				}
				//the last display is ebp of caller
				//lea edi, [ebp]
				//push edi
#ifdef ASMDEBUG
				this->asms.push_back(new Asm("display_cnt"));
#endif
				args.clear();
				char value[MAXLEN];
				sprintf_s(value, MAXLEN - 1, "[ebp]");
				args.push_back("edi"); args.push_back(value);
				asmcode = new Asm(ASMLEA, args);
				this->asms.push_back(asmcode);
				push("edi");
			}
			else
			{
				//case of calling function of the same level or higher level
				for (int i = 1; i <= callee_display_cnt; ++i)
				{
					args.clear();
					sprintf_s(value, MAXLEN - 1, "[esi - %d]", i * UNITSIZE);
					args.push_back(value);
					asmcode = new Asm(ASMPUSH, args);
					this->asms.push_back(asmcode);
				}
			}
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";end pushing display"));
#endif
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";start pushing parameters"));
#endif
			//push reversed parameters to stack
			for (int i = code->args.size() - 1; i >= 0; --i)
			{
				args.clear();
				Parameter* para = code->cal->getParaAt(i);
				assert(para != NULL); 
				Temp* arg = code->args.at(i);
				if (arg->temp_type == VALUETP)
				{
					if (para->real)
						code_table->error("Value type can not be passed by address.");
					//assert(para->real == false);
					sprintf_s(value, MAXLEN - 1, "%d", arg->value);
					push(value);
				}
				else if (arg->temp_type == TEMPINTTP || arg->temp_type == TEMPCHARTP || arg->temp_type == CONSTTP)
				{
					if (para->real)
					{
						if (arg->temp_type == TEMPINTTP || arg->temp_type == TEMPCHARTP)
							code_table->error("Temp value can not be passed by address.");
						else
							code_table->error("Const type can not be passed by address.");
						//assert(para->real == false);
					}
					getTempValue(arg);
					push("edx");
				}
				else if (arg->temp_type == VARTP || arg->temp_type == FORMPARA)
				{
					if (para->real)
					{
						getTempAddr(arg);
						push("esi");
					}
					else
					{
						getTempValue(arg);
						push("edx");
					}
				}
				else if (arg->temp_type == REALPARA)
				{
					if (para->real)
					{
						getTempAddr(arg);
						push("esi");
					}
					else
					{
						getTempValue(arg);
						push("edx");
					}
				}
				else
				{
					code_table->error("Parameter invalid.");
					//assert(0 == 1);
				}
			}
#ifdef ASMDEBUG
			this->asms.push_back(new Asm(";end pushing parameterst"));
#endif
			//call函数
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
			args.clear();
			args.push_back("esp");
			sprintf_s(value, MAXLEN - 1, "%d", UNITSIZE * (callee_display_cnt + code->args.size()));
			args.push_back(value);
			asmcode = new Asm(ASMADD, args);
			this->asms.push_back(asmcode);
		}
		else if (basecode->kind == READKD)
		{
			ReadCode* code = dynamic_cast<ReadCode*>(basecode);
			//getTempAddr()
			if (code->temp->temp_type != VARTP)
				code_table->error("Read to an unchangeable identifier");
			getTempAddr(code->temp);
			//clear [esi]
			//sub eax, eax
			//mov [esi], eax
			args.clear();
			args.push_back("eax"); args.push_back("eax");
			asmcode = new Asm(ASMSUB, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("[esi]"); args.push_back("eax");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			//mov eax, esi
			//lea ebx, _value
			//push eax
			//push ebx
			//call scanf
			//add esp, 2 * UNITSIZE
			args.clear();
			args.push_back("eax"); args.push_back("esi");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("ebx");
			if (code->temp->ident->type == CHAR ||
				code->temp->ident->type == ARRAYCHAR ||
				code->temp->ident->type == CONSTCHAR)
				args.push_back("_charac");
			else
				args.push_back("_value");
			asmcode = new Asm(ASMLEA, args);
			this->asms.push_back(asmcode);
			push("eax");
			push("ebx");
			args.clear();
			args.push_back("scanf");
			asmcode = new Asm(ASMCALL, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("esp");
			char value[MAXLEN];
			sprintf_s(value, MAXLEN - 1, "%d", 2 * UNITSIZE);
			args.push_back(value);
			asmcode = new Asm(ASMADD, args);
			this->asms.push_back(asmcode);

		}
		else if (basecode->kind == WRITEKD)
		{
			WriteCode* code = dynamic_cast<WriteCode*>(basecode);
			if (code->is_string)
			{
				//printf("%s", string)
				//mov eax "in_string+id"
				//lea ebx, _string
				args.clear();
				args.push_back("eax");
				char str[MAXLEN];
				sprintf_s(str, MAXLEN - 1, "in_string%d", code->value.str_id);
				args.push_back(str);
				asmcode = new Asm(ASMLEA, args);
				this->asms.push_back(asmcode);
				args.clear();
				args.push_back("ebx"); args.push_back("dword ptr [_string]");
				asmcode = new Asm(ASMLEA, args);
				this->asms.push_back(asmcode);
			}
			else
			{
				//printf("%d", value)
				//getTempValue()
				//mov eax edx
				//lea ebx, _value
				getTempValue(code->value.temp);
				args.clear();
				args.push_back("eax"); args.push_back("edx");
				asmcode = new Asm(ASMMOV, args);
				this->asms.push_back(asmcode);
				args.clear();
				args.push_back("ebx");
				if (code->value.temp->temp_type == VALUETP)
				{
					args.push_back("_value");
				}
				else if (code->value.temp->temp_type != TEMPINTTP && code->value.temp->temp_type != TEMPCHARTP)
				{
					if (code->value.temp->ident->type == CHAR ||
						code->value.temp->ident->type == ARRAYCHAR ||
						code->value.temp->ident->type == CONSTCHAR || 
						code->value.temp->ident->type == PARACHAR)
						args.push_back("dword ptr [_charac]");
					else
						args.push_back("dword ptr [_value]");
				}
				else
				{
					if (code->value.temp->temp_type == TEMPCHARTP)
						args.push_back("dword ptr [_charac]");
					else
						args.push_back("dword ptr [_value]");
				}
				asmcode = new Asm(ASMLEA, args);
				this->asms.push_back(asmcode);
			}
			//push eax
			//push ebx
			//call printf
			//add esp, 2 * UNITSIZE
			push("eax");
			push("ebx");
			args.clear();
			args.push_back("printf");
			asmcode = new Asm(ASMCALL, args);
			this->asms.push_back(asmcode);
			args.clear();
			args.push_back("esp");
			char value[MAXLEN];
			sprintf_s(value, MAXLEN - 1, "%d", 2 * UNITSIZE);
			args.push_back(value);
			asmcode = new Asm(ASMADD, args);
			this->asms.push_back(asmcode);
		}
		else
		{
			assert(basecode->kind == NOPKD);
		}
	}
	if(symbol_table->nodes[this->index]->is_proc == false)
	{
		//mov eax, [ebp + 6 * UNITSIZE]
		args.clear();
		args.push_back("eax");
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "[ebp - %d]", 6 * UNITSIZE);
		args.push_back(value);
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
	}
#ifndef LESSPUSHPOP
	//pop edi, esi, edx, ecx, ebx, eax
	pop("edi"); pop("esi");
	pop("edx"); pop("ecx"); pop("ebx");
	if (symbol_table->nodes[this->index]->is_proc)
		pop("eax");
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
	this->asms.push_back(new Asm(";getTempValue Srart"));
	//printf(";getTempValue Start\n");
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
		//mov edx, value
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
	this->asms.push_back(new Asm(";getTempValue End"));
	//printf(";getTempValue End\n");
#endif
}

void CodeTable::Node::getTempAddr(Temp *temp)
{
#ifdef ASMDEBUG
	this->asms.push_back(new Asm(";getTempAddr Srart"));
	//printf(";getTempAddr Start\n");
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
	if (temp->temp_type == VARTP || temp->temp_type == CONSTTP || 
		temp->temp_type == REALPARA || temp->temp_type == FORMPARA)
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
		if (temp->temp_type == REALPARA)
		{
			//mov esi, [esi]
			args.clear();
			args.push_back("esi"); args.push_back("[esi]");
			asmcode = new Asm(ASMMOV, args);
			this->asms.push_back(asmcode);
		}
	}
	else
	{
		display_offset = UNITSIZE * (2 + symbol_table->nodes[temp->this_node]->last_para + display_id - 1);
		ident_base_offset = ident->getOffset();
		//mov esi, ebp
		//add esi, display_offset
		//mov esi, [esi]
		//add esi, ident_base_offset
		args.clear();
		args.push_back("esi"); args.push_back("ebp");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
		this->asms.push_back(new Asm(";add display offset to esi"));
		args.clear();
		args.push_back("esi");
		char value[MAXLEN];
		sprintf_s(value, MAXLEN - 1, "%d", display_offset);
		args.push_back(value);
		asmcode = new Asm(ASMADD, args);
		this->asms.push_back(asmcode);
		this->asms.push_back(new Asm(";display is to esi"));
		args.clear();
		args.push_back("esi"); args.push_back("[esi]");
		asmcode = new Asm(ASMMOV, args);
		this->asms.push_back(asmcode);
		args.clear();
		args.push_back("esi");
		sprintf_s(value, MAXLEN - 1, "%d", ident_base_offset);
		args.push_back(value);
		asmcode = new Asm(ASMADD, args);
		this->asms.push_back(asmcode);
	}
	if (temp->has_subscript)//only IDENTTP
	{
		getTempValue(temp->subscribe);
		//imul edx, edx, 4
		args.clear();
		args.push_back("edx"); args.push_back("edx"); args.push_back("4");
		asmcode = new Asm(ASMMUL, args);
		this->asms.push_back(asmcode);
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
	this->asms.push_back(new Asm(";getTempAddr End"));
	//printf(";getTempAddr End\n");
#endif
}

void CodeTable::Init()
{
	Asm* asmcode;
	std::vector<std::string> args;
	//push ebp
	this->nodes[1]->push("ebp");
	//mov ebp, esp
	args.clear();
	args.push_back("ebp"); args.push_back("esp");
	asmcode = new Asm(ASMMOV, args);
	this->nodes[1]->asms.push_back(asmcode);
#ifndef LESSPUSHPOP
	//push eax, ebx, ecx, edx, esi, edi
	this->nodes[1]->push("eax");
	this->nodes[1]->push("ebx");
	this->nodes[1]->push("ecx");
	this->nodes[1]->push("edx");
	this->nodes[1]->push("esi");
	this->nodes[1]->push("edi");
#endif
}

void CodeTable::End()
{
	std::vector<std::string> args;
	this->nodes[1]->asms.pop_back();
	args.clear();
	args.push_back("ENDPOINT");
	this->nodes[1]->asms.push_back(new Asm(ASMJMP, args));
}

void CodeTable::error(char* err_info)
{
	std::cerr << err_info << std::endl;
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

StringTable* StringTable::getInstance()
{
	if (stringtable == NULL)
		stringtable = new StringTable();
	return stringtable;
}

int StringTable::add(char* str)
{
	std::string value = str;
	this->strs.push_back(value);
	return strs.size() - 1;
}

CodeTable* CodeTable::codetable = NULL;
StringTable* StringTable::stringtable = NULL;
